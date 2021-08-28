#include "Usuario.h"

//Construtor da Classe Usuario
Usuario::Usuario(string nome, string senha, int numero_conta , double debito, double credito, bool privilegio){
    this -> nome = nome;
    this -> senha = senha;
    this -> numero_conta = numero_conta;
    this -> debito = debito;
    this -> credito = credito;
    this -> privilegio = privilegio;
}

//Fun��es de atribu��o
void Usuario::set_nome(string nome){
    this -> nome = nome;
}

void Usuario::set_senha(string senha){
    this -> senha = senha;
}

void Usuario::set_numero_conta(int numero_conta){
    this -> numero_conta = numero_conta;
}

void Usuario::set_debito(double debito){
    this -> debito = debito;
}

void Usuario::set_credito(double credito){
    this -> credito = credito;
}

void Usuario::set_privilegio(bool privilegio){
    this -> privilegio = privilegio;
}

//Fun��es de retorno
string Usuario::set_nome(void)const{
    return nome;
}

string Usuario::set_senha(void)const{
    return senha;
}

int Usuario::set_numero_conta(void)const{
    return numero_conta;
}

double Usuario::set_debito(void)const{
    return debito;
}

double Usuario::set_credito(void)const{
    return credito;
}

bool Usuario::set_privilegio(void)const{
    return privilegio;
}

// Funcionalidades da conta
void Usuario::mostrar_estrato(void)const{
    //Fun��o time : para mostrar a hora da impress�o do estrato
    //Iomanip
    cout<<setprecision(2)<<fixed;
    cout<<"---------"<<"Usu�rio :"<<get_numero_conta()<<"---------"<<endl
        <<"Cr�ditos negativados : "<<get_debito()<<"  R$."<<endl
        <<"Saldo                : "<<get_credito()<<" R$."<<endl;
        (get_privilegio) ? cout<<"Usu�rio Private."<<endl; : cout<<"Usu�rio Comum."<<endl;
    for(int indice = 0 ; indice < historico.size() ; indice++)
        cout<<"Foi realizado um"<<historico[indice]<<endl;
}

//Destrutor
Usuario::~Usuario(void){
};
