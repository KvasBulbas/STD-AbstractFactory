#include <QCoreApplication>
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
#include "factories.h"

#include <QDebug>

std::string generateCpp() {
    //ClassCpp myClass( "MyACsdfdaaasdss" );

    auto factoryCpp = std::make_shared< FactoryJAVA >();



    auto myClass2 = factoryCpp->createClassUnit("MyClass2", ClassCpp::PUBLIC);
    auto myClass = factoryCpp->createClassUnit("MyClass1");
    auto method1 = factoryCpp->createMethodUnit("testfunc1", "real", MethodCpp::VIRTUAL | MethodCpp::PROTECTED);


    auto method2 = factoryCpp->createMethodUnit("testfucn2", "real", MethodCpp::PROTECTED);


    auto method3 = factoryCpp->createMethodUnit("testfunc3", "void");

    auto myClass3 = factoryCpp->createClassUnit("MyClass3", ClassCpp::PROTECTED);

    auto myClass4 = factoryCpp->createClassUnit("MyClass4", ClassCpp::PUBLIC);


    method2->add(myClass3);


    //auto myClass2= std::make_shared< ClassCpp >( "MyCAlaasasdsa1ss", ClassCpp::PUBLIC);
    myClass->add(myClass2);

    myClass2->add(myClass4);

    //auto method1 = std::make_shared< MethodCpp >("testfunAc1", "real", MethodCpp::VIRTUAL | MethodCpp::PROTECTED);

    myClass2->add(method1);
    myClass2->add(method2);
    myClass2->add(method3);


    return myClass->compile();
}

std::string generateCSharp()
{


    auto factorySharp = std::make_shared< FactoryCSharp >();

    //factorySharp->createClassUnit();
    //factorySharp->createMethodUnit();
    //factorySharp->createPrintOperatorUnit();


    auto myClass = factorySharp->createClassUnit( "MyClass");

    auto myClass2 = factorySharp->createClassUnit( "MyClass2", ClassCSharp::FILE);


    auto method1 = factorySharp->createMethodUnit( "testFunc1", "void", ClassCSharp::PRIVATE_PROTECTED );

    auto method2 = factorySharp->createMethodUnit( "testFunc2", "real", ClassCSharp::PROTECTED_INTERNAL);

    auto method3 = factorySharp->createMethodUnit( "testFunc3", "int", ClassCSharp::PROTECTED_INTERNAL);

    auto operator1 = factorySharp->createPrintOperatorUnit("Hello world!");


    myClass->add(method1);

    myClass->add(myClass2);

    myClass2->add(method2);

    myClass->add(method3);


    method2->add(operator1);

    return myClass->compile();
}



std::string generateJAVA() {

    auto factoryJAVA = std::make_shared< FactoryJAVA >();

    //factoryJAVA->createClassUnit();
    //factoryJAVA->createMethodUnit();
    //factoryJAVA->createPrintOperatorUnit();

    auto myClass = factoryJAVA->createClassUnit( "MyCla1ss", ClassJAVA::FILE | ClassJAVA::PUBLIC);

    auto method1 = factoryJAVA->createMethodUnit("testfunc1", "long",
                               MethodJAVA::PROTECTED | MethodJAVA::ABSTRACT | MethodJAVA::STATIC);


    auto method2 = factoryJAVA->createMethodUnit("testfunc2", "void",
                                                 MethodJAVA::INTERNAL);

    method1->add(factoryJAVA->createPrintOperatorUnit( "Hello world!" ));

    myClass->add(method1);

    myClass->add(method2);

    return myClass->compile();
}


std::string generateCode(const std::shared_ptr<Factory> &factory)
{
    auto myClass = factory->createClassUnit( "MyCla1ss", ClassCpp::PUBLIC);

    auto method1 = factory->createMethodUnit("testfunc1", "long", ClassUnit::PROTECTED );

    auto method2 = factory->createMethodUnit("testfunc2", "int", ClassUnit::PUBLIC);

    myClass->add(method1);

    myClass->add(method2);

     method1->add(factory->createPrintOperatorUnit( "Hello world!" ));

    return myClass->compile();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::cout << "C++ code:\n" <<generateCpp() << std::endl;

    std::cout << "C# code:\n" << generateCSharp() << std::endl;

    std::cout << "JAVA code:\n" << generateJAVA() << std::endl;

    //std::cout << generateCode(std::make_shared< FactoryCSharp >()) << std::endl;

    return a.exec();
}
