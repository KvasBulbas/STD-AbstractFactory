#ifndef PRINTOPERATORCPP_H
#define PRINTOPERATORCPP_H
#include "printoperatorunit.h"

class PrintOperatorCpp: public PrintOperatorUnit
{
public:
    explicit PrintOperatorCpp( const std::string& text )
    {
        m_text = text;
    }
    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORCPP_H
