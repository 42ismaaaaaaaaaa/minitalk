/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:18:37 by iouali            #+#    #+#             */
/*   Updated: 2021/07/01 14:23:42 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	sighandler(int signum);
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
	static char	c = 0;
	static int	i = 0;
	int			a;

	a = 2;
	if (signum == SIGUSR1)
		a = 0;
	else if (signum == SIGUSR2)
		a = 1;
	if (a == 2)
		return ;
	c |= (a << i++);
	if (i > 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
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
