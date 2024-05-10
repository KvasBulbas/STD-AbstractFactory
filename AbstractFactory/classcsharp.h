#ifndef CLASSCSHARP_H
#define CLASSCSHARP_H
#include <string>
#include <classunit.h>
#include <vector>

class ClassCSharp : public ClassUnit
{
public:
    ClassCSharp();

public:
    explicit ClassCSharp( const std::string& name, Flags modifier = 0 )
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

        result += "class " + m_name  + " {\n";

        for( const auto& b : m_fields ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level ) + "};\n";
        return result;
    }

};


#endif // CLASSCSHARP_H
