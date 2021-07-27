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
void ten_to_two_2(unsigned n) {
    // 동적 배열 생성 
    int size = 1;
    int *a = (int*)calloc(sizeof(int)*size);
    // 배열에 원소 넣기 ex) 11 => 1 1 0 1 (2로 나누고 나머지 값) 
    for (int i = 0; n != 0; i++) {
        a[i] = n % 2;
        n /= 2;
        if (n != 0) {
            size++;
            a = realloc(a, sizeof(int)*size);
        }
    }
    // 배열 원소 거꾸로 출력 
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    free(a);
}