#include "Caixa.h"

// Construtor da classe Caixa
Caixa::Caixa( int local , int tipo ){
    ifstream Caixa;
    this -> local = local;
    this -> tipo = tipo;
    ler();
    Caixa.open("Dinheiros.txt" , ios::in);
    Caixa>>Qtd_dinheiro;
    int primeiro,segundo;
    string linha,first_temp,second_temp;
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

//Este método é responsável pelo tratamento de erro da classe
int Caixa::erro(string tentativa){
    int conversao;
    try{
        conversao = stoi(tentativa);
    }catch(exception& e){
        cout << "erooooooooooooooooooooooooooooooooou !!!!!!!!!!!! : " << e.what() << " ,Erro de conversão insira um inteiro . "<< endl;
        system("pause");
        return -1;
    }
    return conversao;
}

void Caixa::ler(void){ //Aqui o programa ler as contas salva no arquivo txt
    //Caso o usuário que inicio a classe seja do tipo private
    if(tipo == 0){
        usuarios_private.clear();
        ifstream Usuario_private;
        string nome_p, senha_p, numero_conta_temp_p, debito_temp_p, credito_temp_p, linha;
        int numero_conta_p;
        double debito_p,credito_p;
        Usuario_private.open("Usuario_private.txt" , ios::in);
        if(Usuario_private.is_open()){
            while (getline(Usuario_private, linha)){
                stringstream ss(linha);
                getline(ss, nome_p, ',');
                getline(ss, senha_p, ',');
                getline(ss, numero_conta_temp_p, ',');
                numero_conta_p = stoi(numero_conta_temp_p);
                getline(ss, debito_temp_p, ',');
                debito_p = stod(debito_temp_p);
                getline(ss, credito_temp_p, ',');
                credito_p = stod(credito_temp_p);

                UsuarioPrivate conta_auxiliar_p(nome_p, senha_p, numero_conta_p, debito_p, credito_p);
                usuarios_private.push_back(conta_auxiliar_p);
            }
        }
        Usuario_private.close();
    }else{
        //Caso o usuário que inicio a classe seja do tipo padrão
        usuarios.clear();
        ifstream Usuario_arq;
        string nome, senha, numero_conta_temp, debito_temp, credito_temp, linha2;
        int numero_conta;
        double debito,credito;
        Usuario_arq.open("Usuario.txt" , ios::in);
        if(Usuario_arq.is_open()){
            while (getline(Usuario_arq, linha2)){
                stringstream ss(linha2);
                getline(ss, nome, ',');
                getline(ss, senha, ',');
                getline(ss, numero_conta_temp, ',');
                numero_conta = stoi(numero_conta_temp);
                getline(ss, debito_temp, ',');
                debito = stod(debito_temp);
                getline(ss, credito_temp, ',');
                credito = stod(credito_temp);

                Usuario conta_auxiliar(nome, senha, numero_conta, debito, credito);
                usuarios.push_back(conta_auxiliar);
            }
        }
        Usuario_arq.close();
    }
    //caso tenha entrado sem nenhum usuário : em caso de test's
    if (usuarios_private.empty() && usuarios.empty())
        saldo = 0;
    else
        //O Saldo é o credito do usuario
        ( tipo == 0 ) ? saldo = usuarios_private[local].get_credito() : saldo = usuarios[local].get_credito() ;
}

// Funcionalidades do caixa : para o gerente
void Caixa::gerenciar(void){
    string opcao;
    do{
        system("cls");
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
        else if(opcao != "3")
            cout<<"Opção inválida ,por favor tente novamente ."<<endl;
    }while(opcao != "3");
}

// Funcionalidades do caixa : para os usuários
void Caixa::menu(void){
    string opcao;
    do{
        system("cls");
        cout<<"########################### Menu ##########################"<<endl
            <<":----------------: O que deseja fazer ? :----------------:"<<endl
            <<"         (1)- Depositar    ."<<endl
            <<"         (2)- saque        ."<<endl
            <<"         (3)- Sair do menu ."<<endl;
        cin>>opcao;
        if(opcao == "1")
            deposito();
        else if(opcao == "2")
            saque();
        else if(opcao != "3")
            cout<<"Opção inválida ,por favor tente novamente ."<<endl;
    }while(opcao != "3");
}

//Método de abastecer o Banco com dinheiro ,e cedulas
void Caixa::abastecer(void){
    int grana;
    grana = proceso_abastecer();
    Qtd_dinheiro += grana;
}

//Método de depositar crédito na conta que no caso támbem aumenta a qtd de dinheiro no caixa e abstece de cedulas
void Caixa::deposito(void){
    int grana;
    grana = proceso_abastecer();
    if (tipo == 0){
        usuarios_private[local].set_credito(usuarios_private[local].get_credito() + grana);
        usuarios_private[local].atualizar_historico("Realizou um deposito");
   }else{
        usuarios[local].set_credito(usuarios_private[local].get_credito() + grana);
        usuarios[local].atualizar_historico("Realizou um deposito");
    }
    Qtd_dinheiro += grana;
    salvar();
    ler();
}

//Verifica se as notas depositadas são válidas
bool Caixa::existe(int dinheiros)const{
    if ( dinheiros == 100 || dinheiros == 50 || dinheiros == 20 || dinheiros == 10 || dinheiros == 5 || dinheiros == 2 )
        return true;
    cout << "Não existe uma nota com esse valor , por favor tente novamente :) " << endl;
    system("pause");
    return false;
}

//Aqui realizamos o processo geral de abastecer o caixa que pode ser tanto o deposito quanto o abastecer
int Caixa::proceso_abastecer(void){
    system("cls");
    string montante_temp,valor_temp,quantidade_temp;
    int montante,acumulado,valor,quantidade,ciclo;
    bool invalido,termino;
    do{
        system("cls");
        cout << "Insira a quantia que deseja abastecer " <<endl
             << "Valor bruto :";
        cin  >> montante_temp;
        montante = erro(montante_temp);
    }while(montante == -1);
    acumulado = 0;
    vector<pair<int,int> >notas_auxiliar;
    do{
       system("cls");
       ciclo = 0;
       do{
           do{
               cout << "Insira a nota que deseja depositar :";
               cin  >> valor_temp;
               valor = erro(valor_temp);
               cout << valor << "antes"<<endl;
           }while(valor == -1);
           cout << valor << "depois"<<endl;
        }while(!existe(valor));
       do{
           system("cls");
           cout << "Insira quantas dessa nota deseja inserir :";
           cin  >> quantidade_temp;
           quantidade = erro(quantidade_temp);
       }while(quantidade == -1);
       ciclo = valor*quantidade;
       (ciclo + acumulado > montante) ? invalido = true : invalido = false;
       if(invalido){
        cout << "Os valores inseridos n�o condizem com a quantia que deseja abastecer" << endl
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

//Aqui recebemos o valor da remoção do dinheiro do caixa pelo gerente
int Caixa::proceso_remocao(void){
    string montante_temp;
    int montante;
    do{
        cout << "Insira a quantia que deseja saquar " <<endl
             << "Valor bruto :";
        cin  >> montante_temp;
        montante = erro(montante_temp);
    }while(montante == -1);
    return montante;
}

//Aqui recebemos o valor do saque do dinheiro da conta do usuário
void Caixa::ordenar(void){
    sort(notas.begin(),notas.end());
    vector<pair<int,int> >notas_auxiliar;
    for(int indice = notas.size() ; indice > 0 ; indice--)
        notas_auxiliar.push_back(notas[indice - 1]);
    notas.swap(notas_auxiliar);
}

//Aqui realizamos o processo geral de remoção de dinheiro do caixa que pode ser tanto o deposito quanto o abastecer
void Caixa::proceso_aritmetrico_remocao(int grana){
    int quociente = 0, montante = 0,valor_nota,opcao;
    contabilizar();
    vector<vector<int> >Conjuntos_solucoes;
    ordenar();
    for(int indice = 0 ; indice < notas.size() ; indice ++){
        vector<int>Conjunto_solucao;
        montante = grana;
        for( int indice2 = indice ; indice2 < notas.size() ; indice2 ++){
            //cout << montante << " / " << notas[indice2].first << " <= " << notas[indice2].second << endl;
            if( montante / notas[indice2].first > 0  && montante != 8 && montante != 6 && montante / notas[indice2].first <= notas[indice2].second){
                    quociente = montante / notas[indice2].first;
                    valor_nota = notas[indice2].first;
                    montante = montante % notas[indice2].first;
                    Conjunto_solucao.push_back(valor_nota);
                    Conjunto_solucao.push_back(quociente);
                    if (montante == 0 )
                        Conjuntos_solucoes.push_back(Conjunto_solucao);
            }else if( montante == 8 || montante == 6 && montante / notas[indice2].first <= notas[indice2].second){
                    for(int indice3 = 0 ; indice3 < notas.size() ; indice3 ++){
                        if(notas[indice3].first == 2)
                            indice2 = indice3;
                        }
                    quociente = montante / notas[indice2].first;
                    valor_nota = notas[indice2].first;
                    montante = montante % notas[indice2].first;
                    Conjunto_solucao.push_back(valor_nota);
                    Conjunto_solucao.push_back(quociente);
                        if (montante == 0 )
                        Conjuntos_solucoes.push_back(Conjunto_solucao);
                }
            }
        }
    if(Conjuntos_solucoes.size() > 0){
        for(int indice = 0 ; indice < Conjuntos_solucoes.size() ; indice++){
            cout<< "-Opção( " << indice << " )-" << endl;
            for(int indice2 = 0 ; indice2 < Conjuntos_solucoes[indice].size() ; indice2 += 2)
                cout << Conjuntos_solucoes[indice][indice2 + 1] << " notas de " << Conjuntos_solucoes[indice][indice2] << " Reais." << endl;
        }
        do{
            string opcao_temp;
            cout << "(Insira a opção que deseja) Como voc� prefere receber : " << grana <<endl;
            cin  >> opcao_temp;
            opcao = erro(opcao_temp);
        }while(opcao == -1);
        for (int indice = 0 ; indice < Conjuntos_solucoes[opcao].size() ; indice += 2 ){
            pair<int,int>p_auxiliar;
            p_auxiliar = make_pair ( Conjuntos_solucoes[opcao][indice] , -Conjuntos_solucoes[opcao][indice + 1]);
            notas.push_back(p_auxiliar);
            }
    }else
        cout << "Não foi possível fornecer o valor requisitado por conta da limitação das notas no caixa por favor tente outro valor :)" << endl;
    system("cls");
    contabilizar();
}

//Neste método organizamos o vetor de pair(Notas) de forma que cada indice seja uma nota
void Caixa::contabilizar(void){
    vector<pair<int,int> >notas_auxiliar;
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

//Aqui juntamos todos os métodos auxiliares de remoção e adptamos para a remoção do gerente
void Caixa::remover(void){
    int grana,quociente = 0, montante = 0,valor_nota,opcao;
    bool invalido;
    do{
        system("cls");
        grana = proceso_remocao();
        (Qtd_dinheiro - grana < 0) ? invalido = true : invalido = false;
        if(invalido)
            cout<< "O banco não possui esse valor : " << grana << " entretanto possui : "<<Qtd_dinheiro <<" R$"<< endl
                << "Por favor tente novamente :)"                                                              << endl;
        else
            proceso_aritmetrico_remocao(grana);
    }while(invalido);
        Qtd_dinheiro -= grana;
}

//Aqui juntamos todos os métodos auxiliares de remoção e adptamos para o saque do usuário
void Caixa::saque(void){
    int grana;
    bool invalido;
    do{
        system("cls");
        grana = proceso_remocao();
        cout << saldo << "|" << grana << "|" << saldo - grana <<endl;
        (saldo - grana < 0) ? invalido = true : invalido = false;
        if(invalido)
            cout<<"Crédito insuficiente, por favor tente novamente ou consulte o extrato da conta :)"<<endl;
        else
            proceso_aritmetrico_remocao(grana);
        system("pause");
    }while(invalido);
    if (tipo == 0)
        usuarios_private[local].set_credito(usuarios_private[local].get_credito() - grana);
    else
        usuarios[local].set_credito(usuarios_private[local].get_credito() - grana);
    Qtd_dinheiro -= grana;
    salvar();
    ler();
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
    if(tipo == 0){
        ofstream Usuario_private("Usuario_private.txt", ios::trunc);
        if(Usuario_private.is_open()){
            for(int indice = 0 ; indice < usuarios_private.size() ; indice++){
                Usuario_private << usuarios_private[indice].get_nome()         << ","
                                << usuarios_private[indice].get_senha()        << ","
                                << usuarios_private[indice].get_numero_conta() << ","
                                << usuarios_private[indice].get_debito()       << ","
                                << usuarios_private[indice].get_credito()      << endl;
            }
        }
        Usuario_private.close();
    }else{
        ofstream Usuario("Usuario.txt", ios::trunc);
        if(Usuario.is_open()){
            for(int indice = 0 ; indice < usuarios.size() ; indice++){
                Usuario << usuarios[indice].get_nome()         << ","
                        << usuarios[indice].get_senha()        << ","
                        << usuarios[indice].get_numero_conta() << ","
                        << usuarios[indice].get_debito()       << ","
                        << usuarios[indice].get_credito()      << endl;
            }
        }
        Usuario.close();
    }
}

Caixa::~Caixa(){
    contabilizar();
    salvar();
}
