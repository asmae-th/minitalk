/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:22:21 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/26 20:51:48 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_binary_to_decimal(int bit, int count)
{
	int	c;

	c = bit * ft_sqrt(2, count);
	return (c);
}

void	initialize_handler(int *sum, int *count)
{
	*sum = 0;
	*count = 0;
}

void	ft_write_msg(int *sum, int client_pid)
{
	if (*sum == '\0')
	{
		kill(client_pid, SIGUSR1);
		usleep(150);
		write(1, "\n", 1);
	}
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	sum;
	int			bit;
	static int	count;
	static int	client_pid;

	(void)context;
	bit = 0;
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		initialize_handler(&sum, &count);
	}
	if (signal == SIGUSR1)
		bit = 0;
	else if (signal == SIGUSR2)
		bit = 1;
	sum += ft_binary_to_decimal(bit, count);
	count++;
	if (count == 8)
	{
		write(1, &sum, 1);
		ft_write_msg(&sum, client_pid);
		initialize_handler(&sum, &count);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	write(1, "Je suis le serveur, mon PID est :", 33);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	write(1, "==================================================", 50);
	write(1, "\n", 1);
	usleep(100);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
