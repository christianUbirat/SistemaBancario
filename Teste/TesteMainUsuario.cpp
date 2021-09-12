#include <iostream>
#include <locale>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Usuario.cpp"

int main(){

    setlocale(LC_ALL, "Portuguese");

    string nome_aux        , senha_aux;
	int    numero_conta_aux;
	double debito_aux      ,credito_aux;

    cout<<"Nome"<<endl;
    cin>>nome_aux;
    cout<<"Senha"<<endl;
    cin>>senha_aux;
    cout<<"Depito"<<endl;
    cin>>debito_aux;
    cout<<"Credito"<<endl;
    cin>>credito_aux;
    cout<<"numero da conta"<<endl;
    cin>>numero_conta_aux;

    Usuario test( nome_aux , senha_aux , numero_conta_aux , debito_aux , credito_aux );
    test.mostrar_estrato();

    return 0;
}