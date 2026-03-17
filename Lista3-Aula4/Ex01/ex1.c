/*MANIPULAÇÃO DE PILHAS/STACK
EDL3-001
Com base nas informações abaixo, crie uma aplicação console que deverá implementar os conceitos de uma Pilha, 
para esta implementação (da pilha), utilize conceitos de vetores.
Livro {
  + codigo
  + titulo
  + preco }

PilhaLivros {
  + PilhaLivros(TamanhoPilha)
  + Empilhar(Livro liv)
  + Desempilhar()
  + Imprimir()}
****************************
MENU
1 - Empilhar
2 - Desempilhar
3 - Imprimir
99 - Sair
****************************
*/
#include <stdio.h>
#include <string.h>
#define TAM 5

struct Livro {
        int codigo;
        char titulo[50];
        float preco; 
};

struct  Livro pilha[TAM];
int topo = -1;


void empilhar(){
    if (topo == TAM -1){
    printf("Pilha cheia!\n");
    return;
    }
    
    topo++;
    
    printf("Digite o codigo:\n");
    scanf("%i", &pilha[topo].codigo);
    printf("Digite o titulo:\n");
    scanf("%s", pilha[topo].titulo);
    printf("Digite o preco:\n");
    scanf("%f", &pilha[topo].preco);
    
}
void desempilhar(){
    if (topo == -1){
        printf("Pilha vazia bro!\n");
    
    }else {
        topo--;
    }
}
void imprimir (struct  Livro pilha[]){
      if (topo == -1){
        printf("Pilha vazia bro!\n");
    }
    else {
        for (int i = topo; i >=0; i--){
            printf("Codigo:[%i] \nTitulo:[%s] \npreco[%.2f]\n--------------------\n", pilha[i].codigo, pilha[i].titulo, pilha[i].preco);

        }
    }
}

   

void menu(){
    int opc = 0;

    do {
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Imprimir\n");
        printf("9. Sair\n");
        printf("Digite:\n");
        scanf("%i", &opc);


        if (opc == 1){
            empilhar();
        }else if (opc == 2){
            desempilhar();
        }else if (opc == 3){
            imprimir(pilha);
        }

    }while (opc != 9);


}


int main(){
    menu();
    return 0;
}