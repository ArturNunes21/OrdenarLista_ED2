#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
#include "linha.h"

using namespace std;

void imprimrVetor(vector <Linha> vector)
{
    //This function will print the vector using the iterator
    std::vector<Linha>::iterator it;
    for(it = vector.begin(); it != vector.end(); it++)
    {
        cout << *it << endl;
    }
}

void quickSort(vector<Linha> &vector, int inicio, int fim, string comp) {
    int i, j;
    Linha aux;
    i = inicio;
    j = fim - 1;
    int vectorComparar = 0;
    if (comp == "Numero" || comp == "numero") {
        int pivo = vector[(inicio + fim) / 2].numero;
        while (i <= j) {
            while (vector[i].numero < pivo && i < fim) {
                i++;
            }
            while (vector[j].numero > pivo && j > inicio) {
                j--;
            }
            if (i <= j) {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                i++;
                j--;
            }
        }
    } else if (comp == "Palavra" || comp == "palavra") {
        string pivo = vector[(inicio + fim) / 2].palavra;
        while (i <= j) {
            while (vector[i].palavra < pivo && i < fim) {
                i++;
            }
            while (vector[j].palavra > pivo && j > inicio) {
                j--;
            }
            if (i <= j) {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                i++;
                j--;
            }
        }
    }
    if (j > inicio) {
        quickSort(vector, inicio, j + 1, comp);
    }
    if (i < fim) {
        quickSort(vector, i, fim, comp);
    }
}

void selectionSort(vector<Linha> &vector, string comp) {
    int i, j, min;
    Linha aux;
    for (i = 0; i < vector.size() - 1; i++) {
        min = i;
        for (j = i + 1; j < vector.size(); j++) {
            if (comp == "Numero" || comp == "numero") {
                if (vector[j].numero < vector[min].numero) {
                    min = j;
                }
            } else if (comp == "Palavra" || comp == "palavra") {
                if (vector[j].palavra < vector[min].palavra) {
                    min = j;
                }
            }
        }
        if (i != min) {
            aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
        }
    }
}



int main()
{
    std::ifstream arqRead;
    std::ofstream arqWrite;
    vector<Linha>vector2;
    vector<Linha>vector;
    
    std::string line, numero, palavra, opcao;
    line = numero, palavra, opcao = "";
    //bool encontrado=false;

    arqRead.open("lista.txt");
    if(arqRead.is_open()){
        while(std::getline(arqRead, line)){
            if(!line.empty()){
                //Armazena o numero, transforma em inteiro e atribui ao objeto
                long unsigned int i;
                for(i = 0; line[i] != '.'; i++)
                {
                    numero += line[i];
                }
                // int numeroInt = stoi(numero);
                // linha.numero = numeroInt;
                for(i++; i < line.size(); i++)
                {
                    palavra += line[i];
                }
                //linha.palavra = palavra;
                Linha linha(numero, palavra);

                 

                // encontrado=false;
                // for(int i=0;i<vector.size();i++){
                //     if(vector[i]==matricula){
                //         encontrado=true;
                //         break;
                //     }
                // }
                //if(numero!="" && palavra!="" && !encontrado){
            vector.push_back(linha); //adiciona objeto no vector
            numero="";
            palavra="";
            }
            }
        arqRead.close();
        //imprimirVetor(vector);
        //vector.clear();
    }else{
        std::cout<<"Nao foi possivel abrir o arquivo."<<std::endl;
        return 0;
    }

    //Copies te vector to another vector
    for(int i = 0; i < vector.size(); i++)
    {
        vector2.push_back(vector[i]);
    }
    double time_spend = 0.0;
    cout << "Digite 'Numero' ou 'Palavra' para ordenar o vetor." << endl;
    cin >> opcao;
    clock_t begin = clock();
    quickSort(vector, 0, vector.size(), opcao);
    clock_t end = clock();
    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // imprimrVetor(vector);
    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao do quickSort: " << time_spend << endl;
    clock_t begin2 = clock();
    selectionSort(vector2, opcao);
    clock_t end2 = clock();
    time_spend = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    cout << "Tempo de execucao do selectionSort: " << time_spend << endl;

    cout << "Vetor ordenado." << endl;

    //Write the vector in the new file
    arqWrite.open("listaOrdenada.txt");
    if(arqWrite.is_open())
    {
        for(int i = 0; i < vector.size(); i++)
        {
            arqWrite << vector[i].numero << "." << vector[i].palavra << std::endl;
        }
        arqWrite.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo." << endl;
        return 0;
    }

    cout << "Vetor ordenado gravado no arquivo 'listaOrdenada.txt'." << endl;

    return 0;
}

