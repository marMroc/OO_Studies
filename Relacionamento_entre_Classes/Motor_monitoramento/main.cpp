#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;


// Classe base para um componente do motor
class Componente {
   private:
      string nome;
   public:
      Componente(string nome) : nome(nome) {}
      string getNome() {
         return nome;
      }
};

// Classe para um motor de um trator
class Motor {
   private:
      vector<Componente*> componentes;
      bool ligado;
   public:
      Motor() : ligado(false) {}
      void adicionarComponente(Componente* componente) {
         componentes.push_back(componente);
      }
      void ligar() {
         ligado = true;
         // Ligar o motor do trator
      }
      void desligar() {
         ligado = false;
         // Desligar o motor do trator
      }
      bool getLigado() {
         return ligado;
      }
};

// Classe para um sensor de temperatura do motor
class SensorTemperatura : public Componente {
   private:
      float temperatura;
   public:
      SensorTemperatura(string nome) : Componente(nome) {}
      float getTemperatura() {
         return temperatura;
      }
      void lerTemperatura() {
   	 // Lê a temperatura de um sensor externo
    	temperatura = rand() % 100 + 1; // valor aleatório entre 1 e 100
      }
};

// Classe para um sensor de pressão do óleo do motor
class SensorPressaoOleo : public Componente {
   private:
      float pressao;
   public:
      SensorPressaoOleo(string nome) : Componente(nome) {}
      float getPressao() {
         return pressao;
      }
      void lerPressao() {
      // Lê a pressão do óleo de um sensor externo
         pressao = rand() % 100 + 1; // valor aleatório entre 1 e 100
    }
};

// Classe para um sistema de monitoramento do motor
class MonitorMotor {
   private:
      Motor* motor;
      vector<SensorTemperatura*> sensoresTemperatura;
      vector<SensorPressaoOleo*> sensoresPressaoOleo;
   public:
      MonitorMotor(Motor* motor) : motor(motor) {}
      void adicionarSensorTemperatura(SensorTemperatura* sensor) {
         sensoresTemperatura.push_back(sensor);
      }
      void adicionarSensorPressaoOleo(SensorPressaoOleo* sensor) {
         sensoresPressaoOleo.push_back(sensor);
      }
      void atualizarLeituras() {
         for (auto sensor : sensoresTemperatura) {
            sensor->lerTemperatura();
            cout << "Temperatura de " << sensor->getNome() << " = " << sensor->getTemperatura() << " C" << endl;
         }
         for (auto sensor : sensoresPressaoOleo) {
            sensor->lerPressao();
            cout << "Pressao de oleo de " << sensor->getNome() << " = " << sensor->getPressao() << " PSI" << endl;
         }
         if (motor->getLigado()) {
            // Faz o processamento das leituras e verifica se é necessário tomar alguma ação
            // ...
         }
      }
};

int main() {
   Motor motor;
   SensorTemperatura* sensor1 = new SensorTemperatura("Cabeçote");
   SensorTemperatura* sensor2 = new SensorTemperatura("Bloco do motor");
   SensorPressaoOleo* sensor3 = new SensorPressaoOleo("Óleo do motor");
   SensorPressaoOleo* sensor4 = new SensorPressaoOleo("Óleo da transmissão");

   motor.adicionarComponente(sensor1);
   motor.adicionarComponente(sensor2);
   motor.adicionarComponente(sensor3);
   motor.adicionarComponente(sensor4);

   MonitorMotor monitor(&motor);

   monitor.adicionarSensorTemperatura(sensor1);
   monitor.adicionarSensorTemperatura(sensor2);
   monitor.adicionarSensorPressaoOleo(sensor3);
   monitor.adicionarSensorPressaoOleo(sensor4);

   motor.ligar();
   monitor.atualizarLeituras();

   motor.desligar();
   monitor.atualizarLeituras();

   delete sensor1;
   delete sensor2;
   delete sensor3;
   delete sensor4;

   return 0;
}



