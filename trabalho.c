#include <stdio.h>
#include <stdlib.h>

struct a_definir
{
	// inserir código aqui
};

struct Feedback
{
	char comments[100];
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

void seeAllFeedbacks()
{
	struct Feedback F;

	FILE *file;
	file = fopen("teste.txt", "r");

	printf("Feedback do resort mais brabo que tem!!\n");
	printf("==========================\n");
	while (fscanf(file, "%s %d", F.name, &F.stars) != EOF)
	{
		fgets(F.comments, 100, file);

		printf("%s %d estrelas:\n", F.name, F.stars);
		printf("- %s\n", F.comments);
	}
	printf("==========================");

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

		if (opcao == 1)
			cadastro(P);
		if (opcao == 2)
			mostra(P);
		if (opcao == 3)
			mostra1(P);
		if (opcao == 6)
			seeAllFeedbacks();
		if (opcao == 9)
			return;
	}
}

int main()
{
	menu();
}