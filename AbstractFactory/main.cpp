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


#include <QDebug>

std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
                                               MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

std::string generateCSharp() {

    //ClassCSharp myClass( "MyClass", ClassCSharp::INTERNAL);

    //myClass.add();

    auto myClass = std::make_shared< ClassCSharp >( "MyClass", ClassCSharp::INTERNAL);

    auto myClass3 = std::make_shared< ClassCSharp >( "MyClass3", ClassCSharp::PUBLIC);

    auto method = std::make_shared< MethodCSharp >( "testFunc2", "void", 0 );

    method->add(std::make_shared< PrintOperatorUnitCSharp >( R"(Hello, world!\n)" ));

    method->add(myClass3);

    method->add(std::make_shared< MethodCSharp >( "testFunc3", "real", 4 ));

    myClass->add(method);



    return myClass->compile();
}



std::string generateJAVA() {
    auto myClass = std::make_shared< ClassJAVA >( "MyClass", ClassJAVA::PRIVATE);

    auto method1 = std::make_shared< MethodJAVA >("testfucn1", "long",
                                                MethodJAVA::PROTECTED, MethodJAVA::ABSTRACT, MethodJAVA::STATIC);


    auto myClass2 = std::make_shared< ClassJAVA >("MyClass2");

    myClass2->add(method1);



    method1->add(std::make_shared< PrintOperatorUnitCSharp >( R"(Hello, world!\n)" ));

    myClass->add(myClass2);

    return myClass->compile();
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::cout << generateJAVA() << std::endl;
    return a.exec();
}
