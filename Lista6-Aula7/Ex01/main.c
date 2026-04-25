/*LISTA EXERC�CIOS FILAS DIN�MICAS

DESCRI��O
  A presente lista de exerc�cios foi desenvolvida para a pr�tida dos conceitos dos conceitos de Filas com uso de Listas Ligadas tamb�m conhecidas como Filas Din�micas, 
  os exerc�os aqui 
  propostos refor�am ainda os conceitos de Tipos de dados estruturados (TDA), 
  Tipos de dados abstratos (TDA), Contadores, Acumuladores, Comandos condicionais, Comandos de Repeti��o, etc.
  Todas as opera��es de cada exerc�cio dever� ser desenvolvida no entanto para controle interno das aplica��es v�rios outros m�todos podem ser desenvolvidos.

EXERC�CIOS

:: EDFLLL01 ::..
Com base nas informa��es abaixo, desenvolva uma aplica��o que faz uso de Filas, o exerc�cio preve o controle de uma Fila de ve�culos.
TDE
Veiculo {
  + Codigo
  + Placa
  + Modelo
  + Marca
  + Preco
}

OPERA��ES
 + Enfileirar (Veiculo)
 + Desenfileirar()
 + Relat�rio() -- Deve imprimir as informa��es de todos os ve�culos da fila, do in�cio para o final.
 + In�cio ()   -- Deve exibir os dados do ve�culo do in�cio da fila.
 + Final()     -- Deve exibir os dados do ve�culo do final da fila.
 + Total()     -- A quantidade de ve�culos da fila.
 + Localizar (Placa) -- Caso a linguagem seja C pesquisar como realizar compara��o textual (Char).
 + Mais Caro ()      -- Deve exibir os dados do ve�culo mais caro.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo{
    int codigo;
    char placa[8];
    char modelo[30];
    char marca[20];
    float preco;

    struct Veiculo *proximo;
    
}ElementoFila;

int numeroElementos;

void iniciar(ElementoFila * Fila){
    Fila->proximo = NULL;
    numeroElementos = 0;
}
int vazia(ElementoFila * Fila){
    if(Fila->proximo == NULL){
        return 1;
    }else {
        return 0;
    }
}

ElementoFila *criar(){
    ElementoFila *novo = (ElementoFila *) malloc(sizeof(ElementoFila));

    if (!novo) {
        printf("Memoria insuficiente\n");
    }else {
        printf("Codigo: \n");
        scanf("%i", &novo->codigo);
        printf("Placa: \n");
        scanf("%s", novo->placa);
        printf("modelo: \n");
        scanf("%s", novo->modelo);
        printf("marca: \n");
        scanf("%s", novo->marca);
        printf("Preco:\n");
        scanf("%f", &novo->preco);
        
        return novo;
    }
}
void enfileirar(ElementoFila *Fila){
    ElementoFila *novo = criar();

    novo->proximo = NULL;

    if (vazia(Fila)){
        Fila->proximo = novo;
    }else {
        ElementoFila *tmp = Fila->proximo;

        while (tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
        
    }

    numeroElementos = numeroElementos + 1;
}

ElementoFila *desenfileirar(ElementoFila *Fila){
    if (Fila->proximo == NULL){
        printf("VAZIA!\n");
        return NULL;
    
    }else {
        ElementoFila *tmp = Fila->proximo;
        Fila->proximo = tmp->proximo;

        numeroElementos = numeroElementos - 1;

        return tmp;
    }
}

void relatorio(ElementoFila * Fila){
    if (vazia(Fila) == 1){
        printf("VAZIA!\n");
        return;
    }else {
        ElementoFila * tmp;
        tmp = Fila->proximo;
        
        while (tmp != NULL){
            printf("Codigo: %i\n", tmp->codigo);
            printf("Placa: %s\n", tmp->placa);
            printf("Modelo: %s\n", tmp->modelo);
            printf("marca: %s\n", tmp->marca);
            printf("Preco: %.2f\n", tmp->preco);
            tmp = tmp->proximo;
        }
    }
}
void inicio(ElementoFila *Fila){
    if (vazia(Fila) == 1){
        printf("VAZIA!\n");
        return;
    }else {  
        ElementoFila * primeiro;
        
        primeiro = Fila->proximo;
        printf("Codigo: %i\n", primeiro->codigo);
        printf("Placa: %s\n", primeiro->placa);
        printf("Modelo: %s\n", primeiro->modelo);
        printf("marca: %s\n", primeiro->marca);
        printf("Preco: %.2f\n", primeiro->preco);
    }
}
void final(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    ElementoFila *tmp = Fila->proximo;

    while (tmp->proximo != NULL){
        tmp = tmp->proximo;
    }

    printf("Codigo: %i\n", tmp->codigo);
    printf("Placa: %s\n", tmp->placa);
    printf("Modelo: %s\n", tmp->modelo);
    printf("Marca: %s\n", tmp->marca);
    printf("Preco: %.2f\n", tmp->preco);
}
int total(){
    return numeroElementos;
}
void localizar(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    char userPlaca[8];
    ElementoFila *tmp = Fila->proximo;

    printf("Digite a placa que deseja procurar!");
    scanf("%s", userPlaca);

    while (tmp != NULL){ 
        if(strcmp(userPlaca, tmp->placa) == 0){
            printf("Codigo: %i\n", tmp->codigo);
            printf("Placa: %s\n", tmp->placa);
            printf("Modelo: %s\n", tmp->modelo);
            printf("Marca: %s\n", tmp->marca);
            printf("Preco: %.2f\n", tmp->preco);
            return;
        }
        tmp = tmp->proximo;
    }
    printf("veiculo não encontrado!");
    return;
}
void maisCaro(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    ElementoFila *tmp = Fila->proximo;
    ElementoFila *maisCaro = Fila->proximo;


    while (tmp != NULL){ 
        if(tmp->preco > maisCaro->preco){
            maisCaro = tmp;
        }
        tmp = tmp->proximo;
    }
    printf("Codigo: %i\n", maisCaro->codigo);
    printf("Placa: %s\n", maisCaro->placa);
    printf("Modelo: %s\n", maisCaro->modelo);
    printf("Marca: %s\n", maisCaro->marca);
    printf("Preco: %.2f\n", maisCaro->preco);
   
}
void menu(){
    int opc;

    ElementoFila *Fila = (ElementoFila *) malloc(sizeof(ElementoFila));

    iniciar(Fila);
    do{
        printf("\n===== MENU =====\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Relatario\n");
        printf("4. Inicio\n");
        printf("5. Final\n");
        printf("6. Total\n");
        printf("7. Localizar \n");
        printf("8. Mais Caro\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        if (opc == 1){
            enfileirar(Fila);

        }else if (opc == 2){
            ElementoFila *removido = desenfileirar(Fila);
            if (removido != NULL){
            printf("Removido:\n");
            printf("Codigo: %i\n", removido->codigo);
            free(removido);
        }
        
        }else if (opc == 3){
            relatorio(Fila);

        }else if (opc == 4){
            inicio(Fila);

        }else if (opc == 5){
            final(Fila);

        }else if (opc == 6){
            printf("Total: %i\n", total());

        }else if (opc == 7){
            localizar(Fila);

        }else if (opc == 8){
            maisCaro(Fila);
        }
    
    }while(opc != 0);
}

int main(){
    menu();
    return 0;
}