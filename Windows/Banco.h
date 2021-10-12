#ifndef BANCO_H
#define BANCO_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

class Banco{
private :
    // Tipo: 0 para private e 1 para comum
    // Local: posição do usuario no vetor de usuarios (private ou comum)
    // Data: data (temporal)
    int data, local, tipo,login_adm;
    vector<UsuarioPrivate> usuarios_private;
    vector<Usuario> usuarios;
    string senha_adm;

public :

    Banco();
    //set
    void set_senha_administrador(string);
    //get
    string get_senha_administrador()const;
    Usuario get_usuario(int);
    UsuarioPrivate get_usuario_private(int);

    //manipulação de arquivo
    void atualizar();
    void salvar()const;
    
    //métodos próprios
    int erro(string);
    pair<int,int> login(void);
    void cadastro(void);
    void cadastro_private(void);
    void cadastro_comum(void);
    void menu(void);
    void menu_inicial(void);
    void transferir(int,bool,float);
    void historico(void);
    
    //auxiliares
    void escolha(int,int);
    int procurar_private(int)const;
    int procurar(int)const;
    void validacao_transferir(void);
    int gerar(void);
    ~Banco(void);

};

#endif
