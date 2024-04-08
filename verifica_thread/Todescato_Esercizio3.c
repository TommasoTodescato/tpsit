// Todescato Tommaso

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

void *thread_function(int *i)
{
   printf("Sono il thread %d\n", *i);
   return NULL;
}

int main()
{
   int n;
   scanf("%d", &n);
   if (n >= INT_MAX || n < 0)
   {
       printf("Input non valido\n");
       return 1;
   }
   pthread_t id;

   for(int i = 0; i < n; i++)
       pthread_create(&id, NULL, (void * (*)(void *)) thread_function, &i);

   pthread_join(id, NULL);
   printf("Tutti i thread hanno terminato\n");
   return 0;
}