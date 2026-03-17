/*----------------
CENÁRIO
----------------
A barraca gourmet PASTEL DELICIA está iniciando suas atividades próximo a faculdade, esta pastelaria vende apenas pasteis de carne e nenhum outro sabor a mais, 
sua única variação corresponde ao tamanho que se dividem em Pequeno (R$ 3.50), Médio (R$ 4.50) e Grande (R$ 5.50), para agilizar o atendimento cada pedido só poderá conter 
pasteis do mesmo tamanho, esta regra apesar de simples é fundamental para que a produção seja rápida e eficiente pois o tempo de intervalo na faculdade é curto.

Para gerenciar a venda dos pasteis foi solicitado o desenvolvimento de um sistema simples com operações básicas conforme descritas abaixo.
a) A primeira versão do sistema (versão beta) suporta apenas a venda de no máximo 10 pedidos sem pagamento, é importante lembrar que o sistema controla 
apenas os pedidos não pagos, os pedidos pagos saem do sistema liberando espaço para outro pedido.
b) Cada pedido registrado deverá conter as seguintes informaçôes: Número pedido; Tamanho; Quantidade.
c) O sistem deve ser interativo, ou seja, permitir que o seu operador venda, imprima, consulte, etc. 
d) Operações básicas do sistema:
    1. Venda (Localiza uma posição vazia e registra as informações: núm. pedido, tamanho, quantidade; Nota: É necessário fazer o controle de número de 
    pedidos abertos, ou seja, não pode exceder 10).
    2. Impressão pedidos a pagar (exibe na tela todos os pedidos não pagos, com todas as informações, e valor total de cada pedido).
    3. Contar número vendas a pagar (exibe na tela o número de pedidos presentes na lista).
    4. Pagamento (localiza pelo número do pedido e remove da lista).
d1) Outras opções podem ser adicionadas conforme o aluno/programador preferir, mas as opções apresentadas aqui nesta relação devem obrigatoriamente existir*/

#include <stdio.h>
#define TAM 10


struct Pedido{
    int codigo;
    char tamanho;
    int quantidade;
    int ativo;
};

struct  Pedido pedidos[TAM];

void venda(){
    
  
    for(int i = 0; i < TAM; i++) {
        if(pedidos[i].ativo == 0) {
            
            printf("Numero do pedido: ");
            scanf("%i", &pedidos[i].codigo);

            printf("Tamanho (P/M/G): ");
            scanf(" %c", &pedidos[i].tamanho);

            printf("Quantidade: ");
            scanf("%i", &pedidos[i].quantidade);

            pedidos[i].ativo = 1;

            printf("Pedido registrado com sucesso!\n");
            return;
        }
    }
    printf("Limite de pedidos atingido!\n");
}

void printPedidosAPagar(){
    int achou = 0;
    float preco, total;
    
    printf("::Pedidos a pagar::\n");
    for (int i = 0; i < TAM; i++){
        if (pedidos[i].ativo == 1){
            
            if(pedidos[i].tamanho == 'P' || pedidos[i].tamanho == 'p')
                preco = 3.50;
            else if(pedidos[i].tamanho == 'M' || pedidos[i].tamanho == 'm')
                preco = 4.50;
            else
                preco = 5.50;
                  
            total = preco * pedidos[i].quantidade;
            
            printf("Numero do pedido: [%i]\n", pedidos[i].codigo);
            printf("Tamanho do pastel: [%c]\n", pedidos[i].tamanho);
            printf("Quantidade comprada: [%i]\n", pedidos[i].quantidade);
            printf("Valor total: R$ %.2f\n\n", total);      
            achou++;
        }
    }
    
    if (achou == 0){
        printf("Nada pendente...\n");
    }
}

int contarPedidos(){

    int contador = 0;

    for(int i = 0; i < TAM; i++){
        if(pedidos[i].ativo == 1){
            contador++;
        }
    }

    return contador;
}

void pagamentos(int cod){
    for (int i = 0; i < TAM; i++){
        if (pedidos[i].ativo == 1 && pedidos[i].codigo == cod){
            pedidos[i].ativo = 0;
            printf("Pedido pago, portanto removido.\n");
            return;
        }
    }
    printf("Pedido nao encontrado.\n");
}


void menu(){

    int opcao;
    int codigo;

    do{

        printf("\n==== PASTEL DELICIA ====\n");
        printf("1 - Registrar venda\n");
        printf("2 - Imprimir pedidos a pagar\n");
        printf("3 - Contar pedidos a pagar\n");
        printf("4 - Realizar pagamento\n");
        printf("9 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){

            venda();

        }
        else if(opcao == 2){

            printPedidosAPagar();

        }
        else if(opcao == 3){

            printf("Total de pedidos a pagar: %d\n", contarPedidos());

        }
        else if(opcao == 4){

            printf("Digite o numero do pedido: ");
            scanf("%d", &codigo);

            pagamentos(codigo);

        }
        else if(opcao == 9){

            printf("Encerrando sistema...\n");

        }
        else{

            printf("Opcao invalida.\n");

        }

    }while(opcao != 9);
}

int main(){
    menu();
}