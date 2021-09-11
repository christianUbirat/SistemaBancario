#ifndef USUARIOPRIVATE_H
#define USUARIOPRIVATE_H

#include "Usuario.h"
#include "Acao.h"
#include "RendaFixa.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// Moeda será outra classe derivada de ativo
struct Moeda{
    string nome;
    string ticker;
    float conversao;
};

class UsuarioPrivate:public Usuario{
private :
    pair<vector<Acao>, vector<int> > acoes_compradas;
    pair<vector<Titulo>, int> titulos_comprados;
    pair<vector<Moeda>, int> outras_moedas_compradas;
public :
	// Construtor
    UsuarioPrivate(string = "",string = "", int = 0, float = 0.0, float = 0.0);

    // Funcionalidades do usuario private
    void comprar_acao(string, int);
    void comprar_titulo(string, int);
    void comprar_moeda(string, int);

    Moeda converter_moeda(Moeda);
    void mostrar_investimentos()const;

    // Destrutor
    ~UsuarioPrivate(void);
};

#endif