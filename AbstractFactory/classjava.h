#ifndef CLASSJAVA_H
#define CLASSJAVA_H

#include <string>
#include <unit.h>
#include <vector>

class ClassJAVA : public Unit
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


    /* для класса отдельное еще можно использовать final, abstract, */
public:
    explicit ClassJAVA( const std::string& name, Flags flags1 = 0 , Flags flags2 = 0 ) :
        m_name( name ), m_flags1( flags1 ), m_flags2( flags2){}

    void add( const std::shared_ptr< Unit >& unit)
    {
        m_fields.push_back( unit );
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

        switch (m_flags2) {
        case FINAL:
            result += "final ";
            break;
        case ABSTRACT:
            result += "abstract ";
        }


        result += "class " + m_name  + " {\n";

        for( const auto& b : m_fields ) {
            result += b->compile( level + 1 );
        }

        result += generateShift( level ) + "};\n";
        return result;
    }


private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    //std::vector< Fields > m_fields;
    Flags m_flags1;
    Flags m_flags2;
    std::vector< std::shared_ptr< Unit > > m_fields;
};

#endif // CLASSJAVA_H
