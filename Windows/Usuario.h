#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
private :
	string nome, senha;
	int numero_conta,debito,credito;
	vector<string>historico;
public :
	// Construtor
    Usuario(string = "",string = "", int = 0, int = 0, int = 0);

    // Metodos Set
    void set_nome(string);
    void set_senha(string);
    void set_numero_conta(int);
    void set_debito(int);
    void set_credito(int);

    // Metodos Get
    string get_nome(void)const;
    string get_senha(void)const;
    int get_numero_conta(void)const;
    int get_debito(void)const;
    int get_credito(void)const;

    // Funcionalidades da conta
    void mostrar_estrato(void)const;
    void atualizar_historico(string);

    // Destrutor
    ~Usuario(void);
};

#endif
