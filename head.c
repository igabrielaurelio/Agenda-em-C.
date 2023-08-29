#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int menu(){
	
	int i;
	
	printf("Bem-vindo a agenda em C, porfavor Selecione o que deseja fazer:\n");
	printf("[1] Criar um Contato\n");
	printf("[2] Acessar um Contato\n");
	printf("[3] Editar um Contato\n");
	printf("[4] Apagar um Contato\n");
	printf("[0] Para Sair\n");
	scanf("%d", &i);
	fflush(stdin);
	
	return i;
}
void criarcontato(){
	
	char nome[50], email[50], telefone[15];
	
	printf("Digite seu nome:\n");
		fgets(nome, sizeof(nome), stdin);
		system("cls");
	printf("Digite o seu email:\n");
		fgets(email, sizeof(email), stdin);
		system("cls");
	printf("Digite o seu telefone:\n");
		fgets(telefone, sizeof(telefone), stdin);
		system("cls");
		
	FILE *arquivo;
	
	arquivo = fopen("arquivo.txt", "a");
	
		if(arquivo == NULL){
		printf("ERRO! Arquivo txt nao encontrado.");
		exit(1);	
	}
	
    fprintf(arquivo, "Nome: %s", nome);
    fprintf(arquivo, "Email: %s", email);
    fprintf(arquivo, "Telefone: %s", telefone);
	
	fclose(arquivo);
}
void acessarcontato() {
	
    char buscarcontato[50];
    int encontrou = 0;

    printf("Qual nome do contato que voce gostaria de consultar?\n");
    fgets(buscarcontato, sizeof(buscarcontato), stdin);
    buscarcontato[strcspn(buscarcontato, "\n")] = '\0';

    system("pause");
    system("cls");

    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.");
        exit(1);
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[50];
        if (sscanf(linha, "Nome: %s", nome) == 1) {
            if (strcmp(nome, buscarcontato) == 0) {
                printf("Informacoes do contato:\n");
                printf("%s\n", linha);
                fgets(linha, sizeof(linha), arquivo);
                printf("%s\n", linha);
                fgets(linha, sizeof(linha), arquivo);
                printf("%s\n", linha);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou) {
        printf("Contato nao encontrado.\n");
    }

    fclose(arquivo);
}
tipodeedicao(){
	
	int i;
	
	printf("Digite [1] para editar o nome\n");
	printf("Digite [2] para editar o email\n");
	printf("Digite [3] para editar o numero\n");
	scanf("%d", &i);
	fflush(stdin);
	system("cls");
	return i;	
}
void editarnome() {
	
    char nome[50];
    int encontrou = 0;
    
    FILE *arquivo;
    FILE *arquivotmp;

    arquivo = fopen("arquivo.txt", "r");
    arquivotmp = fopen("arquivotmp.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo nao foi encontrado");
        exit(1);
    }

    if (arquivotmp == NULL) {
        printf("Erro ao abrir arquivo temporario");
        fclose(arquivo);
        exit(1);
    }
    
        printf("Informe o nome do usuario que voce gostaria de editar:\n");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        char linha[100];
        char novonome[100];

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (strstr(linha, nome)) {
                encontrou = 1;
                printf("Digite o novo nome:\n");
                fgets(novonome, sizeof(novonome), stdin);
                novonome[strcspn(novonome, "\n")] = '\0';
                fprintf(arquivotmp, "Nome: %s\n", novonome);
            } else {
                fputs(linha, arquivotmp);
        }
    }

    fclose(arquivo);
    fclose(arquivotmp);


    if(!encontrou) {
        printf("Nome nao encontrado\n");
        remove("arquivotmp.txt");
    } else {
        remove("arquivo.txt");
        rename("arquivotmp.txt", "arquivo.txt");
    }
}
void editartelefone() {
	
    char telefone[15];
    int encontrou = 0;
    
    FILE *arquivo;
    FILE *arquivotmp;

    arquivo = fopen("arquivo.txt", "r");
    arquivotmp = fopen("arquivotmp.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo nao foi encontrado");
        exit(1);
    }

    if (arquivotmp == NULL) {
        printf("Erro ao abrir arquivo temporario");
        fclose(arquivo);
        exit(1);
    }
    
        printf("Informe o telefone do usuario que voce gostaria de editar:\n");
        fgets(telefone, sizeof(telefone), stdin);
        telefone[strcspn(telefone, "\n")] = '\0';

        char linha[100];
        char novotelefone[15];

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (strstr(linha, telefone)) {
                encontrou = 1;
                printf("Digite o novo telefone:\n");
                fgets(novotelefone, sizeof(novotelefone), stdin);
                novotelefone[strcspn(novotelefone, "\n")] = '\0';
                fprintf(arquivotmp, "Telefone: %s\n", novotelefone);
            } else {
                fputs(linha, arquivotmp);
        }
    }

    fclose(arquivo);
    fclose(arquivotmp);


    if(!encontrou) {
        printf("Nome nao encontrado\n");
        remove("arquivotmp.txt");
    } else {
        remove("arquivo.txt");
        rename("arquivotmp.txt", "arquivo.txt");
    }
}
void editaremail() {
	
    char email[50];
    int encontrou = 0;
    
    FILE *arquivo;
    FILE *arquivotmp;

    arquivo = fopen("arquivo.txt", "r");
    arquivotmp = fopen("arquivotmp.txt", "w");

    if (arquivo == NULL) {
        printf("Arquivo nao foi encontrado");
        exit(1);
    }

    if (arquivotmp == NULL) {
        printf("Erro ao abrir arquivo temporario");
        fclose(arquivo);
        exit(1);
    }
    
        printf("Informe o email do usuario que voce gostaria de editar:\n");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        char linha[100];
        char novoemail[100];

        while (fgets(linha, sizeof(linha), arquivo)) {
            if (strstr(linha, email)) {
                encontrou = 1;
                printf("Digite o novo email:\n");
                fgets(novoemail, sizeof(novoemail), stdin);
                novoemail[strcspn(novoemail, "\n")] = '\0';
                fprintf(arquivotmp, "Email: %s\n", novoemail);
            } else {
                fputs(linha, arquivotmp);
        }
    }

    fclose(arquivo);
    fclose(arquivotmp);


    if(!encontrou) {
        printf("Nome nao encontrado\n");
        remove("arquivotmp.txt");
    } else {
        remove("arquivo.txt");
        rename("arquivotmp.txt", "arquivo.txt");
    }
}
void apagacontato() {
	
    char nome[100];
    char linha[100];
    int encontrou = 0, i;

    printf("Digite o nome do contato que você deseja apagar:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    FILE *arquivo;
    FILE *arquivotmp;

    arquivo = fopen("arquivo.txt", "r"); 
    arquivotmp = fopen("arquivotmp.txt", "a"); 

    if (arquivotmp == NULL) {
        printf("Erro ao abrir arquivotmp.txt\n");
        exit(1);
    }
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.txt\n");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, nome) != NULL) {
            encontrou = 1;
            
            
        for(i=0;i<2;i++){
        	if (fgets(linha, sizeof(linha), arquivo) == NULL){
        		break;
				}
			}
			continue;	
        }
        fprintf(arquivotmp, "%s", linha);
    }

    fclose(arquivo);
    fclose(arquivotmp);

    if (encontrou) {
        remove("arquivo.txt");
        rename("arquivotmp.txt", "arquivo.txt");
        printf("Contato apagado com sucesso.\n");
    } else {
        remove("arquivotmp.txt");
        printf("Contato não encontrado.\n");
    }
}
