#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H
#include "unit.h"

class PrintOperatorJAVA : public Unit
{
public:
    explicit PrintOperatorJAVA( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "println( \"" + m_text + "\" );\n";
    }


private:
    std::string m_text;
};

#endif // PRINTOPERATORJAVA_H
