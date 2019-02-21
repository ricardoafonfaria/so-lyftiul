#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
	int numero;
	char nome[50];
	char turma[10];
	char telemovel[15];
	char email[40];
	char tipo[20];
	char marca[20];
	char matricula[15];
	int viagens;
	int pontos;
	float saldo;
	int activo;
	long disponivel_desde;
	int PID;
} Condutor;

typedef struct {
	int numero;
	char nome[50];
	char turma[10];
	char telemovel[15];
	char email[40];
	char c_credito[20];
} Passageiro;

int counter_condutores = 0;
int counter_passageiros = 0;

Condutor condutores[1024];
Passageiro passageiros[4096];


void ler_condutores() {
	FILE * f = fopen("condutores.txt", "r");
	char l[256];
	char converte2[50];
	while(fgets(l, 256, f) != NULL) {
		Condutor c;
		split(l, converte2, 0);
		c.numero = atoi(converte2);
		split(l, converte2, 1);
		strcpy(c.nome, converte2);
		split(l, converte2, 2);
		strcpy(c.turma, converte2);
		split(l, converte2, 3);
		strcpy(c.telemovel, converte2);
		split(l, converte2, 4);
		strcpy(c.email, converte2);
		split(l, converte2, 5);
		strcpy(c.tipo, converte2);
		split(l, converte2, 6);
		strcpy(c.marca, converte2);
		split(l, converte2, 7);
		strcpy(c.matricula, converte2);
		split(l, converte2, 8);
		c.viagens = atoi(converte2);
		split(l, tmp, 9);
		c.pontos = atoi(converte2);
		split(l, tmp, 10);
		c.saldo = atof(converte2);
		condutores[i] = c;
		i++;
	}
	fclose(f);

	void ler_passageiros() {
		FILE * f = fopen("passageiros.txt", "r");
		while(fgets(l, 256, f) != NULL) {
			Passageiro p;
			split(l, tmp, 0);
			p.numero = atoi(tmp);
			split(l, tmp, 1);
			strcpy(p.nome, tmp);
			split(l, tmp, 2);
			strcpy(p.turma, tmp);
			split(l, tmp, 3);
			strcpy(p.telemovel, tmp);
			split(l, tmp, 4);
			strcpy(p.email, tmp);
			split(l, tmp, 5);
			strcpy(p.c_credito, tmp);
			passageiros[counter_passageiros++] = p;
		}
		fclose(f);
	}

	void updateCondutores() {
		FILE * f = fopen("condutores.txt", "r");
		char l[256];
		char tmp[50];
		while(fgets(l, 256, f) != NULL) {
			split(l, tmp, 0);
			int numero = atoi(tmp);
			split(l, tmp, 8);
			int viagens = atoi(tmp);
			for (int i = 0; i < counter_condutores; ++i) {
				if(condutores[i].numero == numero && condutores[i].viagens != viagens) {
					condutores[i].viagens = viagens;
					split(l, tmp, 9); condutores[i].pontos = atoi(tmp);
					split(l, tmp, 10); condutores[i].saldo = atof(tmp);
				}
			}
		}
		fclose(f);
	}

	void rewriteFicheiros() {
		FILE * f = fopen("condutores.txt", "w");
		for (int i = 0; i < counter_condutores; i++) {
			Condutor c = condutores[i];
			fprintf(f, "%d:%s:%s:%s:%s:%s:%s:%s:%d:%d:%.1f\n", c.numero, c.nome, c.turma, c.telemovel, c.email, c.tipo, c.marca, c.matricula, c.viagens, c.pontos, c.saldo);
		}
		fclose(f);

		f = fopen("passageiros.txt", "w");
		for (int i = 0; i < counter_passageiros; i++) {
			Passageiro p = passageiros[i];
			fprintf(f, "%d:%s:%s:%s:%s:%s\n", p.numero, p.nome, p.turma, p.telemovel, p.email, p.c_credito);
		}
		fclose(f);
	}

	void printMemory() {
		printf("\nCondutores:\n");
		for (int i = 0; i < counter_condutores; i++) {
			Condutor c = condutores[i];
			printf("%d:%s:%s:%s:%s:%s:%s:%s:%d:%d:%.1f\n", c.numero, c.nome, c.turma, c.telemovel, c.email, c.tipo, c.marca, c.matricula, c.viagens, c.pontos, c.saldo);
		}
		printf("\nPassageiros:\n");
		for (int i = 0; i < counter_passageiros; i++) {
			Passageiro p = passageiros[i];
			printf("%d:%s:%s:%s:%s:%s", p.numero, p.nome, p.turma, p.telemovel, p.email, p.c_credito);
		}
	}

	void updatePassageiro() {
		char tmp[50];
		printf("\nInsira o número de aluno do passageiro que quer alterar\n");
		fgets(tmp, 50, stdin);
		int exists = 0;
		for (int i = 0; i < counter_passageiros; ++i) {
			if(passageiros[i].numero == atoi(tmp)) {
				exists = 1;
				char tmp[50];
				while (atoi(tmp) != 6) {
					printf("\nSelecione uma opção:\n1 - Alterar nome\n2 - Alterar turma\n3 - Alterar número de telemóvel\n4 - Alterar email\n5 - Alterar cartão de crédito\n6 - Sair\n");
					fgets(tmp, 50, stdin);
					switch (atoi(tmp)){
						case 1:
						printf("\nInsira o novo nome\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(passageiros[i].nome, tmp);
							printf("\nNome alterado com sucesso!\n");	
						} else {
							printf("Erro, tente outra vez...\n");
						} 
						break;
						case 2:
						printf("\nInsira a nova turma\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {	
							strtok(tmp, "\n");
							strcpy(passageiros[i].turma, tmp);
							printf("\nTurma alterada com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}
						break;
						case 3:
						printf("\nInsira o novo telemóvel\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(passageiros[i].telemovel, tmp);
							printf("\nNúmero de telemóvel alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}
						break;
						case 4:
						printf("\nInsira o novo email\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(passageiros[i].email, tmp);
							printf("\nEmail alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}
						break;
						case 5:
						printf("\nInsira o novo cartão de crédito\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(passageiros[i].c_credito, tmp);
							printf("\nCartão de crédito alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}
						break;
						case 6:
						menu();
						break;
						default:
						printf("\nSelecione uma opção válida.\n");
						break;
					}
				}
			} 
		}
		if (!exists) {
			printf("\nNão existe nenhum passageiro com esse número de aluno.\n");
		}
	}

	void updateCondutor() {
		char tmp[50];
		printf("\nInsira o número de aluno do condutor que quer alterar\n");
		fgets(tmp, 50, stdin);
		int exists = 0;
		for (int i = 0; i < counter_condutores; i++) {
			if(condutores[i].numero == atoi(tmp)) {
				exists = 1;
				char tmp[50];
				while (atoi(tmp) != 8) {
					printf("\nSelecione uma opção:\n1 - Alterar nome\n2 - Alterar turma\n3 - Alterar número de telemóvel\n4 - Alterar email\n5 - Alterar tipo da viatura\n6 - Alterar marca da viatura\n7 - Alterar matricula\n8 - Sair\n");
					fgets(tmp, 50, stdin);
					switch (atoi(tmp)){
						case 1:
						printf("\nInsira o novo nome\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].nome, tmp);
							printf("\nNome alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 2:
						printf("\nInsira a nova turma\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].turma, tmp);
							printf("\nTurma alterada com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 3:
						printf("\nInsira o novo telemóvel\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].telemovel, tmp);
							printf("\nNúmero de telemóvel alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 4:
						printf("\nInsira o novo email\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].email, tmp);
							printf("\nEmail alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 5:
						printf("\nInsira o novo tipo de viatura\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].tipo, tmp);
							printf("\nTipo de viatura alterado com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 6:
						printf("\nInsira a nova marca da viatura\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].marca, tmp);
							printf("\nMarca da viatura alterada com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 7:
						printf("\nInsira a nova matrícula\n");
						fgets(tmp, 50, stdin);
						if(!invalid(tmp)) {
							strtok(tmp, "\n");
							strcpy(condutores[i].matricula, tmp);
							printf("\nMatrícula alterada com sucesso!\n");
						} else {
							printf("Erro, tente outra vez...\n");
						}break;
						case 8: 
						menu();
						break;
						default:
						printf("\nSelecione uma opção válida.\n");
						break;
					}
				}
			} 
		}
		if (!exists) {
			printf("\nNão existe nenhum condutor com esse número de aluno.\n");
		}
	}

	void menu(){
		char tmp[10];
		while (atoi(tmp) != 4) {
			printf("\nSelecione uma opção:\n1 - Imprimir memória\n2 - Alterar passageiro\n3 - Alterar condutor\n4 - Sair\n");
			fgets(tmp, 10, stdin);
			switch (atoi(tmp)){
				case 1: printMemory();
				break;
				case 2: updatePassageiro();
				break;
				case 3: updateCondutor();
				break;
				case 4: exit(0);
				default:
				printf("\nSelecione uma opção válida.\n");
				break;
			}
		}
	}

	void dealWithSignal(int signal) {
		if ( signal == SIGUSR1 )
			updateCondutores();
		else if ( signal == SIGTERM ) {
			rewriteFicheiros();
			exit(0);
		} else if (signal == SIGALRM ) {
			int id = fork();
			if (id == 0) {
				execl("/home/a82897/trabalho/LyftTask", "LyftTask", NULL);
				exit(0);
			}
			wait(NULL);
		}
	}

	void main() {
		FILE * f = fopen("lyftadmin.pid","w");
		fprintf(f, "%d", getpid());
		fclose(f);
		writeToMemory();
		signal(SIGUSR1, dealWithSignal);
		signal(SIGTERM, dealWithSignal);
		signal(SIGALRM, dealWithSignal);
		while(1){
			alarm (60);
			menu();
		}
	}
