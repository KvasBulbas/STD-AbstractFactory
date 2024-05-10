#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include <string>
#include <classunit.h>
#include <vector>
#include <QDebug>

class ClassJAVA : public ClassUnit
{
public:
    explicit ClassJAVA( const std::string& name, Flags modifier = 0 )
    {
        m_name = name;
        m_modifier =  modifier;
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


        if(m_modifier & FINAL)
            result += "final ";
        else
        if(m_modifier & ABSTRACT)
            result += "abstract ";

        result += "class " + m_name  + " {\n";

        for( const auto& b : m_fields ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level ) + "};\n";
        return result;
    }

};

#endif // CLASSJAVA_H
