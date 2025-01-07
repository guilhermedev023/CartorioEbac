#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", cpf);//%s refere-se a string

	strcpy(arquivo, cpf); //Responsaavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e "a" atualiza as informa��es
	fprintf(file,"\n");//"\n" separa as informa��es por linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coleta informa��es do usu�rio
	scanf("%s", nome);// "%s" refere-se a string
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informa��es
	fprintf(file,nome);//salva a informa��o na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informa��es
	fprintf(file, "\n");//separa as informa��es em linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: ");//coleta informa��o do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");// abre o arquivo e "a" atualiza as informa��es
	fprintf(file,sobrenome);//salva as informa��es na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informa��es
	fprintf(file, "\n");//separa as informa��es por linhas
	fclose(file);//fecha o arquivo
	
	printf("Digite o Cargo a ser cadastrado: ");//coleta informa��o do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informa��es
	fprintf(file,cargo);//salva as informa��es na variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e "a" atualiza as informa��es
	fprintf(file, "\n");//separa as informa��es por linhas
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
		printf("N�o foi possovel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
 	{
 		printf("\nEssas s�o as informa��es do usu�rio: ");
 		printf("%s", conteudo);
	 }
	 
	 system("pause");
	 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o do usu�rio CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");	
	}
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	int opcao=0; //Definindo Vari�veis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf(" ### Cart�rio da EBAC ###\n\n");
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
	
			printf(" ### Cart�rio da EBAC ###\n\n");
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consutar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:");//fim do menu
	
			scanf("%d", &opcao);//armazenando a esolha do usu�rio
	
			system("cls");// responsavel por limpar a tela
	
			switch(opcao)
			{
				case 1:
					registro();// chamada de fun��o
				break;
				
				case 2:
					consulta();//chamada de fun��o
				break;
				
				case 3:
					deletar();//chamada de fun��o
				break;
			
				case 4: //chamda de fun��o, encerramento do sistema
					printf("O sistema foi finalizado.");
					return 0;
					break;
					
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;		
				
			}
		}
	}		

	else
		printf("Senha incorreta!!");	
}
		

