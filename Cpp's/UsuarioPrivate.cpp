#include "UsuarioPrivate.h"

//Construtor
UsuarioPrivate::UsuarioPrivate(string nome, string senha, int numero_conta, int debito, int credito){
    // Checar preços nos arquivos (acoes, titulos e moedas)
    set_nome(nome);
    set_senha(senha);
    set_numero_conta(numero_conta);
    set_debito(debito);
    set_credito(credito);
}

// Get
pair<vector<Acao>, vector<int> > UsuarioPrivate::get_acoes(){
    return acoes_compradas;
}
pair<vector<Titulo>, vector<int> > UsuarioPrivate::get_titulos(){
    return titulos_comprados;
}

//Set
void UsuarioPrivate::set_acoes(Acao acao, int qtd){
    acoes_compradas.first.push_back(acao);
    acoes_compradas.second.push_back(qtd);
}
void UsuarioPrivate::set_titulo(Titulo titulo, int qtd){
    titulos_comprados.first.push_back(titulo);
    titulos_comprados.second.push_back(qtd);
}

//Destrutor
UsuarioPrivate::~UsuarioPrivate(){
}
