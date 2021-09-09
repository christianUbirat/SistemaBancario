#include "Banco.h"

//Construtor da classe Banco
Banco::Banco(void){ //Aqui o programa lê as contas salva no arquivo txt
    ifstream Usuario;
	string nome, senha;
	int numero_conta;
	bool privilegio;
	double debito,credito,investimentos,saldo_moeda_estrangeira;
    Usuario.open("Usuário.txt" , ios::in);
    if(Usuario.is_open()){
        while(!Usuario.eof()){
            getline(Usuario,nome);
            if(Usuario.eof())
                break;
            getline(Usuario,senha);
            Usuario>>numero_conta;
            Usuario>>privilegio;
            Usuario>>debito;
            Usuario>>credito;
            Usuario>>investimentos;
            Usuario>>saldo_moeda_estrangeira;
            UsuarioPrivate conta_auxiliar(nome, senha, numero_conta, debito, credito, privilegio, investimentos, saldo_moeda_estrangeira);
            contas.push_back(conta_auxiliar);
            Usuario.ignore();
        }
    }
    Usuario.close();
}

//Tela inicial -> Login do usuário
bool Banco::login(void){
    int num,local;
    string senha;
    cout << "################### Login ##################"<<endl
         << "Insira o número do cartão : ";
    cin  >> num;
    cout << "Insira sua senha : ";
    cin  >> senha;
    //local = Banco.verifica_usuario();
    if(local != -100){
        //Banco.menuInicial();
        return true;
    }
    else
        cout<<"Senha incorreta, por favor tente novamente :)"<<endl;
    return false;
}

//Destrutor da classe Banco
Banco::~Banco(void){
    ofstream Usuario("Usuário.txt", ios::trunc);
    if(Usuario.is_open()){
        for(int indice = 0 ; indice < contas.size() ; indice++){
            Usuario<<contas[indice].get_nome()<<endl
                    <<contas[indice].get_senha()<<endl
                    <<contas[indice].get_numero_conta()<<endl
                    <<contas[indice].get_privilegio()<<endl
                    <<contas[indice].get_debito()<<endl
                    <<contas[indice].get_investimentos()<<endl
                    <<contas[indice].get_saldo_moeda_estrangeira()<<endl;
        }
    }
}
