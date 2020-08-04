/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:22:55 by lemarabe          #+#    #+#             */
/*   Updated: 2019/12/11 15:46:59 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_param
{
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precis;
}				t_param;
int				ft_printf_char(va_list *arg_list, t_param *data);
int				ft_printf_str(va_list *arg_list, t_param *data);
int				ft_printf_adr(va_list *arg_list, t_param *data);
int				ft_printf_nbr(va_list *arg_list, t_param *data);
int				ft_printf_nbr_u(va_list *arg_list, t_param *data);
int				ft_printf_hexa_min(va_list *arg_list, t_param *data);
int				ft_printf_hexa_maj(va_list *arg_list, t_param *data);
int				ft_printf_modulo(va_list *arg_list, t_param *data);
int				ft_putchar_convert(char c, t_param *data);
int				ft_putstr_convert(char *str, t_param *data);
int				ft_putaddress_convert(unsigned long ptr, t_param *data);
int				ft_putnbr_convert(int n, t_param *data);
int				ft_putunsigned_convert(unsigned int n, t_param *data);
int				ft_puthexa_min_convert(unsigned int nb, t_param *data);
int				ft_puthexa_maj_convert(unsigned int nb, t_param *data);
char			*ft_itoa_base_di(int nbr, t_param *data, char *base);
char			*ft_itoa_base_ux(unsigned long nbr, t_param *data, char *base);
int				ft_atoi_from(const char *str, int i);
int				ft_abs(int nb);
void			reset_params(t_param *data);
void			set_params(char *sgmt, t_param *data, va_list *arg_list);
int				ft_printf(const char *format, ...);

#endif
