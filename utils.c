/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:39:54 by atahtouh          #+#    #+#             */
/*   Updated: 2024/05/16 10:31:47 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar_fd('-', fd);
		}
		if (nb > 9)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
}
