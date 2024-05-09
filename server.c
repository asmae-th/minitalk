/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:25:29 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/09 21:44:24 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void handler(int signal)
// {
// 	if(signal == SIGUSR1)
// 	{
// 		printf("ana 0\n");
// 	}
// 	else if(signal == SIGUSR2)
// 	{
// 		printf("ana 1\n");
// 	}
	
// }
// int main(int ac , char **av)
// {
// 	printf("I am the serveur my pid is : %d\n", getpid());
// 	while (1)
// 	{
// 		signal(SIGUSR1, handler);
// 		signal(SIGUSR2, handler);
// 	}
	
// }

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
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
// void handler(int signal)
// {
// 	int sum;
// 	int bit;
// 	int count;

// 	count = -1;
// 	sum = 0;
void handler(int signal)
{
	static	int sum = 0;
	int bit;
	static int count = -1;

	bit = 0;
		if (signal == SIGUSR1)
			bit = 0;
		else if (signal == SIGUSR2)
			bit = 1;
		count++;
		printf("bit == %d\n", bit);
		printf("count == %d\n", count);
		sum += ft_binary_to_decimal(bit, count);

	printf("sum == %d\n", sum);
}
	// while(count < 8)
	// {
	// 	//bit = 0;
	// 	if (signal == SIGUSR1)
	// 		bit = 0;
	// 	else if (signal == SIGUSR2)
	// 		bit = 1;
	// 	count++;
	// 	printf ("bit == %d\n", ft_binary_to_decimal(bit,count));
	// 	printf ("count == %d\n", count);
	// 	sum = sum + ft_binary_to_decimal(bit,count);
	// 	printf ("sum1 == %d\n", sum);
	// }
// 	printf ("sum == %d\n", sum);
// }

int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	printf("Je suis le serveur, mon PID est : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		// sigaction(SIGUSR1, &sa, NULL);
		// sigaction(SIGUSR2, &sa, NULL);
		sleep(1);
	}

	return 0;
}
// struct sigaction sa;
//     sa.sa_handler = handler;
//     sigemptyset(&sa.sa_mask);

// void handle_signal(int signal) {
//     printf("Signal reçu : %d\n", signal);
//     // Ajoutez ici le code pour gérer le signal selon vos besoins
// }

// int main() {
//     struct sigaction sa;
//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = 0;
//     sa.sa_handler = handle_signal;

//     // Définir le comportement pour le signal SIGINT
//     sigaction(SIGQUIT , &sa, NULL);

//     printf("En attente du signal SIGINT...%d\n",getpid());
//     while (1) {
//         // Boucle infinie pour maintenir le programme en cours d'exécution
//     }

//     return 0;
// }