#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

/* Sistema de Transação Bancária */

/* Grupo 11:
    Christian Ubiratan
    Lucas Martins

    Monitor: Francinildo
*/

// Para acessar os detalhes do programa, acesse:
// https://github.com/christianUbirat/SistemaBancario

// Os system("cls") é system("clear") no MacOS (trocar conforme necessário)

using namespace std;

#include "UsuarioPrivate.cpp"
#include "Banco.cpp"
#include "Caixa.cpp"
#include "BolsaDeValores.cpp"

int main(){
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    //Criar Banco
    Banco opt_bank;
    BolsaDeValores opt_bolsa;

    string ativos;
    cout << "Já existe um arquivo com as ações e títulos da bolsa de valores?" << endl
         << "(1) - Sim" << endl
         << "(2) - Não" << endl; 
    cin >> ativos;

    if(ativos == "2"){
        // Criar ativos para a bolsa de valores
        Acao A1("Petrobrás", "PETR3", 25, 4);
        Acao A2("TradersClub", "TRAD3", 8, 5);
        Acao A3("Taesa", "TAEE11", 35, 1);
        Acao A4("UFCG", "UFCG4", 22, 1);

        vector <Acao> acoes;
        acoes.push_back(A1);
        acoes.push_back(A2);
        acoes.push_back(A3);
        acoes.push_back(A4);

        opt_bolsa.setAcoes(acoes);

        Titulo T1("Títulos Optimum Bank", "OPMB11 ", 10000, 1);
        Titulo T2("ETF CDB's", "CDBB11", 5000, 3);
        Titulo T3("ETF Taxa de Juros", "FIXA11", 15000, 5);

        vector <Titulo> titulos;
        titulos.push_back(T1);
        titulos.push_back(T2);
        titulos.push_back(T3);

        opt_bolsa.setTitulos(titulos);
    }

    string cadastro, privilegio;
    pair <int , int> dados;
    //system("cls");
    system("clear"); 
    while(cadastro != "3"){
        //Primeiro menu
        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
            << "    Bem-vindo ao Optimum Bank" << endl
            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl
            << "(0) - Conhecer funcionalidades" << endl
            << "-------------------------------------" << endl
            << "Você já possui cadastro?" << endl
            << "(1) - Sim" << endl
            << "(2) - Não" << endl
            << "-------------------------------------" << endl
            << "(3) - Encerrar programa." << endl
            << "Digite aqui: ";
        cin >> cadastro;

        //system("cls");
        system("clear");

        // Inciar menu
        if(cadastro == "0"){
            int inicio;
            do{
                cout<< "----------------------------------------------------" << endl
                    << "Qual funcinalidade deseja conhecer ? " << endl
                    << "(1) - Funções da conta." << endl
                    << "(2) - Caixa." << endl
                    << "(3) - Bolsa de Valores." << endl
                    << "(4) - Voltar para o início." << endl
                    << "Digite aqui: ";
                cin >> inicio;
                if( inicio == 1 ){
                    system("clear");
                    cout << "No banco você terá acesso ao extrato da conta e poderá realizar transferência de crédito." << endl;
                }
                else if( inicio == 2 ){
                    system("clear");
                    cout << "No caixa poderá sacar e depositar " << endl;
                }
                else if( inicio == 3 ){
                    system("clear");
                    cout << "Você poderá acessar a bolsa de valores se for usuário private. "        << endl
                         << "Na bolsa de valores você poderá comprar ações e títulos de renda fixa." << endl;
                }
            }while( inicio != 4 );
            system("clear");
        }
        else if(cadastro == "1"){
            dados = opt_bank.login();
            if(dados.first == 0){
                string menu;
                do{
                    cout<< "Bem-vindo ao Optimum Bank, " << opt_bank.get_usuario_private(dados.second).get_nome() << endl
                        << "O que deseja acessar ? " << endl
                        << "(1) - Funções da conta." << endl
                        << "(2) - Caixa." << endl
                        << "(3) - Bolsa de Valores." << endl
                        << "(4) - Sair do Optimum Bank." << endl
                        << "Digite aqui: ";
                    cin>> menu;
                    if(menu == "1"){
                        //system("cls");
                        system("clear");
                        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
                            << "         Funções da conta" << endl
                            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
                        if( dados.second == -1 )
                            cout << "Gerente não possui método no banco " << endl;
                        else
                            opt_bank.menu();
                    }else if(menu == "2"){
                        //system("cls");
                        system("clear");
                        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
                            << "Bem-vindo ao Optimum Caixa." << endl
                            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
                        Caixa Cofre(dados.first,dados.second);
                        if( dados.second == -1 )
                            Cofre.gerenciar();
                        else
                            Cofre.menu();
                    }else if(menu == "3"){
                        //system("cls");
                        system("clear");
                        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
                            << "Bem-vindo ao Optimum Bolsa de Valores" << endl
                            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
                        if( dados.second == -1 )
                            cout << "Gerente não possui método na Bolsa de Valores " << endl;
                        else
                            opt_bolsa.menu(dados.second);
                    }else if(menu == "4"){
                        //system("cls");
                        system("clear");
                    }else{
                        //system("cls");
                        system("clear");
                        cout << "Opção inválida." << endl;
                    }
                }while(menu != "4");
            }else if(dados.first == 1){
                string menu;
                do{
                    cout<< "Bem-vindo ao Optimum Bank, " << opt_bank.get_usuario(dados.second).get_nome() << endl
                        << "O que deseja acessar ? " << endl
                        << "(1)- Funções da conta." << endl
                        << "(2)- Caixa." << endl
                        << "(3)- Sair do Optimum Bank." << endl
                        << "Digite aqui: ";
                    cin>> menu;
                    if(menu == "1"){
                        //system("cls");
                        system("clear");
                        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
                            << "Funções da sua conta:" << endl
                            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
                        opt_bank.menu();
                    }else if(menu == "2"){
                        //system("cls");
                        system("clear");
                        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
                            << "Bem-vindo ao Optimum Caixa." << endl
                            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
                        Caixa Cofre(dados.first,dados.second);
                        Cofre.menu();
                    }else if(menu == "3"){
                        //system("cls");
                        system("clear"); 
                    }else{
                        //system("cls");
                        system("clear");
                        cout << "Opção inválida." << endl;
                    }
                }while(menu != "3");
            }
            else if(dados.first == -1){
                system("clear");
                cout << "Dados de login inválidos!" << endl << endl;
            }
        // Cadastrar
        }else if(cadastro == "2"){
            opt_bank.cadastro();
        }else if(cadastro == "3"){
            //system("cls");
            system("clear"); 
            cout << "Volte sempre! O Optimum Bank agradece." << endl;

        }else
            cout << "Opção inválida, tente novamente..." << endl << endl;
    }
    return 0;
};
