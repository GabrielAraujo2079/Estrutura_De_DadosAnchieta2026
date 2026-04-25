/*EDL3-002 (CONTAINNERS)
Crie uma aplicação console que deve utilizar os conceitos de Pilhas (com auxílio de vetores), 
esta aplicação, deverá manipular Containners (codigo, altura, largura, profundidade, marca, empresa). Logo abaixo, está sendo apresentado todos os métodos que devem ser 
implementados na manipulação da estrutura de Pilha.

Containner{
    + code;
    + heigth;
    + width;
    + profundity;
    + brand;
    + company
}
StackContainners
  + StackContainners(tamanho) //Construtor.
  + Push(Containner cont)     //Adicionar a partir de um elemento.
  + Push(codigo, altura, largura, profundidade, marca, empresa) //Adic. utilizando os atrib. do elem.
  + Pop()                     //Remover
  + IsEmpty()                 //Se estiver vazia, retorna verdadeiro, caso contrário, falso.
  + IsFull()                  //Se estiver cheia, retorna verdadeiro, caso contrário, falso.
  + PrintAll()                //Imprime todos os elementos presentes na pilha, do topo para base.
  + PrintAllOfEnterprise(empr)//Imprime todos os elementos de uma determinada empresa.   
  + PrintTop()                //Imprime o elemento presente no topo da pilha.
  + FindPrint(codigo)         //Pesquisa um elemento a partir de seu código, e imprime os dados na tela.
  + GetNumberElements()       //Retorna o número de elementos presentes na pilha.
*/
#include <stdio.h>
#include <string.h>
#define TAM 5

struct Containner {
    int codigo;
    float altura;
    float largura;
    float profundidade;
    char marca[50];
    char companhia[50];
};

struct Containner stack[TAM];
int topo = -1;

int isEmpty() {
    return topo == -1;
}

int isFull(){
    return topo == TAM - 1;
}

int GetNumberElements(){
    return topo + 1;
}

void PrintTop() {

    if (isEmpty()) {  // CORRIGIDO (era IsEmpty)
        printf("Stack vazia!\n");
        return;
    }

    printf("\n--- TOPO DA PILHA ---\n");
    printf("Codigo: %d\n", stack[topo].codigo);
    printf("Altura: %.2f\n", stack[topo].altura);
    printf("Largura: %.2f\n", stack[topo].largura);
    printf("Profundidade: %.2f\n", stack[topo].profundidade);
    printf("Marca: %s\n", stack[topo].marca);
    printf("Companhia: %s\n", stack[topo].companhia);
}

void pop(){

    if (isEmpty()) {  // CORRIGIDO
        printf("Stack vazia!\n");
        return;
    }

    printf("Removido codigo: %d\n", stack[topo].codigo);
    printf("Companhia: %s\n", stack[topo].companhia);

    topo--;
}

void Push(){

    if (isFull()){
        printf("Stack cheia!\n");
        return;
    }

    topo++;

    printf("Digite o codigo: ");
    scanf("%d", &stack[topo].codigo);

    printf("Digite altura: ");
    scanf("%f", &stack[topo].altura);

    printf("Digite a largura: ");
    scanf("%f", &stack[topo].largura);

    printf("Digite a profundidade: ");
    scanf("%f", &stack[topo].profundidade);

    printf("Digite a marca: ");
    scanf("%s", stack[topo].marca);

    printf("Digite a companhia: ");
    scanf("%s", stack[topo].companhia);

    printf("Container adicionado com sucesso!\n");
}

void PrintAll(){

    if (isEmpty()){
        printf("Stack vazia!\n");
        return;
    }

    for (int i = topo; i >= 0; i--){

        printf("\n--- POSICAO %d ---\n", i);
        printf("Codigo: %d\n", stack[i].codigo);
        printf("Altura: %.2f\n", stack[i].altura);
        printf("Largura: %.2f\n", stack[i].largura);
        printf("Profundidade: %.2f\n", stack[i].profundidade);
        printf("Marca: %s\n", stack[i].marca);
        printf("Companhia: %s\n", stack[i].companhia);
    }
}

void PrintAllOfEnterprise(char empresa[50]){

    if (isEmpty()){
        printf("Stack vazia!\n");
        return;
    }

    int encontrou = 0;

    for (int i = topo; i >= 0; i--){

        if (strcmp(stack[i].companhia, empresa) == 0){

            printf("\n--- ENCONTRADO ---\n");
            printf("Codigo: %d\n", stack[i].codigo);
            printf("Altura: %.2f\n", stack[i].altura);
            printf("Largura: %.2f\n", stack[i].largura);
            printf("Profundidade: %.2f\n", stack[i].profundidade);
            printf("Marca: %s\n", stack[i].marca);
            printf("Companhia: %s\n", stack[i].companhia);

            encontrou = 1;
        }
    }

    if (!encontrou){
        printf("Nenhum container dessa empresa encontrado.\n");
    }
}

void FindPrint(int codigo){

    if (isEmpty()){
        printf("Stack vazia!\n");
        return;
    }

    for (int i = topo; i >= 0; i--){

        if (stack[i].codigo == codigo){

            printf("\n--- ENCONTRADO ---\n");
            printf("Codigo: %d\n", stack[i].codigo);
            printf("Altura: %.2f\n", stack[i].altura);
            printf("Largura: %.2f\n", stack[i].largura);
            printf("Profundidade: %.2f\n", stack[i].profundidade);
            printf("Marca: %s\n", stack[i].marca);
            printf("Companhia: %s\n", stack[i].companhia);

            return;
        }
    }

    printf("Codigo nao encontrado!\n");
}

void menu(){

    int opcao;
    int codigo;
    char empresa[50];

    do {

        printf("\n===== MENU STACK CONTAINERS =====\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - PrintTop\n");
        printf("4 - PrintAll\n");
        printf("5 - PrintAllOfEnterprise\n");
        printf("6 - FindPrint\n");
        printf("7 - GetNumberElements\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1){
            Push();
        }
        else if (opcao == 2){
            pop();
        }
        else if (opcao == 3){
            PrintTop();
        }
        else if (opcao == 4){
            PrintAll();
        }
        else if (opcao == 5){
            printf("Digite a empresa: ");
            scanf("%s", empresa);
            PrintAllOfEnterprise(empresa);
        }
        else if (opcao == 6){
            printf("Digite o codigo: ");
            scanf("%d", &codigo);
            FindPrint(codigo);
        }
        else if (opcao == 7){
            printf("Numero de elementos: %d\n", GetNumberElements());
        }
        else if (opcao == 0){
            printf("Saindo...\n");
        }
        else{
            printf("Opcao invalida!\n");
        }

    } while(opcao != 0);
}

int main(){
    menu();
    return 0;
}