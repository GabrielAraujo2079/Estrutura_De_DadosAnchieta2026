#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// - O '*' indica que a variável *pIdade é uma variável do tipo ponteiro, 
    // que irá armazenar um endereço de memória.
	int idade = 10;
	int *pIdade = NULL;
	
	printf("idade = 10;\n");
	printf("'idade' - endereco memoria: %p\n", &idade);
	printf("'idade' - valor variaval: %i\n", idade);
	
	//ponteiro 'pIdade' recebe endereço memória variável 'idade' 
	pIdade = &idade;
	
	printf("\n");
	printf("pIdade = &idade; \n");
	printf("'pIdade' - valor carregado: %p\n", pIdade);
	printf("'pIdade' - endereco do proprio ponteiro: %p\n", &pIdade);
	printf("'pIdade' - valor contido endereco armazenado: %i\n", *pIdade);
	
	//alterando o valor do ponteiro 'pIdade', consecutivamente
	//alterará também o valor da variável 'idade'.
	*pIdade = 5;
	printf("\n");
	printf("*pIdade = 5;\n");
	printf("'idade' - novo valor variaval alterado atraves ponteiro: %i\n", idade);
	
	system("pause");
	return 0;
}