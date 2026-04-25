/*- O exercício abaixo visa a aplicação de vários conceitos de estrutura de dados vistos 
até o momento tais como: Estruturas lineares; Tipos de dados estruturados; Tipos de dados abstratos e Filas Circulares. 
Implementar o exercício abaixo utilizando métodos TDA.
DESCRIÇÃO
  – Criar uma fila circular de veículos, cada veículo deverá conter as seguintes informações: Placa, Modelo, Preço.
 
  – Crie um menu para manipular a fila de veículos com as seguintes opções:
	1. Enfileirar
	2. Desenfileirar
	3. Imprimir
	4. Maior valor
	5. Soma todos valores
	9. Sair
  - Extra: Apesar de não ser obrigatório, demonstre que está com disposição para aprender, adicione ao exercício os itens: 
  a) Uma opção que possibilite realizar uma busca pela placa de um veículo (esta implementação visa comparação textual em C, pesquise sobre 'strcmp'). 
  b) Adicione uma regra que não permite incluir um segundo veículo com a mesma placa caso já exista um veículo com a mesma placa já cadastrado. */
#include <stdio.h>
#define TAM 5


struct Veiculo{
    char placa[10];
    char modelo[50];
    float preco;
};

struct Veiculo fila[TAM];

int ini = -1;
int fin = -1;
int con = 0;

void enfileirar(){

    struct Veiculo v;

    if (con == TAM){
        printf("Fila cheia!\n");
        return;
    }

    printf("Placa: ");
    scanf("%s", v.placa);

    printf("Modelo: ");
    scanf("%s", v.modelo);

    printf("Preco: ");
    scanf("%f", &v.preco);

    if (fin == -1){
        fin++;
        ini++;
    }else{
        if (fin == (TAM - 1)){
            fin = 0;
        }else{
            fin++;
        }
    }

    con++;
    fila[fin] = v;
}

void desenfileirar(){

    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    if (ini == (TAM - 1)){
        ini = 0;
    }else{
        ini++;
    }

    con--;

    if (con == 0){
        ini = -1;
        fin = -1;
    }

    printf("Veiculo removido!\n");
}
void imprimir(){
    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    int i = ini;

    for (int j = 0; j < con; j++){
        printf("%s %s %.2f\n", fila[i].placa, fila[i].modelo, fila[i].preco);

        if (i == TAM - 1){
            i = 0;
        } else {
            i++;
        }
    }
}
float somaValores(){
    float soma = 0;
    if (con == 0){
        printf("Fila vazia!\n");
        return 0;
    }

    int i = ini;

    for (int j = 0; j < con; j++){
        soma+=fila[i].preco;

        if (i == TAM - 1){
            i = 0;
        } else {
            i++;
        }
    }
    return soma;
}

float maiorValor(){
    
    if (con == 0){
        printf("Fila vazia!\n");
        return 0;
    }

    int i = ini;
    float maior = fila[ini].preco;

    for (int j = 0; j < con; j++){
        if (fila[i].preco > maior){
            maior = fila[i].preco;  
    }
             
        if (i == TAM - 1){
            i = 0;
        } else {
            i++;
        }
    }
    return maior;
}

void menu () {
    int opc = 0;

    do{
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Imprimir\n");
        printf("4. Maior valor\n");
        printf("5. Soma todos valores\n");
        printf("9. Sair\n");
        scanf("%i", &opc);

        if (opc == 1){
            enfileirar();

        }else if (opc == 2){
            desenfileirar();
        }else if (opc == 3){
            imprimir();
        }else if (opc == 4){
           printf("O maior valor e: %.2f\n", maiorValor());
        }else if (opc == 5){
            printf("A soma dos vlaores da: %.2f\n", somaValores());
        }
    }while(opc !=9);

}

int main (){
    menu();

}