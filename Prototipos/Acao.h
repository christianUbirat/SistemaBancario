#ifndef ACAO_H
#define ACAO_H

#include "AtivoFinanceiro.h"

using namespace std;

class Acao: public Ativo{
private :
    float volatilidade;
    int risco;
    vector<float> historico;
public :
    Acao(string, string, float, int);        //Construtor
    
    // Get's
    float getVol()const;
    int getRisco()const;
    
    // Set's
    void setVol(float);
    void setRisco(int);

    // Outras funcoes uteis
    // void mostrarDados();
    float precoMaximo(int);
    float precoMinimo(int);
    float precoMedio(int);
    float variancia(int);
};

#endif