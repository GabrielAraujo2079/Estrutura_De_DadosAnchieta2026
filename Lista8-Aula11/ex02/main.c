/*Inúmeros diferentes tipos de dados podem ser ordenados, tipos primitivos, tipos estruturados, etc. Para os tipos de dados estruturados, é necessário que seja feita a definição de campos chaves que são considerados os mais relevantes. Logo abaixo é solicitado a implementação de um vetor responsável por armazenar informações de alunos, 
este vetor deverá ser ordenado a partir dos campos chaves (indicados no TDE por um asterisco).
Orientações importantes:
- Caso crie um vetor com 10 posições, deve-se carregar o mesmo com informações de 10 alunos, nenhuma posição do vetor deverá ficar vazia;
- Caso o número de alunos inseridos no vetor seja inferior a capacidade do mesmo, quando ocorrer a ordenação as posições não ocupadas do vetor não devem ser exibidas.
Tipo de dados estruturado (TDE)
Aluno {
  + ra: inteiro;*
  + cpf: inteiro;
  + nome: texto;}

Desenvolva o menu a seguir:
************************
MENU ORDENACAO
************************
1 - Carregar vetor de alunos;
2 - Imprimir vetor (ra, cpf, nome);
3 - Ordenar Insertion RA;
4 - Ordenar Insertion CPF;
5 - Ordenar Buble RA;
6 - Ordenar Buble CPF;
9 - Sair;
*/
#define TAM 10
#include <stdio.h>

struct Aluno{
    int ra;
    int cpf;
    char nome[30];
};
int posicao = 0;
int quantidadeAlunos = 0;
struct Aluno vetor[TAM];


void carregarAlunos(){
    printf("Digite RA:\n");
    scanf("%d", &vetor[posicao].ra);
    printf("Digite CPF:\n");
    scanf("%d", &vetor[posicao].cpf);
    printf("Digite Nome:\n");
    scanf("%s", vetor[posicao].nome);
    posicao++;
    quantidadeAlunos++;
    
    if(posicao == TAM){
        posicao = 0;
    }
}
void imprimirAlunos(){
    for(int i = 0; i < quantidadeAlunos; i++){
            printf("RA:%d\n", vetor[i].ra);
            printf("CPF:%d\n", vetor[i].cpf);
            printf("Nome:%s\n", vetor[i].nome);
    }
}
void insertionRa(){
    int aux = 0, seguraValor = 0;
    for(int i = 1; i < quantidadeAlunos; i++){
        seguraValor = vetor[i].ra;
        aux = i - 1;
        
        while(aux >= 0 && vetor[aux].ra > seguraValor){
            vetor[aux + 1].ra = vetor[aux].ra;
            aux--;
        }
        vetor[aux + 1].ra = seguraValor;
    }
}
void insertionCPF(){
    int aux = 0, seguraValor = 0;
    for(int i = 1; i < quantidadeAlunos; i++){
        seguraValor = vetor[i].cpf;
        aux = i - 1;
        
        while(aux >= 0 && vetor[aux].cpf > seguraValor){
            vetor[aux + 1].cpf = vetor[aux].cpf;
            aux--;
        }
        vetor[aux + 1].cpf = seguraValor;
    }
}
void burbbleRA(){
    int aux = 0;

    for(int i = 0; i < quantidadeAlunos -1; i++){
        for(int j = 0; j < quantidadeAlunos -1 - i; j++){
            if(vetor[j].ra > vetor[j+1].ra){
                aux = vetor[j].ra;
                vetor[j].ra = vetor[j + 1].ra;
                vetor[j + 1].ra = aux;
            }
        }
    }
}
void burbbleCPF(){
    int aux = 0;

    for(int i = 0; i < quantidadeAlunos -1; i++){
        for(int j = 0; j < quantidadeAlunos -1 - i; j++){
            if(vetor[j].cpf > vetor[j+1].cpf){
                aux = vetor[j].cpf;
                vetor[j].cpf = vetor[j + 1].cpf;
                vetor[j + 1].cpf = aux;
            }
        }
    }
}
void menu(){
    int opc = 0;

    do{
        printf("1. Carregar\n");
        printf("2. Imprimir\n");
        printf("3. Inserction RA\n");
        printf("4. Inserction CPF\n");
        printf("5. Bubble RA\n");
        printf("6. BUBBLE CPF\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao\n");
        scanf("%d", &opc);


        if(opc == 1){
            carregarAlunos();
        } else if(opc == 2){
            imprimirAlunos();
        } else if(opc == 3){
            insertionRa();
        } else if(opc == 4){
            insertionCPF();
        } else if(opc == 5){
            burbbleRA();
        } else if(opc == 6){
            burbbleCPF();
        } 

    }while(opc !=9);
}
int main(){
    menu();
    return 0;
}