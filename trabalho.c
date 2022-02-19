#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a_definir{
	//inserir código aqui
};


void cadastro(struct a_definir T[]){
	//inserir código aqui
}

void mostra(struct a_definir T[]){
	//inserir código aqui
}

void mostra1(struct a_definir T[]){
	//inserir código aqui
}

void mostra_contatos(){
    printf("\ninstagram: resort_instagram\n");
    printf("gmail: resort@gmail.com\n");
    printf("Telefone: (34)99877-0392\n");
}


void menu(){
	int opcao;
	struct a_definir P[30];

	while(1){
		printf("\nBem vindo ao Sistema de... ");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
		printf("\n7- Mostrar Contatos");
		printf("\n9- Sair ");
		printf("\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(P);
		if(opcao == 7) mostra_contatos();
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}

