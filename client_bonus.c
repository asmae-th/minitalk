/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:22:26 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/26 21:29:59 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	reslt;
	int	sing;

	sing = 1;
	reslt = 0;
	i = 0;
	if (!str[i])
		return (-1);
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sing = -sing;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		reslt = reslt * 10 + str[i++] - '0';
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (-1);
	return (reslt * sing);
}

void	pass_bit_server(pid_t pid, char c)
{
	int	bit;
	int	j;

	j = 0;
	while (j < 8)
	{
		bit = (c >> j) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "ok\n", 3);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	char				*msg;
	int					i;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid == -1)
			return (1);
		msg = av[2];
		i = 0;
		while (msg[i])
		{
			pass_bit_server(pid, msg[i]);
			i++;
		}
		pass_bit_server(pid, '\0');
	}
	else
		write(1, "nbr d'arg not 3\n", 16);
	return (0);
}
