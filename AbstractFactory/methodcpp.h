#ifndef METHODCPP_H
#define METHODCPP_H
#include "methodunit.h"
#include <vector>
#include <QDebug>

class MethodCpp: public MethodUnit
{
public:
    MethodCpp( const std::string& name, const std::string& returnType, Flags modifier = PRIVATE )
    {
        m_name = name;
        m_returnType = returnType;

        if(!(modifier & PUBLIC || modifier & PROTECTED || modifier & PRIVATE ))
            modifier |= PRIVATE;

        m_modifier = modifier;
    }

    std::string compile( unsigned int level = 0 ) const override {
        std::string result = generateShift( level );
        if( m_modifier & STATIC ) {
            result += "static ";
        } else if( m_modifier & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_modifier & CONST ) {
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";

        return result;
    }


};

#endif // METHODCPP_H
