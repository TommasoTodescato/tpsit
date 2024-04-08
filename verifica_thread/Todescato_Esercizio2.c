// Todescato Tommaso

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void input_arr(int n, int arr[])
{
   for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void print_arr(int n, int arr[])
{
   for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}

int sum_arr(int n, int arr[])
{
   int r = 0;
   for (int i = 0; i < n; i++)
   {
       r += arr[i];
   }
   return r;
}

int main()
{
   int n;
   printf("Quanti dati vuoi passare? ");
   scanf("%d", &n);
   if (n >= INT_MAX || n < 0)
   {
       printf("Input non valido\n");
       return 1;
   }

   int fd[2];
   pipe(fd);
   int id = fork();
   if (id < 0)
   {
       printf("Errore nella creazione del processo\n");
       return 1;
   }
   else if (id > 0)
   {
       // padre
       close(fd[0]);
       int arr[n];
       input_arr(n, arr);
       write(fd[1], arr, sizeof(arr));
       close(fd[1]);
   }
   else
   {
       //figlio
       close(fd[1]);
       int arr[n];
       read(fd[0], arr, sizeof(arr));

       print_arr(n, arr);
       int somma = sum_arr(n, arr);
       printf("Somma = %d\nMedia = %f", somma, (double)somma/n);

       close(fd[0]);
   }

   return 0;
}