#include <iostream>
using namespace std;

class Pessoa {
   private:
      string nome;
      int idade;
   public:
      Pessoa(string n, int i) {
         nome = n;
         idade = i;
      }
      void imprimir() {
         cout << "Nome: " << nome << ", Idade: " << idade << endl;
      }
};

int main() {
   Pessoa pessoa1("João", 30);
   pessoa1.imprimir();

   Pessoa pessoa2("Maria", 25);
   pessoa2.imprimir();

   return 0;
}
