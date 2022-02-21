#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_BUFFER 256 // Verificar com o João se isso é considerado uma variável global e se poder ter no trabalho. (Dá para corrigir fácil se não puder)

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
    if (strcmp(senha, "\\sair") == 0) {
      printf("A operação foi cancelada\n");
      return 1;
    }
    if (strcmp(senha, "senha") != 0)
      printf("\nSenha incorreta, para cancelar a operação, digite \"\\sair\" em vez da senha\n");
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
  printf("\n");
  FILE *eventos = fopen("eventos", "r");
  if (eventos == NULL) // Caso o arquivo "eventos" não exista, criá-lo
    eventos = fopen("eventos", "w");
  fseek(eventos, 0, SEEK_END);
  if (ftell(eventos) == 0) // Se o arquivo estiver vazio, imprimir a mensagem:
    printf("Nenhum evento foi encontrado\n");

  char eventos_contents[TAMANHO_BUFFER];
  rewind(eventos);
  while (fgets(eventos_contents, TAMANHO_BUFFER, eventos) != NULL) // Imprimir todas as linhas do arquivo eventos
    printf("%s", eventos_contents);

  // Menu de opções
  int opcao;
  while (1) {
    fclose(eventos); eventos = fopen("eventos", "r");
    
    printf("\n\nComandos:\n");
    printf("1 - Criar um evento\n");
    printf("2 - Remover um evento\n");
    printf("3 - Remover todos os eventos\n");
    printf("4 - Recarregar eventos\n");
    printf("9 - Voltar\n");
    printf("Digite o número da opção => ");
    scanf("%d", &opcao);
    printf("\n");
    if (opcao == 9) {
      fclose(eventos);
      return;
    }
    
    if (opcao == 1) { // Adicionar um evento
      // O usuário ditará um evento por linha. Para que ele saia do modo de digitação, basta digitar "\sair".
      if (autenticacao() == 0) {
        fclose(eventos); eventos = fopen("eventos", "a");
        char eventreg_text[TAMANHO_BUFFER];
        eventreg_text[0] = '0'; // O while abaixo não executa se a string já for igual a "\sair". Esta linha corrige isso mudando 1 caractere da string
        printf("Digite os eventos a serem adicionados, separando-os por uma quebra de linha\nAo concluir, digite \"\\sair\"\n");
        
        while (strcmp(eventreg_text, "\\sair\n") != 0) {
          setbuf(stdin, NULL);
          fgets(eventreg_text, TAMANHO_BUFFER, stdin);
          if (strcmp(eventreg_text, "\\sair\n") != 0) // Impedir que a string "\sair" seja escrita no arquivo
            fputs(eventreg_text, eventos); // Vai lendo e já vai salvando no arquivo
        }
        printf("Os eventos foram gravados\n");
      }
    }

    if (opcao == 2) { // Remover um evento
      // Todos os eventos serão listados com um número de referência na frente. O usuário digtará um número e o evento correspondente será excluído
      if (autenticacao() == 0) {
        char arquivo_original[TAMANHO_BUFFER * 16] = {'\0'}; // Funciona com até 16 linhas de eventos, mude o número para suportar mais linhas
        int linha_deletar, linha_atual, i, c;
        for (i=0; i < TAMANHO_BUFFER*16; ++i)
          arquivo_original[i] = '\0';
        linha_atual=i=c = 0;

        rewind(eventos);
        while (fgets(eventos_contents, TAMANHO_BUFFER, eventos) != NULL) { // Imprimir todas as linhas com um número de referência na frente
          printf("%d | %s", i, eventos_contents);
          strcat(arquivo_original, eventos_contents); // Transferindo o conteúdo do arquivo para o vetor "arquivo_original"
          i++;
        }
        printf("\n");

        printf("\nInsira o número do evento que será deletado => ");
        linha_deletar=-1;
        while (linha_deletar >= i || linha_deletar < 0) // Impedir que números fora do intervalo sejam escritos
          scanf("%d", &linha_deletar);

        fclose(eventos); eventos = fopen("eventos", "w"); fclose(eventos); eventos = fopen("eventos", "a"); // Tenho que testar se toda essa anarquia é necessária...

        while (linha_atual < i) {
          if (linha_atual != linha_deletar) // Se a linha atual for igual à linha que será deletada, nada será impresso
            fprintf(eventos, "%c", arquivo_original[c]);
          if (arquivo_original[c] == '\n')
            linha_atual++;
          c++;
        }
      }
    }

    if (opcao == 3) { // Remover todos os eventos
      if (autenticacao() == 0) {
        char confirm[3];
        confirm[0] = '\0'; // Evitar que o while não seja executado na segunda vez que a opção é selecionada
        printf("Tem certeza que deseja remover todos os eventos? (Esta ação é definitiva)\n");
        while (strcmp(confirm, "sim") && strcmp(confirm, "nao")) {
          printf("Digite \"sim\" ou \"nao\" => ");
          scanf("%s", confirm);
        }
        if (strcmp(confirm, "sim") == 0) {
          fclose(eventos); eventos = fopen("eventos", "w");
        } else
          printf("Operação cancelada\n");
      }
    }

    if (opcao == 4) { // Recarregar eventos
      rewind(eventos);
      while (fgets(eventos_contents, TAMANHO_BUFFER, eventos) != NULL) // Imprimir todas as linhas do arquivo eventos
        printf("%s", eventos_contents);
    }
  }
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
