#ifndef CAIXA_H
#define CAIXA_H

#include "Banco.cpp"

class Caixa{
private :
    double Qtd_dinheiro;
public :
    // Construtor
    Caixa(double = 0.0);

    // Funcionalidades do caixa
    void abastecer(double);
    void gerenciar(void);

    // Destrutor
    ~Caixa(void);
};

#endif
#endif
