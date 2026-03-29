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

typedef struct Livro{
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
            // o novo elemento agora tem como anterior o antigo último
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

void AdicionarAposCodigo(){
    if (cheia() == 1) {
		printf("Lista cheia!\n");
	}else {
    
        int userCodigo = 0, atual = 0;
        printf("Digite o codigo antescessor ao seu novo livro!\n");
        scanf("%i", &userCodigo);
        atual = primeiro;
        
        while(atual != -1){
            
        
            if (lista[atual].codigo == userCodigo){
                int pv = obterPosicaoVazia();
                
                printf("Antescessor encontrado!\n");
                printf("Digite o codigo:\n");
                scanf("%i", &lista[pv].codigo);
                printf("Digite o nome: \n");
                scanf("%s", lista[pv].nome);
                printf("Digite a classificacao\n");
                scanf("%s", lista[pv].classificacao);
                printf("Digite o preco do livro: \n");
                scanf("%f", &lista[pv].preco);
             
                
                //novo recebe seu Antescessor
                lista[pv].anterior = atual;
                //novo recebe seu do Antescessor o seu antigo proximo
                lista[pv].proximo = lista[atual].proximo;
                
                if(lista[atual].proximo != -1){
                    //“avisa” pro antigo próximo que o seu anterior mudou para o novo livro | passando o proximo do antigo livro como indice!
                    lista[lista[atual].proximo].anterior = pv;
                }
                lista[atual].proximo = pv;
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
	}else {
    
        int userCodigo = 0, atual = 0;
        printf("Digite o codigo do sucessor ao seu novo livro!\n");
        scanf("%i", &userCodigo);
        atual = primeiro;
        
        while(atual != -1){
            
        
            if (lista[atual].codigo == userCodigo){
                int pv = obterPosicaoVazia();
                
                printf("Antescessor encontrado!\n");
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
                    //“avisa” pro antigo anterior que o seu proximo mudou para o novo livro 
                    lista[lista[atual].anterior].proximo = pv;
                }else {
                    // Se não houver anterior, significa que o novo elemento vai ser o primeiro
                    primeiro = pv;
                }
                lista[atual].anterior= pv;
                quantidade++;
                return;
            }
        atual = lista[atual].proximo;
        }
    }
    printf("Nada encontrado!\n");
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
        primeiro = aux;
    }
}

void removerFinal(){
    if(vazia()) {
        printf("Lista vazia!\n");
        return;
    } else {
        if (primeiro == ultimo) {
            // Só tinha um elemento
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

            // Se o livro removido não é o último
            // Faz o próximo do livro apontar para o anterior do removido
            if(lista[atual].proximo != -1){
                lista[lista[atual].proximo].anterior = lista[atual].anterior;
            } else {
                // Se for o último da lista, atualiza o índice do último
                ultimo = lista[atual].anterior;
            }

            // Se o livro removido não é o primeiro
            // Faz o anterior do livro apontar para o próximo do removido
            if(lista[atual].anterior != -1){
                lista[lista[atual].anterior].proximo = lista[atual].proximo;
            } else {
                // Se for o primeiro da lista, atualiza o índice do primeiro
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
    printf("Digite o codigo do livro para remocao!\n");
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
void menu() {
	int opc = 0;
	
	do {
		printf("\n:: LIVROS DUPLAMENTE LIGADOS ::\n");
		printf("1.  Adicionar Inicio\n");
		printf("2.  Adicionar Final\n");
		printf("3.  Adicionar Após Código\n");
		printf("4.  Adicionar Antes Código\n");
		printf("5.  Remover Inicio\n");
		printf("6.  Remover Final\n");
		printf("7.  Remover Código\n");
		printf("8.  Pesquisar Código\n");
		printf("9.  Imprimir Inicio -> Final\n");
		printf("10. Imprimir Final -> Inicio\n");
		printf("11. Contar Número de Livros\n");
		printf("12. Maior Preço\n");
		printf("13. Média de Preços\n");
		printf("14. Contar por Classificação\n");
		printf("15. Imprimir Número por Classificação\n");
		printf("16. Imprimir Soma por Classificação\n");
		printf("17. Remover por Classificação\n");
		printf("18. Classificação com mais livros\n");
		printf("19. Imprimir Ordenado por Código\n");
		printf("00.  Sair\n");
		
		scanf("%i", &opc);
		
		if (opc == 1) {
			adicionarInicio();
		} else if (opc == 2) {
			adicionarFinal();
		} else if (opc == 3) {
			AdicionarAposCodigo();
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
		    printf("A quantidade de livros e de %i", contarNumeroLivros());
		} else if (opc == 12) {
		
		} else if (opc == 13) {
		
		} else if (opc == 14) {
		
		} else if (opc == 15) {
		
		} else if (opc == 16) {
		
		} else if (opc == 17) {
		
		} else if (opc == 18) {
		
		} else if (opc == 19) {
		
		}
		
	} while (opc != 0);
}

int main(){
	iniciarLista();
	menu();
	return 0;
}





