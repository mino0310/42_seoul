#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

// 해당 server_pid 와 연결을 종료하는 함수.
void fin_connect(pid_t server_pid)
{
	int i;

	i = 8;
	while (i--)
	{
		// 시그널을 보내는 간격을 유지하기 위해 usleep 호출
		usleep(50);
		// server_pid로 SIGUSR2 시그널을 보낸다.
		kill(server_pid, SIGUSR2);
	}
	// 종료
	exit(0);
}

// 바이트를 시그널로 쪼개서 보내는 함수.
void send_byte(char *s, pid_t pid)
{
	// 해당 변수들을 재사용할 것이므로 static 으로 선언한다.
	static int i = 8;
	static unsigned char c;
	static char	*str;
	static pid_t server_pid;

	// 매개변수로 받아온 문자열이 존재한다면
	if (s)
	{
		// 만들어 놓은 str에 매개변수 s의 주소를 복사한다. 
		str = s;
		// 받아온 pid 를 server_pid에 저장한다.
		server_pid = pid;
		// 보낼 바이트(한 문자)를 확보하기 위해서 str에서 첫 문자를 가져온다.
		c = *str;
	}
	// 보낼 비트의 개수(8개가 초기값)이 없을 경우에 이를 채워줘야 하므로 검사한다.
	if (!i)
	{
		// 보낼 비트의 개수를 초기화한다.
		i = 8;
		// i가 0이라는 말은 보내려는 바이트의 비트를 다 보냈다는 이야기이므로 다음 문자를 가져온다. 
		c = *(++str);
		// 문자를 받아왔으니 문자가 실제 문자인지, 아니면 널값인지 체크할 필요가 있다.
		if (!c) // 가져온 문자가 없을 경우엔 연결을 끊는다.
			fin_connect(server_pid);
	}
	// 문자를 받아오고, 보낼 비트가 있는지도 확인을 끝낸 상태. 
	// 문자가 존재하고 문자 바이트의 가장 마지막 비트가 1이라면 SIGUSR1 을 보낸다.
	if (c && c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	// 문자만 존재하고 마지막 비트가 1이 아니라면 SIGUSR2를 보낸다. 
	else if (c)
		kill(server_pid, SIGUSR2);
}

// 시그널이 들어왔을 때 실제로 작동할 핸들러
// 첫번째 매개변수는 대처할 시그널, 두번째 매개변수는 시그널의 정보 구조체, 마지막은 쓰이지 않는다.
// 이 원형은 다음과 같다. 
// void    (*__sa_sigaction)(int, struct __siginfo *, void *);
void sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	// 받은 바이트의 개수를 저장할 변수를 선언해두고 처음만 0으로 초기화해둔다.
	static int received_bytes = 0;

	// (void)siginfo;
	// (void)unused;
	// 들어온 시그널이 SIGUSR1인지 파악.
	if (sig == SIGUSR1)
	{
		// 커서의 위치를 맨 앞으로 돌린다음 받은 비트수를 출력
		ft_putstr_fd("\rReceived Bytes : ", 1);
		ft_putnbr_fd(++received_bytes, 1);
	}
	// 0, 0을 보내면 연결 종료.
	send_byte(0, 0);
}

int main(int argc, char **argv)
{
	// sigaction 함수에 사용할 구조체 선언.
	struct sigaction e;
	
	// 입력값 에외처리
	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr_fd("Usage : ./client [99 < Server PID < 99999] [Message]", 1);
		return (1);
	}
	// 입력값이 없을 경우에 프로그램 종료
	if (!ft_strlen(argv[2]))
		exit(0);
	// sighandler 를 사용하기 위해서 SA_SIGINFO 할당.
	e.sa_flags = SA_SIGINFO;
	// sighandler 지정
	e.sa_sigaction = sig_handler;
	// 시그널에 따라 시행할 핸들러가 지정된 구조체를 시그널과 매칭.
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	// 보낸 바이트 출력
	ft_putstr_fd("Send Bytes  : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	// 보낼 문자열을 바이트 단위로 전송
	send_byte(argv[2], ft_atoi(argv[1]));
	// 대기
	while (1)
		pause();
	return 0;
}