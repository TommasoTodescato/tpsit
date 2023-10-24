#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DIM 	100
#define RANGE 	100
#define NC 		25


void *stampa(void *string)
{
	printf("%s\n", (char*)string);
	return NULL;
}

typedef struct array
{
	int d;
	int *v;
} array;

void *BubbleSort(array* a);

int main()
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, stampa, "Ciao");
	pthread_create(&thread2, NULL, stampa, "Hello");
	pthread_join(thread2, NULL);
	return 0;
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void CaricaVettore(int d, int *v)
{
	srand(time(NULL));
	for (int i = 0; i < d; i++)
	{
		v[i] = rand() % RANGE;
	}
}

void StampaVettore(int d, int *v, char *commento)
{
	printf("%s", commento);
	for (int i = 0; i < d; i++)
	{
		if (i % NC == 0)
		{
			printf("\n");
		}
		printf("%d ", v[i]);
	}
}

void *BubbleSort(array* a)
{
	int c = 0;
	bool finito = false;
	for (int i = 0; i < a->d - 1; i++)
	{
		finito = false;
		for (int j = 0; j < a->d - i - 1; j++)
		{
			if (a->v[j] > a->v[j + 1])
			{
				swap(a->v+j, a->v+j+1);
				finito = true;
				c++;
			}
		}
		if (!finito) break;
	}
	printf("vettore ordinato in %d passi", c);
	return NULL;
}