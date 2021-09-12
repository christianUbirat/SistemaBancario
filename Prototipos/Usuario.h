#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
private :
	string nome, senha;
	int numero_conta;
	double debito,credito;
	vector<string>historico;
public :
	// Construtor
    Usuario(string = "",string = "", int = 0, double = 0.0, double = 0.0);

    // Metodos Set
    void set_nome(string);
    void set_senha(string);
    void set_numero_conta(int);
    void set_debito(double);
    void set_credito(double);
    void set_privilegio(bool);

    // Metodos Get
    string get_nome(void)const;
    string get_senha(void)const;
    int get_numero_conta(void)const;
    double get_debito(void)const;
    double get_credito(void)const;

    // Funcionalidades da conta
    void mostrar_estrato(void)const;
    void atualizar_historico(string);

    // Destrutor
    ~Usuario(void);
};

#endif