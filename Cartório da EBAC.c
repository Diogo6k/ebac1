#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//inicio da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; // cria o arquivo
	file = fopen (arquivo, "w"); // criando o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	    
    file= fopen(arquivo, "a"); // abrindo o arquivo e "a" significa atualizar o arquivo
    fprintf(file,","); // separando as informações do usuário cadastrado
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",nome); //armazenando informações do usuário
    
    file = fopen(arquivo, "a"); //abrindo arquivo
    fprintf(file,nome); //salvando o nome do usuário
    fclose(file); //fechando arquivo
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
    scanf("%s",sobrenome); //armazenando informações do usuario
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome); // salvando o sobrenome do usuário
    fclose(file);
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo); //salvando o cargo do usuário
    fclose(file);
    
    system ("pause");
    
	}

int consulta() //consultando os dados do usuário
{
	//inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser consultado:"); //consultando informações do usuário
	scanf("%s",cpf); //salvando a variável cpf
	
	FILE *file; //procurando o arquivo
	file = fopen(cpf,"r");// abrindo o arquivo cpf e "r" significa ler a informação
	
	
	if(file == NULL) //validação do aqruivo
	{
		printf("Nao foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando os informações do usuários na variável conteudo
	{
		printf("\nEssas são as informações do usuário: "); //consultando informações
		printf("%s", conteudo); //apresentando informações
		printf("\n\n");
	}
	
	fclose(file);
	
	
	system("pause");//terminando processo
	
	
}

int deletar()
{
	//inicio de criações de variáveis/string
	char cpf[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser deletado: ");//informando qual cpf sera deletado
	scanf("%s",cpf);//proucurando o cpf informado
	
	
	remove(cpf);//removendo o cpf
	
	FILE *file;//procurando arquivo do cpf
	file = fopen(cpf,"r");//abrindo arquivo e lendo a variável cpf
	
	system("cls");
	

	if(file == NULL) //validação
		{
		printf("O usuário foi deletado do sistema!.\n");
		system("pause");//fim do processo
 	
	}
		
}

int main()
    {
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	    
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Começo do menu
    	printf(" Cartório da EBAC\n\n");
		printf("Escolha uma das opções abaixo\n\n");
    	printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do programa\n\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
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
		    printf("Essa opção é inexistente!\n");
			system("pause");	
			break;
		}
    }
}
	
