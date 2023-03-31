#include <iostream>
using namespace std;

class Veiculo {
   public:
      virtual void acelerar() {
         cout << "Veículo acelerando..." << endl;
      }
};

class Carro : public Veiculo {
   public:
      void acelerar() {
         cout << "Carro acelerando..." << endl;
      }
};

class Moto : public Veiculo {
   public:
      void acelerar() {
         cout << "Moto acelerando..." << endl;
      }
};

int main() {
   Veiculo* veiculo;
   Carro carro;
   Moto moto;

   veiculo = &carro;
   veiculo->acelerar();

   veiculo = &moto;
   veiculo->acelerar();

   return 0;
}
