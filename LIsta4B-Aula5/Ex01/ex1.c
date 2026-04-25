/*ED-L5-001 - DRIVE THRU
Crie um software que será responsável por organizar a fila de veículos de um drive thrue capaz de orgnaizar até 10 veículos, 
é importante que a estrutura de fila permita adicionar até 10 veículos. Logo abaixo estão descritas as informações que serão necessárias armazenar de cada veículo.

Veiculo {
  + Placa;
  + NomeMotorista;
  + TotalPedido;}

FilaDriveThru {
  + Adicionar(Veiculo);  //Adiciona um veículo na fila do drive thrue;
  + Atender(); // Remove um veículo da fila;
  + VeiculosNaFila; //Exibe a placa e nome do motorista dos veículos da fila;
  + NumeroVeiculosParaAtender(); //Exibe o número de veículos na fila;
  + Pesquisar(Placa); //Verifica se um determinado veículo está na fila a partir da placa;
}
*/
#include <stdio.h>
#include <string.h>
#define TAM 10
struct Veiculo{
    char placa[10];
    char nomeMotorista[50];
    float precoPedido;
};
struct Veiculo fila[TAM];

int ini = -1;
int fin = -1;
int con = 0;

void adicionarVeiculo(){
    struct Veiculo v;

    if (con == TAM){
        printf("FILA CHEIA!\n");
        return;
    }
    
    printf("Placa: \n");
    scanf("%s", v.placa);

    printf("Nome do motorista: \n");
    scanf("%s", v.nomeMotorista);

    printf("Total Pedido: \n");
    scanf("%f", &v.precoPedido);

    if (fin == -1){
        fin++;
        ini++;
     
    }else {
        if (fin == (TAM - 1)){
            fin = 0;
        }else{
            fin++;
        }
    }
    con++;
    fila[fin] = v;
}
void removerVeiculo(){

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
        printf("Nome do motorista: [%s] |Placa: [%s]\n", fila[i].nomeMotorista,  fila[i].placa);

        if (i == TAM - 1){
            i = 0;
        } else {
            i++;
        }
    }
}
int numeroVeiculoAtender(){
    return con; 
}
void pesquisar(char *placa){
    if (con == 0){
        printf("Fila vazia!\n");
        return;
    }

    int i = ini;

    for (int j = 0; j < con; j++){
       
        if (strcmp(placa, fila[i].placa) == 0){
            printf("Veiculo esta na fila!\n");
            return;
       } 

        if (i == TAM - 1){
            i = 0;
        } else {
            i++;
        }
    }
    printf("Veiculo não encontrado!\n");
    
}
void menu () {
    int opc = 0;

    do{
        printf("1. Adicionar(Veiculo)\n");
        printf("2. Remover veiculo\n");
        printf("3. Veiculos Na Fila\n");
        printf("4. Numero de Veiculos Para Atender()\n");
        printf("5. Pesquisar(Placa)\n");
        printf("9. Sair\n");
        scanf("%i", &opc);

        if (opc == 1){
            adicionarVeiculo();

        }else if (opc == 2){
            removerVeiculo();
        }else if (opc == 3){
            imprimir();
        }else if (opc == 4){
            printf("Veiculos na fila: %i\n", numeroVeiculoAtender());
        }else if (opc == 5){
            char placa[10];
            printf("Digite a placa para achar!\n");
            scanf("%s", placa);
            pesquisar(placa);
        }
    }while(opc !=9);

}

int main(){
    menu();
}