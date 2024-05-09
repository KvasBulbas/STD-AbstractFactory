#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H
#include "printoperatorunit.h"

class PrintOperatorJAVA : public PrintOperatorUnit
{
public:
    explicit PrintOperatorJAVA( const std::string& text )
    {
        m_text = text;
    }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "println( \"" + m_text + "\" );\n";
    }

};

#endif // PRINTOPERATORJAVA_H
