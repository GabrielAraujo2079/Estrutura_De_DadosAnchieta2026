/*A empresa JOGOS DA SORTE LTDA. está com uma vaga para programador em aberto, todos os candidatos a vaga devem desenvolver um código fonte que envolva 
a manipulação de cartas 52, em resumo, a aplicação deverá:

a) Considrar que existem 52 cartas, sendo 4 nipes (Ouro, Espada, Copas, Paus), e que cada naipe contem números entre 1 a 13, ou seja, 1 
(Ás), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 (Valete), 12 (Dama), 13 (Rei).

b) A aplicação deverá conter as seguintes operações:
b.1) Sortear/Empilhar cartas (esta operação deverá fazer o sorteio das 52 cartas). 
b.2) Comprar/Desempilhar carta (esta opção deverá exibir e retirar a carta do topo).
b.3) Exibir cartas monte (exibir na ordem todas as cartas que ainda estão no monte (que não foram desempilhadas)).

c) É importante que ao final do Sorteio/Empilhamento as cartas empilhadas estejam aleatórias. 

SUGESTÕES
1 - Implementar Pilha sobre Estrutura Linear (vetor) Heterogênea (Structs).
2 - Pesquisar sobre método de sorteio aleatório, já fizemos isso em sala durante as aulas de manipulação de vetores.*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 52

struct Cartas{
    int numero;
    char nipe;
};

struct Cartas baralho[TAM];

int topo = -1;

void sortear(){

    int numeroCarta = 0;

    if(topo != -1){
        printf("BARALHO JA FOI GERADO!\n");
        return;
    }

    for(int i = 0; i < TAM; i++){

        if(i <= 12){
            if(i == 0) numeroCarta = 1;
            baralho[i].numero = numeroCarta++;
            baralho[i].nipe = 'O';
        }
        else if(i <= 25){
            if(i == 13) numeroCarta = 1;
            baralho[i].numero = numeroCarta++;
            baralho[i].nipe = 'E';
        }
        else if(i <= 38){
            if(i == 26) numeroCarta = 1;
            baralho[i].numero = numeroCarta++;
            baralho[i].nipe = 'C';
        }
        else{
            if(i == 39) numeroCarta = 1;
            baralho[i].numero = numeroCarta++;
            baralho[i].nipe = 'P';
        }
    }

    for(int i = 0; i < TAM; i++){

        int j = rand() % TAM;

        struct Cartas temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    topo = TAM - 1;

    printf("BARALHO GERADO E EMBARALHADO!\n");
}

void comprar(){

    if(topo == -1){
        printf("MONTE VAZIO!\n");
        return;
    }

    printf("Carta removida: %i de %c\n", baralho[topo].numero, baralho[topo].nipe);

    topo--;
}

void exibirMonte(){

    if(topo == -1){
        printf("MONTE VAZIO!\n");
        return;
    }

    printf(":: REVELANDO O MONTE ::\n");

    for(int i = topo; i >= 0; i--){

        if(baralho[i].numero == 1){
            printf("NUMERO CARTA: [%i] TIPO: [AS] | NIPE: [%c]\n", baralho[i].numero, baralho[i].nipe);
        }
        else if(baralho[i].numero == 11){
            printf("NUMERO CARTA: [%i] TIPO: [Valete] | NIPE: [%c]\n", baralho[i].numero, baralho[i].nipe);
        }
        else if(baralho[i].numero == 12){
            printf("NUMERO CARTA: [%i] TIPO: [Dama] | NIPE: [%c]\n", baralho[i].numero, baralho[i].nipe);
        }
        else if(baralho[i].numero == 13){
            printf("NUMERO CARTA: [%i] TIPO: [Rei] | NIPE: [%c]\n", baralho[i].numero, baralho[i].nipe);
        }
        else{
            printf("NUMERO CARTA: [%i] TIPO: [Comum] | NIPE: [%c]\n", baralho[i].numero, baralho[i].nipe);
        }
    }
}

void menu(){

    int opc = 0;

    do{

        printf("\n1. Sortear/Empilhar\n");
        printf("2. Comprar/Desempilhar\n");
        printf("3. Exibir cartas monte\n");
        printf("9. Sair\n");

        scanf("%i", &opc);

        if(opc == 1){
            sortear();
        }
        else if(opc == 2){
            comprar();
        }
        else if(opc == 3){
            exibirMonte();
        }

    }while(opc != 9);
}

int main(){

    srand(time(NULL));
    menu();
}