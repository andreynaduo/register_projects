#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define TAM 200

typedef struct dados {

	int codigo, ano, status;
	float orcamento;
	char titulo[40], descricao[100], gerente[50], tipo[30], publico[30];

} base_projetos;

int contador = 0;
int i;
int status;

void cadastrar_projeto(base_projetos cadastro[TAM]);
void relatorio_projeto(base_projetos cadastro[TAM]);
void buscar_codigo(base_projetos cadastro[TAM]);
void aFazer(base_projetos cadastro[TAM]);
void fazendo(base_projetos cadastro[TAM]);
void concluidos(base_projetos cadastro[TAM]);
void verificarStatus(base_projetos cadastro[TAM], int st);

int main() {

	setlocale(LC_ALL, "portuguese");
	base_projetos cadastro[TAM];

	int escolha;

	system("cls");

	do {
		system("cls");
		printf("===========================================\n");
		printf("|                   MENU                  | \n");
		printf("===========================================\n");
		printf("\n>> Escolha uma opcao abaixo:\n");
		printf("\n[1] - CADASTRAR UM PROJETO\n");
		printf("[2] - LISTAR TODOS OS PROJETOS\n");
		printf("\n[3] - LISTAR OS PROJETOS A FAZER\n");
		printf("[4] - LISTAR OS PROJETOS EM ANDAMENTO\n");
		printf("[5] - LISTAR OS PROJETOS CONCLU�DOS\n");
		printf("\n[6] - BUSCAR POR C�DIGO\n");
		printf("[0] - ENCERRAR\n\n");

		scanf("%d", &escolha);
		fflush(stdin);

		switch(escolha) {
			case 1:
				cadastrar_projeto(cadastro);
				break;

			case 2:
				relatorio_projeto(cadastro);
				break;

			case 3:
				aFazer(cadastro);
				break;

			case 4:
				fazendo(cadastro);
				break;

			case 5:
				concluidos(cadastro);
				break;

			case 6:
				buscar_codigo(cadastro);
				break;

			case 0:
				system("cls");
				printf("\nPROGRAMA ENCERRADO\n");
				break;

			default:
				system("cls");
				printf("\nOP��O INV�LIDA\n");
				system("Pause");
				break;
		}
	} while(escolha != 0);

	return 0;
}

void cadastrar_projeto(base_projetos cadastro[TAM]) {

	/*int status;*/

	if(contador <= TAM) {


		system("cls");
		printf("===========================================\n");
		printf("|          CADASTRAR NOVO PROJETO         | \n");
		printf("===========================================\n");
		printf("\nC�digo do projeto: %d \n", contador+1);
		cadastro[contador].codigo = contador+1;

		printf("T�tulo: ");
		fgets(cadastro[contador].titulo, 40, stdin);
		fflush(stdin);

		printf("Descri��o: ");
		fgets(cadastro[contador].descricao, 100, stdin);
		fflush(stdin);

		printf("Ano: ");
		scanf("%d", &cadastro[contador].ano);
		fflush(stdin);

		printf("Tipo de projeto: ");
		fgets(cadastro[contador].tipo, 30, stdin);
		fflush(stdin);

		printf("P�blico:");
		fgets(cadastro[contador].publico, 30, stdin);
		fflush(stdin);

		printf("Gerente de projetos respons�vel: ");
		fgets(cadastro[contador].gerente, 50, stdin);
		fflush(stdin);

		printf("Or�amento do projeto: R$ ");
		scanf("%f", &cadastro[contador].orcamento);
		fflush(stdin);

		printf("Status: \n");
		printf(" [1] - A fazer    [2] - Em andamento    [3] - Concluido \n");
		scanf("%d", &status);
		fflush(stdin);

		switch(status) {
			case 1:
				cadastro[contador].status = 1;
				break;

			case 2:
				cadastro[contador].status = 2;
				break;

			case 3:
				cadastro[contador].status = 3;;
				break;

			default:
				cadastro[contador].status = 10;
				break;
		}
		printf("\n");
		contador++;
		system("Pause");
	} else {
		printf("N�mero m�ximo de cadastros atingido!");
		system("Pause");
	}
}

void relatorio_projeto(base_projetos cadastro[TAM]) {

	/*int i;*/

	system("cls");
	if(contador != 0) {
		printf("================================================\n");
		printf("|                TODOS OS PROJETOS             | \n");
		printf("================================================\n");
		for(i=0; i<contador; i++) {
			printf("\n");
			printf("C�digo: %d\n", i+1);
			printf("T�tulo: %s", cadastro[i].titulo);
			printf("Descri��o: %s", cadastro[i].descricao);
			printf("Ano: %d\n", cadastro[i].ano);
			printf("Tipo de projeto: %s", cadastro[i].tipo);
			printf("P�blico: %s", cadastro[i].publico);
			printf("Gerente de projetos respons�vel: %s", cadastro[i].gerente);
			printf("Or�amento do projeto: R$ %f\n", cadastro[i].orcamento);
			printf("Status: %d\n", cadastro[i].status);
		}
	} else {
		printf("\n\nLista vazia!\n");
	}
	system("Pause");

}


void buscar_codigo(base_projetos cadastro[TAM]) {

	int j;
	int busca;
	int acha;

	system("cls");
	printf("===========================================\n");
	printf("|             BUSCAR POR C�DIGO           | \n");
	printf("===========================================\n");
	printf("\nDigite o c�digo que deseja buscar: \n");
	scanf ("%d", &busca);
	fflush(stdin);
	j = 0;
	acha = 0;
	while((j < TAM) && (acha == 0)) {
		if (cadastro[j].codigo == busca) {
			printf("\nC�digo: %d\n", cadastro[j].codigo);
			printf("T�tulo: %s", cadastro[j].titulo);
			printf("Descri�ao: %s", cadastro[j].descricao);
			printf("Ano: %d\n", cadastro[j].ano);
			printf("Tipo de projeto: %s", cadastro[j].tipo);
			printf("P�blico: %s", cadastro[j].publico);
			printf("Gerente de projetos respons�vel: %s", cadastro[j].gerente);
			printf("Or�amento do projeto: R$ %f\n", cadastro[j].orcamento);
			printf("Status: %d\n", cadastro[j].status);
			acha = 1;
			system("Pause");
		}
		j++;
	}
	if(acha == 0) {
		printf("Projeto n�o encontrado com o c�digo %d\n", busca);
		system("Pause");
	}

}


void aFazer(base_projetos cadastro[TAM]) {

	system("cls");
	printf("===========================================\n");
	printf("|             PROJETOS A FAZER            | \n");
	printf("===========================================\n");
	verificarStatus(cadastro, 1);
}


void fazendo(base_projetos cadastro[TAM]) {

	system("cls");
	printf("==========================================\n");
	printf("|          PROJETOS EM ANDAMENTO         | \n");
	printf("==========================================\n");
	verificarStatus(cadastro, 2);
}

void concluidos(base_projetos cadastro[TAM]) {

	system("cls");
	printf("==========================================\n");
	printf("|           PROJETOS CONCLU�DOS          | \n");
	printf("==========================================\n");
	verificarStatus(cadastro, 3);
}

void verificarStatus(base_projetos cadastro[TAM], int st) {
	int x = 0;
	for(i=0; i<contador; i++) {
		if(cadastro[i].status == st) {
			printf("\n");
			printf("C�digo: %d\n", i+1);
			printf("T�tulo: %s", cadastro[i].titulo);
			printf("Descri��o: %s", cadastro[i].descricao);
			printf("Ano: %d\n", cadastro[i].ano);
			printf("Tipo de projeto: %s", cadastro[i].tipo);
			printf("P�blico: %s", cadastro[i].publico);
			printf("Gerente de projetos respons�vel: %s", cadastro[i].gerente);
			printf("Or�amento do projeto: R$ %f\n", cadastro[i].orcamento);
			printf("Status: %d\n", cadastro[i].status);
			x += 1;
		}
	}
	if(x == 0) {
		printf("\nN�o existem projetos com esse status!\n\n");
	}
	system("Pause");
}
