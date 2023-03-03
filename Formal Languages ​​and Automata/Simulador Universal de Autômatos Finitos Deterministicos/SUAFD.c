/*

	Trabalho 1 - Simulador Universal de Automatos Finitos Deterministicos (AFD)
	
	Disciplina: Linguagens Formais e Automatos
	Aluno: Christian Jonas Oliveira
	Matricula: 2018205888

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transicao{
    int i, f;
    char elem;
}Transition;

Transition *create_Transition(int ini, int fim, char ele){
    Transition *ptr = NULL;
    ptr = (Transition *)calloc(1, sizeof(Transition));
    if (ptr){
        ptr->i = ini;
        ptr->f = fim;
        ptr->elem = ele;
    }
    return ptr;
}

int verificaPertinencia(char e, char s[]){
	int j=0;
	for(int i=0; i<strlen(s); i++) if(e==s[i]) j=1;
	return j;
}

int verificaFinal(int pos, int Aceitacao[], int qntFinais){
	int aux = 0;
	for(int i=0; i<qntFinais; i++)
		if(Aceitacao[i]==pos) aux = 1;
	return aux;
}

int verificaCaminho(char e, Transition **t, int tam, int pos){
    int k = -1;
	for(int c = 0; c<tam; c++){
		if(t[c]->i==pos && t[c]->elem==e){
		    k = t[c]->f;
		    break;
		}
	}
	return k;
}

int verificaCadeia(char *cadeia, Transition *t[], int Aceitacao[], char s[], int qntFinais, int qTransicoes){
	int p = 1;
	int aux = 0;

	// verifica se a cadeia passada eh uma cadeia vazia
	if(verificaFinal(0, Aceitacao, qntFinais) && cadeia[0]=='-') return 1;

	// verifica os caracteres da cadeia estao no alfabeto
	for(int i = 0; i<strlen(cadeia); i++){
		if (verificaPertinencia(cadeia[i], s)==0) return 0;
	}

	// verifica se a cadeia eh valida
	for(int i=0; i<strlen(cadeia); i++){
		aux = verificaCaminho(cadeia[i], t, qTransicoes, aux);
		if(aux==-1){
			p = 0;
			break;
		}
	}

	// verifica se a cadeia passada termina em um estado final
	if(p==1)
		p = verificaFinal(aux, Aceitacao, qntFinais);
	return p;
}

int main(){
    int qEstados, qSimbolos, qTermos, qIniciais, qAceitacao, qTransicoes, ini, f, qCadeias;
    char e;

    scanf("%d", &qEstados);
    scanf("%d", &qSimbolos);
    char simb[qSimbolos];
    for(int i=0; i<qSimbolos; i++){
        getchar();
        scanf("%c", &simb[i]);
    }

    scanf("%d", &qIniciais);
    scanf("%d", &qAceitacao);
    int eAceitacao[qAceitacao];
    for(int i=0; i<qAceitacao; i++) scanf("%d", &eAceitacao[i]);

    scanf("%d", &qTransicoes);
    Transition *vet[qTransicoes];
    for(int i=0; i<qTransicoes; i++){
        scanf("%d", &ini);
        getchar();
        scanf("%c", &e);
        scanf("%d", &f);
        Transition *ptr = create_Transition(ini, f, e);
        vet[i] = ptr;
    }
    scanf("%d", &qCadeias);
	char *cadeia;
	for(int i = 0; i<qCadeias; i++){
		cadeia = (char *)calloc(1, 20*sizeof(char));
		scanf("%s", cadeia);
		if(verificaCadeia(cadeia, vet, eAceitacao, simb, qAceitacao, qTransicoes)) printf("aceita\n");
		else printf("rejeita\n");
	}
}