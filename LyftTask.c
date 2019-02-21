#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

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
} Condutor;

Condutor condutores[1024];

int counter_condutores = 0;

void split(char in[], char out[],  int index) {
	int j=0, k=0;
	for (int i=0; in[i] != '\0'; i++) {
		if ( in[i] == ':' ) {
			k++;
		} else if (k == index) {
			out[j++]=in[i];
		}
	}	
	out[j]='\0';
}

int main() {

	FILE * f = fopen("viagens.txt", "r");
	if (f != NULL) {
		fseek (f, 0, SEEK_END);
		if (ftell(f) != 0) {
			fclose(f);			
			f = fopen("condutores.txt", "r");
			char l[256];
			char tmp[50];
			while(fgets(l, 256, f) != NULL) {
				Condutor c;
				split(l, tmp, 0);
				c.numero = atoi(tmp);
				split(l, tmp, 1);
				strcpy(c.nome, tmp);
				split(l, tmp, 2);			
				strcpy(c.turma, tmp);
				split(l, tmp, 3);			
				strcpy(c.telemovel, tmp);
				split(l, tmp, 4);			
				strcpy(c.email, tmp);
				split(l, tmp, 5);
				strcpy(c.tipo, tmp);
				split(l, tmp, 6);
				strcpy(c.marca, tmp);
				split(l, tmp, 7);
				strcpy(c.matricula, tmp);
				split(l, tmp, 8);
				c.viagens = atoi(tmp);
				split(l, tmp, 9);
				c.pontos = atoi(tmp);
				split(l, tmp, 10);
				c.saldo = atof(tmp);
				condutores[counter_condutores++] = c;
			}
			fclose(f);
			f = fopen("viagens.txt", "r");
			while(fgets(l, 256, f) != NULL) {
				for(int i = 0; i < counter_condutores; i++) {
					split(l, tmp, 1);
					if ( condutores[i].numero == atoi(tmp) ) {
						condutores[i].viagens++;
						split(l, tmp, 3);
						condutores[i].pontos += atoi(tmp);
						split(l, tmp, 4);
						condutores[i].saldo += atof(tmp);
					}
				}
			}
			fclose(f);
			f = fopen("condutores.txt", "w");
			for (int i = 0; i < counter_condutores; i++) {
				Condutor c = condutores[i];
				fprintf(f,"%d:%s:%s:%s:%s:%s:%s:%s:%d:%d:%.1f\n", c.numero, c.nome, c.turma, c.telemovel, c.email, c.tipo, c.marca, c.matricula, c.viagens, c.pontos, c.saldo);
			}
			fclose(f);

			f = fopen("lyftadmin.pid","r");
			if (f != NULL) {
				fgets(tmp, 10, f);
				kill (atoi(tmp), SIGUSR1);
				fclose(f);
			}
		}
		f = fopen("viagens.txt", "w");
		fclose(f);
	}
}