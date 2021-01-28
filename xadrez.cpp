#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Cria as Variaveis
enum pecas { espacovazio, peao, cavalo, torre, bispo, rei, rainha }; 

int main()

{
	float c;

	// cria a matriz tabuleiro 8x8 e posiciona as peças de acordo com o enunciado.

	int tabuleiro[8][8] = {
	{1, 3, 0, 5, 4, 0, 2, 1},
	{1, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 6, 0},
	{1, 0, 0, 1, 1, 0, 0, 1},
	{0, 1, 0, 4, 0, 0, 1, 0},
	{0, 0, 3, 1, 0, 0, 1, 1},
	{1, 0, 6, 6, 0, 0, 1, 0},
	{1, 0, 5, 0, 1, 1, 0, 6}
	};

// Mostra o tabuleiro Inicial ao usuário.
	printf("Bem vindo ao Xadrez by Uninter!\n");
	printf("\nO tabuleiro esta configurado da seguinte forma:\n\n");
	int linha, coluna;
	for (linha = 0; linha < 8; linha++)
	{
		for (coluna = 0; coluna < 8; coluna++)
		{
			printf("%d ", tabuleiro[linha][coluna]);
		}
		printf("\n");
	}

	int contador[7] = { 0 }; // criação do vetor "contador" com as 7 opções de peças e atribui um valor para cada alteração de peças.
	int i, x;
	for (i = 0; i < 8; i++) {

		for (x = 0; x < 8; x++) {
			switch (tabuleiro[i][x])
			{
			case espacovazio:
				contador[0]++;
				break;
			case peao:
				contador[1]++;
				break;
			case cavalo:
				contador[2]++;
				break;
			case torre:
				contador[3]++;
				break;
			case bispo:
				contador[4]++;
				break;
			case rei:
				contador[5]++;
				break;
			case rainha:
				contador[6]++;
				break;
			default:
				break;
			}

		}

	}

	printf("\n");
// Exibe algumas informações ao usuarios
	printf("LEGENDA DA APLICACAO\n");
	printf("0 - Espaco vazio | 1 - Peao | 2 - Cavalo | 3 - Torre | 4 - Bispo | 5 - Rei | 6 - Rainha\n\n");
	printf("\nQuantidade de casas vazias e pecas:\n\n");
	printf("Casas vazias\t= %d\n", contador[0]);
	printf("Peoes\t\t= %d\n", contador[1]);
	printf("Cavalos\t\t= %d\n", contador[2]);
	printf("Torres\t\t= %d\n", contador[3]);
	printf("Bispos\t\t= %d\n", contador[4]);
	printf("Reis\t\t= %d\n", contador[5]);
	printf("Rainhas\t\t= %d\n", contador[6]);
	printf("\n");

	system("pause");

// Inicio da Criação do Tabuleiro Personalizado
// Inicialmente zera todos os contadores!
	contador[0] = 0;
	contador[1] = 0;
	contador[2] = 0;
	contador[3] = 0;
	contador[4] = 0;
	contador[5] = 0;
	contador[6] = 0;

// Cria um novo tabuleiro personalizado, mas com as mesmas peças do tabuleiro anterior.

	int tabuleirousuario[8][8] = {
	{1, 3, 0, 5, 4, 0, 2, 1},
	{1, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 6, 0},
	{1, 0, 0, 1, 1, 0, 0, 1},
	{0, 1, 0, 4, 0, 0, 1, 0},
	{0, 0, 3, 1, 0, 0, 1, 1},
	{1, 0, 6, 6, 0, 0, 1, 0},
	{1, 0, 5, 0, 1, 1, 0, 6}
	};
	int linhausuario, colunausuario; // definição das variaveis que o usuario vai preencher.
	int escolhausuario;
	int SimOuNao;

	system("cls");
	printf("Agora vamos comecar a montar o seu tabuleiro!\n\n");
	// exibição do tabuleiro atual para o usuário.
	for (linha = 0; linha < 8; linha++)
	{
		for (coluna = 0; coluna < 8; coluna++)
		{
			printf("%d ", tabuleirousuario[linha][coluna]);
		}
		printf("\n");
	}

	// Solicita que o Usuário informe as peças.
	printf("\nDigite a posicao da linha (1 a 8) que deseja alterar:\n");
	scanf_s("%d", &linhausuario);
	while ((linhausuario < 1) || (linhausuario > 8))
	{
		printf("O valor inserido e invalido! Digite um numero de 1 a 8 para a posição na linha!\n");
		scanf_s("%d", &linhausuario);
	}
	printf("Agora, digite a posicao da coluna (1 a 8) que deseja alterar:\n");
	scanf_s("%d", &colunausuario);
	while ((colunausuario < 1) || (colunausuario > 8))
	{
		printf("O valor inserido e invalido! Digite um numero de 1 a 8 para a posição na coluna!\n");
		scanf_s("%d", &colunausuario);
	}
	printf("Digite a peca que deseja inserir na posicao %d,%d:\n", linhausuario, colunausuario);
	printf("0 = espaco em branco\n");
	printf("1 = Peao\n");
	printf("2 = Cavalo\n");
	printf("3 = Torre\n");
	printf("4 = Bispo\n");
	printf("5 = Rei\n");
	printf("6 = Rainha\n");
	scanf_s("%d", &escolhausuario);

	while ((escolhausuario < 0) || (escolhausuario > 6))
	{
		printf("A peça desejada nao existe! Insira uma opcao valido conforme o menu!\n");
		scanf_s("%d", &escolhausuario);
	}

	// Um tabuleiro de xadrez é exibido ao usuario como sendo 8 linhas por 8 colunas.
	// Lógica Utilizada: quando o usuario digita 2 para linha e 2 para coluna, na verdade vai inserir o valor na posical 1x1 da matriz do tabuleiro.
	tabuleirousuario[linhausuario - 1][colunausuario - 1] = escolhausuario;
	printf("Deseja alterar outra posicao?\n");
	printf("(1) para SIM e (2) para NAO\n");
	scanf_s("%d", &SimOuNao);
	while (SimOuNao == 1) // enquanto o usuario escolher que quer mudar mais peças, fica no loop.
	{
		printf("\nDigite a posicao da linha (1 a 8) que deseja alterar:\n");
		scanf_s("%d", &linhausuario);
		while ((linhausuario < 1) || (linhausuario > 8)) //se o usuario escolher um valor errado para linha, fica no loop
		{
			printf("O valor inserido e invalido! Digite um numero de 1 a 8 para a posicao na linha!\n");
			scanf_s("%d", &linhausuario);
		}
		printf("Agora, digite a posicao da coluna (1 a 8) que deseja alterar:\n");
		scanf_s("%d", &colunausuario);
		while ((colunausuario < 1) || (colunausuario > 8)) // se o usuario escolhe um valor errado para coluna, fica no laço.
		{
			printf("O valor inserido e invalido! Digite um numero de 1 a 8 para a posicao na coluna!\n");
			scanf_s("%d", &colunausuario);
		}
		printf("Digite a peca que deseja inserir na posicao %d,%d:\n", linhausuario, colunausuario);
		printf("0 = espaco em branco\n");
		printf("1 = Peao\n");
		printf("2 = Cavalo\n");
		printf("3 = Torre\n");
		printf("4 = Bispo\n");
		printf("5 = Rei\n");
		printf("6 = Rainha\n");
		scanf_s("%d", &escolhausuario);
		while ((escolhausuario < 0) || (escolhausuario > 6)) // se o usuario escolhe uma peça que nao existe, fica no laço.
		{
			printf("A peca desejada nao existe! Insira um valor valido conforme o menu!\n");
			scanf_s("%d", &escolhausuario);
		}
		tabuleirousuario[linhausuario - 1][colunausuario - 1] = escolhausuario;
		printf("Deseja alterar outra posicao?\n");
		printf("(1) para SIM e (2) para NAO\n");
		scanf_s("%d", &SimOuNao);

	}
	// com tudo preenchido, exibe o tabuleiro que o usuário escolheu.
	system("cls");// Limpa a tela
	printf("Tabuleiro de Xadrez by Uninter!\n\n");
	printf("Este e o seu NOVO tabuleiro!\n\n");
	int linha1, coluna1;
	int contadorusuario[7];
	for (linha1 = 0; linha1 < 8; linha1++)
	{
		for (coluna1 = 0; coluna1 < 8; coluna1++)
		{
			printf("%d ", tabuleirousuario[linha1][coluna1]);
		}
		printf("\n");
	}
	int j, l;
	for (j = 0; j < 8; j++) {
		for (l = 0; l < 8; l++)
		{
			switch (tabuleirousuario[j][l])
			{
			case espacovazio:
				contador[0]++;
				break;
			case peao:
				contador[1]++;
				break;
			case cavalo:
				contador[2]++;
				break;
			case torre:
				contador[3]++;
				break;
			case bispo:
				contador[4]++;
				break;
			case rei:
				contador[5]++;
				break;
			case rainha:
				contador[6]++;
				break;
			default:
				break;
			}

		}

	}

	// exibe o contador final, com todas as alterações feitas pelo usuario.

	printf("\n");
	printf("LEGENDA DA APLICACAO\n");
	printf("0 - Espaco vazio | 1 - Peao | 2 - Cavalo | 3 - Torre | 4 - Bispo | 5 - Rei | 6 - Rainha\n\n");
	printf("\nQuantidade de casas vazias e pecas:\n");
	printf("Casas vazias\t= %d\n", contador[0]);
	printf("Peoes\t\t= %d\n", contador[1]);
	printf("Cavalos\t\t= %d\n", contador[2]);
	printf("Torres\t\t= %d\n", contador[3]);
	printf("Bispos\t\t= %d\n", contador[4]);
	printf("Reis\t\t= %d\n", contador[5]);
	printf("Rainhas\t\t= %d\n", contador[6]);
	printf("\n");

	int escolhafimprograma;
	printf("Digite (1) para encerrar o programa ou (2) para exibir um tabuleiro inicial do jogo!\n"); //mostra uma opção extra ao usuario.
	scanf_s("%d", &escolhafimprograma);
	while ((escolhafimprograma < 1) || (escolhafimprograma > 2)) // enquanto o usuario nao escolhe uma opção do menu, fica no loop abaixo.
	{
		printf("\nOpcao invalida! Digite (1) para encerrar ou (2) para exibir um tabuleiro inicial do jogo!\n");
		scanf_s("%d", &escolhafimprograma);
	}
	if (escolhafimprograma == 1) // se o usuário quer encerrar o programa, encerra.
	{
		system("cls"); // limpa a tela
		printf("XEQUE-MATE!");
		return 0;
	}

	if (escolhafimprograma == 2) //exibe o tabuleiro inicial de um jogo de xadrez para o usuário.
	{
		contador[0] = 0;
		contador[1] = 0;
		contador[2] = 0;
		contador[3] = 0;
		contador[4] = 0;
		contador[5] = 0;
		contador[6] = 0;
		system("cls");
		printf("POSICAO INICIAL DAS PEÇAS DE UM TABULEIRO DE XADREZ\n\n");
		int tabuleirodefault[8][8] = { // cria um novo tabuleiro padrao do jogo.
		{3, 2, 4, 6, 5, 4, 2, 3},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{3, 2, 4, 6, 5, 4, 2, 3}
		};
		int linhadefault, colunadefault;
		for (linhadefault = 0; linhadefault < 8; linhadefault++)
		{
			for (colunadefault = 0; colunadefault < 8; colunadefault++)
			{
				printf("%d ", tabuleirodefault[linhadefault][colunadefault]);
			}
			printf("\n");
		}
		int m, n;

		for (m = 0; m < 8; m++) {
			for (n = 0; n < 8; n++)
			{
				switch (tabuleirodefault[m][n])
				{
				case espacovazio:
					contador[0]++;
					break;
				case peao:
					contador[1]++;
					break;
				case cavalo:
					contador[2]++;
					break;
				case torre:
					contador[3]++;
					break;
				case bispo:
					contador[4]++;
					break;
				case rei:
					contador[5]++;
					break;
				case rainha:
					contador[6]++;
					break;
				default:
					break;
				}
			}
		}

		// exibe o contador com as peças iniciais do jogo.
		printf("\n");
		printf("LEGENDA DA APLICACAO\n");
		printf("0 - Espaco vazio | 1 - Peao | 2 - Cavalo | 3 - Torre | 4 - Bispo | 5 - Rei | 6 - Rainha\n\n");
		printf("\nQuantidade de casas vazias e pecas:\n");
		printf("Casas vazias\t= %d\n", contador[0]);
		printf("Peoes\t\t= %d\n", contador[1]);
		printf("Cavalos\t\t= %d\n", contador[2]);
		printf("Torres\t\t= %d\n", contador[3]);
		printf("Bispos\t\t= %d\n", contador[4]);
		printf("Reis\t\t= %d\n", contador[5]);
		printf("Rainhas\t\t= %d\n", contador[6]);
		printf("\n");
		system("pause");
	}
	system("cls"); // limpa a tela
	printf("XEQUE-MATE!\n");
	return 0;
}
