#ifndef CAIXA_H
#define CAIXA_H

#include "Banco.cpp"

class Caixa{
private :
    double Qtd_dinheiro;
    //Biblioteca ultillit
    vector<pair<notas,Qtd>>Notas;
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
