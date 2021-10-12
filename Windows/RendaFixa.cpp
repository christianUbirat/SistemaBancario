#include "RendaFixa.h"

using namespace std;

Titulo::Titulo(string nome, string ticker, float preco, int prazo){
    setNome(nome);
    setTicker(ticker);
    setPreco(preco);
    this->prazo = prazo;
}

// Get's
int Titulo::getPrazo()const{
    return prazo;
}
float Titulo::getDuration()const{
    return duration;
}

// Set's
void Titulo::setPrazo(int prazo){
    this->prazo = prazo;
}
void Titulo::setDuration(float duration){
    this->duration = duration;
}