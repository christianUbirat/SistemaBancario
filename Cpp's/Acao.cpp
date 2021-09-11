#include "Acao.h"

using namespace std;

Acao::Acao(string nome, string ticker, float preco, int risco){
    setNome(nome);
    setTicker(ticker);
    setPreco(preco);
    this->risco = risco;
}

// Get's
float Acao::getVol()const{
    return volatilidade;
}
int Acao::getRisco()const{
    return risco;
}

// Set's
void Acao::setVol(float volatilidade){
    this->volatilidade = volatilidade;
}
void Acao::setRisco(int risco){
    this->risco = risco;
}