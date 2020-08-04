/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:31:04 by lemarabe          #+#    #+#             */
/*   Updated: 2019/10/23 19:37:16 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_lstnew_elem(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*map;
	t_list	**begin;

	map = NULL;
	begin = &map;
	while (lst)
	{
		if (!(map = ft_lstnew_elem((*f)(lst->content))))
		{
			(*del)(map);
			free(map);
		}
		lst = lst->next;
		map = map->next;
	}
	return (*begin);
}
