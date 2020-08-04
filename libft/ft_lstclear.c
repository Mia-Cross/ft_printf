/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:58:40 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/19 20:41:20 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_lstdel(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (lst)
	{
		while (*lst)
		{
			save = (*lst)->next;
			ft_lstdel(*lst, del);
			*lst = save;
		}
		lst = NULL;
	}
}
