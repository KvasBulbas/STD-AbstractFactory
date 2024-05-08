#include <QCoreApplication>
#include <iostream>
#include <shared_mutex>
#include "unit.h"
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "classcsharp.h"
#include "methodcsharp.h"
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

    ClassCSharp myClass( "MyClass", ClassCSharp::INTERNAL);

    myClass.add(std::make_shared< MethodCSharp >( "testFunc1", "void", 0 ));

    return myClass.compile();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::cout << generateCSharp() << std::endl;
    return a.exec();
}
