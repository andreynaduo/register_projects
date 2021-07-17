#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 200

/*==================== STRUCT PROJETOS ====================*/
struct projetos {
	int codigo, ano, status;
	float orcamento;
	char titulo[40], descricao[100], gerente[50], tipo[30], publico[30];
};

/*====================== CÓDIGO FONTE =======================*/
int main() {
	
	struct projetos proj[TAM];

	int escolha, contador = 0, i;
	int j, acha, busca;
	int status;
	
	/*======================== MENU =========================*/
	do {
		system("cls");
		printf("===========================================\n");
		printf("|                   MENU                  | \n");
		printf("===========================================\n");
		printf("\nEscolha uma opcao abaixo:\n");
		printf("\n[1] - CADASTRAR UM PROJETO\n");
		printf("[2] - LISTAR TODOS OS PROJETOS\n");
		printf("[3] - LISTAR OS PROJETOS A FAZER\n");
		printf("[4] - LISTAR OS PROJETOS EM ANDAMENTO\n");
		printf("[5] - LISTAR OS PROJETOS CONCLUIDOS\n");
		printf("[6] - LISTAR OS PROJETOS PELO CODIGO\n");
		printf("[0] - ENCERRAR\n\n");

		scanf("%d", &escolha);
		fflush(stdin);

		switch(escolha) {

				/*======================= CADASTRO =======================*/
			case 1:
				if(contador <= TAM) {
					system("cls");
					printf("===========================================\n");
					printf("|          CADASTRAR NOVO PROJETO         | \n");
					printf("===========================================\n");
					printf("\nCodigo do projeto: %d \n", contador+1);
					proj[contador].codigo = contador+1;

					printf("Titulo: ");
					fgets(proj[contador].titulo, 40, stdin);
					fflush(stdin);

					printf("Descricao: ");
					fgets(proj[contador].descricao, 100, stdin);
					fflush(stdin);

					printf("Ano: ");
					scanf("%d", &proj[contador].ano);
					fflush(stdin);

					printf("Tipo de projeto: ");
					fgets(proj[contador].tipo, 30, stdin);
					fflush(stdin);

					printf("Publico:");
					fgets(proj[contador].publico, 30, stdin);
					fflush(stdin);

					printf("Gerente de projetos responsavel: ");
					fgets(proj[contador].gerente, 50, stdin);
					fflush(stdin);

					printf("Orcamento do projeto: ");
					scanf("%f", &proj[contador].orcamento);
					fflush(stdin);

					printf("Status: \n");
					printf(" [1] - A fazer    [2] - Em andamento    [3] - Concluido \n");
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
					printf("Número maximo de cadastros atingido!");
					system("Pause");
				}
				break;

				/*====================== LISTAR TODOS ======================*/
			case 2:
				system("cls");
				if(contador != 0) {
					printf("===========================================\n");
					printf("|             TODOS OS PROJETOS           | \n");
					printf("===========================================\n");
					for(i=0; i<contador; i++) {
						printf("\n");
						printf("Codigo: %d\n", i+1);
						printf("Titulo: %s", proj[i].titulo);
						printf("Descricao: %s", proj[i].descricao);
						printf("Ano: %d\n", proj[i].ano);
						printf("Tipo de projeto: %s", proj[i].tipo);
						printf("Publico: %s", proj[i].publico);
						printf("Gerente de projetos responsavel: %s", proj[i].gerente);
						printf("Orcamento do projeto: %f\n", proj[i].orcamento);
						printf("Status: %d\n", proj[i].status);
						
					}
				} else {
					printf("\nLista vazia!\n");
				}
				system("Pause");
				break;

				/*==================== LISTAR PROJETOS - A FAZER ====================*/
			case 3:
				system("cls");
				if( status == 1) {
					printf("\nPROJETOS A FAZER\n");

					for(i=0; i<contador; i++) {
						printf("\n");
						printf("Codigo: %d\n", i+1);
						printf("Titulo: %s", proj[i].titulo);
						printf("Descricao: %s", proj[i].descricao);
						printf("Ano: %d\n", proj[i].ano);
						printf("Tipo de projeto: %s", proj[i].tipo);
						printf("Publico: %s", proj[i].publico);
						printf("Gerente de projetos responsavel: %s", proj[i].gerente);
						printf("Orcamento do projeto: %f\n", proj[i].orcamento);
						printf("Status: %d\n", proj[i].status);
					}

				} else {
					printf("\nNao existem projetos a fazer!\n");
				}
				system("Pause");
				break;

				/*=================== LISTAR PROJETOS - EM ANDAMENTO ===================*/
			case 4:
				system("cls");
				if( status == 2) {
					printf("\nPROJETOS EM ANDAMENTO\n");

					for(i=0; i<contador; i++) {
						printf("\n");
						printf("Codigo: %d\n", i+1);
						printf("Titulo: %s", proj[i].titulo);
						printf("Descricao: %s", proj[i].descricao);
						printf("Ano: %d\n", proj[i].ano);
						printf("Tipo de projeto: %s", proj[i].tipo);
						printf("Publico: %s", proj[i].publico);
						printf("Gerente de projetos responsavel: %s", proj[i].gerente);
						printf("Orcamento do projeto: %f\n", proj[i].orcamento);
						printf("Status: %d\n", proj[i].status);
					}
				} else {
					printf("\nNao existem projetos em andamento!\n");
				}
				system("Pause");
				break;

				/*=================== LISTAR PROJETOS - CONCLUÍDOS ===================*/
			case 5:
				system("cls");
				if( status == 3) {
					printf("\nPROJETOS CONCLUIDOS\n");

					for(i=0; i<contador; i++) {
						printf("\n");
						printf("Codigo: %d\n", i+1);
						printf("Titulo: %s", proj[i].titulo);
						printf("Descricao: %s", proj[i].descricao);
						printf("Ano: %d\n", proj[i].ano);
						printf("Tipo de projeto: %s", proj[i].tipo);
						printf("Publico: %s", proj[i].publico);
						printf("Gerente de projetos responsavel: %s", proj[i].gerente);
						printf("Orcamento do projeto: %f\n", proj[i].orcamento);
						printf("Status: %d\n", proj[i].status);
					}
				} else {
					printf("\nNao existem projetos concluido!\n");
				}
				system("Pause");
				break;

				/*==================== BUSCAR POR CÓDIGO ====================*/
			case 6:
				system("cls");
				printf("\nBUSCAR POR CODIGO\n");
				printf("Digite o codigo que deseja buscar: \n");
				scanf ("%d", &busca);
				fflush(stdin);
				j = 0;
				acha = 0;
				while((j < TAM) && (acha == 0)) {
					if (proj[j].codigo == busca) {
						printf("\nCodigo: %d\n", proj[j].codigo);
						printf("Titulo: %s", proj[j].titulo);
						printf("Descricao: %s", proj[j].descricao);
						printf("Ano: %d\n", proj[j].ano);
						printf("Tipo de projeto: %s", proj[j].tipo);
						printf("Publico: %s", proj[j].publico);
						printf("Gerente de projetos responsavel: %s", proj[j].gerente);
						printf("Orcamento do projeto: %f\n", proj[j].orcamento);
						printf("Status: %d\n", proj[j].status);
						acha = 1;
						system("Pause");
					}
					j++;
				}
				if(acha == 0) {
					printf("Projeto nao encontrado com o codigo %d\n", busca);
					system("Pause");
				}
				break;

				/*==================== ENCERRAR PROGRAMA ====================*/
			case 0:
				system("cls");
				printf("\nPROGRAMA ENCERRADO\n");
				break;
			default:
				system("cls");
				printf("\nOPCAO INVALIDA\n");
				system("Pause");
				break;
		}
	} while(escolha != 0);

	return(0);
}
