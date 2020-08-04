/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ft_atoi_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:21:31 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/03 18:08:11 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_from(const char *str, int i)
{
	int	out;

	out = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	return (out);
}
