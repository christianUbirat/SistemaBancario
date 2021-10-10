#include "BolsaDeValores.h"

using namespace std;

BolsaDeValores::BolsaDeValores(){
    atualizar_ativos();
    atualizar_usuarios();
    att_ativos_usuarios();
}

void BolsaDeValores::atualizar_ativos(){
    acoes.clear();
    titulos.clear();

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

void BolsaDeValores::atualizar_usuarios(void){
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
    att_ativos_usuarios();
}

void BolsaDeValores::att_ativos_usuarios(){
    ifstream arquivo_usuarios("ativos_de_usuarios.txt");
    // Variaveis auxiliares
    string nome, ticker, qtd_, indice_, linha;
    int qtd, indice;

    if(arquivo_usuarios.is_open()){
        while (getline(arquivo_usuarios, linha)){
            stringstream ss(linha);

            bool stop = false;
            int cont = 0;
            while(!stop){
                if(cont == 0){
                    if(ss.eof()){
                        stop = true;
                        break;
                    }
                    getline(ss, indice_, ',');
                    indice = stoi(indice_);
                    //cout << "indice: " << indice << endl;
                    cont = 1;
                }
                if(cont == 1){
                    if(ss.eof()){
                        stop = true;
                    }
                    if(!stop){
                        getline(ss, ticker, ',');
                        //cout << "ticker: " << ticker << endl;
                        cont = 2;
                    }
                }
                if(cont == 2){
                    if(ss.eof()){
                        stop = true;
                    }
                    if(!stop){
                        getline(ss, qtd_, ',');
                        qtd = stoi(qtd_);
                        //cout << "qtd: " << qtd << endl;
                        usuarios_private[indice].set_acoes(acoes[encontrar_acao(ticker)], qtd);
                        //cout << usuarios_private[indice].get_acoes().first[0].getNome() << endl;
                        cont = 1;
                    }
                }
            }
        }
    }
    arquivo_usuarios.close();
}

void BolsaDeValores::salvar_usuarios(void){
    ofstream Usuario_private("Usuario_private.txt");
    if(Usuario_private.is_open()){
        for(int i = 0 ; i < usuarios_private.size() ; i++){
            Usuario_private << usuarios_private[i].get_nome()         << ",";
            Usuario_private << usuarios_private[i].get_senha()        << ",";
            Usuario_private << usuarios_private[i].get_numero_conta() << ",";
            Usuario_private << usuarios_private[i].get_debito()       << ",";
            Usuario_private << usuarios_private[i].get_credito()      << endl;
             }
    }
    Usuario_private.close();
    salvar_ativos_usr();
}

void BolsaDeValores::mostrarAcoes(){
    atualizar_ativos();
    cout << "Ações:" << endl;
    for(int i = 0; i<acoes.size(); i++){
        cout << acoes[i].getNome() << " (" << acoes[i].getTicker() << "): R$ " << fixed << setprecision(2) <<
        acoes[i].getPreco() << "/ Risco: " << acoes[i].getRisco() << endl;
    }
}
void BolsaDeValores::mostrarTitulos(){
    atualizar_ativos();
    cout << "Títulos:" << endl;
    for(int i = 0; i<titulos.size(); i++){
        cout << titulos[i].getNome() << " (" << titulos[i].getTicker() << "): R$ " << fixed << setprecision(2) <<
        titulos[i].getPreco() << "/ Prazo: " << titulos[i].getPrazo() << " dias" << endl;
    }
}
void BolsaDeValores::mostrarAtivos(){
    atualizar_ativos();
    system("clear");
    cout << "############################################" << endl;
    cout << "Ativos da Bolsa de Valores do Optimum Bank" << endl;
    cout << "############################################" << endl;
    mostrarAcoes();
    cout << "-----------------------------------------------------" << endl;
    mostrarTitulos();
}

// Get's
vector<Acao> BolsaDeValores::getAcoes()const{
    return acoes;
}
vector<Titulo> BolsaDeValores::getTitulos()const{
    return titulos;
}

// Set's
void BolsaDeValores::setAcoes(vector<Acao> novasAcoes){
    for(int i=0; i<novasAcoes.size(); i++){
        acoes.push_back(novasAcoes[i]);
    }
    salvarAcoes();
}
void BolsaDeValores::setTitulos(vector<Titulo> novosTitulos){
    for(int i=0; i<novosTitulos.size(); i++){
        titulos.push_back(novosTitulos[i]);
    }
    salvarTitulos();
}

void BolsaDeValores::comprar_ativo(int indice){
    // Garantindo que o vetor de ações esteja atualizado
    atualizar_ativos();
    atualizar_usuarios();
    string escolha;
    do{
        cout << usuarios_private[indice].get_nome() << " o seu saldo é: " << usuarios_private[indice].get_credito() << endl
            << "----------------------------------------------------------------------" << endl
            << "(1) - Comprar ação." << endl
            << "(2) - Comprar título." << endl
            << "(3) - Verificar ativos disponíveis." << endl
            << "(4) - Verificar ativos comprados" << endl
            << "(5) - Sair da bolsa de valores." << endl
            << "Digite aqui: ";
        cin >> escolha;
        if(escolha == "1"){
            string ticker;
            int qtd;
            bool sucesso = false;

            system("clear");
            cout << "Digite o ticker da ação que você deseja comprar: ";
            cin >> ticker;
            cout << "Digite quantas ações você deseja comprar: ";
            cin >> qtd;
            for(int i=0; i<acoes.size(); i++){
                if(ticker == acoes[i].getTicker()){
                    if(usuarios_private[indice].get_credito() >= qtd * acoes[i].getPreco()){
                        usuarios_private[indice].set_acoes(acoes[i], qtd);
                        usuarios_private[indice].set_credito(usuarios_private[indice].get_credito() - acoes[i].getPreco()*qtd);
                        cout << "Preço da ação " << acoes[i].getNome() << ": " << acoes[i].getPreco() << endl;
                        cout << "Quantidade comprada: " << qtd << endl;
                        cout << "Custo total: " << qtd*acoes[i].getPreco() << endl;
                        cout << "Compra efetuada com sucesso!" << endl << endl;
                        sucesso = true;
                        salvar_usuarios();
                        atualizar_ativos();
                    }
                    else{
                        cout << "Saldo insuficiente..." << endl;
                    }
                }
            }
            if(sucesso == true){
                cout << "Lista de ações: " << endl;
                for(int i=0; i<usuarios_private[indice].get_acoes().first.size(); i++){
                    cout << "Nome: " << usuarios_private[indice].get_acoes().first[i].getNome() << "/ Quantidade: " << usuarios_private[indice].get_acoes().second[i] << endl;
                }
            }
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
            system("clear");
        }
        else if(escolha == "2"){
            string ticker;
            int qtd;
            bool sucesso = false;

            system("clear");
            cout << "Digite o ticker do título que você deseja comprar: ";
            cin >> ticker;
            cout << "Digite quantos títulos você deseja comprar: ";
            cin >> qtd;

            for(int i=0; i<titulos.size(); i++){
                if(ticker == titulos[i].getTicker()){
                    if(usuarios_private[indice].get_credito() >= qtd * titulos[i].getPreco()){
                        usuarios_private[indice].set_titulo(titulos[i], qtd);
                        usuarios_private[indice].set_credito(usuarios_private[indice].get_credito() - titulos[i].getPreco()*qtd);
                        cout << "Preço da ação " << titulos[i].getNome() << ": " << titulos[i].getPreco() << endl;
                        cout << "Quantidade comprada: " << qtd << endl;
                        cout << "Custo total: " << qtd*titulos[i].getPreco() << endl;
                        cout << "Compra efetuada com sucesso!" << endl << endl;
                        sucesso = true;
                        salvar_usuarios();
                        atualizar_ativos();
                    }
                    else{
                        cout << "Saldo insuficiente..." << endl;
                    }
                }
            }
            if(sucesso == true){
                cout << "Lista de títulos: " << endl;
                for(int i=0; i<usuarios_private[indice].get_titulos().first.size(); i++){
                    cout << "Nome: " << usuarios_private[indice].get_titulos().first[i].getNome() << "/ Quantidade: " << usuarios_private[indice].get_titulos().second[i] << endl;
                }
            }
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
            system("clear");
            
        }
        else if(escolha == "3"){
            mostrarAtivos();
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
            system("clear");
        }
        else if(escolha == "4"){
            cout << "Lista de ativos comprados: " << endl  
                 << "-----------------------------------" << endl
                 << "Lista de ações: " << endl;
                for(int i=0; i<usuarios_private[indice].get_acoes().first.size(); i++){
                    cout << "Nome: " << usuarios_private[indice].get_acoes().first[i].getNome() << "/ Quantidade: " << usuarios_private[indice].get_acoes().second[i] << endl;
                }
                cout << "Lista de títulos: " << endl;
                for(int i=0; i<usuarios_private[indice].get_titulos().first.size(); i++){
                    cout << "Nome: " << usuarios_private[indice].get_titulos().first[i].getNome() << "/ Quantidade: " << usuarios_private[indice].get_titulos().second[i] << endl;
                }
                cout << "Pressione qualquer tecla para continuar";
                cin.get();
                cin.get();
                system("clear");
        }
        else{
            system("clear");
            cout << "Opção inválida..." << endl << endl;
        }
    }
    while(escolha != "5");
    
}

int BolsaDeValores::encontrar_acao(string ticker){
    for(int i=0; i<acoes.size(); i++){
        if(ticker == acoes[i].getTicker()){
            return i;
        }
    }
    return -1;

}

int BolsaDeValores::encontrar_titulo(string ticker){
    for(int i=0; i<titulos.size(); i++){
        if(ticker == titulos[i].getTicker()){
            return i;
        }
    }
    return -1;
}

// Salvar titulos e acoes nos arquivos
void BolsaDeValores::salvarTitulos(){
     // Salvando dados dos titulos
    ofstream arquivo_titulos("titulos.txt");
    if(arquivo_titulos.is_open()){
        //cout << "Abrindo arquivo..." << endl;
        for(int i=0; i<titulos.size(); i++){
            arquivo_titulos << titulos[i].getNome() << ",";
            arquivo_titulos << titulos[i].getTicker() << ",";
            arquivo_titulos << titulos[i].getPreco() << ",";
            arquivo_titulos << titulos[i].getPrazo() << endl;
        }
    }
    arquivo_titulos.close();
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

void BolsaDeValores::salvar_ativos_usr(){
    ofstream arquivo_usuarios("ativos_de_usuarios.txt");
    if(arquivo_usuarios.is_open()){
        for(int i=0; i<usuarios_private.size(); i++){
            arquivo_usuarios << i;
            if(!usuarios_private[i].get_acoes().first.empty()){
                for(int j=0; j<usuarios_private[i].get_acoes().first.size();j++){
                    arquivo_usuarios << "," << usuarios_private[i].get_acoes().first[j].getTicker()
                                    << "," << usuarios_private[i].get_acoes().second[j];
                    if(j == usuarios_private[i].get_acoes().first.size()-1){
                        arquivo_usuarios << endl;
                    }
                }
            }
            else{
                arquivo_usuarios << endl;
            }
        }
    }
    arquivo_usuarios.close();
}

// Destrutor
BolsaDeValores::~BolsaDeValores(){
    //salvarAcoes();
    //salvarTitulos();
    //cout << "Dados salvos!" << endl;
}
