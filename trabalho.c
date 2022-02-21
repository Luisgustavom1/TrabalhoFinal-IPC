#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a_definir{
	//inserir código aqui
};

typedef struct feedback_struct{
    char coment_feedback[1000];
    char nome_feedback[60];
    char nota_feedback[2];
}feedback_struct;


void cadastro(struct a_definir T[]){
	//inserir código aqui
}

void mostra(struct a_definir T[]){
	//inserir código aqui
}

void mostra1(struct a_definir T[]){
	//inserir código aqui
}

void coleta_feedback( feedback_struct F2[] ){
    FILE *feedback_arq;
    if (feedback_arq == NULL) feedback_arq = fopen("feedback.txt", "w");
    feedback_arq = fopen("feedback.txt", "a");

    setbuf(stdin, NULL);
    printf("\nEscreva seu nome: ");
    scanf("%[^\n]s", F2[0].nome_feedback);
    fputs("Nome: ", feedback_arq);
    fputs(F2[0].nome_feedback, feedback_arq);
    fputc('\n', feedback_arq);

    setbuf(stdin, NULL);
    printf("\nDeixe uma nota (0 a 5): ");
    scanf("%s", F2[0].nota_feedback);
    fputs("Nota: ", feedback_arq);
    fputs(F2[0].nota_feedback, feedback_arq);
    fputc('\n', feedback_arq);

    setbuf(stdin, NULL);
    printf("\nAdicione um comentario: ");
    scanf("%[^\n]s", F2[0].coment_feedback);
    fputs("Feedback: ", feedback_arq);
    fputs(F2[0].coment_feedback, feedback_arq);
    fputc('\n', feedback_arq);
    fputc('\n', feedback_arq);

    fclose(feedback_arq);

    setbuf(stdin, NULL);
}

void mostra_contatos(){
    printf("\ninstagram: resort_instagram\n");
    printf("gmail: resort@gmail.com\n");
    printf("Telefone: (34)99877-0392\n");
}


void menu(){
	int opcao;
	struct a_definir P[30];
	struct feedback_struct F[30];


	while(1){
		printf("\nBem vindo ao Sistema de um resort");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
		printf("\n5- Deixe seu Feedback");
		printf("\n7- Mostrar Contatos");
		printf("\n9- Sair ");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);

		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(P);
		if(opcao == 5) coleta_feedback(F);
		if(opcao == 7) mostra_contatos();
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}

