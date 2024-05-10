#ifndef CLASSCPP_H
#define CLASSCPP_H
#include <string>
#include <classunit.h>
#include <vector>
#include <QDebug>

class ClassCpp: public ClassUnit
{

public:

    std::vector< bool > ACCESS_MODIFIERS = {0, 0, 0};

    explicit ClassCpp( const std::string& name, Flags modifier = PRIVATE )
    {

        m_name = name;

        if(!(modifier & PUBLIC || modifier & PROTECTED || modifier & PRIVATE ))
            modifier |= PRIVATE;

        m_modifier =  modifier;
    }

    void add( const std::shared_ptr< Unit >& unit ) override{


        if(unit->getModifier() & PUBLIC)
            ACCESS_MODIFIERS[0] = true;
        if(unit->getModifier() & PROTECTED)
            ACCESS_MODIFIERS[1] = true;
        if(unit->getModifier() & PRIVATE)
            ACCESS_MODIFIERS[2] = true;

        m_fields.push_back( unit );
    }

    std::string compile( unsigned int level = 0 )  const override
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";


        if(ACCESS_MODIFIERS[0])
        {
            result += generateShift( level ) + "public:\n";
            for( const auto& b : m_fields ) {
                if(b->getModifier() & PUBLIC)
                result += b->compile( level + 1 );
            }
        }


        if(ACCESS_MODIFIERS[1])
        {
            result += generateShift( level ) + "protected:\n";
            for( const auto& b : m_fields ) {
                if(b->getModifier() & PROTECTED)
                result += b->compile( level + 1 );
            }
        }


        if(ACCESS_MODIFIERS[2])
        {
            result += generateShift( level ) + "private:\n";
            for( const auto& b : m_fields ) {
                if(b->getModifier() & PRIVATE)
                result += b->compile( level + 1 );
            }
        }

        result += generateShift( level ) + "};\n";

        return result;
    }


};





#endif // CLASSCPP_H
