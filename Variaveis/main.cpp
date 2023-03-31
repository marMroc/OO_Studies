#include <iostream>  // biblioteca comandos básicos de escrita

using namespace std; // onde estão as bibliotecas que vamos trabalhar 

int main()
{
    // TIPO NOME;
    // TIPO NOME = VALOR;
    
    int vidas = 0;
    char letra = 'b';
    double decimal=5.2;
    float deciaml = 5.2;
    bool vivo = true;
    string nome="bruno";
    
    cout << "digite o numero de vidas: ";
    cin >> vidas;
    cout << "digite uma letra:";
    cin >> letra;
    cout << "digite um decimal: ";
    cin >> decimal;
    cout << "digite outro decimal:";
    cin >> deciaml;
    cout << "digite 1 para vivo 0 pra morto: ";
    cin >> vivo;
    cout << "digite um nome:";
    cin >> nome;
    
    cout << vidas << "\n";
    cout << letra << "\n";
    cout << decimal << "\n";
    cout << deciaml << "\n";
    cout << vivo << "\n";
    cout << nome << "\n";
    
    

    return 0;
}