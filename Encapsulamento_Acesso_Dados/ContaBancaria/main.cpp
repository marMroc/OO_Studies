#include <iostream>
using namespace std;

class ContaBancaria {
   private:
      int numeroConta;
      float saldo;
   public:
      void setNumeroConta(int n) {
         numeroConta = n;
      }
      int getNumeroConta() {
         return numeroConta;
      }
      void depositar(float valor) {
         saldo += valor;
      }
      void sacar(float valor) {
         if (saldo >= valor) {
            saldo -= valor;
         } else {
            cout << "Saldo insuficiente." << endl;
         }
      }
      float consultarSaldo() {
         return saldo;
      }
};

int main() {
   ContaBancaria conta;
   conta.setNumeroConta(123);
   conta.depositar(1000);
   cout << "Saldo atual: " << conta.consultarSaldo() << endl;
   conta.sacar(500);
   cout << "Saldo atual: " << conta.consultarSaldo() << endl;
   return 0;
}
