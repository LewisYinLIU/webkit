/*
 *  Copyright (C) 1999-2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2007, 2011 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef ArrayPrototype_h
#define ArrayPrototype_h

#include "JSArray.h"
#include "Lookup.h"

namespace JSC {

class ArrayPrototype : public JSArray {
private:
    ArrayPrototype(VM&, Structure*);

public:
    typedef JSArray Base;

    static ArrayPrototype* create(VM&, JSGlobalObject*, Structure*);
        
    static bool getOwnPropertySlot(JSObject*, ExecState*, PropertyName, PropertySlot&);

    DECLARE_INFO;

    static Structure* createStructure(VM& vm, JSGlobalObject* globalObject, JSValue prototype)
    {
        return Structure::create(vm, globalObject, prototype, TypeInfo(ObjectType, StructureFlags), info(), ArrayClass);
    }

protected:
    void finishCreation(VM&, JSGlobalObject*);
};

EncodedJSValue JSC_HOST_CALL arrayProtoFuncValues(ExecState*);

} // namespace JSC

#endif // ArrayPrototype_h
