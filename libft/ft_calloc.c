/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:39:50 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/19 15:25:20 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_fill_zero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	if (n == 0)
		return ;
	c = s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
	return ;
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = malloc(size * count)))
		return (NULL);
	ft_fill_zero(ptr, size * count);
	return (ptr);
}
