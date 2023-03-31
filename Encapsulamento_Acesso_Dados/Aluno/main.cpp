#include <iostream>
using namespace std;

class Aluno {
   private:
      string nome;
      int idade;
      float media;
   public:
      Aluno(string n, int i) {
         nome = n;
         idade = i;
         media = 0;
      }
      void setNome(string n) {
         nome = n;
      }
      string getNome() {
         return nome;
      }
      void setIdade(int i) {
         idade = i;
      }
      int getIdade() {
         return idade;
      }
      void setMedia(float m) {
         media = m;
      }
      float getMedia() {
         return media;
      }
      void imprimirDados() {
         cout << "Nome: " << nome << ", Idade: " << idade << ", Média: " << media << endl;
      }
};

int main() {
   Aluno aluno("João", 20);
   aluno.imprimirDados();

   aluno.setMedia(8.5);
   aluno.imprimirDados();

   return 0;
}
