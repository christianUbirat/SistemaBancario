#include "BolsaDeValores.cpp"
#include "AtivoFinanceiro.cpp"
#include "Acao.cpp"
#include "RendaFixa.cpp"
#include "Usuario.cpp"
#include "UsuarioPrivate.cpp"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>


//#include "Banco.cpp"

using namespace std;

int main(){
    // Teste Bolsa de Valores
    BolsaDeValores B3;

    int teste;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n" <<
    "Bem-vindo a bolsa de valores do Optimum Bank! \n" <<
    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n\n" <<
    "Hoje é o dia de inauguração da bolsa? \n" <<
    "1 - Sim \n" <<
    "2 - Não \n";

    cin >> teste;
    if(teste == 1){
        Acao A1("Petrobrás", "PETR3", 25, 4);
        Acao A2("TradersClub", "TRAD3", 8, 5);
        Acao A3("Taesa", "TAEE11", 35, 1);

        vector <Acao> acoes;
        acoes.push_back(A1);
        acoes.push_back(A2);
        acoes.push_back(A3);

        B3.setAcoes(acoes);

        Titulo T1("Títulos Optimum Bank", "OPMB11 ", 10000, 1);
        Titulo T2("ETF CDB's", "CDBB11", 5000, 3);
        Titulo T3("ETF Taxa de Juros", "FIXA11", 15000, 5);

        vector <Titulo> titulos;
        titulos.push_back(T1);
        titulos.push_back(T2);
        titulos.push_back(T3);

        B3.setTitulos(titulos);
    }
    B3.mostrarAtivos();
    cout << "--------------------------------------------------------" << endl;

    UsuarioPrivate U1("Christian", "abc123", 123, 0, 1800);
    UsuarioPrivate U2("Joao", "def456", 456, 0, 0);
    cout << "O usuário Christian (com crédito suficiente) irá tentar comprar 100 ações do TradersClub:" << endl;
    U1.comprar_acao("TRAD3", 100);
    cout << "--------------------------------------------------------" << endl;
    cout << "Agora o usuário João (sem crédito suficiente) irá tentar fazer a mesma coisa:" << endl;
    U2.comprar_acao("TRAD3", 100);

    return 0;
}