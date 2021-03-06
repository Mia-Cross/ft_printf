/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:24:08 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/11 15:52:37 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	sgmt_len(const char *type_list, const char *format, int i)
{
	int	save;
	int	c;

	save = i;
	while (format[++i])
	{
		c = -1;
		while (type_list[++c])
		{
			if (type_list[c] == format[i])
				return (i - save);
		}
	}
	return (-1);
}

static int	move_cursor(const char *format, int i)
{
	int seg_len;

	seg_len = sgmt_len("cspdiuxX%", format, i);
	if (seg_len == -1)
		i++;
	else
		i += seg_len + 1;
	return (i);
}

static int	ft_convert(va_list *arg_list, const char *format, int i,
int (**tab)(va_list *, t_param *))
{
	int		seg_len;
	int		ret;
	t_param	data;

	seg_len = sgmt_len("cspdiuxX%", format, i);
	ret = 0;
	if (seg_len != -1)
	{
		reset_params(&data);
		set_params(ft_substr(format, i, seg_len), &data, arg_list);
		ret = (*tab[(int)format[i + seg_len]])(arg_list, &data);
	}
	return (ret);
}

static void	fill_tab(int (**tab)(va_list *, t_param *))
{
	tab['%'] = &ft_printf_modulo;
	tab['c'] = &ft_printf_char;
	tab['s'] = &ft_printf_str;
	tab['p'] = &ft_printf_adr;
	tab['d'] = &ft_printf_nbr;
	tab['i'] = &ft_printf_nbr;
	tab['u'] = &ft_printf_nbr_u;
	tab['x'] = &ft_printf_hexa_min;
	tab['X'] = &ft_printf_hexa_maj;
}

int			ft_printf(const char *format, ...)
{
	va_list		arg_list;
	int			i;
	int			count;
	int			(*tab[121])(va_list *, t_param *);

	va_start(arg_list, format);
	fill_tab(tab);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_convert(&arg_list, format, i, tab);
			i = move_cursor(format, i);
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	return (count);
}
