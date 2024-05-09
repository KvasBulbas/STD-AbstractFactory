#ifndef PRINTOPERATORUNITCSHARP_H
#define PRINTOPERATORUNITCSHARP_H
#include "printoperatorunit.h"

class PrintOperatorCSharp : public PrintOperatorUnit {

public:
    explicit PrintOperatorCSharp( const std::string& text )
    {
        m_text = text;
    }
    std::string compile( unsigned int level = 0 ) const override{
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }

};

#endif // PRINTOPERATORUNITCSHARP_H
