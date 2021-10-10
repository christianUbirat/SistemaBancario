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
    int local, tipo,login_adm;
    vector<UsuarioPrivate> usuarios_private;
    vector<Usuario> usuarios;
    string senha_adm;

public :
    // Construtor
    Banco();
   
    // Set
    void set_senha_administrador(string);
    
    // Get
    string get_senha_administrador()const;
    Usuario get_usuario(int);
    UsuarioPrivate get_usuario_private(int);
    
    // Manipulação de arquivos
    void atualizar();
    void salvar()const;
    
    // Controle de erros
    int erro(string);

    // Outros métodos
    pair<int,int> login(void);
    void cadastro(void);
    void cadastro_private(void);
    void cadastro_comum(void);
    void menu(void);
    //void menu_inicial(void);
    void transferir(int,bool,float);
    void historico(void);
    int procurar_private(int)const;
    int procurar(int)const;
    void validacao_transferir(void);
    int gerar(void);

    // Destrutor
    ~Banco(void);

};

#endif
