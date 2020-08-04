/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:03:58 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/10 18:58:25 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_size(int s_count, t_param *data)
{
	int	size;

	size = s_count;
	if (s_count < data->precis)
		size += (data->precis - s_count);
	if (data->width < 0 && data->precis < 0 && s_count < ft_abs(data->width))
		size += (ft_abs(data->width) - s_count);
	return (size);
}

static int		nbr_len(unsigned long nbr, int base_len, t_param *data)
{
	int		i;

	if (!data->precis && nbr == 0)
		return (0);
	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr = nbr / base_len;
		i++;
	}
	return (i);
}

static void		put_zero_and_p(char *str, t_param *data, int s_count)
{
	int	p;
	int	i;
	int	w;

	i = 0;
	p = data->precis;
	w = ft_abs(data->width);
	while (p-- > s_count)
		str[i++] = '0';
	while (p < 0 && data->width < 0 && w-- > s_count)
		str[i++] = '0';
}

static char		*print_nbr(char *str, unsigned long nbr, char *base,
t_param *data)
{
	int		i;
	int		s_count;
	int		base_len;
	int		size;

	s_count = nbr_len(nbr, ft_strlen(base), data);
	size = get_size(s_count, data);
	base_len = ft_strlen(base);
	put_zero_and_p(str, data, s_count);
	i = size - 1;
	if (nbr == 0 && data->precis)
		str[i] = '0';
	while (nbr)
	{
		str[i] = base[nbr % base_len];
		nbr = nbr / base_len;
		i--;
	}
	str[size] = 0;
	return (str);
}

char			*ft_itoa_base_ux(unsigned long nbr, t_param *data, char *base)
{
	int		s_count;
	int		size;
	char	*str;

	s_count = nbr_len(nbr, ft_strlen(base), data);
	size = get_size(s_count, data);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str = print_nbr(str, nbr, base, data);
	return (str);
}
