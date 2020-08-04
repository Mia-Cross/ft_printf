/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <leila.marabese@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:52 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/08 13:34:14 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		u;
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	u = (unsigned char)c;
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == u)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
