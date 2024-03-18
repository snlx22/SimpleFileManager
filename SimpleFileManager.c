#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


FILE*fp;
char arq[150];

void Pro(){

  printf("-- DIGITE O NOME DO ARQUIVO --\n\n:");
  
  scanf("%s", arq);

  fp = fopen(arq, "r");
  if(fp == NULL){
    sleep(1);
    printf("\n---------------------------\n");
    printf("-- ARQUIVO NAO ENCONTRADO --\n");
    printf("---------------------------\n\n");
    printf("-- SAINDO --");
    exit(0);
  }
  else{
    printf("-- ARQUIVO ENCONTRADO --\n\n");
    sleep(1);
    printf("-- O QUE DESEJA FAZER COM O ARQUIVO? --\n\n");
    printf("1 - LER\n\n2- ESCREVER NO ARQUIVO\n\n3 - REMOVER ARQUIVO\n\n");
    printf(": ");
    int op;
    scanf("%d", &op);
    sleep(1);
    
    switch(op){
      case 1:
        printf("-- LENDO ARQUIVO --\n\n");

        sleep(1);
        char ch;

        while((ch = fgetc(fp)) != EOF){
           printf("%c", ch);
        }
        sleep(1);
        printf("-- SAINDO --\n\n ");
        break;

      case 2:
        printf("-- ABRINDO ARQUIVO --\n\n");
        sleep(1);
        char txt[150];

        printf("-- DIGITE O TEXTO QUE DESEJA ADICIONAR --\n\n: ");
        scanf("%s", txt);

        fp = fopen(arq, "a");
        fprintf(fp, "%s", txt);

        fclose(fp);
        sleep(1);
        printf("-- ARQUIVO MODIFICADO!! --\n\n");
        break;

      case 3:
        printf("-- REMOVENDO ARQUIVO --\n\n");
        sleep(1);
        remove(arq);
        printf("-- ARQUIVO REMOVIDO COM SUCESSO!! --\n\n");
        break;
    }
  }
  
}

int main(){
  printf("---------------------------\n");
  printf("-- GERENCIADOR DE ARQUIVOS --\n");
  printf("---------------------------\n\n");

  Pro();
}

