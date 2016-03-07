/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_TimezoneFNs_H
#define Patternist_TimezoneFNs_H

#include "qatomiccomparator_p.h"
#include "qfunctioncall_p.h"

/**
 * @file
 * @short Contains classes implementing the functions found in
 * <a href="http://www.w3.org/TR/xpath-functions/#timezone.functions">XQuery 1.0 and
 * XPath 2.0 Functions and Operators, 10.7 Timezone Adjustment on Dates and SchemaTime Values</a>.
 * @ingroup Patternist_functions
 */

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Base class for classes implementing functions changing the timezone
     * on values.
     *
     * It would be possible to implement this with the Curiously Recurring Template Pattern, in order
     * to avoid the virtual call dispatching that is done via createValue(). However, these are not
     * very hot code paths and evaluateSingleton() is quite large, which would lead to heavy code
     * expansion.
     *
     * @see <a href="http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern">Curiously
     * Recurring Template Pattern, Wikipedia, the free encyclopedia</a>
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustTimezone : public FunctionCall
    {
    public:
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;

    protected:
        virtual Item createValue(const QDateTime &dt) const = 0;
    };

    /**
     * @short Implements the function <tt>fn:adjust-dateTime-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustDateTimeToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };

    /**
     * @short Implements the function <tt>fn:adjust-dateTime-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustDateToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };

    /**
     * @short Implements the function <tt>fn:adjust-time-to-timezone()</tt>.
     *
     * @ingroup Patternist_functions
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class AdjustTimeToTimezoneFN : public AdjustTimezone
    {
    protected:
        virtual Item createValue(const QDateTime &dt) const;
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
