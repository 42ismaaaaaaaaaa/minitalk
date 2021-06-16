/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:47:32 by iouali            #+#    #+#             */
/*   Updated: 2021/06/16 15:44:14 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int		ft_atoi(const char *nptr);
void	send_signal(pid_t pid, char c);
char	*char_to_bin(char c);

int	main(int argc, char *argv[])
{
	int		i;
	int		y;
	char	*bin;

	if (argc != 3)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		bin = char_to_bin(argv[2][i]);
		y = 0;
		while (bin[y])
		{
			send_signal(ft_atoi(argv[1]), bin[y]);
			y++;
		}
		i++;
	}
	free(bin);
	return (0);
}

void 	send_signal(pid_t pid, char c)
{
	if (c == '0')
		kill(pid, SIGUSR1);
	if (c == '1')
		kill(pid, SIGUSR2);
	usleep(90);
}

char	*char_to_bin(char c)
{
	char	*bin;
	int		i;
	int		div;
	int		mod;

	i = 7;
	bin = malloc(9 * sizeof(char));
	if (!bin)
		return (NULL);
	div = c;
	while (i >= 0)
	{
		mod = div % 2;
		if (mod == 0)
			bin[i] = '0';
		else
			bin[i] = '1';
		div /= 2;
		i--;
	}
	bin[8] = '\0';
	return (bin);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t			i;
	unsigned char	*tmp_nptr;
	int				sign;
	long long		result;

	tmp_nptr = (unsigned char *)nptr;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(tmp_nptr[i]))
		i++;
	if (tmp_nptr[i] == '-' || tmp_nptr[i] == '+')
	{
		if (tmp_nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (tmp_nptr[i] >= '0' && tmp_nptr[i] <= '9')
	{
		result = (result * 10) + (tmp_nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
