#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf( "Budet schitan file \"input\"\n" );
	/* Первое число в файле есть число N*/
	FILE *f;
	if ( ( f = fopen ( "input" , "rb" ) ) == 0 )
	{
		printf( "ERROR 1\n" );
		return 1;
	}
	int A[100][100];
	int N;
	fscanf( f, "%d", &N);
	if ( N > 100 ) 
	{
		printf ( "ERROR 2\n" );
		return 1;
	}
	/*Начинаем считывать массив мощности |N|*|N|*/
	int i, j;
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
		{
			fscanf( f, "%d", &A[i][j]);
		}
	}
	/*Ввод массива окончен*/
	/* Вывод исходного массива для проверки правильности ввода */
	
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
		{
			printf( "A[%d][%d] = %d\n", i, j, A[i][j] );
		}
	}
	printf("\n");
	/*Начинаем выборку минимального и максимального произведений элементов строк*/
	int Min = 1, Max = 1;
	int IMin = 0, IMax = 0;
	for ( j = 0; j < N; j++)
	{
		Min *= A[0][j];
	}
	Max = Min;
	int Current;
	for ( i = 1; i < N; i++)
	{
		Current = 1;
		for ( j = 0; j < N; j++)
		{
			Current *= A[i][j];
		}
		if ( Current < Min )
		{
			Min = Current;
			IMin = i;
		}
		if ( Current > Max )
		{
			Max = Current;
			IMax = i;
		}
	}
	/*Меняем строки местами*/
	if ( IMax != IMin ) 
	{
		for ( i = 0; i < N; i++)
		{
			j = A[IMin][i];
			A[IMin][i] = A[IMax][i];
			A[IMax][i] = j;	
		}
	}
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
		{
			printf( "A[%d][%d] = %d\n", i, j, A[i][j] );
		}
	}
	return 0;
}
