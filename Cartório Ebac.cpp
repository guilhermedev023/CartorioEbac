#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cpf);//%s refere-se a string

	strcpy(arquivo, cpf); //Responsaavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" atualiza as informações
	fprintf(file,"\n");//"\n" separa as informações por linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coleta informações do usuário
	scanf("%s", nome);// "%s" refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informações
	fprintf(file,nome);//salva a informação na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informações
	fprintf(file, "\n");//separa as informações em linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: ");//coleta informação do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");// abre o arquivo e "a" atualiza as informações
	fprintf(file,sobrenome);//salva as informações na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informações
	fprintf(file, "\n");//separa as informações por linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Cargo a ser cadastrado: ");//coleta informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informações
	fprintf(file,cargo);//salva as informações na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informações
	fprintf(file, "\n");//separa as informações por linhas
	fclose(file);//fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possovel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
 	{
 		printf("\nEssas são as informações do usuário: ");
 		printf("%s", conteudo);
	 }
	 
	 system("pause");
	 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o do usuário CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");	
	}
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	int opcao=0; //Definindo Variáveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf(" ### Cartório da EBAC ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	system("cls");
	
	
	if(comparacao == 0)
	{
	
		for(x=1;x=1;)
		{
		
			system("cls");//responsavel por limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
			printf(" ### Cartório da EBAC ###\n\n");
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consutar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:");//fim do menu
	
			scanf("%d", &opcao);//armazenando a esolha do usuário
	
			system("cls");// responsavel por limpar a tela
	
			switch(opcao)
			{
				case 1:
					registro();// chamada de função
				break;
				
				case 2:
					consulta();//chamada de função
				break;
				
				case 3:
					deletar();//chamada de função
				break;
			
				case 4: //chamda de função, encerramento do sistema
					printf("O sistema foi finalizado.");
					return 0;
					break;
					
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;		
				
			}
		}
	}		

	else
		printf("Senha incorreta!!");	
}
		

