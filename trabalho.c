#include <stdio.h>
#include <stdlib.h>

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

void eventos() {
  // Os eventos serão guardados em um arquivo para melhor organização
  FILE *eventos;
  eventos = fopen("eventos", "r");
  if (eventos == NULL) { // Caso o arquivo "eventos" não exista, criá-lo
    printf("Nenhum evento foi encontrado\n");
    //fclose(eventos);
    eventos = fopen("eventos", "w");
  } else
    printf("O arquivo foi encontrado\n");

  return;
  
  // Daqui pra baixo eu tô testando os ngc e é pura anarquia
  int input_max = 200;
  char eventctl_register_text[input_max];
  while (fgets(eventctl_register_text, input_max, eventos) != NULL) {
    printf("%s\n", eventctl_register_text);
  }

  //#########################################
  int x, y;
  fprintf(eventos, "Teste");
  fscanf(eventos, "%d %d", &x, &y);
  fclose(eventos);
}

void menu(){
	int opcao;
	struct a_definir P[30];

	while(1){
		printf("\nBem vindo ao Sistema de... ");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
		printf("\n4- Mostrar todos os lazeres/atrações/eventos");
		printf("\n9- Sair ");
		printf("\nDigite opção: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		if(opcao == 2) mostra(P);
		if(opcao == 3) mostra1(P);
		if(opcao == 4) eventos();
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}
