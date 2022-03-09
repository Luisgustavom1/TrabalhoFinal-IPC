#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a_definir
{
  // inserir código aqui
};

struct Cliente
{
  char nome[100], cpf[30], nasc[20], profissao[50], nacionalidade[30], idade[10], sexo[20], id[30], endereco[100], cep[30], telefone[30], cidade[50], estado[50], pais[30], email[30];
};

typedef struct Feedback_struct
{
  char coment_feedback[1000];
  char nome_feedback[60];
  char nota_feedback[2];
} Feedback_struct;

struct Feedback
{
  char feedback[100];
  char name[60];
  int stars;
};

int autenticacao()
{
  // Solicita que o usuário digite uma senha até ele acertar. Quando ele acerta, é retornado 0; quando ele opta por sair, é retornado 1.
  // Não tem criptografia nenhuma, é só para demonstrar
  char senha[10] = {};
  printf("Para executar esse comando, é necessário informar a senha de administração.\n");

  while (strcmp(senha, "senha") != 0)
  {
    printf("Digite a senha => ");
    scanf("%s", senha);
    printf("\n");
    if (strcmp(senha, "\\sair") == 0)
    {
      printf("A operação foi cancelada\n");
      return 1;
    }
    if (strcmp(senha, "senha") != 0)
      printf("\nSenha incorreta, para cancelar a operação, digite \"\\sair\" em vez da senha\n");
  }

  return 0;
}

void cadastro(struct Cliente T[])
{
  FILE *f;

  f = fopen("usuarios.txt", "a");
  if (f == NULL)
  {
    printf("Arquivo nao pode ser aberto");
    exit(1);
  }

  int i, confirma;
  for (i = 0;; i++)
  {
    setbuf(stdin, NULL);
    printf("Nome completo:\n");
    scanf("%[^\n]s", T[i].nome);
    setbuf(stdin, NULL);
    printf("\n");

    printf("CPF:\n");
    scanf("%[^\n]s", T[i].cpf);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Identidade(apenas o numero):\n");
    scanf("%[^\n]s", T[i].id);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Data de nascimento:\n");
    scanf("%[^\n]s", T[i].nasc);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Nacionalidade:\n");
    scanf("%[^\n]s", T[i].nacionalidade);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Idade:\n");
    scanf("%[^\n]s", T[i].idade);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Sexo(M/F):\n");
    scanf("%[^\n]s", T[i].sexo);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Profissao:\n");
    scanf("%[^\n]s", T[i].profissao);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Endereco:\n");
    scanf("%[^\n]s", T[i].endereco);
    setbuf(stdin, NULL);
    printf("\n");

    printf("CEP:\n");
    scanf("%[^\n]s", T[i].cep);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Telefone:\n");
    scanf("%[^\n]s", T[i].telefone);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Cidade:\n");
    scanf("%[^\n]s", T[i].cidade);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Estado:\n");
    scanf("%[^\n]s", T[i].estado);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Pais:\n");
    scanf("%[^\n]s", T[i].pais);
    setbuf(stdin, NULL);
    printf("\n");

    printf("E-mail:\n");
    scanf("%[^\n]s", T[i].email);
    setbuf(stdin, NULL);
    printf("\n");

    printf("Nome: %s\n", T[i].nome);
    printf("CPF: %s\n", T[i].cpf);
    printf("Identidade: %s\n", T[i].id);
    printf("Data de nascimento: %s\n", T[i].nasc);
    printf("Nacionalidade: %s\n", T[i].nacionalidade);
    printf("Idade: %s\n", T[i].idade);
    printf("Sexo: %s\n", T[i].sexo);
    printf("Profissao: %s\n", T[i].profissao);
    printf("Endereco: %s\n", T[i].endereco);
    printf("CEP: %s\n", T[i].cep);
    printf("Telefone: %s\n", T[i].telefone);
    printf("Cidade: %s\n", T[i].cidade);
    printf("Estado: %s\n", T[i].estado);
    printf("Pais: %s\n", T[i].pais);
    printf("E-mail: %s\n", T[i].email);
    printf("\n");

    printf("Confirmar cadastro ?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &confirma);

    if (confirma == 1)
    {
      fprintf(f, "Nome: %s\n", T[i].nome);
      fprintf(f, "CPF: %s\n", T[i].cpf);
      fprintf(f, "Identidade: %s\n", T[i].id);
      fprintf(f, "Data de nascimento: %s\n", T[i].nasc);
      fprintf(f, "Nacionalidade: %s\n", T[i].nacionalidade);
      fprintf(f, "Idade: %s\n", T[i].idade);
      fprintf(f, "Sexo: %s\n", T[i].sexo);
      fprintf(f, "Profissao: %s\n", T[i].profissao);
      fprintf(f, "Endereco: %s\n", T[i].endereco);
      fprintf(f, "CEP: %s\n", T[i].cep);
      fprintf(f, "Telefone: %s\n", T[i].telefone);
      fprintf(f, "Cidade: %s\n", T[i].cidade);
      fprintf(f, "Estado: %s\n", T[i].estado);
      fprintf(f, "Pais: %s\n", T[i].pais);
      fprintf(f, "E-mail: %s\n", T[i].email);
      fprintf(f, "\n");
      return;
    }

    fclose(f);
  }
}

void eventos()
{
  // Os eventos serão guardados em um arquivo para melhor organização
  const int TAMANHO_BUFFER = 256; // Máximo de caracteres que podem ser inseridos por linha
  printf("\n");
  FILE *eventos = fopen("eventos", "r");
  if (eventos == NULL) // Caso o arquivo "eventos" não exista, criá-lo
    eventos = fopen("eventos", "w");
  char eventos_contents[TAMANHO_BUFFER]; // Variável será usada para imprimir o conteúdo do arquivo "eventos"

  int opcao;
  while (1)
  {
    fclose(eventos);
    eventos = fopen("eventos", "r");
    printf("\n");
    while (fgets(eventos_contents, TAMANHO_BUFFER, eventos) != NULL) // Imprimir todas as linhas do arquivo eventos
      printf("%s", eventos_contents);

    rewind(eventos);
    fseek(eventos, 0, SEEK_END);
    if (ftell(eventos) == 0) // Se o arquivo estiver vazio, imprimir a mensagem:
      printf("Nenhum evento foi encontrado\n");

    // Menu de opções
    printf("\n\nComandos:\n");
    printf("Qualquer tecla - Recarregar eventos\n");
    printf("1 - Criar um evento\n");
    if (ftell(eventos) != 0)
    { // Opções só vão aparecer se existirem eventos
      printf("2 - Remover um evento\n");
      printf("3 - Remover todos os eventos\n");
    }
    printf("\n\n9 - Voltar\n");
    //
    printf("Digite o número da opção => ");
    setbuf(stdin, NULL); // Evitar que o código entre em loop
    opcao = -1;          // Evitar erros caso o usuário não insira um número
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 9)
    {
      fclose(eventos);
      return;
    }

    if (opcao == 1)
    { // Adicionar um evento
      // O usuário ditará um evento por linha. Para que ele saia do modo de digitação, basta digitar "\sair".
      if (autenticacao() == 0)
      {
        fclose(eventos);
        eventos = fopen("eventos", "a");
        char eventreg_text[TAMANHO_BUFFER];
        eventreg_text[0] = '0'; // O while abaixo não executa se a string já for igual a "\sair". Esta linha corrige isso mudando 1 caractere da string
        printf("Digite os eventos a serem adicionados, separando-os por uma quebra de linha\nAo concluir, digite \"\\sair\"\n");

        while (strcmp(eventreg_text, "\\sair\n") != 0)
        {
          setbuf(stdin, NULL);
          fgets(eventreg_text, TAMANHO_BUFFER, stdin);
          if (strcmp(eventreg_text, "\\sair\n") != 0) // Impedir que a string "\sair" seja escrita no arquivo
            fputs(eventreg_text, eventos);            // Vai lendo e já vai salvando no arquivo
        }
        printf("Os eventos foram gravados\n");
      }
    }

    if (opcao == 2 && ftell(eventos) != 0)
    { // Remover um evento
      // Todos os eventos serão listados com um número de referência na frente. O usuário digtará um número e o evento correspondente será excluído
      if (autenticacao() == 0)
      {
        char arquivo_original[TAMANHO_BUFFER * 16]; // Funciona com até 16 linhas de eventos garantidamente, mude o número para suportar mais linhas
        int linha_deletar, linha_atual, i, c;
        for (i = 0; i < TAMANHO_BUFFER * 16; ++i)
          arquivo_original[i] = '\0';
        linha_atual = i = c = 0;

        rewind(eventos);
        while (fgets(eventos_contents, TAMANHO_BUFFER, eventos) != NULL)
        { // Imprimir todas as linhas com um número de referência na frente
          printf("%d | %s", i, eventos_contents);
          strcat(arquivo_original, eventos_contents); // Transferindo o conteúdo do arquivo para o vetor "arquivo_original"
          i++;
        }
        printf("\n");

        printf("\nInsira o número do evento que será deletado => ");
        linha_deletar = -1;
        while (linha_deletar >= i || linha_deletar < 0) // Impedir que números fora do intervalo sejam escritos
          scanf("%d", &linha_deletar);

        fclose(eventos);
        eventos = fopen("eventos", "w");
        fclose(eventos); // Apagar o conteúdo do arquivo
        eventos = fopen("eventos", "a");

        while (linha_atual < i)
        {
          if (linha_atual != linha_deletar) // Se a linha atual for igual à linha que será deletada, nada será impresso
            fprintf(eventos, "%c", arquivo_original[c]);
          if (arquivo_original[c] == '\n')
            linha_atual++;
          c++;
        }
      }
    }

    if (opcao == 3 && ftell(eventos) != 0)
    { // Remover todos os eventos
      if (autenticacao() == 0)
      {
        char confirm[3];
        confirm[0] = '\0'; // Evitar que o while não seja executado na segunda vez que a opção é selecionada
        printf("Tem certeza que deseja remover todos os eventos? (Esta ação é definitiva)\n");
        while (strcmp(confirm, "sim") && strcmp(confirm, "nao"))
        {
          printf("Digite \"sim\" ou \"nao\" => ");
          scanf("%s", confirm);
        }
        if (strcmp(confirm, "sim") == 0)
        {
          fclose(eventos);
          eventos = fopen("eventos", "w");
        }
        else
          printf("Operação cancelada\n");
      }
    }
  }
}

void mensagemDeNenhumFeedback()
{
  printf("======================\n");
  printf("Nenhum feedback encontrado!! Nos deixe uma sugestão ou crítica acessando a opção 5!!\n");
  printf("======================\n");
}

void perguntarParaNovoFeedback(int opcao)
{
  struct Feedback_struct NovoFeedback[1];

  printf("\nDeseja deixar seu feedback para nos?\n");
  printf("1- Deixar feedback\n");
  printf("2- Voltar ao menu\n");
  printf("Digite opção: ");
  scanf("%d", &opcao);
  if (opcao == 2)
  {
    return;
  }
  else
  {
    coleta_feedback(NovoFeedback);
  }
}

void verTodosOsFeedbacks(int opcao)
{
  struct Feedback F;

  FILE *file;
  file = fopen("feedback.txt", "r");

  if (file == NULL)
  {
    mensagemDeNenhumFeedback();
    return 0;
  }

  printf("Confira os feedbacks que nossos hospedes deixaram!\n");
  printf("======================");
  while (fscanf(file, "Nome: %60[^\n]\n", F.name) != EOF)
  {
    fscanf(file, "Nota: %d\n", &F.stars);
    fscanf(file, "Feedback: %100[^\n]\n", F.feedback);

    printf("\n%s - %d estrelas:\n", F.name, F.stars);
    printf("- %s\n", F.feedback);
  }
  printf("======================\n");

  perguntarParaNovoFeedback(opcao);
  fclose(file);
}

void coleta_feedback(Feedback_struct F2[])
{
  FILE *feedback_arq;
  feedback_arq = fopen("feedback.txt", "r");
  if (feedback_arq == NULL)
    feedback_arq = fopen("feedback.txt", "w");
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

void mostra_contatos()
{
  printf("\nInstagram: resort_instagram\n");
  printf("Gmail: resort@gmail.com\n");
  printf("Telefone: (34)99877-0392\n");
}

void menu()
{
  int opcao;
  struct Cliente C[1];
  struct Feedback_struct F[30];
  struct a_definir P[30];

  while (1)
  {
    printf("\nBem vindo ao Sistema de um resort ");
    printf("\n1- Cadastrar ");
    printf("\n2- Mostrar Todos");
    printf("\n3- Mostrar um");
    printf("\n4- Mostrar todos os lazeres/atrações/eventos");
    printf("\n5- Dar um feedback");
    printf("\n6- Ver feedback");
    printf("\n7- Ver contatos do Resort");
    printf("\n9- Sair ");
    printf("\nDigite opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
      cadastro(C);
    if (opcao == 4)
      eventos();
    if (opcao == 5)
      coleta_feedback(F);
    if (opcao == 6)
      verTodosOsFeedbacks(opcao);
    if (opcao == 7)
      mostra_contatos();
    if (opcao == 9)
      return;
  }
}

int main()
{
  menu();
}
