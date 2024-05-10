#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 3

enum Cargos {
	Gerente = 0,
	Vendedor,
	Atendente,
	QtdCargos
};

char *cargo_nome[3] = {"Gerente", "Vendedor", "Atendente"};

struct Pessoa {
	char nome[50];
	enum Cargos cargo;
	float salario;
};

struct Pessoa *cadastra_pessoa(){
	struct Pessoa *p = malloc(sizeof(struct Pessoa));
	printf("Diga o nome da pessoa: ");
	gets(p->nome);
	printf("\nDiga o cargo de %s: \n", p->nome);
	int i = 0;
	for(i; i < QtdCargos; i++){
		printf("%d = %s\t", i + 1, cargo_nome[i]);
	}
	printf("\n");
	int cargo;
	scanf("%d", &cargo);
	p->cargo = cargo - 1;
	setbuf(stdin, NULL);
	printf("\nDiga o salário de %s: ", p->nome);
	scanf("%f", &p->salario);
	setbuf(stdin, NULL);
	return p;
}

void mostra_pessoa(struct Pessoa *p, int index){
	printf("**** [%d] ****", index + 1);
	printf("\nO nome da pessoa é: %s", p->nome);
	printf("\nO cargo da pessoa é: %s", cargo_nome[p->cargo]);
	printf("\nO salário da pessoa é: %.2f", p->salario);
	printf("\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	struct Pessoa *p[N];
	int i = 0; 
	for(i; i < N; i++){
		p[i] = cadastra_pessoa();
		printf("\n");
	}
	i = 0;
	for(i; i < N; i++){
		mostra_pessoa(p[i], i);
	}
	i = 0;
	for(i; i < N; i++){
		free(p[i]);	
	}
	
	return 0;
}
