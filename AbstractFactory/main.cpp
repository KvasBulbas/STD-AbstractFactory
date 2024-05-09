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

#include <QDebug>

std::string generateCpp() {
    ClassCpp myClass( "MyACsdfdaaasdss" );

    auto myClass2= std::make_shared< ClassCpp >( "MyCAlaasasdsa1ss", ClassCpp::PUBLIC);
    myClass.add(myClass2);

    auto method1 = std::make_shared< MethodCpp >("testfunAc1", "real", MethodCpp::VIRTUAL | MethodCpp::PROTECTED);

    myClass2->add(method1);

    method1->add(std::make_shared< PrintOperatorCpp >( "asdsa2342d" ));

//    myClass.add(
//        std::make_shared< MethodCpp >( "testFunc1", "void", 0 ),
//        ClassCpp::PUBLIC
//        );
//    myClass.add(
//        std::make_shared< MethodCpp >( "testFunc2", "void", MethodCpp::STATIC | ClassCpp::PRIVATE)
//        );
//    myClass.add(
//        std::make_shared< MethodCpp >( "testFunc3", "void", MethodCpp::VIRTUAL | MethodCpp::CONST ),
//        ClassCpp::PUBLIC
//        );
//    auto method = std::make_shared< MethodCpp >( "testFunc4", "void",
//                                               MethodCpp::STATIC );
//    method->add( std::make_shared< PrintOperatorCpp >( R"(Hello, world!\n)" ) );
//    myClass.add( method, ClassCpp::PROTECTED );
    return myClass.compile();
}

std::string generateCSharp() {

    auto myClass = std::make_shared< ClassCSharp >( "MyClasass", ClassCSharp::INTERNAL);

    auto method = std::make_shared< MethodCSharp >( "testFunc2", "void", ClassCSharp::PRIVATE_PROTECTED );

    method->add(std::make_shared< PrintOperatorCSharp >( "asdasd" ));

    myClass->add(method);

    return myClass->compile();
}



std::string generateJAVA() {
    auto myClass = std::make_shared< ClassJAVA >( "MyCla1ss", ClassJAVA::FINAL | ClassJAVA::PUBLIC);

    auto method1 = std::make_shared< MethodJAVA >("testfucn1", "long",
                               MethodJAVA::PROTECTED | MethodJAVA::ABSTRACT | MethodJAVA::STATIC);

    method1->add(std::make_shared< PrintOperatorJAVA >( "SADFASDF" ));

    myClass->add(method1);

    return myClass->compile();
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::cout << generateCpp() << std::endl;
    return a.exec();
}
