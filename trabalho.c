#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a_definir{
	//inserir código aqui
};

int autenticacao() {
  // Solicita que o usuário digite uma senha até ele acertar. Quando ele acerta, é retornado 0; quando ele opta por sair, é retornado 1.
  // Não tem criptografia nenhuma, é só para demonstrar
  char senha[10] = {};
  printf("Para executar esse comando, é necessário informar a senha de administração.\n");
  
  while (strcmp(senha, "senha") != 0) {
  printf("Digite a senha => ");
  scanf("%s", senha); printf("\n");
  if (strcmp(senha, "sair") == 0) {
    printf("A operação foi cancelada\n");
    return 1;
  }
  if (strcmp(senha, "senha") != 0)
    printf("\nSenha incorreta, para cancelar a operação, digite \"sair\" em vez da senha\n");
  }
  
  return 0;
}

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
  FILE *eventos = fopen("eventos", "r");
  if (eventos == NULL) { // Caso o arquivo "eventos" não exista, criá-lo
    printf("Nenhum evento foi encontrado\n");
    eventos = fopen("eventos", "w");
  }
  char eventos_contents[300];
  while (fgets(eventos_contents, 300, eventos) != NULL) // Imprimir todas as linhas do arquivo eventos
    printf("%s", eventos_contents);

  // Menu de opções
  int opcao;
  while (1) {
    printf("\nComandos:\n");
    printf("1 - Criar um evento\n");
    printf("2 - Remover um evento\n");
    printf("3 - Remover todos os eventos\n");
    printf("9 - Voltar\n");
    printf("Digite o número da opção => ");
    scanf("%d", &opcao);
    printf("\n");
    if (opcao == 9) {
      return;
      fclose(eventos);
    }
    if (opcao == 1) {
      if (autenticacao() == 0) {
	fclose(eventos); eventos = fopen("eventos", "a");
	char eventctl_register_text[300];
        printf("Digite os eventos a serem adicionados, separando-os por uma quebra de linha\nAo concluir, digite \"\\sair\"\n");
	while (strcmp(eventctl_register_text, "\\sair\n") != 0) {
	  fgets(eventctl_register_text, 300, stdin);
	  if (strcmp(eventctl_register_text, "\\sair\n") != 0) // Impedir que a string "\sair" seja escrita no arquivo
	    fputs(eventctl_register_text, eventos); // Vai lendo e já vai salvando no arquivo
	}
	fclose(eventos); eventos = fopen("eventos", "r");
	printf("Os eventos foram gravados\n");
      }
    }
  }

  exit(0); //Testing
  return;
}

void menu(){
  eventos(); //Testing
  
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
