#include "Usuario.h"

//Construtor da Classe Usuario
Usuario::Usuario(string nome, string senha, int numero_conta , int debito, int credito){
    this -> nome = nome;
    this -> senha = senha;
    this -> numero_conta = numero_conta;
    this -> debito = debito;
    this -> credito = credito;
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

void Usuario::set_debito(int debito){
    this -> debito = debito;
}

void Usuario::set_credito(int credito){
    this -> credito = credito;
}

//Fun��es de retorno
string Usuario::get_nome(void)const{
    return nome;
}

string Usuario::get_senha(void)const{
    return senha;
}

int Usuario::get_numero_conta(void)const{
    return numero_conta;
}

int Usuario::get_debito(void)const{
    return debito;
}

int Usuario::get_credito(void)const{
    return credito;
}

// Funcionalidades da conta
void Usuario::mostrar_estrato(void)const{
    //Fun��o time : para mostrar a hora da impress�o do estrato
    cout<<setprecision(2)<<fixed;
    cout<<"---------"<<"Usuário : "<<get_numero_conta()<<"---------"<<endl
        <<"Dívidas : "<<get_debito()<<"  R$."<<endl
        <<"Saldo : "<<get_credito()<<" R$."<<endl;
    for(int indice = 0 ; indice < historico.size() ; indice++)
        cout<<"Foi realizado um : "<<historico[indice]<<endl;
}

void Usuario::atualizar_historico( string acao ){
    cout << historico.size();
    historico.push_back( acao );
    cout << historico.size();
}

//Destrutor
Usuario::~Usuario(void){
};
