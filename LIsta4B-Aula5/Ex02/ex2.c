/*ED-L5-002 - CONTROLE ENTREGAS
A empresa Logistica S.A. necessita controlar o fluxo de recebimento de cargas por ordem de chegada dos caminhões, 
para que esse trabalho seja desenvolvido foi necessário a criação de um sistema que deverá registrar a chegada de cada caminhão em ordem 
e deverá chama-lo para descarregar quando chegar a vez do mesmo, a area de espera não é muito grande e cabe apenas 10 caminhões em espera. Baseado no contexto acima, 
implemente uma Fila utilizando a estrutura abaixo.

Caminhao {
  + Placa;
  + Marca;
  + PesoTotal;
  + NumeroCaixas;}

FilaCaminhoes {
    + Chegada (Caminaho); //Adiciona na fila de espera para descarregar.
    + Descarregar(); //Chama o caminhão para descarregar e o retira da fila de espera.
    + PatioCheio(): Boolean; //Retorna True se o pátio estiver cheio e False se ainda existir espaço;
    + Pesquisar(Placa); //Verifica através da placa se um determinado caminhão está na fila de espera;
    + MaisPesado(); //Exibe os dados do caminhão mais pesado;
    + PesoTotalPatioEspera(); //Exibe a soma dos pesos de todos caminhões no pátio de espera;
    + MenorNumeroCaixas(); Exibe os dados do caminhão que contém o menor número de caixas;
    + NumeroCaminhoesEspera(); //Retorna o número de caminhões que estão em espera.     
}
*/
#include <stdio.h>
#include <string.h>

#define TAM 10

struct Caminhao{
    char placa[10];
    char marca[30];
    float pesoTotal;
    int numeroCaixas;
};

struct Caminhao fila[TAM];

int ini = -1;
int fin = -1;
int con = 0;

void chegada(){
    struct Caminhao c;

    if (con == TAM){
        printf("FILA CHEIA!\n");
        return;
    }

    printf("Digite a placa do caminhao:\n");
    scanf("%s", c.placa);

    printf("Digite a marca do caminhao:\n");
    scanf("%s", c.marca);

    printf("Digite o peso do caminhao:\n");
    scanf("%f", &c.pesoTotal);

    printf("Digite o numero de caixas:\n");
    scanf("%d", &c.numeroCaixas);

    if (fin == -1){
        ini = 0;
        fin = 0;
    }else{
        if (fin == TAM - 1){
            fin = 0;
        }else{
            fin++;
        }
    }

    fila[fin] = c;
    con++;
}

void descarregar(){
    if (con == 0){
        printf("FILA VAZIA!\n");
        return;
    }

    if (ini == TAM - 1){
        ini = 0;
    }else{
        ini++;
    }

    con--;

    if (con == 0){
        ini = -1;
        fin = -1;
    }

    printf("Caminhao removido!\n");
}

int patioCheio(){
    if (con == TAM){
        return 1;
    }else{
        return 0;
    }
}

void pesquisar(char *placa){
    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    int i = ini;

    for (int j = 0; j < con; j++){

        if (strcmp(placa, fila[i].placa) == 0){
            printf("Caminhao esta na fila!\n");
            return;
        }

        if (i == TAM - 1){
            i = 0;
        }else{
            i++;
        }
    }

    printf("Caminhao nao encontrado!\n");
}

void maisPesado(){

    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    int i = ini, salvaIndice = ini;
    float maisPesado = fila[ini].pesoTotal;

    for (int j = 0; j < con; j++){

        if (fila[i].pesoTotal > maisPesado){
            maisPesado = fila[i].pesoTotal;
            salvaIndice = i;
        }

        if (i == TAM - 1){
            i = 0;
        }else{
            i++;
        }
    }

    printf("MARCA: [%s] | PLACA: [%s] | PESO TOTAL: [%.2f] | NUMERO DE CAIXAS: [%d]\n",
           fila[salvaIndice].marca,
           fila[salvaIndice].placa,
           fila[salvaIndice].pesoTotal,
           fila[salvaIndice].numeroCaixas);
}

float PesoTotalPatio(){
    float soma = 0;

    if (con == 0){
        printf("Fila vazia!\n");
        return 0;
    }

    int i = ini;

    for (int j = 0; j < con; j++){

        soma += fila[i].pesoTotal;

        if (i == TAM - 1){
            i = 0;
        }else{
            i++;
        }
    }

    return soma;
}

void menorNumeroCaixa(){

    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    int i = ini, salvaIndice = ini;
    int menorCaixa = fila[ini].numeroCaixas;

    for (int j = 0; j < con; j++){

        if (fila[i].numeroCaixas < menorCaixa){
            menorCaixa = fila[i].numeroCaixas;
            salvaIndice = i;
        }

        if (i == TAM - 1){
            i = 0;
        }else{
            i++;
        }
    }

    printf("MARCA: [%s] | PLACA: [%s] | PESO TOTAL: [%.2f] | NUMERO DE CAIXAS: [%d]\n",
           fila[salvaIndice].marca,
           fila[salvaIndice].placa,
           fila[salvaIndice].pesoTotal,
           fila[salvaIndice].numeroCaixas);
}

int NumeroEspera(){
    return con;
}

void menu (){
    int opc = 0;

    do{

        printf("\n1. Chegada\n");
        printf("2. Descarregar\n");
        printf("3. Patio Cheio\n");
        printf("4. Pesquisar\n");
        printf("5. Mais Pesado\n");
        printf("6. Peso Total no Patio\n");
        printf("7. Menor Numero de Caixas\n");
        printf("8. Numero de Caminhoes em Espera\n");
        printf("9. Sair\n");

        scanf("%d", &opc);

        if (opc == 1){
            chegada();
        }
        else if (opc == 2){
            descarregar();
        }
        else if (opc == 3){
            if (patioCheio()){
                printf("Patio lotado!\n");
            }else{
                printf("Ainda ha espaco disponivel!\n");
            }
        }
        else if (opc == 4){
            char placa[10];

            printf("Digite a placa:\n");
            scanf("%s", placa);

            pesquisar(placa);
        }
        else if (opc == 5){
            maisPesado();
        }
        else if (opc == 6){
            printf("Peso total no patio: %.2f\n", PesoTotalPatio());
        }
        else if (opc == 7){
            menorNumeroCaixa();
        }
        else if (opc == 8){
            printf("Numero de caminhoes em espera: %d\n", NumeroEspera());
        }

    }while(opc != 9);
}

int main(){
    menu();
}