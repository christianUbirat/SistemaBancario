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
    // Vetor com as ações
    vector<Acao> acoes;
    // Vetor com os títulos
    vector<Titulo> titulos;
    // Vetor com todos os usuários private
    vector<UsuarioPrivate> usuarios_private;    
public :
    // Construtor
    BolsaDeValores();      

    // Get's
    vector<Acao> getAcoes()const;
    vector<Titulo> getTitulos()const;

    // Sets's
    void setAcoes(vector<Acao>);
    void setTitulos(vector<Titulo>);

    // Menu principal da classe
    void menu(int);

    // Manipulação de arquivos
    void salvarAcoes();
    void salvarTitulos();
    void atualizar_usuarios();
    void salvar_usuarios();
    void atualizar_ativos();
    void att_ativos_usuarios();
    void salvar_ativos_usr();
    
    // Outras funções
    void mostrarAcoes();
    void mostrarTitulos();
    void mostrarAtivos();
    int encontrar_acao(string);
    int encontrar_titulo(string);
    
    // Destrutor
    ~BolsaDeValores();      // Destrutor
};

#endif
