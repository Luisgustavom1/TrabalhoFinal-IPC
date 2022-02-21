#include <stdio.h>
#include <stdlib.h>

struct cliente{
	char nome[100], cpf[30], nasc[20], profissao[50], nacionalidade[30], idade[10], sexo[20], id[30], endereco[100], cep[30], telefone[30], cidade[50], estado[50], pais[30], email[30];
};


void cadastro(struct cliente T[]){
	FILE *f;

	f = fopen ("arquivo.txt", "a");
	if(f == NULL)
	{
		printf("Arquivo nao pode ser aberto");
		getchar();
		exit(1);
	}
	

	int i, confirma;
	for(i = 0; ;i++)
	{
		setbuf(stdin, NULL);
		printf("Nome completo:\n");
		fgets(T[i].nome,100,stdin);
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

		if(confirma == 1)
		{
			fprintf(f,"Nome: %s\n", T[i].nome);
			fprintf(f,"CPF: %s\n", T[i].cpf);
			fprintf(f,"Identidade: %s\n", T[i].id);
			fprintf(f,"Data de nascimento: %s\n", T[i].nasc);
			fprintf(f,"Nacionalidade: %s\n", T[i].nacionalidade);
			fprintf(f,"Idade: %s\n", T[i].idade);
			fprintf(f,"Sexo: %s\n", T[i].sexo);
			fprintf(f,"Profissao: %s\n", T[i].profissao);
			fprintf(f,"Endereco: %s\n", T[i].endereco);
			fprintf(f,"CEP: %s\n", T[i].cep);
			fprintf(f,"Telefone: %s\n", T[i].telefone);
			fprintf(f,"Cidade: %s\n", T[i].cidade);
			fprintf(f,"Estado: %s\n", T[i].estado);
			fprintf(f,"Pais: %s\n", T[i].pais);
			fprintf(f,"E-mail: %s\n", T[i].email);
			return;
		}

		fclose(f);

	}
	
}

/*void mostra(struct cliente T[]){
	//inserir código aqui
}

void mostra1(struct cliente T[]){
	//inserir código aqui
}*/

void menu(){
	int opcao;
	struct cliente P[30];

	while(1){
		printf("\nBem vindo ao Sistema de... ");
		printf("\n1- Cadastrar ");
		printf("\n2- Mostrar Todos");
		printf("\n3- Mostrar um");
		printf("\n9- Sair ");
		printf("\nDigite opcao: ");
		scanf("%d", &opcao);
	
		if(opcao == 1) cadastro(P);
		//if(opcao == 2) mostra(P);
		//if(opcao == 3) mostra1(P);
		if(opcao == 9) return;
	}
}


int main(){
	menu();
}

