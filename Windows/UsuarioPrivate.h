#ifndef USUARIOPRIVATE_H
#define USUARIOPRIVATE_H

#include <vector>
#include <string>

using namespace std;

#include "Usuario.cpp"
#include "Acao.cpp"
#include "RendaFixa.cpp"

// Moeda será outra classe derivada de ativo
struct Moeda{
    string nome;
    string ticker;
    float conversao;
};

class UsuarioPrivate:public Usuario{
private :
    pair<vector<Acao>, vector<int> > acoes_compradas;
    pair<vector<Titulo>, vector<int> > titulos_comprados;
    pair<vector<Moeda>, int> outras_moedas_compradas;
public :
	// Construtor
    UsuarioPrivate(string = "",string = "", int = 0, int = 0, int = 0);

    // Get
    pair<vector<Acao>, vector<int> > get_acoes();
    pair<vector<Titulo>, vector<int> > get_titulos();

    // Set
    void set_acoes(Acao, int);
    void set_titulo(Titulo, int);
    void set_qtd_acoes(string, int);
    void set_qtd_titulo(string, int);

    Moeda converter_moeda(Moeda);
    void mostrar_investimentos()const;

    // Destrutor
    ~UsuarioPrivate(void);
};

#endif
