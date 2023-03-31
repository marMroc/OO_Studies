#include <iostream>
using namespace std;

// Interface para um dispositivo
class Dispositivo {
   public:
      virtual void ligar() = 0;
      virtual void desligar() = 0;
};

// Classe abstrata para um dispositivo eletrônico
class DispositivoEletronico {
   public:
      DispositivoEletronico() {
         ligado = false;
      }
      void ligar() {
         ligado = true;
         cout << "Dispositivo eletrônico ligado" << endl;
      }
      void desligar() {
         ligado = false;
         cout << "Dispositivo eletrônico desligado" << endl;
      }
      bool estaLigado() {
         return ligado;
      }
   private:
      bool ligado;
};

// Classe para uma TV
class TV : public DispositivoEletronico, public Dispositivo {
   public:
      void mudarCanal(int canal) {
         if (estaLigado()) {
            cout << "Canal mudado para " << canal << endl;
         } else {
            cout << "A TV está desligada" << endl;
         }
      }
};

// Classe para um rádio
class Radio : public DispositivoEletronico, public Dispositivo {
   public:
      void sintonizar(float frequencia) {
         if (estaLigado()) {
            cout << "Rádio sintonizado em " << frequencia << " MHz" << endl;
         } else {
            cout << "O rádio está desligado" << endl;
         }
      }
};

int main() {
   Dispositivo* tv = new TV();
   Dispositivo* radio = new Radio();

   tv->ligar();
   static_cast<TV*>(tv)->mudarCanal(5);

   radio->ligar();
   static_cast<Radio*>(radio)->sintonizar(88.5);

   delete tv;
   delete radio;

   return 0;
}
