/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSProgressEvent.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "ProgressEvent.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSProgressEvent);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSProgressEventTableValues[5] =
{
    { "lengthComputable", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventLengthComputable), (intptr_t)0 THUNK_GENERATOR(0) },
    { "loaded", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventLoaded), (intptr_t)0 THUNK_GENERATOR(0) },
    { "total", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventTotal), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsProgressEventConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSProgressEventTable = { 9, 7, JSProgressEventTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSProgressEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSProgressEventConstructorTable = { 1, 0, JSProgressEventConstructorTableValues, 0 };
class JSProgressEventConstructor : public DOMConstructorObject {
public:
    JSProgressEventConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSProgressEventConstructor::s_info = { "ProgressEventConstructor", &DOMConstructorObject::s_info, &JSProgressEventConstructorTable, 0 };

JSProgressEventConstructor::JSProgressEventConstructor(ExecState* exec, Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSProgressEventPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSProgressEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSProgressEventConstructor, JSDOMWrapper>(exec, &JSProgressEventConstructorTable, this, propertyName, slot);
}

bool JSProgressEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSProgressEventConstructor, JSDOMWrapper>(exec, &JSProgressEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSProgressEventPrototypeTableValues[2] =
{
    { "initProgressEvent", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsProgressEventPrototypeFunctionInitProgressEvent), (intptr_t)6 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSProgressEventPrototypeTable = { 2, 1, JSProgressEventPrototypeTableValues, 0 };
const ClassInfo JSProgressEventPrototype::s_info = { "ProgressEventPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSProgressEventPrototypeTable, 0 };

JSObject* JSProgressEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSProgressEvent>(exec, globalObject);
}

bool JSProgressEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSProgressEventPrototypeTable, this, propertyName, slot);
}

bool JSProgressEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSProgressEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSProgressEvent::s_info = { "ProgressEvent", &JSEvent::s_info, &JSProgressEventTable, 0 };

JSProgressEvent::JSProgressEvent(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<ProgressEvent> impl)
    : JSEvent(structure, globalObject, impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSProgressEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSProgressEventPrototype(exec->globalData(), globalObject, JSProgressEventPrototype::createStructure(exec->globalData(), JSEventPrototype::self(exec, globalObject)));
}

bool JSProgressEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSProgressEvent, Base>(exec, &JSProgressEventTable, this, propertyName, slot);
}

bool JSProgressEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSProgressEvent, Base>(exec, &JSProgressEventTable, this, propertyName, descriptor);
}

JSValue jsProgressEventLengthComputable(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->lengthComputable());
    return result;
}


JSValue jsProgressEventLoaded(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsNumber(imp->loaded());
    return result;
}


JSValue jsProgressEventTotal(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    JSValue result = jsNumber(imp->total());
    return result;
}


JSValue jsProgressEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSProgressEvent* domObject = static_cast<JSProgressEvent*>(asObject(slotBase));
    return JSProgressEvent::getConstructor(exec, domObject->globalObject());
}

JSValue JSProgressEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSProgressEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsProgressEventPrototypeFunctionInitProgressEvent(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSProgressEvent::s_info))
        return throwVMTypeError(exec);
    JSProgressEvent* castedThis = static_cast<JSProgressEvent*>(asObject(thisValue));
    ProgressEvent* imp = static_cast<ProgressEvent*>(castedThis->impl());
    const String& typeArg(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool canBubbleArg(exec->argument(1).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool cancelableArg(exec->argument(2).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool lengthComputableArg(exec->argument(3).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    unsigned long long loadedArg(static_cast<unsigned long long>(exec->argument(4).toInteger(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    unsigned long long totalArg(static_cast<unsigned long long>(exec->argument(5).toInteger(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->initProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg);
    return JSValue::encode(jsUndefined());
}


}
