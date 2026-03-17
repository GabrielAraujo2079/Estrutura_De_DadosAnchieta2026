/*
EDL6-001 (LIVROS)
Com base nas informações abaixo, crie uma aplicação console que deverá implementar os conceitos de uma Pilha, 
esta aplicação deverá utilizar os conceitos de lista ligada para implementação da PilhaLivros.

a) Estrutura do elemento (TDE).
Livro {
  + codigo: Inteiro
  + titulo: Texto
  + preco: Numerico
  + anterior: Livro}

b) Estrutura da pilha (TDA)
PilhaLivros {
  + Empilhar(Livro novo);
  + Desempilhar();
  + Imprimir();
  + Vazia(): Boolean //Retorna valor verdadeiro ou falso, informando se a pilha está fazia ou não.
  + Pesquisar(Inteiro codigo); //Pesquisa se um determinado livro existe na pilha a partir de um código informato.
  + MaisCaro(); //Exibibe as informações (código, título e preço) do livro mais caro que existe na pilha.
  + MediaPreco();  //Exibe a média de preços dos livros presentes na pilha.
  + NumeroTotalLivros(); Exibe o número de livros da pilha.
}

c) Menu.

Crie um menu para utilizar as operações descritas no TDA.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Livro {
    int codigo;
    char titulo[100];
    float preco;
    struct Livro *anterior;
} Livro;

Livro *topo = NULL;

Livro* empilhar(Livro *topo){
    Livro *novo = (Livro *) malloc(sizeof(Livro));

    if (novo){
        printf("Digite o codigo\n");
        scanf("%i", &novo->codigo);
        printf("Digite o titulo\n");
        scanf(" %[^\n]", novo->titulo);
        printf("Digite o preco\n");
        scanf("%f", &novo->preco);
        novo->anterior = topo;
        return novo;
    
    }else{
        printf("!Erro nao foi possivel cadastrar livro!\n");
        return topo;
    }
}
Livro* desempilhar(Livro *topo){
    if (topo == NULL){
        printf("PILHA VAZIA!\n");
        return topo;
    }

    Livro *remover = topo;
    topo = topo->anterior;
    free(remover);

    return topo;
}
void imprimir(Livro *topo){
    Livro *aux = topo;
    
    while(aux != NULL){
        printf("CODIGO DO LIVRO: [%i]\n", aux->codigo);
        printf("TITULO DO LIVRO: [%s]\n", aux->titulo);
        printf("PRECO DO LIVRO: [%.2f]\n", aux->preco);
        printf("--------------------------\n");
        aux = aux->anterior;
    }
}
void pesquisar(Livro *topo){
    Livro *aux = topo;
    int  codigoInformado = 0;
    printf("Informe o codigo:\n");
    scanf("%i", &codigoInformado);
    


    
    while(aux != NULL){
        if (codigoInformado == aux->codigo){
            printf("CODIGO DO LIVRO: [%i]\n", aux->codigo);
            printf("TITULO DO LIVRO: [%s]\n", aux->titulo);
            printf("PRECO DO LIVRO: [%.2f]\n", aux->preco);
            printf("--------------------------\n");
            return;
        }
        aux = aux->anterior;
    }
    printf("Codigo nao foi encontrado ;(\n");
}

int verificaVazia(Livro *topo){
    if(topo == NULL){
        return 1;
    }else {
        return 0;
    }
}
void maisCaro(Livro *topo){
    if(topo == NULL){
        printf("PILHA VAZIA!\n");
        return;
    }

    Livro *aux = topo;
    Livro *maisCaro = topo;

    while(aux != NULL){
        if(aux->preco > maisCaro->preco){
            maisCaro = aux;
        }
        aux = aux->anterior;
    }

    printf("LIVRO MAIS CARO:\n");
    printf("CODIGO: [%i]\n", maisCaro->codigo);
    printf("TITULO: [%s]\n", maisCaro->titulo);
    printf("PRECO: [%.2f]\n", maisCaro->preco);
}

void mediaPreco(Livro *topo){
    if(topo == NULL){
        printf("PILHA VAZIA!\n");
        return;
    }
    
    Livro *aux = topo;
    float totalPreco =  0, contador = 0;
    
    while(aux != NULL){
        
        
        totalPreco += aux->preco;
        aux = aux->anterior;
        contador++;
    }
    printf("A media de valores e [%.2f]\n", totalPreco / contador);
}
void numeroTotalLivro(Livro *topo){
    if(topo == NULL){
        printf("PILHA VAZIA!\n");
        return;
    }
    
    Livro *aux = topo;
    int contador = 0;
    
    while(aux != NULL){
        contador++;
        aux = aux->anterior;
    }
    printf("A quantidade de livros e [%i]\n", contador);
}
void menu(){
    int opc = 0;

    do{ 
        printf("1. Empilhar(Livro novo)\n");
        printf("2. Desempilhar\n");
        printf("3. Imprimir\n");
        printf("4. Verificar se esta vazia\n");
        printf("5. Pesquisar\n");
        printf("6. MaisCaro\n");
        printf("7. MediaPreco\n");
        printf("8. NumeroTotalLivros\n");
        printf("9. Sair\n");
        printf("Oque deseja fazer?:\n");
        scanf("%i", &opc);



        if (opc == 1){
            topo = empilhar(topo);
        }else if (opc == 2){
            topo = desempilhar(topo);
        }else if (opc == 3){
            imprimir(topo);
        }else if (opc == 4){
            if(verificaVazia(topo)){
                printf("PILHA ESTA VAZIA\n");
            }else{
                printf("PILHA NAO ESTA VAZIA\n");
            }
        }else if (opc == 5){
            pesquisar(topo);
        }else if (opc == 6){
            maisCaro(topo);
        }else if (opc == 7){
           mediaPreco(topo);
        }else if (opc == 8){
                numeroTotalLivro(topo);
        }

    }while(opc != 9);
}

int main(){
    menu();
}
    

