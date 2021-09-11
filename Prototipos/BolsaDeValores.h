#ifndef BOLSADEVALORES_H
#define BOLSADEVALORES_H

#include <vector>
#include <string>

//#include "Banco.cpp"
#include "Acao.h"
#include "RendaFixa.h"

using namespace std;

class BolsaDeValores{
private :
    vector<Acao> acoes;
    vector<Titulo> titulos;
public :
    BolsaDeValores();      // Construtor
    
    // Get's
    /*
    vector<Acao> getAcoes()const;
    vector<Titulo> getTitulos()const;
    */

    // Sets's
    void setAcoes(vector<Acao>);
    void setTitulos(vector<Titulo>);
    
    void mostrarAcoes();
    void mostrarTitulos();
    void mostrarAtivos();

    void salvarAcoes();
    void salvarTitulos();

    ~BolsaDeValores();      // Destrutor
};

#endif
