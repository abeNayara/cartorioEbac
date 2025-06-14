#include <stdio.h> //bibl�oteca de comunica��o com o usu�rio
#include <stdlib.h> //bibl�oteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibl�oteca de aloca��o de texto por regi�o
#include <string.h> //bibl�oteca respons�vel por cuidar das strings

//Registro de Usu�rio

int registro()
{
	//Cria��o dos vetores(strings) para REGISTRAR os dados do usu�rio
	char arquivo[40];
	char cpf[40];
	char senha[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Registro CPF:
	printf ("Digite o CPF a ser cadastrado: \n");
    scanf ("%s", cpf);
    
    strcpy (arquivo, cpf); // Respons�vel por copiar os valores da string 'cpf' e deixa-lo como elemento chave de busca para CONSULTA DE USU�RIO
	
	//Cria��o do arquivo para ARMAZENAR os dados coletados dos vetores(strings)
	FILE *file;
	file = fopen (arquivo, "w"); //Abre o arquivo para "w"(escrever - write)
    fprintf (file, "\nCPF: "); //Adicionado para CONSULTAR o CPF
    fprintf (file, "%s", cpf); //Salva o dado 'cpf' desntro de uma v�riavel
    fclose (file); 
	//Fecha o arquivo
	
    //Quebra de linha
    file = fopen (arquivo, "a");//Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    //Registro de SENHA
    printf("Digite a senha a ser cadastrada: \n");
    scanf("%s", senha);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf(file,"\nSenha: "); //Adicionado para CONSULTAR a SENHA
    fprintf(file, "%s", senha); //Salva o dado 'senha' dentro de uma vari�veil
    fclose(file);
    
    //Quebra de linha
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    //Registro NOME:
    printf ("Digite o nome a ser cadastrado: \n");
    scanf ("%s", nome);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\nNome: "); //Adicionado para CONSULTAR o NOME
    fprintf (file, "%s", nome); //Salva o dado 'nome' dentro de uma v�riavel
    fclose (file);
    
    //Espa�o entre NOME e SOBRENOME
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, " ");
    fclose (file);
    
    //Registro SOBRENOME:
    printf ("Digite o sobrenome a ser cadastrado: \n");
    scanf ("%s", sobrenome);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "%s", sobrenome); //Adicioando para consultar o SOBRENOME
    fclose (file);
    
    /*OBS: n�o possui 
	fprintf (file, "\nSobrenome: ");
	para fins est�ticos
	*/
    
    //Quebra de linha
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    //Resgistro de CARGO:
    printf ("Digite o cargo designado: \n");
    scanf ("%s", cargo);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\nCargo: "); //Adicionado para CONSULTAR o CARGO
    fprintf (file,"%s", cargo); //Salva o dado 'cargo' dentro de uma vari�vel
    fclose (file);
    
    system("pause");
}

//Login do Usu�rio
int login()
{
	
	//Defini��o da l�nguagem
	setlocale (LC_ALL, "Portuguese");
	
	//Cria��o dos vetores(strings) para identificar o login do usu�rio
	char cpf[40];
	char senha[40];
	char conteudo[200];
	
	//Salva o cpf como forma de login
	printf("Degite o CPF como login: \n");
	scanf("%s",cpf);
	
	//Salva a senha que o usu�rio deseja utilizar
	printf("Digite a senha: \n");
	scanf("%s",senha);
	
	char arquivo[40];
	strcpy(arquivo, cpf);
	
	//Abertura do arquivo com "r"(write - escreva)
	FILE *file;
	file = fopen(arquivo, "r");
	
	//Se o arquivo for igual a NULL(valor nulo)
	if(file == NULL)
	{
		//O usu�rio n�o ser� encontrado
		printf("Usu�rio n�o encontrado!\n");
		return 0;
	}
	//Se arquivo for diferente de NULL
	else
	{
		//Realiza a consulta dos dados dentro do arquivo
		fgets(conteudo, 200, file);
		fgets(conteudo, 200, file);
		
		//Se os dados forem deferentes de NULL
		if(strstr(conteudo, senha) != NULL)
		{
			//O usu�rio tem acesso ao MENU
			printf("\nBem-vindo, usu�rio encontrado!\n");
		}
		//Caso os dados n�o forem achados no arquivo
		else
		{
			printf("\nCPF ou senha incorretos!\n");
		}
		
		//Fecha o arquivo e retorna ao MENU
		fclose(file);
		return 1;
		
	}	

	
}

//Consulta do Usu�rio

int consulta()
{
	
	//Defini��o da l�nguagem
	setlocale (LC_ALL, "Portuguese"); 
	
	//Cria��o de vetores(strings) para LOCALIZAR no arquivo os dados j� REGISTRADOS
	char cpf[40];
	char conteudo[200];
	char resp;
	
	//Salva a resposta dada, para realizar a consulta 'cpf'
	printf ("Digite o CPF a ser consultado: \n");
	scanf ("%s", cpf);
	
	//Abertura do arquivo com "r"(write - escreva)
	FILE *file;
	file = fopen (cpf, "r");
	
	//Se a resposta dada for igual a NULL(valor nulo):
	if (file == NULL)
	{	
		//Ser� apresentada a seguinte mensagem:
		printf ("N�o foi poss�vel localizar o usu�rio! \n");
	}
	
	//Se a resposta dada for diferente de NULL
	else if(file != NULL)
	{
		//Ser� apresnetada a seguinte mensagem +
		printf ("\nEssas s�o as informa��es do usu�rio: \n");
		//enquanto "fgets"(realiza a leitura) for diferente de NULL, ir� ler o arquivo
		while (fgets(conteudo, 200, file) != NULL) 
		{
			//Leitura das vari�veis registradas 
			printf ("%s", conteudo);
		}
	}
	
	//Condi��o apresentada caso queira consultar mais de um usu�rio
	printf ("\n\nAinda deseja consultar um usu�rio? Se sim digite (S), se n�o (N): \n");
	
	getchar(); //Registra o caracter apresentado
	resp = getchar(); //V�riavel 'resp' recebe o caracter
		
	//Enquanto vari�vel 'resp' receber valor igual a s/S	
	while (resp == 's' || resp == 'S')
	{
		//realiza a opera��o de consulta novamente
		printf ("\nDigite o CPF a ser consultado: \n");
		scanf ("%s", cpf);
		
		FILE *file;
		file = fopen (cpf, "r");
	
		if (file == NULL)
		{
			printf ("\nN�o foi poss�vel localizar o usu�rio! \n");
		}
	
		else if(file != NULL)
		{
			printf ("\nEssas s�o as informa��es do usu�rio: \n");
			while (fgets(conteudo, 200, file) != NULL) 
			{
				printf ("%s", conteudo);
			}
		}
				
		//Realiza a pergunta de consulta novamente e salva na vari�vel 'resp'
		printf ("\n\nDeja consultar mais um usu�rio? Se sim digite (S), se n�o (N): \n");
		getchar();
		resp = getchar();
	}	
	
	//Se vari�vel 'resp' receber valor igual a n/N
	if (resp == 'n' || resp == 'N')
	{
		//Ser� pausado o sistema e retornar� ao MENU
		printf("\nRetorno ao Menu do Cart�rio. \n");
		system("pause");		
	}
	//Caso a vari�vel 'resp' n�o receba valor correspondente
	else
	{
		//Ser� pausado o sistema e retornar� ao MENU
		printf("\nOp��o inv�lida! Retorno ao Menu do Cart�rio.\n"); 
		system("pause");
	}	
	printf ("\n\n");
	fclose (file); //Fechamento do arquivo
}

//Deletar Usu�rio

int deletar()
{
	//Cria��o do vetor 'cpf' para consultar no registro
	char cpf[40];
	
	//Salva a resposta dada para realizar a consulta da vari�vel 'cpf'
	printf ("Digite o CPF a ser deletado: \n");
	scanf ("%s", cpf);
	
	//Abre o arquivo com "r"(read - leitura)
	FILE *file;
	file = fopen(cpf, "r"); 
	
	//Se arquivo for igual a NULL
	if (file == NULL) 
	{
		//Ser� dada a seguinte resposta e o sistema ser� pausado com retorno ao MENU
		printf ("Usu�rio n�o encontado no sistema!\n");
		system ("pause");
		return 0; //Retorno para tela inicial
	}
	
	fclose (file); //Fechando e confirmando a existecia do arquivo 
	
	//confima��o do usu�rio para deletar os arquivos
	
	printf ("Deseja realmente deletar este usu�rio do sistema?\n");
	printf ("%s", cpf);
	printf ("\nDigite (S) para confimar ou (N) caso n�o deseje deletar o usu�rio: \n");
	
	getchar(); //Fun��o respons�vel por salvar o caractere digitado 
	
	//Vari�vel caractere criada
	char opcao;
	opcao = getchar(); //A vari�vel 'pega' o valor escreito pelo usu�rio e o salva em 'getchar'(pegar o caracter)
	
	//se for digitado (s)
	if (opcao == 's' || opcao == 'S')
	{
		if (cpf != NULL) //confere se a remo��o foi bem sucedida com a seguinte mensagem
		{
		remove(cpf);//remove o arquivo 'cpf'
		printf("\nO usu�rio foi deletado com sucesso!\n");
		printf("\nRetorno ao Menu do Cart�rio.\n");
		system("pause");
		}
	}
	
	//se for digitado (n)
	else if (opcao == 'n' || opcao == 'N')
	{
		printf ("\nVoc� ser� retornado(a) ao Menu do Cart�rio. \n");
		system ("pause");
	}
	
	//Caso o cpf inserido n�o exista
	else
	{
		printf("Op��o inv�lida");
		system("pause");
	}
}

//MENU PRINCIPAL

int main()
{
	//Definindo as vari�veis inteiras
	int opcao = 0; 
	int laco = 1;
	
	//Defini��o da l�nguagem
	setlocale(LC_ALL,"Portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	//Enquanto laco igual a 1
	while (laco == 1)
	{
        system("cls");
          
		//Menu de login
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 - Login\n");
		printf("\t2 - Registrar Usu�rio\n");
		printf("\t3 - Sa�da do Sistema\n\n");
		printf("Op��o: ");
		scanf("%d",&opcao);
		
		switch (opcao)
		{
			case 1:
			//Chama a fun��o login e se caso o valor retorne verdadeiro
			if(login())
			{
				laco = 0; //Para o loop do MENU DE LOGIN se o valor do laco for 0 
			}
			break;
			
			case 2:
			registro();
			break;
			
			case 3:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
		}
		
	}
	
	//Repeti��o do menu
	laco = 1;
	
	//enquanto laco igual a 1
	while(laco == 1)
	{
		system("cls");
		
		//Defini��o da l�guagem
		setlocale(LC_ALL, "Portuguese"); 
		
		//In�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Ol� Ebacer!\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sa�da do Sistema\n\n");
		printf("Op��o: "); 
		//Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
		system("cls");
		
		switch(opcao)//In�cio do menu;
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
		} //Fim da sele��o
			
	}//Fim da repeti��o do menu

}
