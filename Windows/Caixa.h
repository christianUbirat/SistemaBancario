#ifndef CAIXA_H
#define CAIXA_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Caixa{
private :

    vector<UsuarioPrivate> usuarios_private;    // Vetor com todos os usu�rios private
    vector<Usuario> usuarios;   // Vetor com todos os usu�rios private
    double Qtd_dinheiro;
    //Pair<valor da nota, Qtd de nota>
    vector<pair<int,int> >notas;
    int saldo,local,tipo;

public :

    //Parãmetros : Localização do usuário que inicio a classe
    //Tipo do usuário que inicio a classe
    Caixa(int,int);
    // Funcionalidades do caixa
    // Funcao da adimistracao
    void gerenciar(void);
    void abastecer(void);
    void remover(void);
    // Funxaoo do's usuarios
    void menu(void);
    void deposito(void);
    void saque(void);
    //Processos
    int erro(string);
    int proceso_abastecer(void);
    int proceso_remocao(void);
    void proceso_aritmetrico_remocao(int);
    void ordenar(void);
    void contabilizar(void);
    bool existe(int)const;
    // Destrutor
    void ler(void);
    void salvar(void);
    ~Caixa();
};

#endif
