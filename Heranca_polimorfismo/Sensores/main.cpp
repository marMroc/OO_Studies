#include <iostream>
#include <string>
using namespace std;

// Classe base para todos os sensores
class Sensor {
   public:
      Sensor(string nome) {
         this->nome = nome;
      }
      virtual float ler() = 0;
      virtual string getTipo() = 0;
   protected:
      string nome;
};

// Classe derivada para sensores de temperatura
class SensorTemperatura : public Sensor {
   public:
      SensorTemperatura(string nome) : Sensor(nome) {}
      float ler() {
         // Lê a temperatura do sensor de temperatura
         return 25.5;
      }
      string getTipo() {
         return "Temperatura";
      }
};

// Classe derivada para sensores de umidade
class SensorUmidade : public Sensor {
   public:
      SensorUmidade(string nome) : Sensor(nome) {}
      float ler() {
         // Lê a umidade do sensor de umidade
         return 60.2;
      }
      string getTipo() {
         return "Umidade";
      }
};

int main() {
   Sensor* sensor1 = new SensorTemperatura("Sensor de temperatura 1");
   Sensor* sensor2 = new SensorUmidade("Sensor de umidade 1");

   cout << sensor1->nome << ": " << sensor1->ler() << " graus Celsius" << endl;
   cout << sensor2->nome << ": " << sensor2->ler() << "%" << endl;

   delete sensor1;
   delete sensor2;

   return 0;
}
