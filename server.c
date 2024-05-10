/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:29 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/10 10:46:39 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_sqrt(int a, int b)
{
	if(a == 1 || b == 0)
		return (1);
	else
		return ((ft_sqrt(a, (b - 1))) * a);
}
int	ft_binary_to_decimal(int bit, int count)
{
	int c;
	c = bit * ft_sqrt(2, count);
	return (c);
}

void handler(int signal)
{
	static	int sum = 0;
	int bit;
	static int count = 0;

	bit = 0;
		if (signal == SIGUSR1)
			bit = 0;
		else if (signal == SIGUSR2)
			bit = 1;
		
		//printf("bit == %d\n", bit);
		//printf("count == %d\n", count);
		sum += ft_binary_to_decimal(bit, count);
		count++;
	if(count == 8)
	{
		printf("%c", sum);
		if(sum == '\0')
			{
				printf("\n");
			}
		count = 0;
		sum = 0;
	}
	
}


int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	printf("Je suis le serveur, mon PID est : %d\n", getpid());
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}

	return 0;
}
