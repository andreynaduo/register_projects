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

void cadastrar_projeto(base_projetos proj[TAM]);
void relatorio_projeto(base_projetos proj[TAM]);
void buscar_codigo(base_projetos proj[TAM]);
void aFazer(base_projetos proj[TAM]);
void fazendo(base_projetos proj[TAM]);
void concluidos(base_projetos proj[TAM]);
void verificarStatus(base_projetos proj[TAM], int st);

int main() {

	setlocale(LC_ALL, "portuguese");
	base_projetos proj[TAM];

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
		printf("[5] - LISTAR OS PROJETOS CONCLUÍDOS\n");
		printf("\n[6] - BUSCAR POR CÓDIGO\n");
		printf("[0] - ENCERRAR\n\n");

		scanf("%d", &escolha);
		fflush(stdin);

		switch(escolha) {
			case 1:
				cadastrar_projeto(proj);
				break;

			case 2:
				relatorio_projeto(proj);
				break;

			case 3:
				aFazer(proj);
				break;

			case 4:
				fazendo(proj);
				break;

			case 5:
				concluidos(proj);
				break;

			case 6:
				buscar_codigo(proj);
				break;

			case 0:
				system("cls");
				printf("\nPROGRAMA ENCERRADO\n");
				break;

			default:
				system("cls");
				printf("\nOPÇÃO INVÁLIDA!\n");
				printf("Aperte ENTER e tente novamente.\n\n");
				system("Pause");
				break;
		}
	} while(escolha != 0);

	return 0;
}

void cadastrar_projeto(base_projetos proj[TAM]) {

	/*int status;*/

	if(contador <= TAM) {


		system("cls");
		printf("===========================================\n");
		printf("|          CADASTRAR NOVO PROJETO         | \n");
		printf("===========================================\n");
		printf("\nCódigo do projeto: %d \n", contador+1);
		proj[contador].codigo = contador+1;

		printf("Título: ");
		fgets(proj[contador].titulo, 40, stdin);
		fflush(stdin);

		printf("Descrição: ");
		fgets(proj[contador].descricao, 100, stdin);
		fflush(stdin);

		printf("Ano: ");
		scanf("%d", &proj[contador].ano);
		fflush(stdin);

		printf("Tipo de projeto: ");
		fgets(proj[contador].tipo, 30, stdin);
		fflush(stdin);

		printf("Público:");
		fgets(proj[contador].publico, 30, stdin);
		fflush(stdin);

		printf("Gerente de projetos responsável: ");
		fgets(proj[contador].gerente, 50, stdin);
		fflush(stdin);

		printf("Orçamento do projeto: R$ ");
		scanf("%f", &proj[contador].orcamento);
		fflush(stdin);

		printf("Status: \n");
		printf(" [1] - A fazer    [2] - Em andamento    [3] - Concluído \n");
		scanf("%d", &status);
		fflush(stdin);

		switch(status) {
			case 1:
				proj[contador].status = 1;
				break;

			case 2:
				proj[contador].status = 2;
				break;

			case 3:
				proj[contador].status = 3;;
				break;

			default:
				proj[contador].status = 10;
				break;
		}
		printf("\n");
		contador++;
		system("Pause");
	} else {
		printf("> Número máximo de cadastros atingido!");
		system("Pause");
	}
}

void relatorio_projeto(base_projetos proj[TAM]) {

	/*int i;*/

	system("cls");
	if(contador != 0) {
		printf("================================================\n");
		printf("|                TODOS OS PROJETOS             | \n");
		printf("================================================\n");
		for(i=0; i<contador; i++) {
			printf("\n");
			printf("Código: %d\n", i+1);
			printf("Título: %s", proj[i].titulo);
			printf("Descrição: %s", proj[i].descricao);
			printf("Ano: %d\n", proj[i].ano);
			printf("Tipo de projeto: %s", proj[i].tipo);
			printf("Público: %s", proj[i].publico);
			printf("Gerente de projetos responsável: %s", proj[i].gerente);
			printf("Orçamento do projeto: R$ %f\n", proj[i].orcamento);
			printf("Status: %d\n", proj[i].status);
		}
	} else {
		printf("\n\nLista vazia!\n");
	}
	system("Pause");

}


void buscar_codigo(base_projetos proj[TAM]) {

	int j;
	int busca;
	int x = 0;

	system("cls");
	printf("===========================================\n");
	printf("|             BUSCAR POR CÓDIGO           | \n");
	printf("===========================================\n");
	printf("\n>> Digite o código que deseja buscar: \n");
	scanf ("%d", &busca);
	fflush(stdin);
	system("cls");

	for(j=0; j<contador; j++) {
		if(proj[j].codigo == busca) {
			printf("\n> Projetos com o código %d: \n", busca);
			printf("\n");
			printf("Código: %d\n", busca);
			printf("Título: %s", proj[j].titulo);
			printf("Descrição: %s", proj[j].descricao);
			printf("Ano: %d\n", proj[j].ano);
			printf("Tipo de projeto: %s", proj[j].tipo);
			printf("Público: %s", proj[j].publico);
			printf("Gerente de projetos responsável: %s", proj[j].gerente);
			printf("Orçamento do projeto: R$ %f\n", proj[j].orcamento);
			printf("Status: %d\n", proj[j].status);
			x += 1;
		}
	}
	if(x == 0) {
		printf("\n> Projeto não encontrado com o código %d\n\n", busca);
	}
	system("Pause");
}


void aFazer(base_projetos proj[TAM]) {

	system("cls");
	printf("===========================================\n");
	printf("|             PROJETOS A FAZER            | \n");
	printf("===========================================\n");
	verificarStatus(proj, 1);
}


void fazendo(base_projetos proj[TAM]) {

	system("cls");
	printf("==========================================\n");
	printf("|          PROJETOS EM ANDAMENTO         | \n");
	printf("==========================================\n");
	verificarStatus(proj, 2);
}

void concluidos(base_projetos proj[TAM]) {

	system("cls");
	printf("==========================================\n");
	printf("|           PROJETOS CONCLUÍDOS          | \n");
	printf("==========================================\n");
	verificarStatus(proj, 3);
}

void verificarStatus(base_projetos proj[TAM], int st) {
	int x = 0;
	for(i=0; i<contador; i++) {
		if(proj[i].status == st) {
			printf("\n");
			printf("Código: %d\n", i+1);
			printf("Título: %s", proj[i].titulo);
			printf("Descrição: %s", proj[i].descricao);
			printf("Ano: %d\n", proj[i].ano);
			printf("Tipo de projeto: %s", proj[i].tipo);
			printf("Público: %s", proj[i].publico);
			printf("Gerente de projetos responsável: %s", proj[i].gerente);
			printf("Orçamento do projeto: R$ %f\n", proj[i].orcamento);
			printf("Status: %d\n", proj[i].status);
			x += 1;
		}
	}
	if(x == 0) {
		printf("\nNão existem projetos com esse status!\n\n");
	}
	system("Pause");
}

