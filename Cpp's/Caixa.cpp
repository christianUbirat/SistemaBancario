#include "Caixa.h"

// Construtor da classe Caixa
Caixa::Caixa(int saldo){
    ifstream Caixa;
    this -> saldo;
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
        cout<<"################### Menu (Gerenciamento)##################"<<endl
            <<":----------------: O que deseja fazer ? :----------------:"<<endl
            <<"         (1)- Abastecer    ."<<endl
            <<"         (2)- Retirar      ."<<endl
            <<"         (3)- Sair do menu ."<<endl;
        cin>>opcao;
        if(opcao == "1")
            abastecer();
        else if(opcao == "2")
            remover();
        else
            cout<<"Opção inválida ,por favor tente novamente ."<<endl;
    }while(opcao != "3");
}

void Caixa::abastecer(void){
    int grana;
    grana = proceso_abastecer();
    Qtd_dinheiro += grana;
}

int Caixa::deposito(void){
    int grana;
    grana = proceso_abastecer();
    return saldo += grana;
}

int Caixa::proceso_abastecer(void){
    int montante,acumulado,valor,quantidade,ciclo;
    bool invalido,termino;
    cout << "Insira a quantia que deseja abastecer " <<endl
         << "Valor bruto :";
    cin  >> montante;
    acumulado = 0;
    vector<pair<int,int>>notas_auxiliar;
    do{
       ciclo = 0;
       cout << "Insira a nota que deseja depositar :";
       cin  >> valor;
       cout << "Insira quantas dessa nota deseja inserir :";
       cin  >> quantidade;
       ciclo = valor*quantidade;
       (ciclo + acumulado > montante) ? invalido = true : invalido = false;
       if(invalido){
        cout << "Os valores inseridos não condizem com a quantia que deseja abastecer" << endl
             << "Por favor tente novamente"                                            << endl;
       }else{
           acumulado += ciclo;
           pair<int,int>remessa;
           remessa.first = valor;
           remessa.second = quantidade;
           notas_auxiliar.push_back(remessa);
        }
       (acumulado == montante) ? termino = true : termino = false;
    }while(!termino);
    for(int indice = 0 ; indice < notas_auxiliar.size() ; indice++)
        notas.push_back(notas_auxiliar[indice]);
    return acumulado;
}

int Caixa::proceso_remocao(void){
    int montante;
    cout << "Insira a quantia que deseja saquar " <<endl
         << "Valor bruto :";
    cin  >> montante;
    return montante;
}

void Caixa::remover(void){
    int grana;
    bool invalido;
    do{
    grana = proceso_remocao();
    (Qtd_dinheiro - grana < 0) ? invalido = true : invalido = false;
    if(invalido)
        cout<< "O banco não possui esse valor : " << grana << " entretanto possui : "<<Qtd_dinheiro <<" R$"<< endl
            << "Por favor tente novamente :)"                                                              << endl;
    else{
        contabilizar();
        sort(notas.begin(),notas.end());
        }
    }while(invalido);
    Qtd_dinheiro -= grana;
}

int Caixa::saque(void){
    int grana;
    bool invalido;
    do{
    grana = proceso_remocao();
    (saldo -= grana < 0) ? invalido = true : invalido = false;
    if(invalido)
        cout<<"Crédito insuficiente, por favor tente novamente ou consulte o extrato da conta :)"<<endl;
    }while(invalido);
    return saldo -= grana;
}

// Construtor da classe Caixa
void Caixa::salvar(void){
    ofstream Caixa("Dinheiros.txt", ios::trunc);
    Caixa<<Qtd_dinheiro<<endl;
    if(Caixa.is_open()){
        for(int indice = 0 ; indice < notas.size() ; indice++){
            Caixa<<notas[indice].first<<endl<<notas[indice].second<<endl;
        }
    }
    Caixa.close();
}

void Caixa::contabilizar(void){
    vector<pair<int,int>>notas_auxiliar;
    int ocorrencia = 0;
    for( int indice = 0 ; indice < notas.size() ; indice++ ){
        ocorrencia = 0;
        for( int indice2 = indice + 1 ; indice2 < notas.size() ; indice2++ ){
            if( indice2 >= notas.size() ){
                break;
            }else if( notas[indice].first == notas[indice2].first ){
                pair<int,int>p_auxiliar;
                p_auxiliar = make_pair ( notas[indice].first , notas[indice].second + notas[indice2].second);
                notas_auxiliar.push_back(p_auxiliar);
                notas.erase(notas.begin()+indice2);
                ocorrencia += 1;
            }
        }
        if( ocorrencia == 0 ){
            pair<int,int>p_auxiliar;
            p_auxiliar = make_pair ( notas[indice].first , notas[indice].second );
            notas_auxiliar.push_back(p_auxiliar);
        }
    }
    notas.swap(notas_auxiliar);
}

Caixa::~Caixa(){
    contabilizar();
    salvar();
}