#ifndef METHODJAVA_H
#define METHODJAVA_H
#include "methodunit.h"
#include <vector>
#include <QDebug>

class MethodJAVA : public MethodUnit
{

public:
    MethodJAVA( const std::string& name, const std::string& returnType, Flags modifier = PUBLIC )
    {
        m_name = name;
        m_returnType = returnType;

        if(!(modifier & PUBLIC || modifier & FILE || modifier & INTERNAL))
            modifier = modifier | PUBLIC;

        m_modifier = modifier;
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level );

        if(m_modifier & PUBLIC)
            result += "public ";
        else
        if(m_modifier & FILE)
            result += "file ";
        else
        if(m_modifier & INTERNAL)
            result += "internal ";

        if(m_modifier & STATIC)
            result += "static ";

        if(m_modifier & FINAL)
            result += "final ";
        else
        if(m_modifier & ABSTRACT)
            result += "abstract ";

        result += m_returnType + " " + m_name + "(){\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";

        return result;
    }


};

#endif // METHODJAVA_H
