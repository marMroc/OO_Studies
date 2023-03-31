#include <iostream>
using namespace std;

class Retangulo {
   public:
      int largura;
      int altura;
      int area() {
         return largura * altura;
      }
};

int main() {
   Retangulo ret1;
   ret1.largura = 5;
   ret1.altura = 10;
   cout << "Área do retângulo: " << ret1.area() << endl;

   Retangulo ret2;
   ret2.largura = 8;
   ret2.altura = 12;
   cout << "Área do retângulo: " << ret2.area() << endl;

   return 0;
}
