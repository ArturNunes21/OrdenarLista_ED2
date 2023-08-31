#ifndef LINHA_H_DEFINED
#define LINHA_H_DEFINED

#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Linha
{
public:
    int numero;
    string palavra;
    Linha () {}
    Linha(string numero, string palavra)
    {
        this->numero = stoi(numero);
        this->palavra = palavra;
    }

friend std::ostream& operator<<(std::ostream& os, const Linha& linha)
{
    //Transforma variável int em string
    os << linha.numero << "." << linha.palavra;
    return os;
}
};

#endif