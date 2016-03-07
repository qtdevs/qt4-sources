/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "private/qdeclarativedirparser_p.h"
#include "qdeclarativeerror.h"

#include <QtCore/QTextStream>
#include <QtCore/QtDebug>

QT_BEGIN_NAMESPACE

QDeclarativeDirParser::QDeclarativeDirParser()
    : _isParsed(false)
{
}

QDeclarativeDirParser::~QDeclarativeDirParser()
{
}

QUrl QDeclarativeDirParser::url() const
{
    return _url;
}

void QDeclarativeDirParser::setUrl(const QUrl &url)
{
    _url = url;
}

QString QDeclarativeDirParser::source() const
{
    return _source;
}

void QDeclarativeDirParser::setSource(const QString &source)
{
    _isParsed = false;
    _source = source;
}

bool QDeclarativeDirParser::isParsed() const
{
    return _isParsed;
}

bool QDeclarativeDirParser::parse()
{
    if (_isParsed)
        return true;

    _isParsed = true;
    _errors.clear();
    _plugins.clear();
    _components.clear();

    QTextStream stream(&_source);
    int lineNumber = 0;

    forever {
        ++lineNumber;

        const QString line = stream.readLine();
        if (line.isNull())
            break;

        QString sections[3];
        int sectionCount = 0;

        int index = 0;
        const int length = line.length();

        while (index != length) {
            const QChar ch = line.at(index);

            if (ch.isSpace()) {
                do { ++index; }
                while (index != length && line.at(index).isSpace());

            } else if (ch == QLatin1Char('#')) {
                // recognized a comment
                break;

            } else {
                const int start = index;

                do { ++index; }
                while (index != length && !line.at(index).isSpace());

                const QString lexeme = line.mid(start, index - start);

                if (sectionCount >= 3) {
                    reportError(lineNumber, start, QLatin1String("unexpected token"));

                } else {
                    sections[sectionCount++] = lexeme;
                }
            }
        }

        if (sectionCount == 0) {
            continue; // no sections, no party.

        } else if (sections[0] == QLatin1String("plugin")) {
            if (sectionCount < 2) {
                reportError(lineNumber, -1,
                            QString::fromUtf8("plugin directive requires 2 arguments, but %1 were provided").arg(sectionCount + 1));

                continue;
            }

            const Plugin entry(sections[1], sections[2]);

            _plugins.append(entry);

        } else if (sections[0] == QLatin1String("internal")) {
            if (sectionCount != 3) {
                reportError(lineNumber, -1,
                            QString::fromUtf8("internal types require 2 arguments, but %1 were provided").arg(sectionCount + 1));
                continue;
            }
            Component entry(sections[1], sections[2], -1, -1);
            entry.internal = true;
            _components.append(entry);

        } else if (sectionCount == 2) {
            // No version specified (should only be used for relative qmldir files)
            const Component entry(sections[0], sections[1], -1, -1);
            _components.append(entry);
        } else if (sectionCount == 3) {
            const QString &version = sections[1];
            const int dotIndex = version.indexOf(QLatin1Char('.'));

            if (dotIndex == -1) {
                reportError(lineNumber, -1, QLatin1String("expected '.'"));
            } else if (version.indexOf(QLatin1Char('.'), dotIndex + 1) != -1) {
                reportError(lineNumber, -1, QLatin1String("unexpected '.'"));
            } else {
                bool validVersionNumber = false;
                const int majorVersion = version.left(dotIndex).toInt(&validVersionNumber);

                if (validVersionNumber) {
                    const int minorVersion = version.mid(dotIndex + 1).toInt(&validVersionNumber);

                    if (validVersionNumber) {
                        const Component entry(sections[0], sections[2], majorVersion, minorVersion);

                        _components.append(entry);
                    }
                }
            }
        } else {
            reportError(lineNumber, -1, 
                        QString::fromUtf8("a component declaration requires 3 arguments, but %1 were provided").arg(sectionCount + 1));
        }
    }

    return hasError();
}

void QDeclarativeDirParser::reportError(int line, int column, const QString &description)
{
    QDeclarativeError error;
    error.setUrl(_url);
    error.setLine(line);
    error.setColumn(column);
    error.setDescription(description);
    _errors.append(error);
}

bool QDeclarativeDirParser::hasError() const
{
    if (! _errors.isEmpty())
        return true;

    return false;
}

QList<QDeclarativeError> QDeclarativeDirParser::errors() const
{
    return _errors;
}

QList<QDeclarativeDirParser::Plugin> QDeclarativeDirParser::plugins() const
{
    return _plugins;
}

QList<QDeclarativeDirParser::Component> QDeclarativeDirParser::components() const
{
    return _components;
}

QT_END_NAMESPACE
