#include <signal.h>
#include <unistd.h>
#include <stdio.h>


void handler(int signo)
{
	// printf()
	if (signo == SIGUSR1){
		write(1, "0", 1);
	} 
	else if (signo == SIGUSR2) {
		write(1, "1", 1);
	}
	// printf("sig = %d", signo);
	
}

int main(int ac, char **av)
{
	printf("%d \n", getpid());

	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		// if (SIGUSR1 == 1) {
		// 	printf("1 come!\n");
		// } else if (SIGUSR2 == 2){
		// 	printf("0 come\n");
		// } else {
		// 	printf("else!\n");
		// }
		// sleep(1);
	}

	return 0;
}
