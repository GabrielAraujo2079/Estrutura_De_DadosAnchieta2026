#include <stdio.h>
#include <string.h>
#define TAM 10

struct Balsa{
    int codigo;
    char placa[8];
    char tipo[20];
    float precoToken;

    int proximo;
    int anterior;
};
struct Balsa fila[TAM];
int primeiro;
int ultimo;
int quantidade;

int vazia(){
    if (quantidade == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int cheia(){
    if (quantidade == TAM){
        return 1;
    }
    else {
        return 0;
    }
}

void iniciarLista(){
    primeiro = -1;
    ultimo = -1;
    quantidade = 0;
    for (int i = 0; i < TAM; i++){
        fila[i].codigo = 0;
    }
}

int obterPosicaoVazia(){
    int pv = -1;

    for (int i = 0; i < TAM; i++){
        if(fila[i].codigo == 0){
            pv = i;
            break;
        }
    }
    return pv;
}

void adicionarInicio(){
    if (cheia()){
        printf("Balsa atingiu capacidade max!\n");
        return;
    }
    else {
       int pv = obterPosicaoVazia();
       printf("Digite o codigo do veiculo:\n");
       scanf("%i", &fila[pv].codigo);
       printf("Digite a placa do veiculo:\n");
       scanf("%s", fila[pv].placa);
       printf("[Moto]::[Carro]::[Pesados]\nDigite o tipo do veiculo:\n");
       scanf("%s", fila[pv].tipo);

       if(strcmp(fila[pv].tipo,"moto") == 0){
            fila[pv].precoToken = 2.50;
       }
       else if(strcmp(fila[pv].tipo,"carro") == 0) {
            fila[pv].precoToken = 5.00;
       }
       else if(strcmp(fila[pv].tipo,"pesados") == 0) {
            fila[pv].precoToken = 7.50;
       } 
    
        if(quantidade == 0){
            primeiro = pv;
            ultimo = pv;
            fila[pv].proximo = -1;
            fila[pv].anterior = -1;
        }
        else {
            fila[primeiro].anterior = pv;
            fila[pv].proximo = primeiro;
            fila[pv].anterior = -1;
            primeiro = pv;

        }
        quantidade ++;
    }
}
void adicionarFinal(){
    if (cheia()){
        printf("Balsa atingiu capacidade max!\n");
        return;
    }
    else {
        int pv = obterPosicaoVazia();
        printf("Digite o codigo do veiculo:\n");
        scanf("%i", &fila[pv].codigo);
        printf("Digite a placa do veiculo:\n");
        scanf("%s", fila[pv].placa);
        printf("[Moto]::[Carro]::[Pesados]\nDigite o tipo do veiculo:\n");
        scanf("%s", fila[pv].tipo);

        if(strcmp(fila[pv].tipo,"moto") == 0){
            fila[pv].precoToken = 2.50;
        }
        else if(strcmp(fila[pv].tipo,"carro") == 0) {
            fila[pv].precoToken = 5.00;
        }
        else if(strcmp(fila[pv].tipo,"pesados") == 0) {
            fila[pv].precoToken = 7.50;
        } 
    
        if(quantidade == 0){
            primeiro = pv;
            ultimo = pv;
            fila[pv].proximo = -1;
            fila[pv].anterior = -1;
        }
        else {
            fila[ultimo].proximo = pv;
            fila[pv].anterior = ultimo;
            fila[pv].proximo = -1;
            ultimo = pv;
        }
        quantidade ++;
    }
}
void adicionarAposCodigo(){
    if (cheia()){
        printf("Balsa atingiu capacidade max!\n");
        return;
    }

    int userCodigo;
    printf("Digite o codigo do seu antecessor\n");
    scanf("%i", &userCodigo);

    int atual = primeiro;
    
    while(atual != -1){
        
        if(fila[atual].codigo == userCodigo){
            int pv = obterPosicaoVazia();
            printf("Digite o codigo do veiculo:\n");
            scanf("%i", &fila[pv].codigo);
            printf("Digite a placa do veiculo:\n");
            scanf("%s", fila[pv].placa);
            printf("[Moto]::[Carro]::[Pesados]\nDigite o tipo do veiculo:\n");
            scanf("%s", fila[pv].tipo);

            if(strcmp(fila[pv].tipo,"moto") == 0){
                fila[pv].precoToken = 2.50;
            }
            else if(strcmp(fila[pv].tipo,"carro") == 0) {
                fila[pv].precoToken = 5.00;
            }
            else if(strcmp(fila[pv].tipo,"pesados") == 0) {
                fila[pv].precoToken = 7.50;
            } 
            
            fila[pv].anterior = atual;
            fila[pv].proximo = fila[atual].proximo;
            
            if (fila[atual].proximo != -1){
                fila[fila[atual].proximo].anterior = pv;
            }else {
                ultimo = pv;
            }

            fila[atual].proximo = pv;
            quantidade++;
            return;
        }

        atual = fila[atual].proximo;
    }
    printf("Codigo nao encontrado!\n");
    return;
}
void removerInicio(){
    if (vazia()){
        printf("Nao ha niguem para remover...\n");
        return;
    }
    int aux;
    if (primeiro == ultimo){
        fila[primeiro].codigo = 0;
        ultimo = -1;
        primeiro = -1;
        quantidade--;
        return;     
    }
    aux = fila[primeiro].proximo;
    fila[primeiro].codigo = 0;
    fila[primeiro].proximo = -1;
    fila[aux].anterior = -1;

    primeiro = aux;
    quantidade--;
}
void removerUltimo(){
    if (vazia()){
        printf("Nao ha niguem para remover...\n");
        return;
    }
    int aux;
    if (primeiro == ultimo){
        fila[primeiro].codigo = 0;
        ultimo = -1;
        primeiro = -1;
        quantidade--;
        return;     
    }
    aux = fila[ultimo].anterior;
    fila[ultimo].codigo = 0;
    fila[ultimo].anterior = -1;
    fila[aux].proximo = -1;
    ultimo = aux;

    quantidade--;
}
void removerPorCodigo(){
    if (vazia()){
        printf("Nao ha niguem para remover...\n");
        return;
    }
    
    int userCodigo;
    printf("Digite o codigo que deseja remover\n");
    scanf("%i", &userCodigo);

    int atual = primeiro, aux;
    
    while(atual != -1){
        
        if(fila[atual].codigo == userCodigo){
            if (primeiro == ultimo){
                fila[primeiro].codigo = 0;
                ultimo = -1;
                primeiro = -1;
                quantidade--;
                return;     
            }
            if(fila[atual].anterior != -1){
                aux = fila[atual].anterior;
                fila[aux].proximo = fila[atual].proximo;
                fila[fila[atual].proximo].anterior = aux;
                fila[atual].proximo = -1;
                fila[atual].anterior = -1;
            
            quantidade--;
            return;
            }
            
            fila[aux].proximo = fila[atual].proximo;
            
            fila[fila[atual].proximo].anterior = aux;
            fila[atual].proximo = -1;
            fila[atual].anterior = -1;
            
            quantidade--;
            return;
        }
        atual = fila[atual].proximo;
    }
    
    printf("Codigo nao encontrado!\n");
    return;
}




