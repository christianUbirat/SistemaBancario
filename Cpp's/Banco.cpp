#include "Banco.h"

// Construtor
Banco::Banco(){
    login_adm = 1;
    set_senha_administrador("a");
    atualizar();
}

// Set
void Banco::set_senha_administrador(string senha_adm){
    this->senha_adm = senha_adm;
}

// Get's
string Banco::get_senha_administrador()const{
    return senha_adm;
}
Usuario Banco::get_usuario(int i){
    return usuarios[i];
}
UsuarioPrivate Banco::get_usuario_private(int i){
    return usuarios_private[i];
}

// Controle de erros
int Banco::erro(string tentativa){
    int conversao;
    try{
        conversao = stoi(tentativa);
    }catch(exception& e){
        cout << "Erro: " << e.what() << " , erro de conversão insira um inteiro . "<< endl;
        cout << "Pressione qualquer tecla para continuar";
        cin.get();
        cin.get();
        return -1;
    }
    return conversao;
}

// Salvar os usuários dos arquivos .txt nos vetores de usuários
void Banco::atualizar(void){ 
    //limpar os 2 vetores
    usuarios.clear();
    usuarios_private.clear();

    // Leitura de usuário private
    ifstream Usuario_private;
	string nome_p, senha_p, numero_conta_temp_p, debito_temp_p, credito_temp_p, linha;
	int numero_conta_p;
	double debito_p,credito_p;

    // Abrir arquivo de usuários private
    Usuario_private.open("Usuario_private.txt" , ios::in);
    if(Usuario_private.is_open()){
        // No arquivo, cada linha representa um usuário
        // Cada dado em uma linha está separado por uma vírgula
        // Enquanto houverem linhas, devemos salvar o usuário com os seus respectivos dados no vetor
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

            // Instanciando objeto UsuarioPrivate com os dados lidos
            UsuarioPrivate conta_auxiliar_p(nome_p, senha_p, numero_conta_p, debito_p, credito_p);
            // Salvando usario no vetor
            usuarios_private.push_back(conta_auxiliar_p);
        }
    }
    // Fechar arquivo de usuarios private
    Usuario_private.close();
    
    // Leitura de usário padrão
    ifstream Usuario_arq;
	string nome, senha, numero_conta_temp, debito_temp, credito_temp, linha2;
	int numero_conta;
	double debito,credito;
    Usuario_arq.open("Usuario.txt" , ios::in);
    if(Usuario_arq.is_open()){
        // No arquivo, cada linha representa um usuário
        // Cada dado em uma linha está separado por uma vírgula
        // Enquanto houverem linhas, devemos salvar o usuário com os seus respectivos dados no vetor
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

            // Instanciando objeto Usuario com os dados lidos
            Usuario conta_auxiliar(nome, senha, numero_conta, debito, credito);
            // Salvando usuário no vetor
            usuarios.push_back(conta_auxiliar);
        }
    }
    Usuario_arq.close();
}

// Menu das funções da conta do usuário
void Banco::menu(){
    int opcao;
    string tentativa;
    do{
        if(tipo == 0){
            cout << "Bem vindo Usuário : " << usuarios_private[local].get_nome() << endl;
        }
        else{
            cout << "Bem vindo Usuário : " << usuarios[local].get_nome() << endl;
        }
        cout  << ":--------: Menu :--------:" << endl
              << "O que deseja fazer ?      " << endl
              << "(1)- Transferir.          " << endl
              << "(2)- Extrato.             " << endl
              << "(3)- Voltar para o início." << endl;
        cin >> tentativa;
        opcao = erro(tentativa);
        if(opcao != -1 && opcao != 1 && opcao != 2 && opcao != 3){
            cout << "Comando inválido, por favor tente novamente :)" <<endl;
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
        }
        else if(opcao == 1){
            validacao_transferir();
        }
        else if(opcao == 2){
            historico();
        }
        else{
            system("clear");
        }
    }while(opcao != 3);
}

// Login
// Verifica se o usuário digitou o número da conta e a senha corretamente
// Caso sim, retorna o tipo do usuário (1 para padrão e 0 para private)
// e a sua posição no seu respectivo vetor de usuários
pair <int, int> Banco::login(){
    bool ok = false;
    int conta;
    string senha;
    pair <int, int> dados;
    do{
        cout << "--------       LOGIN       --------" << endl
             << "Número da conta: ";
        cin >> conta;
        cout << "Senha: ";
        cin >> senha;
        // Verificando se os dados digitados estão no vetor de usuários padrão
        for (int indice = 0 ; indice < usuarios.size(); indice++){
            if (conta == usuarios[indice].get_numero_conta()){
                // Verificando se a senha digitada está correta
                if(senha == usuarios[indice].get_senha()){
                    local = indice;
                    tipo = 1;
                    dados.first = tipo;
                    dados.second = local;
                    //system("cls");
                    system("clear");
                    ok = true;
                    // Caso tudo esteja válido, o seu tipo e posição são retornados
                    return dados;
                }
            }
        }
        // Verificando se os dados digitados estão no vetor de usuários private
        for (int indice = 0 ; indice < usuarios_private.size(); indice++){
            if (conta == usuarios_private[indice].get_numero_conta()){
                // Verificando se a senha digitada está correta
                if(senha == usuarios_private[indice].get_senha()){
                    local = indice;
                    tipo = 0;
                    dados.first = tipo;
                    dados.second = local;
                    //system("cls");
                    system("clear");
                    ok = true;
                    // Caso tudo esteja válido, o seu tipo e posição são retornados
                    return dados;
                }
            }
        }

        // Verificando se os dados digitados foram de administrador
        if(conta == login_adm && senha == senha_adm){
            pair < int , int > gerente (0, -1);
            // Caso sim, retorna o pair padrão de adm (0 ,-1)
            return gerente;
        }

        // Caso os dados digitados estejam errados, ou o usuário não exista
        // Retorna-se o pair padrão de dados inválidos (1, -2)
        //system("cls");
        system("clear");
        return pair < int, int> (-1, -2);
    }while(!ok);
}

// Método para gerar número da conta
int Banco::gerar(){
    int num_conta;
    bool ok1 = false, ok2 = false;

    // Garantindo que a cada vez que o programa seja executado os números gerados sejam diferentes
    srand(time(NULL));
    do{
        // Criando número aleatório com o tamanho desejado
        num_conta = 100000 + rand() % 1000000;
        // cout << num_conta << endl;
        // Se houverem usuários private cadastrados
        if(!usuarios_private.empty()){
            // Se o número da conta ainda não pertencer a nenhum outro usuário
            // Basta saber agora se o número não pertence a nenhum usuário padrão
            (procurar_private(num_conta) == -1) ? ok1 = true : ok1 = false ;
        }
        // Caso não existam usuários private ainda, também não há problemas
        else{
            ok1 = true;
        }
        // Se houverem usuários padrão
        if(!usuarios.empty()){
            // Se o número da conta não pertencer a nenhum outro usuário padrão
            // Essa parte também está OK
            (procurar(num_conta) == -1) ? ok2 = true : ok2 = false ;
        }
        else{
            ok2 = true;
        }
    // Enquanto os dois ok'S não forem satisfeitos, buscar outro número 
    }while(!ok1 && !ok2);
    
    // Retornar número gerado
    return num_conta;
}

// Método para cadastrar usuários
void Banco::cadastro(){
    string privilegio;
    //system("cls");
    system("clear");
    do{
        cout<< "O patrimônio que você pretende guardar no Optimum Bank:" << endl
            << "(1) - > R$ 1.000.000 (mais que 1 milhão de reais)" << endl
            << "(2) - < R$ 1.000.000 (menos que 1 milhão de reais)" << endl
            << "Digite aqui: ";
        cin >> privilegio;
        // Cadastro de usuário private
        if(privilegio == "1"){
            cadastro_private();
        }
        // Cadastro de usuário padrão
        else if(privilegio == "2"){
            cadastro_comum();
        }
        else{
            //system("cls");
            system("clear");
            cout << "Opção inválida, tente novamente..." << endl << endl;
        }
    }
    while(privilegio != "1" && privilegio != "2");
}

// Cadastro de usuário private
void Banco::cadastro_private(){
    int num_conta;
    double credito = 0;
    string senha_aux,nome_aux, tipo_aux,credito_temp;

    cout << ":------: Cadastro de Usuário Private :------:" << endl
         << "Nome: ";
    cin.ignore();
    getline(cin, nome_aux);
    num_conta = gerar();
    cout << "O número da sua conta é (anote-o!): " << num_conta << endl
         << "Insira uma senha: ";
    cin >> senha_aux;

    // Garantindo que o valor mínimo de R$1mi seja satisfeito
    while(credito < 1000000){
        do{
            cout << "Insira o valor do seu depósito inicial (mínimo de 1.000.000): ";
            cin >> credito_temp;
            credito = erro(credito_temp);
            system("clear");
        }while(credito == -1);
        if(credito < 1000000){
            cout << "Valor insuficiente, para criar uma conta private você deve depositar ao menos R$1.000.000" << endl;
        }
    }

    // Instanciando objeto Usuario private
    UsuarioPrivate Usuario_aux(nome_aux,senha_aux,num_conta,0.0,credito);
    // Adicioanando usuário no vetor de usuarios private
    usuarios_private.push_back(Usuario_aux);
    // Salvando novo vetor de usuários no arquivo
    salvar();

    //system("cls");
    system("clear");
    cout << "Usuário Private cadastrado com sucesso!" << endl << endl;
}

// Cadastro de usuário comum
void Banco::cadastro_comum(){
    int num_conta;
    double credito = 0;
    string senha_aux,nome_aux, tipo_aux, credito_temp;

    cout << ":------: Cadastro de Usuário :------:" << endl
         << "Nome: ";
    cin.ignore();
    getline(cin, nome_aux);
    num_conta = gerar();
    cout << "O número da sua conta : " << num_conta << endl
         << "Insira uma senha: ";
    cin >> senha_aux;

    // Garantindo que o valor inicial da conta seja válido
    do{
        cout << "Insira o valor do seu depósito inicial: ";
        cin >> credito_temp;
        credito = erro(credito_temp);
        //system("cls");
        system("clear");
    }while(credito == -1 && credito >= 0);

    // Instanciando objeto Usuario
    Usuario Usuario_aux(nome_aux,senha_aux,num_conta,0.0,credito);
    // Adicioanando usuário no vetor de usuarios 
    usuarios.push_back(Usuario_aux);
    // Salvando novo vetor de usuários no arquivo
    salvar();

    //system("cls");
    system("clear");
    cout << "Usuário cadastrado com sucesso!" << endl << endl;
}

void Banco::validacao_transferir(){
    string conta_temp,qtd_temp;
    int conta2,local2;
    bool tipo2 = false ,valido = true;
    float qtd;
    do{
        do{
            cout << ":------: Transferência :------:" << endl
                 << "Insira o número da conta que vai receber :";
            cin  >> conta_temp;
            conta2 = erro(conta_temp);
            //system("cls");
            system("clear");
        }while(conta2 == -1);
        if ( procurar_private(conta2) != -1 && procurar_private(conta2) != -2){
            local2 = procurar_private(conta2);
            tipo2 = true;
        }else{
            ( procurar(conta2) == -1 && procurar(conta2) == -2) ? valido = false : valido = true;
            local2 = procurar(conta2);
            tipo2 = false;
        }
        if(!valido){
            cout << "Conta inválida, por favor tente novamente." << endl;
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
            system("clear");
        }
        //system("cls");
        system("clear");
    }while(!valido);
    valido = true;
    do{
        do{
            cout << "Insira a quantidade de dinheiro :";
            cin >> qtd_temp;
            qtd = erro(qtd_temp);
            //system("cls");
            system("clear");
        }while(qtd == -1);
        if( tipo == 0 )
            ( qtd >  usuarios_private[local].get_credito() ) ? valido = false : valido = true;
        else if ( tipo == 1 )
            ( qtd >  usuarios[local].get_credito() ) ? valido = false : valido = true;
        if(!valido){
            cout << "Quantidade de dinheiro insuficiente, por favor tente novamente." << endl;
            cout << "Pressione qualquer tecla para continuar";
            cin.get();
            cin.get();
            system("clear");
        }
        //system("cls");
        system("clear");
    }while(!valido);
    transferir(local2,tipo2,qtd);
    salvar();
    atualizar();
    cout << "Transferência realizada com sucesso !" << endl;
}

void Banco::transferir( int local2, bool tipo2, float qtd ){
    if( tipo == 0 ){
        usuarios_private[local].set_credito(usuarios_private[local].get_credito() - qtd);
        usuarios_private[local].atualizar_historico(" realizou uma transferência ");
    }else{
        usuarios[local].set_credito(usuarios[local].get_credito() - qtd);
        usuarios[local].atualizar_historico(" realizou uma transferência ");
    }
    if(tipo2){
        usuarios_private[local2].set_credito(usuarios_private[local2].get_credito() + qtd);
        usuarios_private[local2].atualizar_historico(" recebeu uma transferência ");
    }else{
        usuarios[local2].set_credito(usuarios[local2].get_credito() + qtd);
        usuarios[local2].atualizar_historico(" recebeu uma transferência ");
    }
}

// Buscar por um usuário private e retornar a sua posição no vetor
int Banco::procurar_private(int numero)const{
    for(int indice = 0 ; indice < usuarios_private.size() ; indice++){
        if(usuarios_private[indice].get_numero_conta() == numero)
            return indice;
    }
    return -1;
}

// Buscar por um usuário padrão e retornar a sua posição no vetor
int Banco::procurar(int numero)const{
    for(int indice = 0 ; indice < usuarios.size() ; indice++){
        if(usuarios[indice].get_numero_conta() == numero)
            return indice;
    }
    return -1;
}

void Banco::historico(void){
    atualizar();
    //system("cls");
    system("clear");
    if(tipo == 1)
        usuarios[local].mostrar_estrato();
    else
        usuarios_private[local].mostrar_estrato();
    cout << "Pressione qualquer tecla para continuar";
    cin.get();
    cin.get();
    //system("cls");
    system("clear");
}

// Método para salvar vetores de usuários nos arquivos
void Banco::salvar(void)const{
    // Abrir arquivo de usuários private
    ofstream Usuario_private("Usuario_private.txt", ios::trunc);
    if(Usuario_private.is_open()){
        // Em cada linha, salvar os dados de um usuários separados por vírgula
        for(int indice = 0 ; indice < usuarios_private.size() ; indice++){
            Usuario_private << usuarios_private[indice].get_nome()         << ","
                            << usuarios_private[indice].get_senha()        << ","
                            << usuarios_private[indice].get_numero_conta() << ","
                            << usuarios_private[indice].get_debito()       << ","
                            << usuarios_private[indice].get_credito()      << endl;
             }
    }
    // Fechar arquivo de usuarios private
    Usuario_private.close();

    // Abrir arquivo de usuarios padrão
    ofstream Usuario("Usuario.txt", ios::trunc);
    if(Usuario.is_open()){
        // Em cada linha, salvar os dados de um usuários separados por vírgula
        for(int indice = 0 ; indice < usuarios.size() ; indice++){
            Usuario << usuarios[indice].get_nome()         << ","
                    << usuarios[indice].get_senha()        << ","
                    << usuarios[indice].get_numero_conta() << ","
                    << usuarios[indice].get_debito()       << ","
                    << usuarios[indice].get_credito()      <<endl;
        }
    }
    // Fechar arquivo de usuarios padrao
    Usuario.close();
}

// Destrutor
Banco::~Banco(){
     // Garantir que os dados dos usuarios nos arquivos sejam salvos
     salvar();
}
