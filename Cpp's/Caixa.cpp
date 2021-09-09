#include "Caixa.h"

// Construtor da classe Caixa
Caixa::Caixa(){
    ifstream Caixa;
    Caixa.open("Dinheiros.txt" , ios::in);
    Caixa>>Qtd_dinheiro;
    if(Caixa.is_open()){
        pair <int,int> auxiliar;
        while(!Caixa.eof()){
            Caixa>>auxiliar.first;
            if(Caixa.eof())
                break;
            Caixa>>auxiliar.second;
            notas.push_back(auxiliar);
        }
    }
    Caixa.close();
}

// Funcionalidades do caixa
void Caixa::gerenciar(void){
    string opcao;
    do{
        cout<<"----------Menu(Gerenciamento)----------"<<endl
            <<"O que deseja fazer ?"<<endl
            <<"(1)- Abastecer   ."<<endl
            <<"(2)- Retirar     ."<<endl
            <<"(3)- Sair do menu."<<endl;
        cin>>opcao;
        if(opcao == "1")
            cout<<"p";
            //abastecer();
        else if(opcao == "2")
            cout<<"i";
            //remover();
        else
            cout<<"Opção inválida ,por favor tente novamente ."<<endl;
    }while(opcao != "3");
}

// Construtor da classe Caixa
Caixa::~Caixa(){
    ofstream Caixa("Dinheiros.txt", ios::trunc);
    Caixa<<Qtd_dinheiro;
    if(Caixa.is_open()){
        for(int indice = 0 ; indice < notas.size() ; indice++){
            Caixa<<notas[indice].first<<notas[indice].second;
        }
    }
    Caixa.close();
}