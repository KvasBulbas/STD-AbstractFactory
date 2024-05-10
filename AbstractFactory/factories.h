#ifndef FACTORIES_H
#define FACTORIES_H
#include <iostream>
#include <shared_mutex>
#include "unit.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "printoperatorunitcsharp.h"
#include "classcsharp.h"
#include "methodcsharp.h"
#include "classjava.h"
#include "methodjava.h"
#include "printoperatorjava.h"
#include "classcpp.h"
#include "methodcpp.h"
#include "printoperatorcpp.h"

class Factory {
public:
    virtual ~Factory() = default;
    using Flags = unsigned int;

    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, const Flags modifier = 0) const = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, const Flags modifier = 0) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};


class FactoryCpp : public Factory{
public:

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, const Flags modifier = 0) const override{
        return std::make_shared< ClassCpp >( name, modifier);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, const Flags modifier = 0) const override{
        return std::make_shared< MethodCpp >( name, returnType, modifier);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override{
        return std::make_shared< PrintOperatorCpp >( text );
    }
};


class FactoryJAVA : public Factory{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, const Flags modifier = 0) const override{
        return std::make_shared< ClassJAVA >( name, modifier);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, const Flags modifier = 0) const override{
        return std::make_shared< MethodJAVA >( name, returnType, modifier);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override{
        return std::make_shared< PrintOperatorJAVA >( text );
    }
};


class FactoryCSharp : public Factory{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, const Flags modifier = 0) const override{
        return std::make_shared< ClassCSharp >( name, modifier);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, const Flags modifier = 0) const override{
        return std::make_shared< MethodCSharp >( name, returnType, modifier);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override{
        return std::make_shared< PrintOperatorCSharp >( text );
    }
};







#endif // FACTORIES_H
