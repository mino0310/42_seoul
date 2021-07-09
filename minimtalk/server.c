#include <signal.h>
#include <unistd.h>
#include <stdio.h>


void print_hello(int signo)
{
	printf("hello\n");
}

int main(int ac, char **av)
{
	printf("%d \n", getpid());

	while (1)
	{
		signal(SIGUSR1, (void *)print_hello);
		sleep(1);
	}

	return 0;
}
