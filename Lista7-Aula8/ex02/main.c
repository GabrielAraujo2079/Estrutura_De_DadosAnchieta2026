/*O banco COFRINHO SA irá implementar em uma de suas agências o "Super Atendimento", para tal o banco solicitou a criação de um software que será responsável pelo controle da fila de espera. O software irá permitir a inclusão e remoção de clientes em várias posições da fila, permitirá ainda a pesquisa de clientes presentes na fila e inúmeras formas de impressão de informações sobre os clientes 
presentes na fila.
Baseado no cenário acima o programador terá que desenvolver o software baseado nas especificações abaixo.
Cada CLIENTE deverá conter as informações abaixo: 

+ CPF*;
+ AGENCIA;
+ CONTA;
+ TIPO DE ATENDIMENTO**;
+ NOME DO CLIENTE;

ONDE:

* O campo CPF deverá ser único na fila, isso implica que 
antes de cada inserção deverá ser verificado primeiramente se não existe outro cliente na fila com o mesmo CPF.
** O campo TIPO DE ATENDIMENTO determina o tipo de atendimento desejado pelo cliente, este campo pode receber os valores
DEPOSITO, PAGTO, SAQUE.
OPÇÕES DO SISTEMA:

1) Adicionar cliente no início;
2) Adicionar cliente no final;
3) Adicionar cliente após CPF
4) Remover cliente inicio;
5) Remover cliente final;
6) Revemor cliente CPF;
7) Imprimir clientes ->
8) Imprimir cliente <-
9) Imprimir clientes Tipo Atendimento ^
10) Localizar cliente CPF
11) Numero clientes na fila
12) Numero clientes atendidos ^^
13) Numero clientes inclusos ^^^
14) Imprimir vizinhos CPF ^^^^

15) Clientes por tipo de atendimento ^^^^^
ONDE:
^ Ao utilizar esta opcao, o usuario deve informar um tipo qualquer de atendimento, e entao o programa devera imprimir o nome de todos os clientes que estao na fila e tem o mesmo tipo de atendimento.
^^ Corresponde ao numero de clientes que foram retiradado da fila, recomendo a criacao de um contador dentro da classe responsavel pelas operacoes e a cada remocao, este contador e incrementado.
^^^ Corresponde ao numero de clientes que foram adicionados desde o inicio do processamento, atencao, pois esta informacao nao corresponde aos clientes presentes na fila.
^^^^ Deve-se localizar o cliente referente ao CPF informado, apos localizadolo, deve imprimir o nome do cliente anterior e posterior ao localizado. Atencao, pois caso o cliente esteja no inicio ou final, ele nao tera um de seus vizinhos.

^^^^^ Deve exibir um relatório informando o número de clientes presentes na fila para cada tipo de atendimento.*/
#include <stdio.h>
#include <string.h>
#define TAM 10
struct Cliente {
    char CPF[12];
    char agencia[30];
    int conta;
    char tipoAtendimento[30];
    char nomeCliente[30];

    int anterior;
    int proximo;
};

struct Cliente lista[TAM];
int primeiro;
int ultimo;
int quantidade;
int clientesAtendidos = 0;

int vazia(){
    if (quantidade == 0){
        return 1;
    }else {
        return 0;
    }
}

int cheia(){
    if (quantidade == TAM){
        return 1;
    }else {
        return 0;
    }
}

void iniciarLista(){
    primeiro = -1;
    ultimo = -1;
    quantidade = 0;

    for (int i = 0; i < TAM; i++){
        lista[i].CPF[0] = '\0'; 
    }
}

int obterPosicaoVazia(){
    int pv = -1;

    for (int i = 0; i < TAM; i++){
        if (lista[i].CPF[0] == '\0'){
            pv = i;
            break;
        }
    }

    return pv;
}
int verificarCPF(char userCPF[12]){   
    int atual = primeiro;
    while(atual != -1) { 
        if(strcmp(lista[atual].CPF, userCPF) == 0) {
            printf("CPF ja cadastrado\n");
            return 1;
        }
        atual = lista[atual].proximo; 
    }
    return 0;
}
void adicionarInicio(){
    int pv;

    if(cheia()){
        printf("Lista cheia!\n");
        return;
    }

    pv = obterPosicaoVazia();
    char userCPF[12];

    printf("Digite o CPF:\n");
    scanf("%s", userCPF);

    if (verificarCPF(userCPF)){
        return;
    }

    strcpy(lista[pv].CPF, userCPF);

    printf("Digite o nome da agencia: \n");
    scanf("%s", lista[pv].agencia);

    printf("Digite a conta\n");
    scanf("%i", &lista[pv].conta);

    printf("Digite o tipo de atendimento: \n");
    scanf("%s", lista[pv].tipoAtendimento);

    printf("Digite o nome do cliente: \n");
    scanf("%s", lista[pv].nomeCliente);

    if (quantidade == 0) {
        primeiro = pv;
        ultimo = pv;
        lista[pv].anterior = -1;
        lista[pv].proximo = -1;
    } else {
        lista[primeiro].anterior = pv;
        lista[pv].proximo = primeiro;
        lista[pv].anterior = -1;
        primeiro = pv;
    }

    quantidade++;
}
void adicionarFinal() {
  int pv;

    if(cheia()){
        printf("Lista cheia!\n");
        return;
    }

    pv = obterPosicaoVazia();
    char userCPF[12];

    printf("Digite o CPF:\n");
    scanf("%s", userCPF);

    if (verificarCPF(userCPF)){
        return;
    }

    strcpy(lista[pv].CPF, userCPF);

    printf("Digite o nome da agencia: \n");
    scanf("%s", lista[pv].agencia);

    printf("Digite a conta\n");
    scanf("%i", &lista[pv].conta);

    printf("Digite o tipo de atendimento: \n");
    scanf("%s", lista[pv].tipoAtendimento);

    printf("Digite o nome do cliente: \n");
    scanf("%s", lista[pv].nomeCliente);
        
        if (quantidade == 0) {
            lista[pv].anterior = -1;
            lista[pv].proximo = -1;
            primeiro = pv;
            ultimo = pv;
        }else {
            // o novo elemento agora tem como anterior o antigo ultimo
            lista[pv].anterior = ultimo;
            //o ultimo nao pode ter um proximo
            lista[pv].proximo = -1;
            //antigo ultimo recebe o proximo novo ultimo
            lista[ultimo].proximo = pv;
            //REAL ULTIMO vira ultimo definitivamente 
            ultimo = pv;
        }
        quantidade++;
} 

void adicionarAposCPF(){
    if (cheia()) {
        printf("Lista cheia!\n");
        return;
    }

    char cpfBusca[12];
    printf("Digite o CPF do cliente após o qual deseja inserir:\n");
    scanf("%s", cpfBusca);

    int atual = primeiro;

    while(atual != -1){
        if (strcmp(lista[atual].CPF, cpfBusca) == 0){

            int pv = obterPosicaoVazia();
            if (pv == -1){
                printf("Erro interno: sem posição vazia\n");
                return;
            }

            char userCPF[12];

            printf("Digite o CPF do novo cliente:\n");
            scanf("%s", userCPF);

            if (verificarCPF(userCPF)){
                return; // CPF duplicado
            }

            strcpy(lista[pv].CPF, userCPF);

            printf("Digite o nome da agencia:\n");
            scanf("%s", lista[pv].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%i", &lista[pv].conta); // ⚡ atenção: & antes do int

            printf("Digite o tipo de atendimento:\n");
            scanf("%s", lista[pv].tipoAtendimento);

            printf("Digite o nome do cliente:\n");
            scanf("%s", lista[pv].nomeCliente);

            // encadeamento
            lista[pv].anterior = atual;
            lista[pv].proximo = lista[atual].proximo;

            if(lista[atual].proximo != -1){
                lista[lista[atual].proximo].anterior = pv;
            } else {
                ultimo = pv;
            }

            lista[atual].proximo = pv;

            quantidade++;
            return;
        } 

        atual = lista[atual].proximo;
    }

    printf("CPF nao encontrado!\n");
}

void removerInicio(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    int aux = lista[primeiro].proximo;

    if(primeiro == ultimo){
        ultimo = -1;
    }

    if(lista[primeiro].proximo != -1){
        lista[lista[primeiro].proximo].anterior = -1;
    }

    lista[primeiro].proximo = -1;
    lista[primeiro].anterior = -1;

    primeiro = aux;
    clientesAtendidos++;
    quantidade--;
}
void removerFinal(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    if(primeiro == ultimo){
        // Só tinha um elemento
        strcpy(lista[ultimo].CPF, "null");
        lista[ultimo].proximo = -1;
        lista[ultimo].anterior = -1;
        primeiro = -1;
        ultimo = -1;
    } else {
        int aux = lista[ultimo].anterior;
        lista[aux].proximo = -1; // antigo penúltimo agora é último
        strcpy(lista[ultimo].CPF, "null");
        lista[ultimo].proximo = -1;
        lista[ultimo].anterior = -1;
        ultimo = aux;
    }

    quantidade--;
    clientesAtendidos++;
}
void removerCPF() {
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    char userCPF[12];
    printf("Digite o CPF do cliente para remocao:\n");
    scanf("%s", userCPF);

    int atual = primeiro;
    while(atual != -1) { 
        if(strcmp(lista[atual].CPF, userCPF) == 0) {
            printf("CPF encontrado!\n");

            // Se não for o último
            if(lista[atual].proximo != -1){
                lista[lista[atual].proximo].anterior = lista[atual].anterior;
            } else {
                // Se for o último
                ultimo = lista[atual].anterior;
            }

            // Se não for o primeiro
            if(lista[atual].anterior != -1){
                lista[lista[atual].anterior].proximo = lista[atual].proximo;
            } else {
                // Se for o primeiro
                primeiro = lista[atual].proximo;
            }

            // Limpa o nó removido (opcional: deixa “vazio”)
            strcpy(lista[atual].CPF, "null");
            lista[atual].proximo = -1;
            lista[atual].anterior = -1;
            clientesAtendidos++;
            quantidade--;
            return; 
        }
        atual = lista[atual].proximo; 
    }
    printf("CPF nao encontrado!\n");
}

void imprimirIF(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    int atual = primeiro;

    while(atual != -1) { 
        printf("CPF: %s\n", lista[atual].CPF);
        printf("Agencia: %s\n", lista[atual].agencia);
        printf("Conta: %i\n", lista[atual].conta);
        printf("Tipo de atendimento: %s\n", lista[atual].tipoAtendimento);
        printf("Nome do cliente: %s\n", lista[atual].nomeCliente);
        atual = lista[atual].proximo; 
    }
}

void imprimirFI(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }
    int atual = ultimo;
    while(atual != -1) { 
        printf("CPF: %s\n", lista[atual].CPF);
        printf("Agencia: %s\n", lista[atual].agencia);
        printf("Conta: %i\n", lista[atual].conta);
        printf("Tipo de atendimento: %s\n", lista[atual].tipoAtendimento);
        printf("Nome do cliente: %s\n", lista[atual].nomeCliente);
        atual = lista[atual].anterior; 
    }
}

void imprimirPorTipoAtendimento(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    char tipo[30];
    printf("Digite o tipo de atendimento desejado (DEPOSITO, PAGTO, SAQUE):\n");
    scanf("%s", tipo);

    int atual = primeiro;
    int achou = 0;

    while(atual != -1){
        if(strcmp(lista[atual].tipoAtendimento, tipo) == 0){
            printf("CPF: %s\n", lista[atual].CPF);
            printf("Agencia: %s\n", lista[atual].agencia);
            printf("Conta: %i\n", lista[atual].conta);
            printf("Nome do cliente: %s\n", lista[atual].nomeCliente);
            achou = 1;
        }
        atual = lista[atual].proximo;
    }

    if(!achou){
        printf("Nenhum cliente encontrado com o tipo de atendimento %s.\n", tipo);
    }
}

void pesquisarCPF(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    char userCPF[12];
    int atual = primeiro;

    printf("Digite o CPF do cliente para pesquisa:\n");
    scanf("%s", userCPF);

    while(atual != -1) { 
        if(strcmp(lista[atual].CPF, userCPF) == 0) {
            printf("CPF encontrado!\n");
            printf("CPF: %s\n", lista[atual].CPF);
            printf("Agencia: %s\n", lista[atual].agencia);
            printf("Conta: %i\n", lista[atual].conta);
            printf("Tipo de atendimento: %s\n", lista[atual].tipoAtendimento);
            printf("Nome do cliente: %s\n", lista[atual].nomeCliente);
            return;
        }
        atual = lista[atual].proximo; 
    }

    printf("CPF nao encontrado!\n");
}

int contarNumerosCliente(){
    return quantidade;
}

int numeroClientesAtendidos(){
    return clientesAtendidos;
}
int numeroIncluso(){
    return quantidade + clientesAtendidos;
}

void imprimirVizinhosCPFSimples() {
    char userCPF[12];
    scanf("%s", userCPF);

    int atual = primeiro;
    while(atual != -1) {
        if(strcmp(lista[atual].CPF, userCPF) == 0) {

            if(lista[atual].anterior != -1)
                printf("Anterior: %s\n", lista[lista[atual].anterior].CPF);
            else
                printf("Anterior: nenhum\n");

            if(lista[atual].proximo != -1)
                printf("Proximo: %s\n", lista[lista[atual].proximo].CPF);
            else
                printf("Proximo: nenhum\n");

            return;
        }
        atual = lista[atual].proximo;
    }
}

void imprimirClientesPorTipo() {
    char tipo[30];
    scanf("%s", tipo);

    int atual = primeiro;
    while(atual != -1) {
        if(strcmp(lista[atual].tipoAtendimento, tipo) == 0) {
            printf("%s\n", lista[atual].nomeCliente);
        }
        atual = lista[atual].proximo;
    }
}

void menu() {
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar cliente no inicio\n");
        printf("2. Adicionar cliente no final\n");
        printf("3. Adicionar cliente apos CPF\n");
        printf("4. Remover cliente inicio\n");
        printf("5. Remover cliente final\n");
        printf("6. Remover cliente CPF\n");
        printf("7. Imprimir clientes ->\n");
        printf("8. Imprimir clientes <-\n");
        printf("9. Imprimir clientes tipo atendimento ^\n");
        printf("10. Localizar cliente CPF\n");
        printf("11. Numero clientes na fila\n");
        printf("12. Numero clientes atendidos ^^\n");
        printf("13. Numero clientes inclusos ^^^\n");
        printf("14. Imprimir vizinhos CPF ^^^^\n");
        printf("15. Clientes por tipo de atendimento ^^^^^\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);

        if(opcao == 1) {
            adicionarInicio();
        } else if(opcao == 2) {
            adicionarFinal();
        } else if(opcao == 3) {
            adicionarAposCPF();
        } else if(opcao == 4) {
            removerInicio();
        } else if(opcao == 5) {
           removerFinal();
        } else if(opcao == 6) {
            removerCPF();
        } else if(opcao == 7) {
            imprimirIF();
        } else if(opcao == 8) {
            imprimirFI();
        } else if(opcao == 9) {
            imprimirPorTipoAtendimento();
        } else if(opcao == 10) {
            pesquisarCPF();
        } else if(opcao == 11) {
            printf("Numero de clientes na fila: %i\n", contarNumerosCliente());
        } else if(opcao == 12) {
            printf("Numero de clientes atendidos: %i\n", numeroClientesAtendidos());
        } else if(opcao == 13) {
            printf("Numero de clientes inclusos: %i\n", numeroIncluso());
        } else if(opcao == 14) {
            imprimirVizinhosCPFSimples();
        } else if(opcao == 15) {
            imprimirClientesPorTipo();
        } else if(opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while(opcao != 0);
}
int main(){
    menu();
    return 0;
}