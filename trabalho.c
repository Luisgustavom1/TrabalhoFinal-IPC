#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Planos
{
  char nome_do_plano[100], quantidade_de_camas[10], refeicoes_no_hotel[6], ingressos_para_eventos[100], transporte_vip[10], quantidade_passagens[10], tipo_de_passagem[100], tamanho_do_quarto[100], quantidade_de_banheiros[10];
  int quantidade_de_dias;
  double preco_do_plano;
};

struct Cliente
{
  char nome[100], cpf[30], nasc[20], profissao[50], nacionalidade[30], idade[10], sexo[20], rg[30], endereco[100], cep[30], telefone[30], cidade[50], estado[50], pais[30], email[30];
  int id;
};

struct Feedback
{
  char feedback[100];
  char name[60];
  int stars;
};

// Normalmente a função "strrev" não está presente na biblioteca padrão do gcc, então para evitar problemas em diferentes compiladores, ela é definida aqui.
char *strrev(char *s)
{
  if (s && *s)
  {                                      // s = string inteira; *s = posição atual do ponteiro (primeiro caractere da string)
    char *b = s, *e = s + strlen(s) - 1; // b = Ponteireo no primeiro caractere; e = Ponteiro no último caractere
    while (b < e)
    { // While que leva o último caractere para a primeira posição e o primeiro para a última. Quando chegar na metade da string, "b" estará em uma posição maior ou superior a "e" e o laço parará.
      char foo;
      foo = *b;
      *b++ = *e;
      *e-- = foo;
    }
  }

  return s;
}

int autenticacao()
{
  // Solicita que o usuário digite uma senha até ele acertar. Quando ele acerta, é retornado 0; quando ele opta por sair, é retornado 1.
  // Não tem criptografia nenhuma, é só para demonstrar
  char senha[10];
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

void cadastro_de_cliente(struct Cliente T[])
{
  FILE *f;

  f = fopen("usuarios.txt", "a");

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

    printf("RG(apenas o numero):\n");
    scanf("%[^\n]s", T[i].rg);
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
    printf("RG: %s\n", T[i].rg);
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
      // Lendo último id usado
      fclose(f);
      f = fopen("usuarios.txt", "r");
      char linha_atual[200], *lixo;
      int ultimoID = 0;

      while (fgets(linha_atual, 200, f) != NULL)
        if (strstr(linha_atual, "ID: ")) // Se a linha conter "ID: "
          ultimoID = strtol(strrev(linha_atual), &lixo, 10);
      // A função strtol extrai o primeiro número de uma string se ele for a primeira coisa presente, então devolve o resto dela em *lixo. Para que o número seja a primeira coisa em "ID: %d", a função strrev escreverá a string de trás para frente, fazendo com que o número do ID ganhe evidência.

      ultimoID++;

      // Escrevendo
      fclose(f);
      f = fopen("usuarios.txt", "a");

      fprintf(f, "ID: %d\n", ultimoID);
      fprintf(f, "Nome: %s\n", T[i].nome);
      fprintf(f, "CPF: %s\n", T[i].cpf);
      fprintf(f, "Identidade: %s\n", T[i].rg);
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
      fclose(f);
      return;
    }

    fclose(f);
    return;
  }
}

void mostrarCadastros()
{

  FILE *f;
  f = fopen("usuarios.txt", "r");

  if (!autenticacao())
  {
    if (f == NULL) // verificando se o arquivo existe ou nao
    {
      printf("Nenhum cadastro encontrado!\n");
      return;
    }

    char destino[100];
    while (fgets(destino, 100, f) != NULL) // Imprimir todas as linhas do arquivo eventos; destino = onde vai ser armazenado a string; 100 = tam max da string; f = arq de onde sao lidos os dados
    {
      printf("%s", destino);
    }

    fclose(f);
  }
}

void mostra_um_cadastro(int ID)
{
  // Lendo último id usado
  FILE *f = fopen("usuarios.txt", "r");

  if (!autenticacao())
  {
    if (f == NULL) // verificando se o arquivo existe ou nao
    {
      printf("Nenhum cadastro encontrado!\n");
      return;
    }

    char linha_atual[200], *lixo;
    int ultimoID = 0;

    while (fgets(linha_atual, 200, f) != NULL) // linha_atual= onde vai ser armaz a string lida; 200 = tam da string; f = arq lido
    {
      if (strstr(linha_atual, "ID: ")) // Se a linha conter "ID: " // strstr (onde eu vou buscar, qual string eu quero buscar)
      {
        ultimoID = strtol(strrev(linha_atual), &lixo, 10); // Explicação na função cadastro (tem exatamente a mesma coisa)
        strrev(linha_atual);
      }
      if (ultimoID == ID)
      {
        printf("%s", linha_atual);
      }
    }
    return;
  }
}

void cadastro_de_planos(struct Planos T[])
{
  FILE *ponteiro_arquivo;

  ponteiro_arquivo = fopen("planos.txt", "a");
  if (ponteiro_arquivo == NULL)
  {
    printf("Arquivo nao pode ser aberto");
    exit(1);
  }

  if (!autenticacao())
  {
    int i, confirma;
    for (i = 0;; i++)
    {
      setbuf(stdin, NULL);
      printf("Nome do plano:\n");
      scanf("%[^\n]s", T[i].nome_do_plano);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Quantidade de camas (1 a 5):\n");
      scanf("%[^\n]s", T[i].quantidade_de_camas);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Quantas refeições terá no hotel (1 a 6):\n");
      scanf("%[^\n]s", T[i].refeicoes_no_hotel);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Ingressos para eventos:\n");
      scanf("%[^\n]s", T[i].ingressos_para_eventos);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Transporte VIP (1 a 3 por dia):\n");
      scanf("%[^\n]s", T[i].transporte_vip);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Quantidade de passagens (ida e volta):\n");
      scanf("%[^\n]s", T[i].quantidade_passagens);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Tipo de veículo de transporte (passagens):\n");
      scanf("%[^\n]s", T[i].tipo_de_passagem);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Tamanho do quarto (pequeno, médio, grande, VIP):\n");
      scanf("%[^\n]s", T[i].tamanho_do_quarto);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Quantidade de banheiros (1 ou 2):\n");
      scanf("%[^\n]s", T[i].quantidade_de_banheiros);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Quantidade de dias:\n");
      scanf("%d", &T[i].quantidade_de_dias);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Preço do plano (total):\nR$ ");
      scanf("%lf", &T[i].preco_do_plano);
      setbuf(stdin, NULL);
      printf("\n");

      printf("Nome do plano: %s\n", T[i].nome_do_plano);
      printf("Quantidade de camas (1 a 5): %s\n", T[i].quantidade_de_camas);
      printf("Quantas refeições terá no hotel (1 a 6): %s\n", T[i].refeicoes_no_hotel);
      printf("Ingressos para eventos: %s\n", T[i].ingressos_para_eventos);
      printf("Transporte VIP (1 a 3 por dia): %s\n", T[i].transporte_vip);
      printf("Quantidade de passagens (ida e volta): %s\n", T[i].quantidade_passagens);
      printf("Tipo de veículo de transporte (passagens): %s\n", T[i].tipo_de_passagem);
      printf("Tamanho do quarto (pequeno, médio, grande, VIP): %s\n", T[i].tamanho_do_quarto);
      printf("Quantidade de banheiros (1 ou 2): %s\n", T[i].quantidade_de_banheiros);
      printf("Quantidade de dias: %d\n", T[i].quantidade_de_dias);
      printf("Preço do plano (total): R$ %.2lf\n", T[i].preco_do_plano);
      printf("\n");

      printf("Confirmar cadastro ?\n");
      printf("1 - Sim\n");
      printf("2 - Nao\n");
      scanf("%d", &confirma);

      if (confirma == 1)
      {

        // Lendo último id usado
        fclose(ponteiro_arquivo);
        ponteiro_arquivo = fopen("planos.txt", "r");
        char linha_atual[200], *lixo;
        int ultimoID = 0;

        while (fgets(linha_atual, 200, ponteiro_arquivo) != NULL)
          if (strstr(linha_atual, "ID: ")) // Se a linha conter "ID: "
            ultimoID = strtol(strrev(linha_atual), &lixo, 10);
        // A função strtol extrai o primeiro número de uma string se ele for a primeira coisa presente, então devolve o resto dela em *lixo. Para que o número seja a primeira coisa em "ID: %d", a função strrev escreverá a string de trás para frente, fazendo com que o número do ID ganhe evidência.

        ultimoID++;

        // Escrevendo
        fclose(ponteiro_arquivo);
        ponteiro_arquivo = fopen("planos.txt", "a");

        fprintf(ponteiro_arquivo, "ID: %d\n", ultimoID);
        fprintf(ponteiro_arquivo, "Nome do plano: %s\n", T[i].nome_do_plano);
        fprintf(ponteiro_arquivo, "Quantidade de camas (1 a 5): %s\n", T[i].quantidade_de_camas);
        fprintf(ponteiro_arquivo, "Quantas refeições terá no hotel (1 a 6): %s\n", T[i].refeicoes_no_hotel);
        fprintf(ponteiro_arquivo, "Ingressos para eventos: %s\n", T[i].ingressos_para_eventos);
        fprintf(ponteiro_arquivo, "Transporte VIP (1 a 3 por dia): %s\n", T[i].transporte_vip);
        fprintf(ponteiro_arquivo, "Quantidade de passagens (ida e volta): %s\n", T[i].quantidade_passagens);
        fprintf(ponteiro_arquivo, "Tipo de veículo de transporte (passagens): %s\n", T[i].tipo_de_passagem);
        fprintf(ponteiro_arquivo, "Tamanho do quarto (pequeno, médio, grande, VIP): %s\n", T[i].tamanho_do_quarto);
        fprintf(ponteiro_arquivo, "Quantidade de banheiros (1 ou 2): %s\n", T[i].quantidade_de_banheiros);
        fprintf(ponteiro_arquivo, "Quantidade de dias: %d\n", T[i].quantidade_de_dias);
        fprintf(ponteiro_arquivo, "Preço do plano (total): R$ %.2lf\n", T[i].preco_do_plano);
        fprintf(ponteiro_arquivo, "\n");
        fclose(ponteiro_arquivo);
        return;
      }

      fclose(ponteiro_arquivo);
      return;
    }
  }
}

void mostrar_todos_os_planos(struct Planos T[])
{
  FILE *ponteiro_arquivo;
  int i;
  char leitura, output[10000];

  ponteiro_arquivo = fopen("planos.txt", "r");

  if (ponteiro_arquivo == NULL)
  {
    printf("Erro na abertura do arquivo");
    exit(1);
  }
  printf("\n\nMostrando planos...\n\n");
  i = 0;
  leitura = fgetc(ponteiro_arquivo);
  while (leitura != EOF)
  {
    output[i] = leitura;
    printf("%c", output[i]);
    i++;
    leitura = fgetc(ponteiro_arquivo);
  }

  return;
  fclose(ponteiro_arquivo);
}

void eventos()
{
  // Os eventos serão guardados em um arquivo para melhor organização
  const int TAMANHO_BUFFER = 256; // Máximo de caracteres que podem ser inseridos por linha

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
    printf("\nComandos:\n");
    printf("Qualquer tecla - Recarregar eventos\n");
    printf("1 - Criar um evento\n");
    if (ftell(eventos) != 0)
    { // Opções só vão aparecer se existirem eventos
      printf("2 - Remover um evento\n");
      printf("3 - Remover todos os eventos\n");
    }
    printf("0 - Voltar\n");

    printf("Digite o número da opção => ");
    setbuf(stdin, NULL); // Evitar que o código entre em loop
    opcao = -1;          // Evitar erros caso o usuário não insira um número
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 0)
    {
      fclose(eventos);
      return;
    }

    if (opcao == 1)
    { // Adicionar um evento
      // O usuário ditará um evento por linha. Para que ele saia do modo de digitação, basta digitar "\sair".
      if (!autenticacao())
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
      if (!autenticacao())
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
      if (!autenticacao())
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

void coleta_feedback()
{
  struct Feedback F;

  FILE *feedback_arq;
  feedback_arq = fopen("feedback.txt", "r");
  if (feedback_arq == NULL)
    feedback_arq = fopen("feedback.txt", "w");
  feedback_arq = fopen("feedback.txt", "a");

  setbuf(stdin, NULL);
  printf("\nEscreva seu nome: ");
  scanf("%[^\n]s", F.name);
  fprintf(feedback_arq, "Nome: %s\n", F.name);

  setbuf(stdin, NULL);
  printf("\nDeixe uma nota (0 a 5): ");
  scanf("%d", &F.stars);
  fprintf(feedback_arq, "Nota: %d\n", F.stars);

  setbuf(stdin, NULL);
  printf("\nAdicione um comentario: ");
  scanf("%[^\n]s", F.feedback);
  fprintf(feedback_arq, "Feedback: %s\n\n", F.feedback);

  fclose(feedback_arq);

  setbuf(stdin, NULL);
}

void mensagem_de_nenhum_feedback()
{
  printf("----------------------\n");
  printf("Nenhum feedback encontrado!! Nos deixe uma sugestao ou critica acessando a opcao 4.\n");
  printf("----------------------\n");

  return;
}

void mostra_feedbacks()
{
  struct Feedback F;

  FILE *feedback_arq;
  feedback_arq = fopen("feedback.txt", "r");

  if (feedback_arq == NULL)
  {
    mensagem_de_nenhum_feedback();
    return;
  }

  printf("\nConfira os feedbacks que nossos hospedes deixaram!");
  while (fscanf(feedback_arq, "Nome: %60[^\n]\n", F.name) != EOF)
  {
    fscanf(feedback_arq, "Nota: %d\n", &F.stars);
    fscanf(feedback_arq, "Feedback: %100[^\n]\n", F.feedback);

    printf("\n----------------------");
    printf("\nNome: %s - %d estrelas:", F.name, F.stars);
    printf("\n- %s", F.feedback);
    printf("\n----------------------\n");
  }

  fclose(feedback_arq);
  return;
}

void mostra_contatos()
{
  printf("\nInstagram: new_horizon_resort_instagram\n");
  printf("Gmail: new_horizon_resort@gmail.com\n");
  printf("Telefone: (34)99877-0392\n");
}

void perguntas_frequentes()
{
  int opcao;
  while (1)
  {
    printf("\nDigite a opção correspondente à pergunta\n");
    printf("\n1. Como entrar em contato com a New Horizon Resort?\n");
    printf("2. Quais os períodos de baixa e alta temporada?\n");
    printf("3. O que fazer se houver um imprevisto e não puder viajar?\n");
    printf("4. Por que confiar na New Horizon resort?\n");
    printf("5. Qual o horário de atendimento da New Horizon Resort?\n");
    printf("6. Quais os recursos que a New Horizon Resort possui para pais com ciranças pequenas?\n");
    printf("7. Como funciona os preços para hóspedes menores de idade?\n");
    printf("0. Voltar\n");

    scanf("%d", &opcao);

    if (opcao == 1)
      printf("Você pode entrar em contato conosco através do nosso gmail, telefone ou instagram. Para acessá-los, basta digitar a opção 6 na \'Área do ciente\'\n");
    if (opcao == 2)
      printf("Os períodos de alta temporada no Brasil são comumentes o Natal, réveillon, os meses de janeiro e julho, bem como os feriados nacionais.\n\nOs periodos de baixa temporada no Brasil compreendem os meses de fevereiro a junho, e agosto até o dia 20 de dezembro.(Nos feriados que acontecem nos meses citados, os valores são os mesmos da alta temporada).\n");
    if (opcao == 3)
      printf("Relações sólidas. Com a expertise de mais de dez anos no mercado de resorts e com forte relação junto aos principais fornecedores do segmento, nossa equipe conhece todos os trâmites do setor. Com isso, é capaz de oferecer soluções com agilidade e segurança a todos os nossos clientes. Para quaisquer dúvidas e imprevistos, o cliente pode contatar o suporte da New Horizon Resort a qualquer momento.\n");
    if (opcao == 4)
      printf("Temos os melhores preços. Com uma larga experiência no universo da hotelaria de alto padrão e com o reconhecimento dos principais fornecedores e sites de reserva do País, a New Horizon Resort tem os melhores preços para a venda de planos e acomodações do Brasil. Por isso, oferece a melhor experiencia de viagem para o cliente.\n");
    if (opcao == 5)
      printf("O horário de atendimento da New Horizon Resort é de segunda-feira a segunda-feira, 24horas por dia, sete dias por semana. Nosso lema é nunca parar de atendê-lo.\n");
    if (opcao == 6)
      printf("Teremos disponibilizados em toda a área do Resort, serviços com monitores para crianças acima dos 5 anos, e serviços de babás para bebês até menores de 4 anos, bem como a disponibilização de berços, carrinhos, e fraldário se os pais assim os solicitarem na portaria.\n");
    if (opcao == 7)
      printf("Os hóspedes de até 4 anos estão isentos da diária, crianças de 5 a 12 pagarão meia diária e adolescentes de 13 a 18 anos, pagarão o valor de uma diária.\n");
    if (opcao == 0)
      return;
  }
}

void menu()
{
  int opcao, ID;
  struct Cliente C[1];
  struct Planos P[100];

  while (1)
  {
    printf("\nBem vindo ao Sistema New Horizon Resort");
    printf("\n----------------------------------------");
    printf("\n            Area do cliente             ");
    printf("\n----------------------------------------");
    printf("\n1- Cadastrar no sistema do nosso resort");
    printf("\n2- Mostrar todos os planos");
    printf("\n3- Mostrar todos os lazeres/atracoes/eventos");
    printf("\n4- Dar um feedback");
    printf("\n5- Ver feedback");
    printf("\n6- Ver contatos do Resort");
    printf("\n7- Perguntas Frequentes");
    printf("\n----------------------------------------");
    printf("\n           Area do Administrador             ");
    printf("\n----------------------------------------");
    printf("\n8- Cadastrar um plano");
    printf("\n9- Mostrar Todos os usuarios cadastrados");
    printf("\n10- Mostrar 1 usuario");
    printf("\n0- Sair ");
    printf("\nDigite opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
      cadastro_de_cliente(C);
    if (opcao == 2)
      mostrar_todos_os_planos(P);
    if (opcao == 3)
      eventos();
    if (opcao == 4)
      coleta_feedback();
    if (opcao == 5)
      mostra_feedbacks();
    if (opcao == 6)
      mostra_contatos();
    if (opcao == 7)
      perguntas_frequentes();
    if (opcao == 8)
      cadastro_de_planos(P);
    if (opcao == 9)
      mostrarCadastros();
    if (opcao == 10)
    {
      printf("Digite o ID do cadastro a ser mostrado => ");
      scanf("%d", &ID);
      mostra_um_cadastro(ID);
    }
    if (opcao == 0)
      return;
  }
}

int main()
{
  menu();
}
