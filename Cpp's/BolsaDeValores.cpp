#include "BolsaDeValores.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

BolsaDeValores::BolsaDeValores(){
    // Abrindo arquivo de acoes
    ifstream arquivo_acoes("acoes.txt");

    // Variaveis auxiliares
    string linha, preco_temp, risco_temp;       
    string nome, ticker;
    float preco;
    int risco;

    if(arquivo_acoes.is_open()){
        while (getline(arquivo_acoes, linha)){
            stringstream ss(linha);
            getline(ss, nome, ',');
            getline(ss, ticker, ',');
            getline(ss, preco_temp, ',');
            preco = stof(preco_temp);
            getline(ss, risco_temp, ',');
            risco = stoi(risco_temp);

            Acao acao(nome, ticker, preco, risco);
            acoes.push_back(acao);
        }
    }
    arquivo_acoes.close();

    // Abrindo arquivo de titulos
    ifstream arquivo_titulos("titulos.txt");

    // Variaveis auxiliares
    string linha2, preco_temp2, prazo_temp;       
    string nome2, ticker2;
    float preco2;
    int prazo;

    if(arquivo_titulos.is_open()){
        while (getline(arquivo_titulos, linha2)){
            stringstream ss(linha2);
            getline(ss, nome2, ',');
            getline(ss, ticker2, ',');
            getline(ss, preco_temp2, ',');
            preco2 = stof(preco_temp2);
            getline(ss, prazo_temp, ',');
            prazo = stoi(prazo_temp);

            Titulo titulo(nome2, ticker2, preco2, prazo);
            titulos.push_back(titulo);
        }
    }
    arquivo_titulos.close();
}

void BolsaDeValores::mostrarAcoes(){
    cout << "Ações:" << endl;
    for(int i = 0; i<acoes.size(); i++){
        cout << acoes[i].getNome() << " (" << acoes[i].getTicker() << "): R$ " << fixed << setprecision(2) << 
        acoes[i].getPreco() << "/ Risco: " << acoes[i].getRisco() << endl;
    }
}
void BolsaDeValores::mostrarTitulos(){
    cout << "Títulos:" << endl;
    for(int i = 0; i<titulos.size(); i++){
        cout << titulos[i].getNome() << " (" << titulos[i].getTicker() << "): R$ " << fixed << setprecision(2) << 
        titulos[i].getPreco() << "/ Prazo: " << titulos[i].getPrazo() << " dias" << endl;
    }
}
void BolsaDeValores::mostrarAtivos(){
    cout << "############################################" << endl;
    cout << "Ativos da Bolsa de Valores do Optimum Bank" << endl;
    cout << "############################################" << endl;
    mostrarAcoes();
    cout << "-----------------------------------------------------" << endl;
    mostrarTitulos();
}

// Get's
/*
vector<Acao> BolsaDeValores::getAcoes()const{

}
vector<Titulo> BolsaDeValores::getTitulos()const{

}
*/

// Set's
void BolsaDeValores::setAcoes(vector<Acao> novasAcoes){
    for(int i=0; i<novasAcoes.size(); i++){
        acoes.push_back(novasAcoes[i]);
    }
}
void BolsaDeValores::setTitulos(vector<Titulo> novosTitulos){
    for(int i=0; i<novosTitulos.size(); i++){
        titulos.push_back(novosTitulos[i]);
    }
}

void BolsaDeValores::salvarAcoes(){
     // Salvando dados das acoes
    ofstream arquivo_acoes("acoes.txt");
    if(arquivo_acoes.is_open()){
        //cout << "Abrindo arquivo..." << endl;
        for(int i=0; i<acoes.size(); i++){
            arquivo_acoes << acoes[i].getNome() << ",";
            arquivo_acoes << acoes[i].getTicker() << ",";
            arquivo_acoes << acoes[i].getPreco() << ",";
            arquivo_acoes << acoes[i].getRisco() << endl;
        }
    }
    arquivo_acoes.close();
}

void BolsaDeValores::salvarTitulos(){
     // Salvando dados dos titulos
    ofstream arquivo_titulos("titulos.txt");
    if(arquivo_titulos.is_open()){
        //cout << "Abrindo arquivo..." << endl;
        for(int i=0; i<acoes.size(); i++){
            arquivo_titulos << titulos[i].getNome() << ",";
            arquivo_titulos << titulos[i].getTicker() << ",";
            arquivo_titulos << titulos[i].getPreco() << ",";
            arquivo_titulos << titulos[i].getPrazo() << endl;
        }
    }
    arquivo_titulos.close();
}

BolsaDeValores::~BolsaDeValores(){
   salvarAcoes();
   salvarTitulos();
    //cout << "Dados salvos!" << endl;
}