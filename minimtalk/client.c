#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	fin_connect(pid_t server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(50);
		kill(server_pid, SIGUSR2);
	}
	exit(0);
}

void	send_byte(char *s, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			server_pid;

	if (s)
	{
		str = s;
		server_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			fin_connect(server_pid);
	}
	if (c && c >> --i & 0x01)
		kill(server_pid, SIGUSR1);
	else if (c)
		kill(server_pid, SIGUSR2);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	received_bytes = 0;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\rReceived Bytes : ", 1);
		ft_putnbr_fd(++received_bytes, 1);
	}
	send_byte(0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	e;

	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr_fd("Usage : ./client [99 < Server PID < 99999] [Message]", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	ft_putstr_fd("Send Bytes  : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	send_byte(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
