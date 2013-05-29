////// Alan Haruo Arakaki - aha10 - GRR20100061 ///////
///// Gustavo Toshi Komura - gtk10 - GRR20102342 ////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define indA 0
#define k 5

//A função Busca retorna o índice "b" tal que v[b] < x 
int Busca(int x, int *v, int a, int b)
{
	if (a > b)
		return -1;
	if (x <= v[b])
		return b;
	return Busca(x, v, a, b - 1);
}

 //Esta função troca os valores, um pelo outro, de duas posições do vetor. 
int *Troca(int *v, int a, int b)
{
	int temp;
	temp = v[a];
	v[a]= v[b];
	v[b]= temp;
	return v;
}

int *Insere(int *v, int a, int b)
{
	int p, i;
	p = Busca(v[b], v, a, b - 1);
	i = b;
	if (p >= 0)
	{
		while (i >= (p + 1))
		{
			Troca(v, i, i - 1);
			i--;
		}
	}
	return v;
}

int *Insertion(int *v, int a, int b)
{
	if (a > b - 1)
		return v;
	Insertion(v, a, b - 1);
	Insere(v, a, b);
	return v;
}

int Particiona(int *v, int a, int b, int pivot)
{
	pivot = v[a];
	int iPivot = a;
	int j = a + 1, i;
	while (j <= b)
	{
		if (v[j] < pivot)
		{
			Troca(v, iPivot, j);
			iPivot = iPivot + 1;
		}
		j++;
	}
	return iPivot;
}

int *QuickInsert(int *v, int a, int b)
{
	int m, q;
	int n = 0;
	int p = 0;
	if ((b - a + 1) < k)
	{
		Insertion(v, a, b);
		return v;
	}
	if (a < b)
	{	
		m = Particiona(v, a, b, v[b]);
		QuickInsert(v, a, m-1);
		m = Particiona(v, a, b, v[b]);
		QuickInsert(v, m+1, b);
	}	
	return v;
}

void main(int count, char *teste[])
{
	char ch;
	int linhas = 0;
	int num;
	FILE * entrada;
	FILE *saida;
	entrada = fopen(teste[1],"r");
	saida= fopen(teste[2], "w+");
	while ((ch = fgetc(entrada)) != EOF)              //conta quantas linhas o arquivo possui
	{
		if (ch == 10)                    //se o caractere for igual à linefeed (\n)
		linhas++;
	}
	int vetor[linhas];                   //declara um vetor de tamanho igual ao número de linhas do arquivo
	int termo;
	int i = 0;
	rewind(entrada);
	while ( i < linhas)
	{
		fscanf (entrada, "%d", &num);          //lê os valores do arquivo e os adiciona ao vetor
		vetor[i] = num;
		i++;
	}
	QuickInsert(vetor, indA, linhas - 1);
	i = 0;
	while ( i < linhas)
	{
		num = vetor[i];
		fprintf (saida, "%d\n", num);          //lê os valores do vetor e os adiciona ao arquivo
		i++;
	}
	fclose(entrada);
	fclose(saida);
}
