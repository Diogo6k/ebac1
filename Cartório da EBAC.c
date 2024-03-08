#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // cria o arquivo
	file = fopen (arquivo, "w"); // criando o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	    
    file= fopen(arquivo, "a"); // abrindo o arquivo e "a" significa atualizar o arquivo
    fprintf(file,","); // separando as informa��es do usu�rio cadastrado
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",nome); //armazenando informa��es do usu�rio
    
    file = fopen(arquivo, "a"); //abrindo arquivo
    fprintf(file,nome); //salvando o nome do usu�rio
    fclose(file); //fechando arquivo
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s",sobrenome); //armazenando informa��es do usuario
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome); // salvando o sobrenome do usu�rio
    fclose(file);
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo); //salvando o cargo do usu�rio
    fclose(file);
    
    system ("pause");
    
	}

int consulta() //consultando os dados do usu�rio
{
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser consultado:"); //consultando informa��es do usu�rio
	scanf("%s",cpf); //salvando a vari�vel cpf
	
	FILE *file; //procurando o arquivo
	file = fopen(cpf,"r");// abrindo o arquivo cpf e "r" significa ler a informa��o
	
	
	if(file == NULL) //valida��o do aqruivo
	{
		printf("Nao foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando os informa��es do usu�rios na vari�vel conteudo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //consultando informa��es
		printf("%s", conteudo); //apresentando informa��es
		printf("\n\n");
	}
	
	fclose(file);
	
	
	system("pause");//terminando processo
	
	
}

int deletar()
{
	//inicio de cria��es de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser deletado: ");//informando qual cpf sera deletado
	scanf("%s",cpf);//proucurando o cpf informado
	
	
	remove(cpf);//removendo o cpf
	
	FILE *file;//procurando arquivo do cpf
	file = fopen(cpf,"r");//abrindo arquivo e lendo a vari�vel cpf
	
	system("cls");
	

	if(file == NULL) //valida��o
		{
		printf("O usu�rio foi deletado do sistema!.\n");
		system("pause");//fim do processo
 	
	}
		
}

int main()
    {
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	    
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Come�o do menu
    	printf(" Cart�rio da EBAC\n\n");
		printf("Escolha uma das op��es abaixo\n\n");
    	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do programa\n\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
		    break;
		    
		    case 3:
		    deletar();
			break;
			
			case 4:
				printf("Obrigado por usar nosso programa e volte sempre!\n\n (Aperte ENTER para sair)\n\n");
				return 0;
				break;
			
			default:
		    printf("Essa op��o � inexistente!\n");
			system("pause");	
			break;
		}
    }
}
	
