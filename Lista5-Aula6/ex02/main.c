/*Crie uma aplicação console que deve utilizar os conceitos de Pilhas (com auxílio listas ligadas), 
abaixo seguem as instruções referentes os elementos da Pilha e também quais operações poderão ser executadas na Pilha,.

a) Elemento carta de baralho (TDA).
Carta {
  + naipe: Texto;
  + valor: Inteiro;
  + anterior: Carta;
}


b) Pilha para controle das cartas (TDE).
PilhaCartas{
  + PilhaCartas (Inteiro tamanho); // Método construtor, note que existe um parametro que definirá a quantidade de cartas que poderão ser adicionadas na pilha;
  + Jogar(Carta nova); //Equivale ao método empilhar, no entanto deve-se respeitar as seguintes regras: 1. Não deve permitir jogar a carta caso o número de cartas 
  ultrapasse o permitido no momento da criação da Pilha; 2. Não deve permitir que seja jogada uma carta igual, pois em um baralho não exitem cartas repetidas;
  + Descartar(); //Equivalente ao método desempilhar;
  + Monte(); //Exibe o naipe e valor de cada carta jogada;
  + Contar(); // Exibe o número de cartas jogadas;
  + ContarPorNaipe(); //Deve exibir o número de cartas por naipe, dentre as cartas jogadas;
  + Pesquisar (Texto naipe, Inteiro valor) //Pesquisa se uma determinada carta foi jogada, é importante notar que a condição leva em consideração dois itens, o naipe e o valor da carta, pois existem cartas com o mesmo número mas de naipes diferentes;
  + Total(Texto naipe); Deve exibir a soma dos valores das cartas jogadas de um determinado naipe informado pelo usuário;
  + TotalPorNaipe(); Deve exibir a soma de todos os valores por naipe das cartas jogadas. Por exemplo: Paus - 35; Copas - 28, etc.
  + Menor (Texto naipe); Exibe a menor carta jogada de um determinado naipe informado;
  + MenorPorNaipe(); Deve exibir a menor carta jogada por naipe;
  + MaiorCarta(); //Deve exibir a maior carta e seu respectivo naipe, dentre as cartas jogadas.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Carta{
    char naipe[20];
    int valor;
    struct Carta *anterior;
}Carta;

Carta *topo = NULL;

int definirLimite(){
    int limite;
    printf("Defina o limite de cartas no jogo\n");
    scanf("%i", &limite);
    return limite;
}

Carta* jogar (Carta *topo){
    Carta *novo = (Carta *) malloc(sizeof(Carta));

    if (novo){
        printf("Digite o naipe da carta [ouro] | [paus] | [espadas] | [copas]:\n");
        scanf("%s", novo->naipe);
        
        if (strcmp(novo->naipe, "copas") != 0 &&
            strcmp(novo->naipe, "ouro") != 0 &&
            strcmp(novo->naipe, "espadas") != 0 &&
            strcmp(novo->naipe, "paus") != 0){
            
            printf("Naipe invalido!\n");
            free(novo);
            return topo;
        }

        printf("Digite o valor da carta:\n");
        scanf("%i", &novo->valor);

        // BLOQUEIO DE CARTA REPETIDA
        Carta *aux = topo;
        while (aux != NULL){
            if (strcmp(aux->naipe, novo->naipe) == 0 && aux->valor == novo->valor){
                printf("Carta repetida!\n");
                free(novo);
                return topo;
            }
            aux = aux->anterior;
        }

        novo->anterior = topo;
        return novo;
    }else{
        printf("Erro ao cadastrar!\n");
        return topo;
    }
}

Carta* descartar(Carta* topo){
    if (topo == NULL){
        printf("PILHA VAZIA!\n");
        return topo;
    }
    Carta *remover = topo;
    topo = topo->anterior;
    free(remover);

    return topo;
}

void monte(Carta *topo){
    Carta * aux = topo;

    while (aux != NULL){
        printf("Naipe: [%s] Valor: [%i]\n", aux->naipe, aux->valor);
        aux = aux->anterior;
    }
}

int contar(Carta *topo){
    Carta * aux = topo;
    int contador = 0;

    while (aux != NULL){
        contador++;
        aux = aux->anterior;
    }
    return contador;
}

void contarPorNaipe(Carta *topo){
    Carta *aux = topo;
    int contaPau = 0, contaOuro = 0, contaEspada = 0, contaCopa = 0;

    while (aux != NULL){
        if (strcmp(aux->naipe, "paus") == 0) contaPau++;
        if (strcmp(aux->naipe, "ouro") == 0) contaOuro++;
        if (strcmp(aux->naipe, "copas") == 0) contaCopa++;
        if (strcmp(aux->naipe, "espadas") == 0) contaEspada++;      
        aux = aux->anterior;
    }

    printf("Paus: %i\n", contaPau);
    printf("Ouros: %i\n", contaOuro);
    printf("Copas: %i\n", contaCopa);
    printf("Espadas: %i\n", contaEspada);
}

void pesquisar(Carta *topo){
    Carta *aux = topo;
    char userNaipe[20];
    int userValor;

    printf("Digite o naipe:\n");
    scanf("%s", userNaipe);

    printf("Digite o valor:\n");
    scanf("%i", &userValor);

    while (aux != NULL){
        if (strcmp(aux->naipe, userNaipe) == 0 && userValor == aux->valor){
            printf("Carta encontrada! [%s] [%i]\n", aux->naipe, aux->valor);
            return;
        }
        aux = aux->anterior;
    }

    printf("Carta nao encontrada\n");
}

int total(Carta *topo, char userNaipe[20]){
    Carta *aux = topo;
    int soma = 0;
    
    while (aux != NULL){
        if (strcmp(aux->naipe, userNaipe) == 0){
            soma += aux->valor;
        }
        aux = aux->anterior;
    }
    return soma;
}

void totalPorNaipe(Carta *topo){
    Carta *aux = topo;
    int totalPau = 0, totalOuro = 0, totalEspada = 0, totalCopa = 0;

    while (aux != NULL){
        if (strcmp(aux->naipe, "paus") == 0) totalPau += aux->valor;
        if (strcmp(aux->naipe, "ouro") == 0) totalOuro += aux->valor;
        if (strcmp(aux->naipe, "copas") == 0) totalCopa += aux->valor;
        if (strcmp(aux->naipe, "espadas") == 0) totalEspada += aux->valor;      
        aux = aux->anterior;
    }

    printf("Paus: %i\n", totalPau);
    printf("Ouros: %i\n", totalOuro);
    printf("Copas: %i\n", totalCopa);
    printf("Espadas: %i\n", totalEspada);
}

void menorNaipe(Carta *topo, char userNaipe[20]){
    Carta *aux = topo;
    int menor = 0, i = 0;

    while (aux != NULL){ 
        if (!i){
            if(strcmp(aux->naipe, userNaipe) == 0){
                menor = aux->valor; 
                i = 1;
            }
        }else if (strcmp(aux->naipe, userNaipe) == 0 && aux->valor < menor){
            menor = aux->valor;
        }
        aux = aux->anterior;
    }

    if (!i){
        printf("Nenhuma carta encontrada\n");
        return;
    }

    printf("Menor [%s]: %i\n", userNaipe, menor);
}

void menorPorNaipe(Carta *topo){
    Carta *aux = topo;

    int menorPau = 0, menorOuro = 0, menorEspada = 0, menorCopa = 0;
    int iPau = 0, iOuro = 0, iEspada = 0, iCopa = 0;

    while (aux != NULL){
        if (strcmp(aux->naipe, "paus") == 0){
            if (!iPau || aux->valor < menorPau){
                menorPau = aux->valor;
                iPau = 1;
            }
        }

        if (strcmp(aux->naipe, "ouro") == 0){
            if (!iOuro || aux->valor < menorOuro){
                menorOuro = aux->valor;
                iOuro = 1;
            }
        }

        if (strcmp(aux->naipe, "copas") == 0){
            if (!iCopa || aux->valor < menorCopa){
                menorCopa = aux->valor;
                iCopa = 1;
            }
        }

        if (strcmp(aux->naipe, "espadas") == 0){
            if (!iEspada || aux->valor < menorEspada){
                menorEspada = aux->valor;
                iEspada = 1;
            }
        }

        aux = aux->anterior;
    }

    printf("Paus: %i\n", iPau ? menorPau : 0);
    printf("Ouros: %i\n", iOuro ? menorOuro : 0);
    printf("Copas: %i\n", iCopa ? menorCopa : 0);
    printf("Espadas: %i\n", iEspada ? menorEspada : 0);
}

void maiorCarta(Carta *topo){
    Carta *aux = topo;

    int maior = 0, i = 0;
    char naipeMaior[20];

    while (aux != NULL){
        if (!i || aux->valor > maior){
            maior = aux->valor;
            strcpy(naipeMaior, aux->naipe);
            i = 1;
        }
        aux = aux->anterior;
    }

    if (!i){
        printf("Nenhuma carta\n");
        return;
    }

    printf("Maior carta: [%s] [%i]\n", naipeMaior, maior);
}

void menu(){
    int opc;
    char naipe[20];

    int limite = definirLimite();

    do{
        printf("\n===== MENU =====\n");
        printf("1. Jogar carta\n");
        printf("2. Descartar carta\n");
        printf("3. Mostrar monte\n");
        printf("4. Contar cartas\n");
        printf("5. Contar por naipe\n");
        printf("6. Pesquisar carta\n");
        printf("7. Total por naipe\n");
        printf("8. Total de todos os naipes\n");
        printf("9. Menor por naipe\n");
        printf("10. Menor por naipe (todos)\n");
        printf("11. Maior carta\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        if (opc == 1){
            if (contar(topo) < limite){
                topo = jogar(topo);
            }else{
                printf("Limite atingido!\n");
            }

        }else if (opc == 2){
            topo = descartar(topo);

        }else if (opc == 3){
            monte(topo);

        }else if (opc == 4){
            printf("Total: %i\n", contar(topo));

        }else if (opc == 5){
            contarPorNaipe(topo);

        }else if (opc == 6){
            pesquisar(topo);

        }else if (opc == 7){
            scanf("%s", naipe);
            printf("Total: %i\n", total(topo, naipe));

        }else if (opc == 8){
            totalPorNaipe(topo);

        }else if (opc == 9){
            scanf("%s", naipe);
            menorNaipe(topo, naipe);

        }else if (opc == 10){
            menorPorNaipe(topo);

        }else if (opc == 11){
            maiorCarta(topo);

        }

    }while(opc != 0);
}

int main(){
    menu();
    return 0;
}