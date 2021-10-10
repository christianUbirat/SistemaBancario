#ifndef BOLSADEVALORES_H
#define BOLSADEVALORES_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#include "UsuarioPrivate.h"
#include "Acao.h"
#include "RendaFixa.h"

class BolsaDeValores{
private :
    vector<Acao> acoes;
    vector<Titulo> titulos;
    vector<UsuarioPrivate> usuarios_private;    // Vetor com todos os usuários private
public :
    BolsaDeValores();      // Construtor

    // Get's
    vector<Acao> getAcoes()const;
    vector<Titulo> getTitulos()const;

    // Sets's
    void setAcoes(vector<Acao>);
    void setTitulos(vector<Titulo>);

    void mostrarAcoes();
    void mostrarTitulos();
    void mostrarAtivos();
    // comprar_acao(indice no vetor, ticker, quantidade)
    void comprar_ativo(int);

    void salvarAcoes();
    void salvarTitulos();

    void atualizar_usuarios();
    void salvar_usuarios();
    void atualizar_ativos();
    void att_ativos_usuarios();
    void salvar_ativos_usr();
    

    int encontrar_acao(string);
    int encontrar_titulo(string);

    ~BolsaDeValores();      // Destrutor
};

#endif
