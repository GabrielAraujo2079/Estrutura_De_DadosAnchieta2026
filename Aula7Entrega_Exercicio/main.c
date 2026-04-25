/*Cada aluno deverá implementar a Fila Dinâmica conforme orientações abaixo relacionadas,  
a implementação deverá respeitar o prazo, o código fonte (em C) deverá ser postado em sua integralidade e deverá conter:

a) Filas dinâmicas; 
b) Utilização de 02 PONTEIROS, um para controle de início e final da fila dinâmica.
c) Deverá fazer uso de Tipo de Dados Estruturados (TDE) contendo ao menos 3 valores.
d) Deverá fazer uso de Tipo de Dados Abstratos (TDA), ou seja, utilização de métodos.
e) Deverá fazer controle de Fila Vazia. 
f) Deverá conter os seguintes métodos além dos métodos básicos: 
  - Exibir todos elementos da fila (do início ao fim);
  - Reiniciar a fila (procedimento que zera a fila totalmente);
  - Buscar elemento pelo Codigo, a busca deverá partir do inicio para o final e deverá verificar se a fila está fazia.
g) Cada aluno poderá escolher o cenário desejado para implementação da fila dinâmica.

Sistema escolhido por mim:
Sistema de balsa com fila para embarque, vai ser separado por carro, moto e onibus/caminhao com o preço variando por tipo
optei por separar po INT ou seja 1 moto, 2 carro, 3 onbius/caminhao 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Veiculo{
    int codigo;
    char placa[8];
    int tipo;
    char marca[20];
    char modelo[30];
    float preco;

    struct Veiculo *proximo;
    
}Veiculo;

typedef struct Fila{
    Veiculo *inicio;
    Veiculo *fim;
}Fila;

int numeroVeiculos;
void iniciar(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

int vazia(Fila *f){
    if(f->inicio == NULL){
        return 1;
    }else {
        return 0;
    }
}
Veiculo *adicionar(Fila *f){
    Veiculo *novo = (Veiculo*) malloc(sizeof(Veiculo));

    if (!novo) {
        printf("Memoria insuficiente\n");
        return NULL;
    }else {
        
        printf("Codigo:\n");
        scanf("%i", &novo->codigo);
        printf("Placa:\n");
        scanf("%s", novo->placa);;
        printf("marca:\n");
        scanf("%s", novo->marca);
        printf("Modelo:\n");
        scanf("%s", novo->modelo);
        printf("ESCOLHA o tipo de veiculo \n[1]Moto \n[2]Carro \n[3]onibus/caminhao \n");
        scanf("%i", &novo->tipo );
        
        if (novo->tipo == 1){
            novo->preco = 2.50;
        
        }else if(novo->tipo == 2){
            novo->preco = 5.00;
        
        }else if(novo->tipo == 3){
            novo->preco = 7.50;
        }     
       
        //inicializa o prox e evita ficar com lixo
        novo->proximo = NULL;
        
        //caso nao tenha nada recebe o novo ai
        if (vazia(f)){
            f->inicio = novo;
            f->fim = novo;
        }else{
            //liga o ultimo ao primeiro
            f->fim->proximo = novo;
            //fim fica com o novinho 
            f->fim = novo;
        }
    numeroVeiculos++;
    return novo;
    }
}
Veiculo *desenfileirar(Fila *f){
    if (f->inicio == NULL){
        printf("VAZIA!\n");
        return NULL;
    
    }else {
        Veiculo *tmp = f->inicio;
        printf("Atendendo veiculo codigo: %d\n", tmp->codigo);
        f->inicio = tmp->proximo;
        numeroVeiculos--;

        //caso fila fique vazia
        if (f->inicio == NULL){
            f->fim = NULL;
        }

        return tmp;
    }
}
void exibir(Fila *f){
    
    if (vazia(f) == 1){
        printf("VAZIA!\n");
        return;
    }else {
        Veiculo *tmp = f->inicio;
        
        while (tmp != NULL){
            printf("Codigo: %i\n", tmp->codigo);
            printf("Placa: %s\n", tmp->placa);
            
            if (tmp->tipo == 1){
                printf("Tipo: Moto\n");
            }
            else if (tmp->tipo == 2){
                printf("Tipo: Carro\n");
            }
            else{
                printf("Tipo: Onibus/Caminhao\n");
            }
            printf("Marca: %s\n", tmp->marca);
            printf("Modelo: %s\n", tmp->modelo);
            printf("preco da passagem: %.2f\n", tmp->preco);
           tmp = tmp->proximo;
        }
    }
}

void reiniciar(Fila *f){
    Veiculo *tmp = f->inicio;

    while(tmp != NULL){
        Veiculo *remover = tmp;
        tmp = tmp->proximo;
        free(remover);
    }
    f->inicio = NULL;
    f->fim = NULL;
    numeroVeiculos = 0;
    printf("FILA ZERADINHA!\n");
}

void localizar(Fila *f){
    if (vazia(f)){
        printf("VAZIA!\n");
        return;
    }

    int userCodigo;
    Veiculo *tmp = f->inicio;

    printf("Digite o codigo do veiculo que deseja procurar!\n");
    scanf("%i", &userCodigo);

    while (tmp != NULL){ 
        if(userCodigo == tmp->codigo){
            printf("Codigo: %i\n", tmp->codigo);
            printf("Placa: %s\n", tmp->placa);
            
            if (tmp->tipo == 1){
                printf("Tipo: Moto\n");
            }
            else if (tmp->tipo == 2){
                printf("Tipo: Carro\n");
            }
            else{
                printf("Tipo: Onibus/Caminhao\n");
            }
            printf("Marca: %s\n", tmp->marca);
            printf("Modelo: %s\n", tmp->modelo);
            printf("preco da passagem: %.2f\n", tmp->preco);
            return;
        }
        tmp = tmp->proximo;
    }
    printf("Veiculo nao encontrado!");
    return;
}
//metodo extra pra mostrar que nao to com preguica
int contarVeiculos(){
    return numeroVeiculos;
}
void menu(){
    int opc;

    Fila *f = (Fila*) malloc(sizeof(Fila));

    iniciar(f);
    
    do{
        printf("\n===== MENU =====\n");
        printf("1. Enfileirar(Veiculo))\n");
        printf("2. Desinfileirar(veiculo)\n");
        printf("3. Exibir\n");
        printf("4. Reiniciar fila\n");
        printf("5. Localizar\n");
        printf("6. Contar veiculos na fila\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        if (opc == 1){
            adicionar(f);

        }else if (opc == 2){
            desenfileirar(f);
        }else if (opc == 3){
            exibir(f);
        }else if (opc == 4){
            reiniciar(f);
        }else if (opc == 5){
            localizar(f);
        }else if (opc == 6){
            printf("O numero total de veiculos na fila e de: %i", contarVeiculos());
        }
           
    }while(opc != 0);   
}

int main(){
    menu();
    return 0;
}