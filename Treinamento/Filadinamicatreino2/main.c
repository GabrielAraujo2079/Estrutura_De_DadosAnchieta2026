#include <stdio.h>
#include <string.h>
#define TAM 5
struct Balsa{
    int codigo;
    char placa[7];
    char tipo[20];
    float token;

    int proximo;
    int anterior;
};
struct Balsa fila[TAM];
int quantidade;
int primeiro = -1;
int ultimo = -1;

int vazia(){
    if (quantidade == 0){
        return 1;
    }
    else {
        return 0;
    }
}
int cheia(){
    if (quantidade == TAM){
        return 1;
    }
    else{
        return 0;
    }
}
void iniciarLista(){
    primeiro = -1;
    ultimo = -1;
    quantidade = 0;

    for(int i = 0; i < TAM; i++){
        fila[i].codigo = 0;
        fila[i].token = 0;
    }
}

int obterPosicaoVazia(){
    int pv = -1;

    for(int i = 0; i < TAM; i++){
        if(fila[i].codigo == 0){
            pv = i;
            break;
        }
    }
    return pv;
}

void adicionarInicio(){
    if(cheia()){
        printf("FILA CHEIA!\n");
        return;
    }
    else {
        int pv = obterPosicaoVazia();
        
        printf("Digite o codigo:\n");
        scanf("%i", &fila[pv].codigo);
        printf("Digite a placa:\n");
        scanf("%s", fila[pv].placa);
        printf("Digite o tipo de veiculo [moto] | [carro] | [pesado]\n");
        scanf("%s", fila[pv].tipo);
        
        //Validação do tipo de veiculo
        if (strcmp(fila[pv].tipo, "moto") == 0){
            fila[pv].token = 2.50;
        }
        else if (strcmp(fila[pv].tipo, "carro") == 0){
            fila[pv].token = 5.00;
        }
        else if (strcmp(fila[pv].tipo, "pesado") == 0){
            fila[pv].token = 7.50;
        }
        else {
            printf("Tipo invalido!\n");
            fila[pv].codigo = 0;
            return;
        }

        if(quantidade == 0){
            primeiro = pv;
            ultimo = pv;
            fila[pv].anterior = -1;
            fila[pv].proximo = -1;
        }else {
            fila[pv].proximo = primeiro;
            fila[primeiro].anterior = pv;
            fila[pv].anterior = -1;
            primeiro = pv;
        }
        quantidade ++;

    }
}
void adicionarFinal(){
    if (cheia()){
        printf("FILA CHEIA!\n");
        return;
    }
    else {
        int pv = obterPosicaoVazia();
        
        printf("Digite o codigo:\n");
        scanf("%i", &fila[pv].codigo);
        printf("Digite a placa:\n");
        scanf("%s", fila[pv].placa);
        printf("Digite o tipo de veiculo [moto] | [carro] | [pesado]\n");
        scanf("%s", fila[pv].tipo);
        
        //Validação do tipo de veiculo
        if (strcmp(fila[pv].tipo, "moto") == 0){
            fila[pv].token = 2.50;
        }
        else if (strcmp(fila[pv].tipo, "carro") == 0){
            fila[pv].token = 5.00;
        }
        else if (strcmp(fila[pv].tipo, "pesado") == 0){
            fila[pv].token = 7.50;
        }
        else {
            printf("Tipo invalido!\n");
            fila[pv].codigo = 0;
            return;
        }

        if(quantidade == 0){
            primeiro = pv;
            ultimo = pv;
            fila[pv].anterior = -1;
            fila[pv].proximo = -1;
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

int pesquisarCodigo(){
    
        int aux = primeiro, encontrado = -1, userCodigo = 0;

        printf("Digite o codigo que deseja encontrar:\n");
        scanf("%i", &userCodigo);

        while(aux != -1){
            if (userCodigo == fila[aux].codigo){
                encontrado = aux;
                return encontrado;
            }

            aux = fila[aux].proximo;    
        }
        return -1;  
}

void adicionarDpsCodigo(){
    if(cheia()){
        printf("FILA CHEIA\n");
        return;
    }
    if(vazia()){
        printf("FILA VAZIA\n");
        return;
    }

    int pl = pesquisarCodigo();
    if(pl == -1){
        printf("CODIGO NAO ENCONTRADO\n");
        return;
    }
    int pv = obterPosicaoVazia();
        
    printf("Digite o codigo:\n");
    scanf("%i", &fila[pv].codigo);
    printf("Digite a placa:\n");
    scanf("%s", fila[pv].placa);
    printf("Digite o tipo de veiculo [moto] | [carro] | [pesado]\n");
    scanf("%s", fila[pv].tipo);
        
    //Validação do tipo de veiculo
    if (strcmp(fila[pv].tipo, "moto") == 0){
        fila[pv].token = 2.50;
    }
    else if (strcmp(fila[pv].tipo, "carro") == 0){
        fila[pv].token = 5.00;
    }
    else if (strcmp(fila[pv].tipo, "pesado") == 0){
        fila[pv].token = 7.50;
    }
    else {
        printf("Tipo invalido!\n");
        fila[pv].codigo = 0;
        return;
    }

    if (fila[pl].proximo == -1){
        fila[pv].proximo = -1;
        fila[pv].anterior = pl;
        fila[pl].proximo = pv;
        ultimo = pv;
    }
    else {
        int aux = fila[pl].proximo;
        fila[pl].proximo = pv;
        fila[pv].anterior = pl;
        fila[pv].proximo = aux;
        fila[aux].anterior = pv;

    }
    quantidade++;
}
void removerInicio(){
    if(vazia()){
        printf("FILA VAZIA\n");
        return;
    }
    if(quantidade == 1){
        fila[primeiro].codigo = 0;
        primeiro = -1;
        ultimo = -1;
    }
    else{
        int aux = fila[primeiro].proximo;
        fila[primeiro].codigo = 0;
        fila[aux].anterior = -1;
        fila[primeiro].proximo = -1;
        primeiro = aux;
    }
    quantidade--;
}
int main(){
    iniciarLista();

}