#ifndef USUARIOPRIVATE_H
#define USUARIOPRIVATE_H

class UsuarioPrivate:public Usuario{
private :
	double investimentos, saldo_moeda_estrangeira;
public :
	// Construtor
    UsuarioPrivate(string = "", string = "", int = 0, double = 0.0, double 0.0, boll = true, double = 0.0, double 0.0);
    
    // Metodos set
    void set_investimentos(double);
    void set_saldo_moeda_estrangeira(double);
    
    // Metodos get
    double get_investimentos(void)const;
    double get_saldo_moeda_estrangeira(void)const;

    // Funcionalidades do usuario private
    void investir(double, int);
    void retirar_envestimento(string, double);
    void converter_modera(double, string);

    // Destrutor
    ~UsuarioPrivate(void);
};

#endif
