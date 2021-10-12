#ifndef RENDAFIXA_H
#define RENDAFIXA_H

#include "AtivoFinanceiro.h"

using namespace std;

class Titulo: public Ativo{
private :
    int prazo;
    float duration;
public :
    Titulo(string, string, float, int);     // Construtor

    // Get's
    int getPrazo()const;
    float getDuration()const;

    // Set's
    void setPrazo(int);
    void setDuration(float);
};

#endif