/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:29 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/26 20:52:08 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_sqrt(int a, int b)
{
	if (a == 1 || b == 0)
		return (1);
	else
		return ((ft_sqrt(a, (b - 1))) * a);
}

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
		if (sum == '\0')
			write(1, "\n", 1);
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
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
