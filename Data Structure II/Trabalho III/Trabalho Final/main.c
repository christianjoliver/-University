/*
	UFES/CEUNES
	Professora: Luciana Lee;
	Disciplina: Estrutura de Dados II;
	Avaliacao 4: Algoritmo de Huffman;
	Equipe: Christian Jonas Oliveira e Joao Victor do Rozario Recla.
*/

#include "Huffman.h"



int print_menu(){

    setlocale(LC_ALL, "portuguese-brasilian");
	int i, op;
	system("clear");
	printf("\n");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");
	printf("\n\t | 1 - Compactar Arquivo\t\t|");
	printf("\n\t | 2 - Descompactar Arquivo\t\t|");
	printf("\n\t | 3 - Sair\t\t\t\t|");
	printf("\n");
	printf("\t ");
	for (i = 0; i<40; i++) printf("-");

    printf("\n\tDigite a operacao desejada: ");
	scanf("%d", &op);
    return op;

}


int main(){

    char *v;
    char *copia;
    Head *v2 = NULL;
    Codigo **vet;
    char *vet_aux;
    char *codigo;
    char *l;
    FILE *fp;
    char saida[50];
    int op;
    op=print_menu();
    int tamCODE = 0;
    int iCODE = 0;

    while(op!=3){

        if(op==1){

            v = readFile_Zip();

            printf("\n\t Digite o nome do arquivo de saida (sem o .txt): ");
	        fgets(saida, 50, stdin);
            saida[strcspn(saida, "\n")] = 0;
	        strcat(saida,".txt");

            copia = (char *)calloc(strlen(v), sizeof(char));
            strcpy(copia, v);

            QuickSort(v, 0, strlen(v)-1);

            v2 = count_Freq(v);

            imprime_Frequencia(v2);

            Huffman(v2);

            vet = (Codigo **)malloc(v2->qnt_elem * sizeof(Codigo));

            vet_aux = (char *)calloc(MAX, sizeof(char));

            codigo = (char *)calloc(MAX, sizeof(char));

            create_Code(v2->vetor[0], codigo, vet, vet_aux, &tamCODE, &iCODE);


            printa_Codigo(vet, v2->qnt_elem);

            printf("\n");
            l = create_vetSaida(vet, copia, v2);
            printf("\n");

            fp = fopen(saida, "wb");

            if(fp){

                zip_File(fp, l, v2, vet);
                destroy_Codigo(vet, v2->qnt_elem);
                free(v);
                free(copia);
	            free(v2);
	            free(vet_aux);
                free(codigo);
	            free(l);
                fclose(fp);
            }
            else printf("\n\tErro ao gerar arquivo de saida");
        }

        else if(op==2){
            getchar();
            printf("\n\t Digite o nome do arquivo a ser descompactado (sem o .txt): ");
	        fgets(saida, 50, stdin);
            saida[strcspn(saida, "\n")] = 0;
	        strcat(saida,".txt");

            fp = fopen(saida, "rb");

            if(fp){

                printf("\n\t Digite o nome do arquivo resultante (sem o .txt): ");
	            fgets(saida, 50, stdin);
                saida[strcspn(saida, "\n")] = 0;
	            strcat(saida,".txt");

                FILE *fp2 = fopen(saida, "w");

                if(fp2){
                    unzip_File(fp, fp2);
                    fclose(fp2);
                }

                else printf("\n\tErro ao gerar arquivo de saida");

                fclose(fp);
            }

            else printf("\n\tErro ao ler arquivo de entrada");

        }

        else if(op!=3)
            printf("\n\tErro ao ler arquivo de entrada");

        printf("\n\t Pressione enter para continuar...");
        getchar();

        iCODE = 0;
	    tamCODE = 0;
        op=print_menu();
    }

	return 0;
}