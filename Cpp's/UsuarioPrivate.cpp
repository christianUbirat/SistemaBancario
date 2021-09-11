#include "UsuarioPrivate.h"

//Construtor
UsuarioPrivate::UsuarioPrivate(string nome, string senha, int numero_conta, float debito, float credito){
    // Checar preços nos arquivos (acoes, titulos e moedas)
    set_nome(nome);
    set_senha(senha);
    set_numero_conta(numero_conta);
    set_debito(debito);
    set_credito(credito);
}

void UsuarioPrivate::comprar_acao(string ticker, int qtd){
    // Abrindo arquivo de acoes
    vector<Acao> acoes;
    vector<Titulo> titulos;
    ifstream arquivo_acoes("acoes.txt");

    // Variaveis auxiliares
    string linha, preco_temp, risco_temp;       
    string nome, ticker_;
    float preco;
    int risco;

    if(arquivo_acoes.is_open()){
        while (getline(arquivo_acoes, linha)){
            stringstream ss(linha);
            getline(ss, nome, ',');
            getline(ss, ticker_, ',');
            getline(ss, preco_temp, ',');
            preco = stof(preco_temp);
            getline(ss, risco_temp, ',');
            risco = stoi(risco_temp);

            Acao acao(nome, ticker_, preco, risco);
            acoes.push_back(acao);
        }
    }
    arquivo_acoes.close();
    cout << "Saldo incial: " << get_credito() << endl;
    for(int i=0; i<acoes.size(); i++){
        if(ticker == acoes[i].getTicker()){
            if(get_credito() >= qtd * acoes[i].getPreco()){
                acoes_compradas.first.push_back(acoes[i]);
                acoes_compradas.second.push_back(qtd);
                set_credito(get_credito() - acoes[i].getPreco()*qtd);
                cout << "Preço da ação " << acoes[i].getNome() << ": " << acoes[i].getPreco() << endl;
                cout << "Quantidade comprada: " << qtd << endl;
                cout << "Custo total: " << qtd*acoes[i].getPreco() << endl;
                cout << "Compra efetuada com sucesso!" << endl << endl;
            }
            else{
                cout << "Saldo insuficiente..." << endl;
            }
        }
    }
    cout << "Lista de ações: " << endl;
    for(int i=0; i<acoes_compradas.first.size(); i++){
        cout << "Nome: " << acoes_compradas.first[i].getNome() << "/ Quantidade: " << qtd << endl;
    }
    cout << "Saldo final: " << get_credito() <<endl;
}


//Destrutor
UsuarioPrivate::~UsuarioPrivate(){
}

