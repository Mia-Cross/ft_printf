/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:00:14 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/25 13:45:13 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u1;
	const unsigned char	*u2;
	size_t				i;

	u1 = s1;
	u2 = s2;
	i = 0;
	while (n > 0 && u1[i] == u2[i])
	{
		i++;
		n--;
	}
	if (n && u1[i] != u2[i])
		return (u1[i] - u2[i]);
	else
		return (0);
}
