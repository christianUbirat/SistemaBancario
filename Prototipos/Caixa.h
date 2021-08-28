#ifndef CAIXA_H
#define CAIXA_H

#include "Banco.cpp"

class Caixa{
private :
    double Qtd_dinheiro;
    //Biblioteca ultillit
    //Pair<valor da nota, Qtd de nota>
    vector<pair<int,int>>Notas;
public :
    // Construtor
    Caixa(double = 0.0);

    // Funcionalidades do caixa
    void gerenciar(void);
    void abastecer(double);
    void remover(double);

    // Destrutor
    ~Caixa(void);
};

#endif
#endif

