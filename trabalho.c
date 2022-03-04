#include <stdio.h>
#include <stdlib.h>

struct a_definir
{
	// inserir código aqui
};

struct Feedback
{
	char feedback[100];
	char name[60];
	int stars;
};

void cadastro(struct a_definir T[])
{
	// inserir código aqui
}

void mostra(struct a_definir T[])
{
	// inserir código aqui
}

void mostra1(struct a_definir T[])
{
	// inserir código aqui
}

void messageNoFeedbacks()
{
	printf("======================\n");
	printf("Nenhum feedback encontrado!! Nos deixe uma sugestão ou crítica acessando a opção 5!!\n");
	printf("======================\n");
}

void seeAllFeedbacks(int opcao)
{
	struct Feedback F;

	FILE *file;
	file = fopen("feedbacks.txt", "r");

	if (file == NULL)
	{
		messageNoFeedbacks();
		return 0;
	}

	printf("Confira os feedbacks que nossos hospedes deixaram!\n");
	printf("======================");
	while (fscanf(file, "Nome: %60[^\n]\n", F.name) != EOF)
	{
		fscanf(file, "Nota: %d\n", &F.stars);
		fscanf(file, "Feedback: %100[^\n]\n", F.feedback);

		printf("\n%s %d estrelas:\n", F.name, F.stars);
		printf("- %s\n", F.feedback);
	}
	printf("======================\n");

	printf("\nDeseja deixar deixar seu feedback para nos?\n");
	printf("1- Deixar feedback\n");
	printf("2- Voltar ao menu\n");
	printf("Digite opção: ");
	scanf("%d", &opcao);
	if (opcao == 2) {
		return;
	} else {
		// coleta_feedback();
	}
	fclose(file);
}

void menu()
{
	int opcao;
	struct a_definir P[30];

	while (1)
	{
		printf("\nBem vindo ao Sistema de... ");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
		printf("\n6- Ver feedbacks");
		printf("\n9- Sair ");
		printf("\nDigite opção: ");
		scanf("%d", &opcao);
		printf("\n");

		if (opcao == 1)
			cadastro(P);
		if (opcao == 2)
			mostra(P);
		if (opcao == 3)
			mostra1(P);
		if (opcao == 6)
			seeAllFeedbacks(opcao);
		if (opcao == 9)
			return;
	}
}

int main()
{
	menu();
}