#ifndef ATIVOFINANCEIRO_H
#define ATIVOFINANCEIRO_H

#include <vector>
#include <string>

using namespace std;

class Ativo{
private :
    string nome, ticker;
    float preco;
public :
    Ativo(string="", string="", float=0);     // Construtor
    
    // Get's
    string getNome()const;
    string getTicker()const;
    float getPreco()const;

    // Set's
    void setNome(string);
    void setTicker(string);
    void setPreco(float);
};

#endif