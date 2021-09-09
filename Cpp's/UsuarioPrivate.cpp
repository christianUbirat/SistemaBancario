#include "UsuarioPrivate.h"

//Construtor da Classe Usuario Private
UsuarioPrivate::UsuarioPrivate(string nome, string senha, int numero_conta , double debito, double credito,
                 bool privilegio, double investimentos, double saldo_moeda_estrangeira){
    set_nome(nome);
    set_senha(senha);
    set_numero_conta(numero_conta);
    set_debito(debito);
    set_credito(credito);
    set_privilegio(privilegio);
    this -> investimentos = investimentos;
    this -> saldo_moeda_estrangeira = saldo_moeda_estrangeira;
}

//Métodos de retorno
double UsuarioPrivate::get_investimentos(void)const{
    return investimentos;
}

double UsuarioPrivate::get_saldo_moeda_estrangeira(void)const{
    return saldo_moeda_estrangeira;
}

//Destrutor da Classe Usuario Private
UsuarioPrivate::~UsuarioPrivate(){
}
