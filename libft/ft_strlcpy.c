/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:18:15 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/25 13:46:57 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[j])
		j++;
	while (i < dstsize)
	{
		if ((i < dstsize - 1) && (src[i]))
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			return (j);
		}
		i++;
	}
	return (j);
}
