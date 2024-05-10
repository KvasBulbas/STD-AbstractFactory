#ifndef METHODCSHARP_H
#define METHODCSHARP_H
#include "methodunit.h"
#include <vector>
#include <QDebug>

class MethodCSharp : public MethodUnit
{
public:
    MethodCSharp( const std::string& name, const std::string& returnType, Flags modifier = PRIVATE)
    {

        m_name = name;
        m_returnType = returnType;

        if(!(modifier & PUBLIC || modifier & PROTECTED || modifier & FILE || modifier & INTERNAL ||
             modifier & PRIVATE || modifier & PRIVATE_PROTECTED || modifier & PROTECTED_INTERNAL))
            modifier = PRIVATE;

        m_modifier = modifier;
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level );

        if(m_modifier & PUBLIC)
            result += "public ";
        else
        if(m_modifier & PROTECTED)
            result += "protected ";
        else
        if(m_modifier & FILE)
            result += "public ";
        else
        if(m_modifier & INTERNAL)
            result += "internal ";
        else
        if(m_modifier & PRIVATE)
            result += "private ";
        else
        if(m_modifier & PRIVATE_PROTECTED)
            result += "private protected ";
        else
        if(m_modifier & PROTECTED_INTERNAL)
            result += "protected internal ";

        result += m_returnType + " " + m_name + "(){\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";

        return result;
    }
};

#endif // METHODCSHARP_H
