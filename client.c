/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:47:32 by iouali            #+#    #+#             */
/*   Updated: 2021/07/01 13:09:27 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int		ft_atoi(const char *nptr);
int		send_signal(pid_t pid, int c);

int	main(int argc, char *argv[])
{
	int		i;
	int		y;
	int		nb;

	if (argc != 3)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		y = 0;
		while (y < 8)
		{
			nb = (argv[2][i] >> y++) & 1;
			usleep(80);
			if (!(send_signal(ft_atoi(argv[1]), nb)))
				return (1);
		}
		i++;
	}
	return (0);
}

int 	send_signal(pid_t pid, int c)
{
	if (pid == 0)
	{
		write(1, "WRONG PID\n", 11);
		return (0);
	}
	if (c == 0)
	{
		if ((kill(pid, SIGUSR1)) == -1)
		{
			write(1, "WRONG PID\n", 11);
			return (0);
		}
	}
	if (c == 1)
	{
		if ((kill(pid, SIGUSR2)) == -1)
		{
			write(1, "WRONG PID\n", 11);
			return (0);
		}
	}
	return (1);
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
