/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:24:15 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/11 15:29:41 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_params(t_param *data)
{
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->precis = -1;
	data->width = 0;
}

static void	process_star_flag(char *sgmt, t_param *data, va_list *arg_list,
int i)
{
	if (sgmt[i - 1] == '.')
	{
		data->precis = va_arg(*arg_list, int);
		if (data->precis < 0)
		{
			data->minus = 1;
			data->precis = -1;
		}
	}
	else
	{
		data->width = va_arg(*arg_list, int);
		if (data->width < 0)
		{
			data->minus = 1;
			data->width = -(data->width);
		}
		if (sgmt[i - 1] == '0' && !data->minus)
			data->width = -(data->width);
	}
}

static int	set_numeric_value(char *sgmt, t_param *data, int i)
{
	if (sgmt[i - 1] == '.')
	{
		data->precis = ft_atoi_from(sgmt, i);
		while (sgmt[i + 1] <= '9' && sgmt[i + 1] >= '0')
			i++;
	}
	else
	{
		data->width = ft_atoi_from(sgmt, i);
		if (sgmt[i] == '0')
			data->width = -(data->width);
		while (sgmt[i + 1] <= '9' && sgmt[i + 1] >= '0')
			i++;
	}
	return (i);
}

void		set_params(char *sgmt, t_param *data, va_list *arg_list)
{
	int	i;

	if (!sgmt)
		return ;
	i = 0;
	while (sgmt[++i])
	{
		if (sgmt[i] == '-')
			data->minus = 1;
		else if (sgmt[i] == '+')
			data->plus = 1;
		else if (sgmt[i] == ' ')
			data->space = 1;
		else if (sgmt[i] == '*')
			process_star_flag(sgmt, data, arg_list, i);
		else if (sgmt[i] <= '9' && sgmt[i] >= '0')
			i = set_numeric_value(sgmt, data, i);
		else if (sgmt[i] == '.' && !(sgmt[i + 1] <= '9' && sgmt[i + 1] >= '0'))
			data->precis = 0;
	}
	free(sgmt);
	return ;
}
