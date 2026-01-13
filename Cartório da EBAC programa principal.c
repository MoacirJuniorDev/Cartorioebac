#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strigns

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Ínicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string


	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário sobre o CPF 
	scanf("%s", cpf); // Comando "scanf" sendo usado para salvar a mnsg do comando "printf". "%s" refere-se a string, ou seja, é usado para salvar o valor quando a variável for uma string 
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, ","); // Reescrevendo/adicionando uma vírgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informações do usuário sobre o nome
	scanf("%s", nome); // Comando "scanf" para salvar a mensagem enviada ao usuário. "%s" refere-se a string, ou seja, é usado para salvar o valor quando a variável for uma string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, nome); // Salvando a infomação do usuário na variável "nome"
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, ","); // Reescrevendo/adicionando uma vírgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando infomações do usuário sobre o sobremeno
	scanf("%s", sobrenome); // Comando "scanf" para salvar a mensagem enviada para o usuário."%s" refere-se a string, ou seja, é usado para salvar o valor quando a variável for uma string
	
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, sobrenome); // Salvando a informação do usuário na variável "sobrenome"
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, ","); // Reescrevendo/adicionando uma vírgula
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Coletando informações do usuário sobre o "cargo"
	scanf("%s", cargo); // Comando "scanf" para salvar a mensagem enviada ao usuário. "%s" refere-se a string, ou seja, é usado para salvar um valor quando uma variável for uma string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa reescrever/adicionar
	fprintf(file, cargo); // Salvando a informação do usuário na variável "cargo"
	fclose(file); // Fecha o arquivo

	system("pause"); // Pausa o programa até o usuário pressionar uma tecla

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	//Informando qual variável vai ser usada para consultar usuários
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informações do usuário a ser consultado
	scanf("%s", cpf); // Comando "scanf" para salvar a mensagem enviada ao usuário. "%s" refere-se a string, ou seja, é usado para salvar um valor quando uma variável for uma string
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf, "r"); // Abre o arquivo e ler ele
	
	if(file==NULL) // Se o arquivo informado for igual a nada...
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); // Informando ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);

	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso! E não se encontra mais no sistema!.\n");
		system("pause");
	}
	fclose(file);
}



int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1; // Criando função de retorno
	
	for(laco=1;laco=1;) // Enquanto laco for = a 1; retornar ao ínicio do laco
	{
		
		system("cls"); // Responsável por limpar a tela
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // Ínicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do  menu

		scanf("%d", &opcao); //Armazenando a escolha do usúario na memória

		system("cls"); // Responsável por limpar a tela
		
		
		switch(opcao) //Ínicio da seleção do menu
		{
			case 1:
			registro(); // Chamada de função registro
			break;
			
			case 2:
			consulta(); // Chamada de função consulta
			break;
			
			case 3:
			deletar(); //  Chamada de função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");
		}	
	
	}
	
}
