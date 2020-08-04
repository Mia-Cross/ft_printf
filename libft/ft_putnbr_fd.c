/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:37:50 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/19 15:39:27 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long p;
	char c;

	if (n < 0)
	{
		p = -(long)n;
		write(fd, "-", 1);
	}
	else
		p = (long)n;
	if (p > 9)
		ft_putnbr_fd((p / 10), fd);
	c = p % 10 + '0';
	ft_putchar_fd(c, fd);
}
