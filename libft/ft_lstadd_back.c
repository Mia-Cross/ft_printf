/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:25:12 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/19 20:24:23 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (alst && new)
	{
		begin = *alst;
		if (begin)
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
			new->next = NULL;
		}
		else
			*alst = new;
	}
}
