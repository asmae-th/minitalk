/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:14:24 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/09 21:27:57 by atahtouh         ###   ########.fr       */
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
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i] != '\0')
			i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			sing = -sing;
		}
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		reslt = reslt * 10 + str[i] - '0';
		i++;
	}
	return (reslt * sing);
}

void	pass_bit_server(pid_t pid, int bit)
{
	if(bit == 0)
	{
		kill(pid, SIGUSR1);
	}
	else if(bit == 1)
	{
		kill(pid, SIGUSR2);
	}
}

int main(int ac, char **av) 
{
	pid_t pid;
	char *msg;
	int	bit;
	int i;
	int	j;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		msg = av[2];
		i = 0;
		while (msg[i])
		{
			j = 0;
			while (j < 8)
			{
				bit = (msg[i] >> j) & 1;
				//printf("%d", bit);
				pass_bit_server(pid, bit);
				j++;
			}
			i++;
		}
	}
} 
 


