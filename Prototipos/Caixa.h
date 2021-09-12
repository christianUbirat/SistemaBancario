#ifndef CAIXA_H
#define CAIXA_H

class Caixa{
private :
    double Qtd_dinheiro;
    //Pair<valor da nota, Qtd de nota>
    vector<pair<int,int>>notas;
    int saldo;

public :
    // Construtor(False padr�o,True private)
    Caixa(int);
    // Funcionalidades do caixa
    // Fun��o da adimistra��o
    void gerenciar(void);
    void abastecer(void);
    void remover(void);
    //Processos
    int proceso_abastecer(void);
    int proceso_remocao(void);
    // Fun��o do's usu�rios
    int deposito(void);
    int saque(void);
    void contabilizar(void);

    // Destrutor
    void salvar(void);
    ~Caixa();
};

#endif