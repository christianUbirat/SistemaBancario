#ifndef BANCO_H
#define BANCO_H

#include "Usuario.cpp"
#include "UsuarioPrivate.cpp"

class Banco{
private :
    vector<UsuarioPrivate>contas;
    string senha_administrador;
public :
    // Construtor
    Banco(void);
    
    // Set
    void set_senha_administrador(string);

    // Get 
    string get_senha_administrador()const;
    void menu(void);
    void escolha(int);
    void cadastro(void);
    void transferir(void);

    // Destrutor
    ~Banco(void);
};

#endif
