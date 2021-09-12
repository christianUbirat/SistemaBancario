#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Caixa.cpp"

int main(){

    setlocale(LC_ALL, "Portuguese");

    Caixa cofre(1000);

    cofre.gerenciar();

    return 0;
}