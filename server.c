#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	sighandler(int signum);
void	bin_to_char(char *bin);
int		ft_pow(int power, int nb);
void	ft_putint(int pid);

int	main(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		return (1);
	ft_putint(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
	return (0);
}

void	sighandler(int signum)
{
	static char	bin[8];
	int			i;

	i = 0;
	while (bin[i])
		i++;
	if (signum == SIGUSR1)
		bin[i] = '0';
	else if (signum == SIGUSR2)
		bin[i] = '1';
	bin[i + 1] = '\0';
	if (i == 7)
	{
		bin_to_char(bin);
		bin[0] = '\0';
	}
}

int	ft_pow(int power, int nb)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

void	bin_to_char(char *bin)
{
	int	i;
	int	y;
	int	num;
	int	zero_one;

	num = 0;
	i = 7;
	y = 0;
	while (i >= 0)
	{
		zero_one = 0;
		if (bin[y] == '1')
			zero_one = 1;
		num += (zero_one * ft_pow(i, 2));
		i--;
		y++;
	}
	write(1, &num, 1);
}

void	ft_putint(int pid)
{
	int		mod;
	int		to_print;

	mod = pid % 10;
	pid /= 10;
	to_print = mod + 48;
	if (pid > 0)
	{
		ft_putint(pid);
		write(1, &to_print, 1);
	}
	if (pid == 0)
		write(1, &to_print, 1);
}
