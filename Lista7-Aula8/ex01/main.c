/*Com base nas informações abaixo, crie uma aplicação console que deverá implementar os conceitos de uma Lista Duplamente Ligada (LDL), onde cada elemento contem uma referência para o anterior e o proxímo, 
note que trata-se de um sistema de livros. 
Utilize para a implementação a criação de métodos (Tipos de Dados Abstratos - TDA) para resolução de cada operação.
No exemplo abaixo o código do livro é o indentificador único de cada livro e a classificação corresponde a Infantil, Adulto, Suspense, Romance, etc. Poderá ser utilizado um valor textual ou numérico para controle.

A) Estrutura do elemento (TDE).
Livro {
  + codigo: Inteiro
  + nome: Texto
  + classificacao: Texto ou Inteiro
  + preco: Numerico

  + anterior: Livro
  + proximo: Livro}

B) Menu.
b.1 Adicionar Inicio (Livro);
b.2 Adicionar Final (Livro);
b.3 Adicionar Após Código (Codigo, Livro); //Adiciona o novo livro após o livro que contiver o código informado. 
b.4 Adicionar Antes Código (Codigo, Livro); //Idem ao item b.3, no entanto adicioa antes.
b.5 Remover Inicio
b.6 Remover Final
b.7 Remover Código (Codigo) //Remove o livro que contiver o código informado. 
b.8 Pesquisar Código (Código);
b.9 Imprimir IF; //Imprime todos os livros a partir do primeiro até o ultimo.
b.10 Imprimir FI; //Imprime todos os livros a partir do final para o início;
b.11 Contar Número Livros;
b.12 Maior Preço;
b.13 Média Preços;
b.14 Contar Número Classificação(Classificacao); //Conta o número de livros existentes de uma determinada classficação informada pelo usuário;
b.15 Imprimir Número por Classificação; //Neste caso, deverá percorrer a estrutura, verificar quais classificações existem, e depois exibir o número de livros de cada 
classificação, 
note que o usuário não informa a classifação desejada.
b.16 Imprimir Soma por Classificação; //Idem ao item b.15.
b.17 Remover Livros Classificação (Classificação); //Deverá remover todos os livros de uma determianda classificação informada pelo usuário;
b.18 Classificação com maior Número de livros; //Deverá exbir a classificação que contem a maior quantidade de livros;
b.19 Imprimir ordenados por Código; //Deverá exibir todos  os livros ordenados a partir de seus códigos. Para codificar 
a solicitação existem várias técnicas, desde ordenar a lista propriamente dito, como criar uma lista auxiliar e adicionar os elementos da lista principal nesta lista ordenada e/ou até mesmo criar um vetor e adicionar os valores e ordenar no vetor e exibi-lo.*/


#include <stdio.h>
#include <string.h>
#define TAM 10

struct Livro {
    int codigo;
    char nome[30];
    char classificacao[30];
    float preco;

    int anterior;
    int proximo;
};
struct Livro lista[TAM];
int primeiro;
int ultimo;
int quantidade;

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

    for (int i = 0; i< TAM; i++){
        lista[i].codigo = 0;
        strcpy(lista[i].nome, "null");
    }
}

int obterPosicaoVazia(){
    int pv = -1;

    for (int i = 0; i < TAM; i++){
        if (lista[i].codigo == 0){
            pv = i;
            break;
        }
    }
    return pv;
}

void adicionarInicio(){
    int pv;

    if(cheia() == 1){
        printf("Lista cheia!\n");
    }else {
        pv = obterPosicaoVazia();
    
        printf("Digite o codigo:\n");
        scanf("%i", &lista[pv].codigo);
        printf("Digite o nome: \n");
        scanf("%s", lista[pv].nome);
        printf("Digite a classificacao\n");
        scanf("%s", lista[pv].classificacao);
        printf("Digite o preco do livro: \n");
        scanf("%f", &lista[pv].preco);
    
        if (quantidade == 0) {
            primeiro = pv;
            ultimo = pv;
            lista[pv].anterior = -1;
            lista[pv].proximo = -1;
        } else {
            //Essa linha diz o primeiro (antigo) agora tem um anterior (novo)
            lista[primeiro].anterior = pv;
            
            //E essa linha diz o novo agora tem um proximo (antigo primeiro)
            lista[pv].proximo = primeiro;
            
            //E como ele e o primeiro e impossivel ele ter alguem antes dele
            lista[pv].anterior = -1;
            
            //Primeiro (novo) vira realmente o novo primeiro:
            primeiro = pv;
        }
        
        quantidade++;		
    }
}

void adicionarFinal() {
    int pv;
    
    if (cheia() == 1) {
        printf("Lista cheia!\n");
    } else {
        pv = obterPosicaoVazia();
        
        printf("Digite o codigo:\n");
        scanf("%i", &lista[pv].codigo);
        printf("Digite o nome: \n");
        scanf("%s", lista[pv].nome);
        printf("Digite a classificacao\n");
        scanf("%s", lista[pv].classificacao);
        printf("Digite o preco do livro: \n");
        scanf("%f", &lista[pv].preco);
        
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
}

void adicionarAposCodigo(){
    if (cheia() == 1) {
        printf("Lista cheia!\n");
    } else {
        int userCodigo = 0, atual = 0;
        printf("Digite o codigo antecessor ao seu novo livro!\n");
        scanf("%i", &userCodigo);
        atual = primeiro;
        
        while(atual != -1){
            if (lista[atual].codigo == userCodigo){
                int pv = obterPosicaoVazia();
                
                printf("Antecessor encontrado!\n");
                printf("Digite o codigo:\n");
                scanf("%i", &lista[pv].codigo);
                printf("Digite o nome: \n");
                scanf("%s", lista[pv].nome);
                printf("Digite a classificacao\n");
                scanf("%s", lista[pv].classificacao);
                printf("Digite o preco do livro: \n");
                scanf("%f", &lista[pv].preco);
             
                // novo recebe seu Antecessor
                lista[pv].anterior = atual;

                // novo recebe do Antecessor o seu antigo proximo
                lista[pv].proximo = lista[atual].proximo;

                if(lista[atual].proximo != -1){
                    // "avisa" pro antigo proximo que o anterior agora e o novo livro
                    lista[lista[atual].proximo].anterior = pv;
                } else {
                    // se nao tinha proximo, entao o novo vira o ultimo
                    ultimo = pv;
                }

                // antigo agora aponta pro novo
                lista[atual].proximo = pv;

                quantidade++;
                return;
            } 

            atual = lista[atual].proximo;
        }

        printf("Nada encontrado!\n");
    }
}

void adicionarAntesCodigo(){
    if (cheia() == 1) {
        printf("Lista cheia!\n");
    } else {
        int userCodigo = 0, atual = 0;
        printf("Digite o codigo do sucessor ao seu novo livro!\n");
        scanf("%i", &userCodigo);
        atual = primeiro;
        
        while(atual != -1){
            if (lista[atual].codigo == userCodigo){
                int pv = obterPosicaoVazia();
                
                printf("Sucessor encontrado!\n");
                printf("Digite o codigo:\n");
                scanf("%i", &lista[pv].codigo);
                printf("Digite o nome: \n");
                scanf("%s", lista[pv].nome);
                printf("Digite a classificacao\n");
                scanf("%s", lista[pv].classificacao);
                printf("Digite o preco do livro: \n");
                scanf("%f", &lista[pv].preco);
            
                lista[pv].proximo = atual;
                lista[pv].anterior = lista[atual].anterior;

                if(lista[atual].anterior != -1){
                    //"avisa" pro antigo anterior que o seu proximo mudou para o novo livro 
                    lista[lista[atual].anterior].proximo = pv;
                }else {
                    // Se nao houver anterior, significa que o novo elemento vai ser o primeiro
                    primeiro = pv;
                }
                lista[atual].anterior = pv;
                quantidade++;
                return;
            }
            atual = lista[atual].proximo;
        }

        // CORRECAO: estava fora do else, sendo impresso sempre apos qualquer insercao
        printf("Nada encontrado!\n");
    }
}

void removerInicio(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }else {
        int aux = lista[primeiro].proximo;
        if (primeiro == ultimo){
            ultimo = -1;
        }
        if (lista[primeiro].proximo != -1 ){
            lista[lista[primeiro].proximo].anterior = -1;
        }
        quantidade--;
        lista[primeiro].codigo = 0;
        lista[primeiro].proximo = -1;
        // CORRECAO: limpa o anterior tambem para nao deixar lixo no no removido
        lista[primeiro].anterior = -1;
        primeiro = aux;
    }
}

void removerFinal(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    } else {
        if (primeiro == ultimo) {
            // So tinha um elemento
            lista[ultimo].codigo = 0;
            lista[ultimo].proximo = -1;
            lista[ultimo].anterior = -1;
            primeiro = -1;
            ultimo = -1;
        } else {
            int aux = lista[ultimo].anterior;
            lista[lista[ultimo].anterior].proximo = -1;
            lista[ultimo].codigo = 0;
            lista[ultimo].proximo = -1;
            lista[ultimo].anterior = -1;
            ultimo = aux;
        }
        quantidade--;
    }
}

void removerCodigo() {
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    int userCodigo, atual;
    printf("Digite o codigo do livro para remocao!\n");
    scanf("%i", &userCodigo);

    atual = primeiro; 
    while(atual != -1) { 
        if(lista[atual].codigo == userCodigo) {
            printf("Codigo encontrado!\n");

            // Se o livro removido nao e o ultimo
            // Faz o proximo do livro apontar para o anterior do removido
            if(lista[atual].proximo != -1){
                lista[lista[atual].proximo].anterior = lista[atual].anterior;
            } else {
                // Se for o ultimo da lista, atualiza o indice do ultimo
                ultimo = lista[atual].anterior;
            }

            // Se o livro removido nao e o primeiro
            // Faz o anterior do livro apontar para o proximo do removido
            if(lista[atual].anterior != -1){
                lista[lista[atual].anterior].proximo = lista[atual].proximo;
            } else {
                // Se for o primeiro da lista, atualiza o indice do primeiro
                primeiro = lista[atual].proximo;
            }

            // Limpa o livro removido 
            lista[atual].codigo = 0;
            lista[atual].proximo = -1;
            lista[atual].anterior = -1;
            quantidade--;
            return; 
        }
        atual = lista[atual].proximo; 
    }
    printf("Nada encontrado!\n");
}

void pesquisarCodigo(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }
    int userCodigo, atual = primeiro;
    printf("Digite o codigo do livro para pesquisa!\n");
    scanf("%i", &userCodigo);
    while(atual != -1) { 
        if(lista[atual].codigo == userCodigo) {
            printf("Codigo encontrado!\n");
            printf("Codigo: %i\n", lista[atual].codigo);
            printf("Nome: %s\n", lista[atual].nome);
            printf("Classificacao: %s\n", lista[atual].classificacao);
            printf("preco: %.2f\n", lista[atual].preco);
            return;
        }
        atual = lista[atual].proximo; 
    }
    printf("Nada encontrado!\n");
}

void imprimirIF(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }
    int atual = primeiro;
    
    while(atual != -1) { 
        printf("Codigo: %i\n", lista[atual].codigo);
        printf("Nome: %s\n", lista[atual].nome);
        printf("Classificacao: %s\n", lista[atual].classificacao);
        printf("preco: %.2f\n", lista[atual].preco);
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
        printf("Codigo: %i\n", lista[atual].codigo);
        printf("Nome: %s\n", lista[atual].nome);
        printf("Classificacao: %s\n", lista[atual].classificacao);
        printf("preco: %.2f\n", lista[atual].preco);
        atual = lista[atual].anterior; 
    }
}

int contarNumeroLivros(){
    return quantidade;
}

void maiorPreco(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }   
    int atual = primeiro;
    float maior = lista[primeiro].preco;
    
    while(atual != -1) {
        if (lista[atual].preco > maior){
            maior = lista[atual].preco;
        }
        atual = lista[atual].proximo; 
    }
    printf("O maior preco encontrado foi de %.2f\n", maior);
}

void mediaPrecos(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }   
    int atual = primeiro;
    float soma = 0;
    
    while(atual != -1) {
        soma += lista[atual].preco;
        atual = lista[atual].proximo; 
    }
    printf("A media de precos foi de %.2f\n", soma / quantidade);
}

// CORRECAO: nome padronizado sem acento (era contarNumeroClassificacao com acento no a)
void contarNumeroClassificacao(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    }

    char userInput[30];
    printf("Digite a classificacao que deseja contar!\n");
    scanf("%s", userInput);

    int atual = primeiro, contaClass = 0;
     
    while(atual != -1) {
        if(strcmp(lista[atual].classificacao, userInput) == 0){
            contaClass++;
        }
        atual = lista[atual].proximo; 
    }
    printf("A quantidade de livros na classificacao buscada e de aprox %i\n", contaClass);
}

void numeroPorClassificacao(){
    if(vazia()){
        printf("Lista vazia!\n");
        return;
    }

    char classificacoes[TAM][30];
    int totalClass = 0;

    int atual = primeiro;

    //  1 loop: guardar classificacoes sem repetir
    while(atual != -1){
        int encontrou = 0;

        for(int i = 0; i < totalClass; i++){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                encontrou = 1;
                break;
            }
        }

        if(!encontrou){
            strcpy(classificacoes[totalClass], lista[atual].classificacao);
            totalClass++;
        }

        atual = lista[atual].proximo;
    }

    // 2 loop: contar cada classificacao
    for(int i = 0; i < totalClass; i++){
        int contador = 0;
        atual = primeiro;

        while(atual != -1){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                contador++;
            }
            atual = lista[atual].proximo;
        }
        printf("Classificacao: %s | Quantidade: %i\n", classificacoes[i], contador);
    }
}

// CORRECAO: nome padronizado com P maiusculo (era somaporClassificacao, menu chamava somaPorClassificacao)
void somaPorClassificacao(){
    if(vazia()){
        printf("Lista vazia!\n");
        return;
    }

    char classificacoes[TAM][30];
    int totalClass = 0;

    int atual = primeiro;

    //  1 loop: guardar classificacoes sem repetir
    while(atual != -1){
        int encontrou = 0;

        for(int i = 0; i < totalClass; i++){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                encontrou = 1;
                break;
            }
        }

        if(!encontrou){
            strcpy(classificacoes[totalClass], lista[atual].classificacao);
            totalClass++;
        }

        atual = lista[atual].proximo;
    }

    // 2 loop: somar preco de cada classificacao
    for(int i = 0; i < totalClass; i++){
        float soma = 0;
        atual = primeiro;

        while(atual != -1){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                soma += lista[atual].preco;
            }
            atual = lista[atual].proximo;
        }
        printf("Classificacao: %s | soma: %.2f\n", classificacoes[i], soma);
    }
}

void removerLivrosClassificacao(){
    if(vazia()){
        printf("Lista vazia!\n");
        return;
    }

    char userInput[30];
    printf("Digite a classificacao que deseja remover!\n");
    scanf("%s", userInput);

    int atual = primeiro;

    while(atual != -1){
        int prox = lista[atual].proximo; // guarda antes

        if(strcmp(lista[atual].classificacao, userInput) == 0){
            if(lista[atual].proximo != -1){
                lista[lista[atual].proximo].anterior = lista[atual].anterior;
            } else {
                ultimo = lista[atual].anterior;
            }

            if(lista[atual].anterior != -1){
                lista[lista[atual].anterior].proximo = lista[atual].proximo;
            } else {
                primeiro = lista[atual].proximo;
            }

            lista[atual].codigo = 0;
            lista[atual].proximo = -1;
            lista[atual].anterior = -1;
            quantidade--;
        }

        atual = prox; // usa o salvo
    }
}

// CORRECAO: nome padronizado com c minusculo (era ClassificacaoComMaiorNumero com C maiusculo)
void classificacaoComMaiorNumero(){
    if(vazia()){
        printf("Lista vazia!\n");
        return;
    }

    char classificacoes[TAM][30];
    int totalClass = 0;

    int atual = primeiro;

    // pegar classificacoes unicas
    while(atual != -1){
        int encontrou = 0;

        for(int i = 0; i < totalClass; i++){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                encontrou = 1;
                break;
            }
        }

        if(!encontrou){
            strcpy(classificacoes[totalClass], lista[atual].classificacao);
            totalClass++;
        }

        atual = lista[atual].proximo;
    }

    // achar maior
    int maior = -1;
    char classMaior[30];

    for(int i = 0; i < totalClass; i++){
        int contador = 0;
        atual = primeiro;

        while(atual != -1){
            if(strcmp(lista[atual].classificacao, classificacoes[i]) == 0){
                contador++;
            }
            atual = lista[atual].proximo;
        }

        if(contador > maior){
            maior = contador;
            strcpy(classMaior, classificacoes[i]);
        }
    }

    printf("Classificacao com maior numero: %s (%i livros)\n", classMaior, maior);
}

void imprimirOrdenadoPorCodigo(){
    if(vazia()){
        printf("Lista vazia!\n");
        return;
    }

    int indices[TAM];
    int n = 0;

    int atual = primeiro;

    // guardar indices validos
    while(atual != -1){
        indices[n++] = atual;
        atual = lista[atual].proximo;
    }

    // ordenar 
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(lista[indices[j]].codigo > lista[indices[j+1]].codigo){
                int temp = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = temp;
            }
        }
    }

    // imprimir ordenado
    for(int i = 0; i < n; i++){
        int idx = indices[i];
        printf("Codigo: %i\n", lista[idx].codigo);
        printf("Nome: %s\n", lista[idx].nome);
        printf("Classificacao: %s\n", lista[idx].classificacao);
        printf("Preco: %.2f\n\n", lista[idx].preco);
    }
}

void menu() {
    int opc = 0;
    
    do {
        printf("\n:: LIVROS DUPLAMENTE LIGADOS ::\n");
        printf("1.  Adicionar Inicio\n");
        printf("2.  Adicionar Final\n");
        printf("3.  Adicionar Apos Codigo\n");
        printf("4.  Adicionar Antes Codigo\n");
        printf("5.  Remover Inicio\n");
        printf("6.  Remover Final\n");
        printf("7.  Remover Codigo\n");
        printf("8.  Pesquisar Codigo\n");
        printf("9.  Imprimir Inicio -> Final\n");
        printf("10. Imprimir Final -> Inicio\n");
        printf("11. Contar Numero de Livros\n");
        printf("12. Maior Preco\n");
        printf("13. Media de Precos\n");
        printf("14. Contar por Classificacao\n");
        printf("15. Imprimir Numero por Classificacao\n");
        printf("16. Imprimir Soma por Classificacao\n");
        printf("17. Remover por Classificacao\n");
        printf("18. Classificacao com mais livros\n");
        printf("19. Imprimir Ordenado por Codigo\n");
        printf("00. Sair\n");
        
        scanf("%i", &opc);
        
        if (opc == 1) {
            adicionarInicio();
        } else if (opc == 2) {
            adicionarFinal();
        } else if (opc == 3) {
            adicionarAposCodigo();
        } else if (opc == 4) {
            adicionarAntesCodigo();
        } else if (opc == 5) {
            removerInicio();
        } else if (opc == 6) {
            removerFinal();
        } else if (opc == 7) {
            removerCodigo();
        } else if (opc == 8) {
            pesquisarCodigo();
        } else if (opc == 9) {
            imprimirIF();
        } else if (opc == 10) {
            imprimirFI();
        } else if (opc == 11) {
            printf("A quantidade de livros e de %i\n", contarNumeroLivros());
        } else if (opc == 12) {
            maiorPreco();
        } else if (opc == 13) {
            mediaPrecos();
        } else if (opc == 14) {
            contarNumeroClassificacao();
        } else if (opc == 15) {
            numeroPorClassificacao();
        } else if (opc == 16) {
            somaPorClassificacao();
        } else if (opc == 17) {
            removerLivrosClassificacao();
        } else if (opc == 18) {
            classificacaoComMaiorNumero();
        } else if (opc == 19) {
            imprimirOrdenadoPorCodigo();
        } else if (opc == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }
        
    } while (opc != 0);
}

int main(){
    iniciarLista();
    menu();
    return 0;
}





