/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:37:46 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/13 15:18:14 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	h = (char *)hay;
	n = (char *)need;
	if (need[0] == 0)
		return (h);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (need[j] && hay[i + j] == need[j] && (i + j) < len)
		{
			if (need[j + 1] == 0)
				return (h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
