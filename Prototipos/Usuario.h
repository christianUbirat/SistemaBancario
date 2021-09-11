#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Usuario{
private :
	string nome, senha;
	int numero_conta;
	float debito,credito;
	vector<string>historico;
public :
    Usuario(string = "",string = "", int = 0, float = 0.0, float = 0.0);

    // Set's
    void set_nome(string);
    void set_senha(string);
    void set_numero_conta(int);
    void set_debito(float);
    void set_credito(float);

    // Metodos Get
    string get_nome(void)const;
    string get_senha(void)const;
    int get_numero_conta(void)const;
    float get_debito(void)const;
    float get_credito(void)const;

    // Funcionalidades da conta
    void mostrar_estrato(void)const;
    void depositar(float);
    void sacar(float);
    void atualizar_historico(int)const;

    // Destrutor
    ~Usuario(void);
};

#endif