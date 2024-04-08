// Todescato Tommaso

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>

typedef struct argomenti
{
    int i;
    int pid;
}argomenti;

void *thread_function(argomenti *args)
{
    printf("Sono il thread %d del processo %d\n", args->i, args->pid);
    return NULL;
}

int main()
{
    int n;
    printf("Inserisci il numero: ");
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
        close(fd[0]);
        write(fd[1], &n, sizeof(n));
        close(fd[1]);

        pthread_t tid;
        argomenti a;
        a.pid = getpid();
        for(int i = 0; i < n; i++)
        {
            a.i = i+1;
            pthread_create(&tid, NULL, (void * (*)(void *)) thread_function, &a);
            pthread_join(tid, NULL);
        }

        printf("Tutti i thread hanno terminato\n");

    }
    else
    {
        close(fd[1]);
        int num;
        read(fd[0], &num, sizeof(num));
        close(fd[0]);

        pthread_t id2;
        argomenti a2;
        a2.pid = getpid();
        for(int j = 0; j < num; j++)
        {
            a2.i = j+1;
            pthread_create(&id2, NULL, (void * (*)(void *)) thread_function, &a2);
            pthread_join(id2, NULL);
        }

        printf("Tutti i thread hanno terminato\n");
    }

    wait(NULL);
    return 0;
}