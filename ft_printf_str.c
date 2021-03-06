/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:23:52 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/10 20:44:28 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf_str(va_list *arg_list, t_param *data)
{
	char	*str;
	int		ret;

	str = va_arg(*arg_list, char *);
	ret = ft_putstr_convert(str, data);
	return (ret);
}

int		ft_putstr_convert(char *str, t_param *data)
{
	int	i;
	int	len;
	int	p;
	int w;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	p = data->precis;
	w = ft_abs(data->width);
	if (data->precis == -1 || data->precis > len)
		p = len;
	while (!data->minus && w-- > p)
		write(1, " ", 1);
	i = 0;
	while (i < p)
		write(1, &(str[i++]), 1);
	while (data->minus && w-- > p)
		write(1, " ", 1);
	if (ft_abs(data->width) > p)
		return (p + (ft_abs(data->width) - p));
	return (p);
}
