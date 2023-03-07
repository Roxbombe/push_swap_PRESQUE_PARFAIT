/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:39:48 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/02 16:53:42 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

//taille de liste
int	ft_lstsize(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

//copier coller une liste (utilise dans put_index pour dupliquer a)
t_stack	*ft_copy_lst(t_stack *lst)
{
	t_stack	*lst2;

	lst2 = ft_lstnew(lst->content);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&lst2, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (lst2);
}

int	ft_is_sort(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	curr = stack;
	next = stack->next;
	while (next)
	{
		if (curr->content > next->content)
			return (0);
		curr = next;
		next = next->next;
	}
	return (1);
}
