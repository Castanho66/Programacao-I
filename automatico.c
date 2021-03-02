#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(){
  FILE *file;
  char linha[1];
  int size_tabuleiro;
  char ficheiro[50];
  int i;

  printf("Qual o nome do ficheiro que pretende abrir? Procure por Automatico.txt\n");
  scanf("%s", ficheiro);

  file = fopen(ficheiro, "r");

  if(file==NULL){
    printf ("O ficheiro 'Automatico.txt' nao foi encontrado.\n");
  }


  fclose(file);
}
