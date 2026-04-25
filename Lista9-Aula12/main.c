/*LISTA EXERCÍCIOS FILAS DINÂMICAS
EXERCÍCIOS
:: EDORD01 ::..
Baseado no conteúdo de Ordenação de Dados e utilizando algum dos arquivos .TXT que foram liberados, crie uma aplicação que contenha contenha as opções de 
ordenação abaixo, a aplicação deverá: 
a) Ler o arquivo .txt; 
b) Realize cada uma das diferentes ordenações; 
c) Calcule e exiba o tempo de ordenação de cada um dos algoritmos de ordenação (lembre-se de que cada ordenação deverá ser realizada sobre os dados desordenados);
d) Compare e exiba qual é o algoritmo mais e menos performático. 
:: ALGORITMOS DE ORDENAÇÃO ::..

0. Carregar dados;
1. Exibir dados (carregados);
2. Exibir dados (carregados);
3. Ordenar Buble;
4. Ordenar Heap;
5. Ordenar Insertion;
6. Ordenar Merge;
7. Ordenar Selection;
8. Ordenar Shell;
9. Ordenar Quick;
10. Exibir tempos ordenação;
11. Avaliar melhor/pior ordenação;
19. Sair*/

#define MAX 70000
#include <stdio.h>

unsigned long long lista[MAX];
int quantidade = 0;

void carregar() {
    FILE *arq;
    int i = 0;

    arq = fopen("AC70000.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (i < MAX && fscanf(arq, "%llu", &lista[i]) == 1) {
        i++;
    }

    fclose(arq);
    quantidade = i;

    printf("Total encontrado: %d\n", quantidade);
}

void exibirDados() {
    for (int i = 0; i < quantidade; i++) {
        printf("Posicao: [%d] - Codigo: %llu\n", i, lista[i]);
    }
}
void ordenarBubble(){
    int aux;
    for(int i = 0; i < quantidade - 1 ; i++){
        for(int j = 0; j < quantidade - 1 ; j ++){
            if(lista[j] > lista[j + 1]){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}
void heapify(int filhosController, int indice){
    //Indice e o numero Atual do vetor (Posição)
    int maior = indice;
    //Pega o filho da esquerda fazendo uma conta simples posicão vezes o indice + 1
    int esq = 2 * indice + 1;
    //Mesma coisa que a esquerda, mas a direita ou seja + 2
    int dir = 2 * indice + 2;

    /*Verifica se o NUMERO a Esquerda e maior doq o maior numero ate o momento
    e ainda previne que o filho realmente exista (esq < filhosController )*/
    if (esq < filhosController && lista[esq] > lista[maior]){
        //AQUI Ò trocando o bagulho lá (Pelo numero maior)
        maior = esq;
    }
    
    /*Mesma coisa controla pra não estourar posição usando o controller e troca o numero da
    variavel maior caso o numero a Direita seja maior */
    if (dir < filhosController && lista[dir] > lista[maior]){
        maior = dir;
    }
    //se o indice for diferente de maior, quer dizer que a lista andou pó
    if (maior != indice) {
        //Temp e uma variavel feita pra ajudar no Troca Troca (são paulo estuda contratação)
                                    //recebe o indice ou seja a posição atual das passadas
        unsigned long long temp = lista[indice];
        //posição atual troca com maior
        lista[indice] = lista[maior];
        //maior troca com a posição atual
        lista[maior] = temp;
        //Conserta possiveis erros depois da modificação do topo
        heapify(filhosController, maior);
    }
}   
void heapSort() {
    int i;

   // Monta o heap garantindo que o maior sempre fique acima dos filhos
    //Começa do último elemento com filhos e vai até a raiz
    for (i = quantidade / 2 - 1; i >= 0; i--) {
    /*
    Para o índice atual:
    - calcula filho esquerdo e direito
    - compara valores
    - troca se necessário
    - ajusta a estrutura descendo na árvore até ficar consistente
    */
        heapify(quantidade, i);
    }

    // vai do ultimo elemento ate o numero 1 da lista (ou seja o segundo entre os primeiros)
    for (i = quantidade - 1; i > 0; i--) {
        //pega o primeiro valor da lista (o Maior)
        unsigned long long temp = lista[0];
        //Joga ele la pro final kkkkkkkkkk
        lista[0] = lista[i];
        //o final agora fica com o antigo primeiro
        lista[i] = temp;
        //ignora os ja ordenados(os maiores que foram pro final)
        //tbm ajeita tudinho pra não quebrar
        heapify(i, 0); 
    }
}
void menu(){
    int opc = -1;

    do{
        printf("0. Carregar\n");
        printf("1. Exibir\n");
        printf("2. Ordenar bubble\n");
        printf("3. Ordenar Heap;\n");
        printf("4. Ordenar Insertion;\n");
        printf("5. Ordenar Merge;\n");
        printf("6. Ordenar Selection;\n");
        printf("7. Ordenar Shell;\n");
        printf("8. Ordenar Quick;\n");
        printf("9. Exibir tempos ordenação;\n");
        printf("10. Avaliar melhor/pior ordenação;\n");
        printf("19. Sair\n");
        printf("OQue deseja fazer:\n");
        
        scanf("%d", &opc);


        if(opc == 0){

        }
        else if (opc == 1){

        }
        else if (opc == 2){
            
        }
        else if (opc == 3){
            
        }
        else if (opc == 4){
            
        }
        else if (opc == 5){
            
        }
        else if (opc == 6){    
        }
        else if (opc == 7){
            
        }
        else if (opc == 8){
            
        }
        else if (opc == 9){
            
        }
        else if (opc == 10){
            
        }
    }while(opc != 19);
}
int main(){
    menu();
    return 0;
}