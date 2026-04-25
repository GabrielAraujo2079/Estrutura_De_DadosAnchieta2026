/*Com base nas informa��es abaixo, desenvolva uma aplica��o que faz uso de Filas, o exerc�cio preve o controle 
de atendimento de alunos em uma secretaria de escola.

TDE
Aluno {
  + NumeroAtendimento;
  + RA;
  + Nome;
  + Curso;
  + ValorMensalidade;
}

OPERA��ES (TDA)
  + Adicionar(Aluno) *
  + Atender () **
  + Relatorio () 
  + MaiorMensalidade () 
  + Localizar (RA)
  + MediaMensalidades;
  + NumeroAlunosDoCurso(Curso) ***
  + ResumoAlunosPorCurso() ****
  + Atender (X) *****

NOTAS
* Adiciona um novo aluno na fila, o campo NumeroAtendimento dever� ser gerado automaticamente (pesquisar como gerar n�meros rand�micos), n�o dever� ser permitido 
inser��o de dois alunos com mesmo RA (antes de inserir deve-se pesquisar se j� existe na fila um outro aluno com o mesmo RA).
** Corresponde ao remover da fila, o aluno sa� da Fila quanto � atendido, dever� exibir o NumeroAtendimento antes da remo��o, a exibi��o equivale a impress�o do n�mero que est� sendo chamado em um painel.
*** Contar o n�mero de alunos presentes na fila de um determinado curso, que ser� fornecido pelo usu�rio.
**** Dever� apresentar apenas o nome dos cursos e a quantidade de alunos de cada curso. 
***** O usu�rio dever� informar a quantidade X de alunos que ser�o atendidos (retirados) de uma �nica vez, � importante lembrar 
que se existir apenas 1 aluno na fila e for solicitado para atender 3, n�o deve apresentar erro.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Aluno{
    int numeroAtendimento;
    int RA;
    char  Nome[40];
    char Curso[40];
    float ValorMensalidade;

    struct Aluno*proximo;
    
}ElementoFila;

int numeroElementos;

void iniciar(ElementoFila * Fila){
    Fila->proximo = NULL;
    numeroElementos = 0;
}
int vazia(ElementoFila * Fila){
    if(Fila->proximo == NULL){
        return 1;
    }else {
        return 0;
    }
}
int checaRA(ElementoFila *Fila, int RA){
   
        ElementoFila * tmp;
        tmp = Fila->proximo;
        
        while (tmp != NULL){
            if(tmp->RA == RA){
                return 1;
            }
        tmp = tmp->proximo;
        }
        return 0;
}


ElementoFila *adicionar(ElementoFila *Fila){
    ElementoFila *novo = (ElementoFila *) malloc(sizeof(ElementoFila));

    if (!novo) {
        printf("Memoria insuficiente\n");
        return NULL;
    }else {
        printf("RA: \n");
        scanf("%i", &novo->RA);
        
        if (checaRA(Fila, novo->RA)){
            printf("RA JA Existe BB\n");
            free(novo);
            return NULL;
        }
        printf("Nome: \n");
        scanf(" %[^\n]", novo->Nome);;
        printf("Curso: \n");
        scanf(" %[^\n]", novo->Curso);
        printf("Valor Mensalidade:\n");
        scanf("%f", &novo->ValorMensalidade);
       
        
        //juntei enfileirar com o metodo criar SUPERCOMBO
        novo->numeroAtendimento = rand() %  1000 + 1;
        novo->proximo = NULL;

        if (vazia(Fila)){
            Fila->proximo = novo;
        }else {
            ElementoFila *tmp = Fila->proximo;

            while (tmp->proximo != NULL){
                tmp = tmp->proximo;
            }
            tmp->proximo = novo;
        }

    numeroElementos++;
    return novo;
    }
}
ElementoFila *atender(ElementoFila *Fila){
    if (Fila->proximo == NULL){
        printf("VAZIA!\n");
        return NULL;
    
    }else {
        ElementoFila *tmp = Fila->proximo;
        printf("Atendendo o Numero de atendimento: %i\n", tmp->numeroAtendimento);
        Fila->proximo = tmp->proximo;

        numeroElementos = numeroElementos - 1;

        return tmp;
    }
}

void relatorio(ElementoFila * Fila){
    if (vazia(Fila) == 1){
        printf("VAZIA!\n");
        return;
    }else {
        ElementoFila * tmp;
        tmp = Fila->proximo;
        
        while (tmp != NULL){
            printf("Numero atendimento: %i\n", tmp->numeroAtendimento);
            printf("RA: %i\n", tmp->RA);
            printf("Nome: %s\n", tmp->Nome);
            printf("Curso: %s\n", tmp->Curso);
            printf("Valor da mensalidade: %.2f\n", tmp->ValorMensalidade);
            tmp = tmp->proximo;
        }
    }
}

void maisCaro(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    ElementoFila *tmp = Fila->proximo;
    ElementoFila *maisCaro = Fila->proximo;


    while (tmp != NULL){ 
        if(tmp->ValorMensalidade > maisCaro->ValorMensalidade){
            maisCaro = tmp;
        }
        tmp = tmp->proximo;
    }
    printf("Numero atendimento: %i\n", maisCaro->numeroAtendimento);
    printf("RA: %i\n", maisCaro->RA);
    printf("Nome: %s\n", maisCaro->Nome);
    printf("Curso: %s\n", maisCaro->Curso);
    printf("Valor de mensalidade: %.2f\n", maisCaro->ValorMensalidade);  
}
void localizar(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    int userRA;
    ElementoFila *tmp = Fila->proximo;

    printf("Digite a RA deseja procurar!");
    scanf("%i", &userRA);

    while (tmp != NULL){ 
        if(userRA == tmp->RA){
            printf("Numero atendimento: %i\n", tmp->numeroAtendimento);
            printf("RA: %i\n", tmp->RA);
            printf("Nome: %s\n", tmp->Nome);
            printf("Curso: %s\n", tmp->Curso);
            printf("Valor da mensalidade: %.2f\n", tmp->ValorMensalidade);
            return;
        }
        tmp = tmp->proximo;
    }
    printf("Aluno não encontrado!");
    return;
}
void mediaMensalidade(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    ElementoFila *tmp = Fila->proximo;
    float somaMensalidade = 0;


    while (tmp != NULL){ 
        somaMensalidade += tmp->ValorMensalidade;
        tmp = tmp->proximo;
    }
    printf("a media de mensalidades foi de: %.2f\n", somaMensalidade / numeroElementos);
     
}
void numeroAlunosDoCurso(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    char cursoBusca[40];
    int contador = 0;

    printf("Digite o nome do curso: ");
    scanf("%s", cursoBusca);

    ElementoFila *tmp = Fila->proximo;

    while (tmp != NULL){
        if (strcmp(cursoBusca, tmp->Curso) == 0){
            contador++;
        }
        tmp = tmp->proximo;
    }

    printf("Quantidade de alunos no curso %s: %d\n", cursoBusca, contador);
}
void resumoAlunosPorCurso(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    ElementoFila *tmp = Fila->proximo;

    char cursos[100][40]; 
    int contagem[100] = {0};
    int totalCursos = 0;

    while (tmp != NULL){
        int encontrado = 0;

    
        for (int i = 0; i < totalCursos; i++){
            if (strcmp(cursos[i], tmp->Curso) == 0){
                contagem[i]++;
                encontrado = 1;
                break;
            }
        }

        
        if (!encontrado){
            strcpy(cursos[totalCursos], tmp->Curso);
            contagem[totalCursos] = 1;
            totalCursos++;
        }

        tmp = tmp->proximo;
    }

    printf("Resumo de alunos por curso:\n");
    for (int i = 0; i < totalCursos; i++){
        printf("%s: %d aluno(s)\n", cursos[i], contagem[i]);
    }
}
void atenderX(ElementoFila *Fila){
    if (vazia(Fila)){
        printf("VAZIA!\n");
        return;
    }

    int x;
    printf("Quantos alunos deseja atender? ");
    scanf("%i", &x);

    for (int i = 0; i < x; i++){
        ElementoFila *removido = atender(Fila);

        if (removido == NULL){
            // fila acabou antes de atingir X
            printf("Nao ha mais alunos na fila!\n");
            return;
        }

        free(removido); // libera memória
    }
}
void menu(){
    int opc;

    ElementoFila *Fila = (ElementoFila *) malloc(sizeof(ElementoFila));

    iniciar(Fila);
    do{
        printf("\n===== MENU =====\n");
        printf("1. Adicionar(Aluno)\n");
        printf("2. Atender\n");
        printf("3. Relatario\n");
        printf("4. Maior Mensalidade \n");
        printf("5.Localizar\n");
        printf("6. MediaMensalidades\n");
        printf("7. Numero Alunos Do Curso(Curso)  \n");
        printf("8. Resumo Alunos Por Curso\n");
        printf("9. Atender X\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%i", &opc);

        if (opc == 1){
            adicionar(Fila);

        }else if (opc == 2){
            atender(Fila);
        }else if (opc == 3){
            relatorio(Fila);
        }else if (opc == 4){
           maisCaro(Fila);
        }else if (opc == 5){
            localizar(Fila);
        }else if (opc == 6){
        mediaMensalidade(Fila);
        }else if (opc == 7){
            numeroAlunosDoCurso(Fila);
        }else if (opc == 8){
            resumoAlunosPorCurso(Fila);
        }else if (opc == 9){
            atenderX(Fila);
        }
        
    
    }while(opc != 0);   
}
int main (){
    srand(time(NULL));
    menu();
    return 0;
}