#include <iostream>
#include <vector>
using namespace std;

// Classe base para um dispositivo IoT
class Dispositivo {
   private:
      int id;
   public:
      Dispositivo(int id) : id(id) {}
      int getId() {
         return id;
      }
};

// Classe para um sensor de temperatura
class SensorTemperatura : public Dispositivo {
   private:
      float temperatura;
   public:
      SensorTemperatura(int id) : Dispositivo(id) {}
      float getTemperatura() {
         return temperatura;
      }
      void lerTemperatura() {
         // Lê a temperatura de um sensor externo
         temperatura = 25.0;
      }
};

// Classe para um atuador de lâmpada
class AtuadorLampada : public Dispositivo {
   private:
      bool ligado;
   public:
      AtuadorLampada(int id) : Dispositivo(id) {}
      void ligar() {
         ligado = true;
         // Liga a lâmpada em um dispositivo externo
      }
      void desligar() {
         ligado = false;
         // Desliga a lâmpada em um dispositivo externo
      }
};

// Classe para uma sala com vários dispositivos
class Sala {
   private:
      vector<SensorTemperatura*> sensores;
      AtuadorLampada* lampada;
   public:
      Sala(AtuadorLampada* lampada) : lampada(lampada) {}
      void adicionarSensor(SensorTemperatura* sensor) {
         sensores.push_back(sensor);
      }
      void atualizarTemperatura() {
         float temperaturaMedia = 0.0;
         for (auto sensor : sensores) {
            sensor->lerTemperatura();
            temperaturaMedia += sensor->getTemperatura();
         }
         temperaturaMedia /= sensores.size();
         if (temperaturaMedia > 25.0) {
            lampada->ligar();
         } else {
            lampada->desligar();
         }
      }
};

int main() {
   AtuadorLampada* lampada = new AtuadorLampada(1);
   SensorTemperatura* sensor1 = new SensorTemperatura(2);
   SensorTemperatura* sensor2 = new SensorTemperatura(3);

   Sala sala(lampada);
   sala.adicionarSensor(sensor1);
   sala.adicionarSensor(sensor2);

   sala.atualizarTemperatura();

   delete lampada;
   delete sensor1;
   delete sensor2;

   return 0;
}
