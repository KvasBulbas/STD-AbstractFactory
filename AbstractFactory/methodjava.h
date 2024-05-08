#ifndef METHODJAVA_H
#define METHODJAVA_H
#include "unit.h"
#include <vector>
#include <QDebug>

class MethodJAVA : public Unit
{
public:
    enum AccessModifier {
        PUBLIC = 1,
        PROTECTED,
        PRIVATE
    };

    enum NonAccessModifier {
        FINAL = 1,
        ABSTRACT
    };

    enum StaticModifier{
        STATIC = 1
    };


public:
    MethodJAVA( const std::string& name, const std::string& returnType,
                 Flags flags1 = 0 , Flags flags2 = 0, Flags flags3 = 0) :
        m_name( name ), m_returnType( returnType ),
                m_flags1( flags1 ), m_flags2( flags2 ), m_flags3( flags3 ) { }

    void add( const std::shared_ptr< Unit >& unit)
    {
        m_body.push_back( unit );
    }


    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift( level );

        switch (m_flags1) {
        case PUBLIC:
            result += "public ";
            break;
        case PROTECTED:
            result += "protected ";
            break;
        case PRIVATE:
            result += "private ";
        }

        if(m_flags3 == STATIC)
            result += "static ";


        switch (m_flags2) {
        case FINAL:
            result += "final ";
            break;
        case ABSTRACT:
            result += "abstract ";
        }


        result += m_returnType + " " + m_name + "(){\n";

        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";

        return result;
    }


private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags1;
    Flags m_flags2;
    Flags m_flags3;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHODJAVA_H
