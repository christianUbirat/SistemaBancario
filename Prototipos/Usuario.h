#ifndef USUARIO_H
#define USUARIO_H

class Usuario:public Usuario{
private :
	string nome, senha;
	int numero_conta;
	double debito,credito;
	bool privilegio;
	vector<string>historico;
public :
	// Construtor
    Usuario(string = "", string = "", int = 0, double = 0.0, double 0.0, boll = false);

    // Metodos Set
    void set_nome(string);
    void set_senha(string);
    void set_numero_conta(int);
    void set_debito(double);
    void set_credito(double);
    void set_privilegio(bool)

    // Metodos Get
    string get_nome(void)const;
    string get_senha(void)const;
    int get_numero_conta(void)const;
    double get_debito(void)const;
    double get_credito(void)const;
    bool get_privilegio(void)const;

    // Funcionalidades da conta
    void mostrar_estrato(void)const;
    void depositar(double);
    void sacar(double);
    void atualizar_historico(int)const;

    // Destrutor
    ~Usuario(void);
};

#endif
