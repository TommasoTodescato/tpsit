#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 30

int main()
{
	char buffer[SIZE];
	int p[2];

	if (pipe(p) < 0)
		return 1;

	if (fork() > 0)
	{
		FILE *f = fopen("/home/tommaso/info/tpsit/es_multi/input.txt", "r");

		size_t r;
		do
		{
			r = fread(buffer, SIZE, 1, f);
			write(p[1], buffer, SIZE);
		}
		while (r == 1);

		wait(NULL);
	}

	else
	{
		close(p[1]);
		while (read(p[0], buffer, SIZE) > 0)
		{
			printf("%s\n", buffer);
		}

		printf("Finito\n");
	}
	return 0;
}