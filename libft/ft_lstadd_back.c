/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:15:39 by abergman          #+#    #+#             */
/*   Updated: 2024/06/02 16:11:49 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*search_last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!lst || !new)
		return ;
	search_last = *lst;
	while (search_last->next)
		search_last = search_last->next;
	search_last->next = new;
}
