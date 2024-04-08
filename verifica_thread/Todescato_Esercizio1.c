// Todescato Tommaso

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

int main()
{
   int n;
   printf("Inserisci quanti livelli vuoi: ");
   scanf("%d", &n);
   if (n >= INT_MAX || n < 0)
   {
       printf("Input non valido\n");
       return 1;
   }

   printf("Sono il processo padre (PID %d)\n\n", getpid());
   for(int i = 0; i < n; i++)
   {
       int id = fork();
       if (id < 0)
       {
           printf("Errore nella creazione del processo\n");
           return 1;
       }
       else if (id == 0)
       {
           for(int j = 0; j < i; j++) printf("\t");

           printf("Sono il processo figlio (PID %d) di livello %d\n", getpid(), i+1);
           return 0;
       }
       wait(NULL);
   }

   return 0;
}