/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:38:53 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/25 13:51:52 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (char*)dest;
	s = (const char*)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
