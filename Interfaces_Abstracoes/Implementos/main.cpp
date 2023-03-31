#include <iostream>
#include <vector>
using namespace std;

// Interface para um implemento agrícola
class Implemento {
   public:
      virtual void operar() = 0;
};

// Classe abstrata para uma semeadora
class Semeadora : public Implemento {
   public:
      virtual void semear() = 0;
      void operar() {
         cout << "Semeadora operando..." << endl;
         semear();
      }
};

// Classe para uma semeadora de grãos
class SemeadoraGraos : public Semeadora {
   public:
      void semear() {
         cout << "Semeadura de grãos realizada!" << endl;
      }
};

// Classe abstrata para um pulverizador
class Pulverizador : public Implemento {
   public:
      virtual void pulverizar() = 0;
      void operar() {
         cout << "Pulverizador operando..." << endl;
         pulverizar();
      }
};

// Classe para um pulverizador de herbicidas
class PulverizadorHerbicida : public Pulverizador {
   public:
      void pulverizar() {
         cout << "Herbicida pulverizado!" << endl;
      }
};

int main() {
   vector<Implemento*> implementos;

   implementos.push_back(new SemeadoraGraos());
   implementos.push_back(new PulverizadorHerbicida());

   for (auto implemento : implementos) {
      implemento->operar();
   }

   for (auto implemento : implementos) {
      delete implemento;
   }

   return 0;
}
