#include "AtivoFinanceiro.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

Ativo::Ativo(string nome, string ticker, float preco){
    this->nome = nome;
    this->ticker = ticker;
    this->preco = preco;
}

// Get's
string Ativo::getNome()const{
    return nome;
}
string Ativo::getTicker()const{
    return ticker;
}
float Ativo::getPreco()const{
    return preco;
}

// Set's
void Ativo::setNome(string nome){
    this->nome = nome;
}
void Ativo::setTicker(string ticker){
    this->ticker = ticker;
}
void Ativo::setPreco(float preco){
    this->preco = preco;
}
