#include "Usuario.h"

//Construtor da Classe Usuario
Usuario::Usuario(string nome, string senha, int numero_conta , float debito, float credito){
    this -> nome = nome;
    this -> senha = senha;
    this -> numero_conta = numero_conta;
    this -> debito = debito;
    this -> credito = credito;
}

//Funções de atribução
void Usuario::set_nome(string nome){
    this -> nome = nome;
}

void Usuario::set_senha(string senha){
    this -> senha = senha;
}

void Usuario::set_numero_conta(int numero_conta){
    this -> numero_conta = numero_conta;
}

void Usuario::set_debito(float debito){
    this -> debito = debito;
}

void Usuario::set_credito(float credito){
    this -> credito = credito;
}

//Funções de retorno
string Usuario::get_nome(void)const{
    return nome;
}

string Usuario::get_senha(void)const{
    return senha;
}

int Usuario::get_numero_conta(void)const{
    return numero_conta;
}

float Usuario::get_debito(void)const{
    return debito;
}

float Usuario::get_credito(void)const{
    return credito;
}

// Funcionalidades da conta
void Usuario::mostrar_estrato(void)const{
    //Função time : para mostrar a hora da impressão do estrato
    //Iomanip
    cout<<setprecision(2)<<fixed;
    cout<<"---------"<<"Usuário :"<<get_numero_conta()<<"---------"<<endl
        <<"Dívida  : "<<get_debito()<<"  R$."<<endl
        <<"Saldo   : "<<get_credito()<<" R$."<<endl;
    for(int indice = 0 ; indice < historico.size() ; indice++)
        cout << historico[indice] << endl;
}

//Destrutor
Usuario::~Usuario(void){
};

