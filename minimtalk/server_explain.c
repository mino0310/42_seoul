#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

// 시그널을 처리할 핸들러
void sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char c = 0x00;
	static int	cnt = 0;
	static pid_t client_pid = 0;

	// (void)unused;
	// client_pid가 없을 경우 이를 siginfo 구조체에서 지정해준다
	if (!client_pid)
		client_pid = siginfo->si_pid;
	// 들어온 시그널이 SIGUSR1인지 비교한다.
	// 맞을 경우 1(참값)을 반환하고 이를 보내야 하는 char 형 변수인 c와  OR비트연산한다.
	// client 에서 마지막 비트가 1일 경우 SIGUSR1을 보내므로, 0으로 초기화되어 있는 c와
	// OR 비트 연산을 하면 1값을 비트에 넣어줄 수 있다.
	c |= (sig == SIGUSR1);
	// 8개의 비트를 다 받았는지 체크한다. 
	if (++cnt == 8)
	{
		// 다시 바이트를 비트단위로 보내야 하므로 초기화한다.
		cnt = 0;
		// 보낼 문자가 0값인지 체크한다. 보낼 문자가 없다는 말이다.
		if (c == 0x00)
		{
			//client_pid를 초기화하고 종료한다.
			client_pid = 0;
			return ;
		}
		// 비트를 모아서 문자를 만들었으므로 이를 출력해준다.
		ft_putchar_fd(c, 1);
		// 문자를 출력해줬으므로 문자를 초기화해준다.
		c = 0x00;
		// client에서 보낸 문자를 출력했으므로 client에 이 문자는 다 받았다고 알려준다.
		kill(client_pid, SIGUSR1);
	}
	// 8개 비트를 아직 덜 받은 상태인지 체크한다.
	else
	{
		// 현재 비트를 받고 있는 바이트의 비트를 왼쪽으로 한칸 민다. 다음 비트를 받기 위해서.
		c <<= 1;
		// 아직 비트를 더 받아야 한다고 client 에 시그널을 보내 알려준다.
		kill(client_pid, SIGUSR2);
	}
}

int main(void)
{
	struct sigaction e;

	ft_putstr_fd("Server PID [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	while (1)
		pause();
	return 0;
}