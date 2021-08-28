#ifndef BOLSADEVALORES_H
#define BOLSADEVALORES_H

#include "Banco.cpp"

class BolsaDeValores{
private :
    double acoes, renda_fixa, liquidez;
public :
    BolsaDeValores(double = 0.0, double = 0.0, double = 0.0);
    ~BolsaDeValores(void);
};

#endif
#endif
