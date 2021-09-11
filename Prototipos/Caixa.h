#ifndef CAIXA_H
#define CAIXA_H

class Caixa{
private :
    double Qtd_dinheiro;
    //Pair<valor da nota, Qtd de nota>
    vector<pair<int,int>>notas;
    int saldo;

public :
    // Construtor(False padrão,True private)
    Caixa(int);
    // Funcionalidades do caixa
    // Função da adimistração
    void gerenciar(void);
    void abastecer(void);
    void remover(void);
    //Processos
    int proceso_abastecer(void);
    int proceso_remocao(void);
    // Função do's usuários
    int deposito(void);
    int saque(void);
    void contabilizar(void);

    // Destrutor
    void salvar(void);
    ~Caixa();
};

#endif