#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int					ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int					ft_atoi(const char *str)
{
	long long int	nbr;
	long			sign;
	size_t			i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] != '\0') && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * nbr);
}

char *char_to_binary(char c, char *str)
{
	unsigned int tmp = c;
	int i = 7;
	while (tmp / 2 != 1)
	{
		str[i] = tmp % 2;
		i--;
	}
	while (i)
		str[i--] = '0';
	return str;
}


int main(int ac, char **av)
{
	pid_t	pid;

	pid = getpid();
	printf("client pid = %d\n", pid);
	// SIGUSR1 = 0;
	// SIGUSR1 = 1;
	// printf("SIGUSR1 = %d \n SIGUSR2 = %d\n", SIGUSR1, SIGUSR2);
	// printf("%s is received! \n", av[2]);
	char *str = (char *)malloc(sizeof(char) * 9);
	
	int tmp = av[2][0] - '0';
	int i = 7;
	while(tmp / 2 != 1)
	{
		if (tmp % 2 == 0)
		{
			str[i] = '0';
			write(1, "zero!\n", 5);
		}
		else{
			str[i] = '1';
			write(1, "one!\n", 4);
		}
		tmp /= 2;
		i--;
	}
	while (i)
		str[i--] = '0';

	for (i = 0; i < 8; i++) {
		if (str[i] == '0')
			kill(ft_atoi(av[1]), SIGUSR1);
		else
			kill(ft_atoi(av[1]), SIGUSR2);
		usleep(1);
	}
	// kill(ft_atoi(av[1]), SIGUSR1);
	// kill(ft_atoi(av[1]), SIGUSR2);

	
	return 0;
}
