#include <stdio.h>
#include "t1.h"

unsigned char FIFO = 1;
unsigned char RR = 2;

int main() {
	TAREFA tarefas[MAX_TAREFAS];
	unsigned num_tarefas, i, tempo;
	int continua;
	Queue *rr_flag = NULL;

	/* Inicia leitura... */
	scanf("%u",&num_tarefas);
	while (num_tarefas > 0) {
		tempo = 0;
		Queue fila_prioridades[32];

		for (i = 0; i < 32; i++){
			fila_prioridades[i].head = NULL;
			fila_prioridades[i].tail = NULL;
		}

		/* LEITURA */
		for (i=0;i<num_tarefas;++i) {
			tarefas[i].id = 'A'+i;
			scanf("%u %u %u %u",&(tarefas[i].c), &(tarefas[i].s),
								&(tarefas[i].p), &(tarefas[i].sched));
		}

		while(1){
			int parado = 1;
			continua = 0;
			for(i = 0; i < num_tarefas; i++)
				if(tarefas[i].s >= tempo) {continua = 1; break;}
			for(i = 0; i < 32; i++)
				if(size(&fila_prioridades[i]) > 0) {continua = 1; break;}
			if(!continua) break;
			//Simulacao
			for(i = 0; i < num_tarefas; i++)
				if(tarefas[i].s == tempo)
					push(&(fila_prioridades[tarefas[i].p - 1]),&tarefas[i]);
			tempo++;
			if(rr_flag != NULL){
				TAREFA *frente = pop(rr_flag);
				push(rr_flag,frente);
				rr_flag = NULL;
			}
			for(i = 0; i < 32; i++){
				if(size(&fila_prioridades[i]) > 0){
					TAREFA* frente = peek(fila_prioridades[i]);
					frente->c -= 1;
					putchar(frente->id);
					if(frente->c > 0){
						if(frente->sched == RR) rr_flag = &(fila_prioridades[i]);
					}
					else{
						pop(&(fila_prioridades[i]));
					}
					parado = 0; break;
				}
			}
			if(parado) putchar('.');
		}
		printf("\n\n");
		/* Inicia nova leitura... */
		scanf("%u",&num_tarefas);
	}
	return 0;	
}
