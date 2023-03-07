/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:55 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:22 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*cell;

	cell = malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->cost = 0;
	cell->next = NULL;
	cell->previous = NULL;
	return (cell);
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!(*stack))
		*stack = new;
	else
	{
		tmp = new;
		tmp->next = *stack;
		(*stack)->previous = tmp;
		*stack = tmp;
	}
}

void	ft_lstadd_back(t_stack **a, t_stack *new)
{
	t_stack	*tmp;

	if (!(*a))
		*a = new;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->previous = tmp;
	}
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!(*stack))
		return ;
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		curr->content = 0;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}

void	ft_lstdelone(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->content = 0;
	free(tmp);
}
