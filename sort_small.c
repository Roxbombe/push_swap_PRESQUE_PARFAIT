/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:14:49 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:36:14 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if (!(ft_is_sort(*a)))
			ft_r(a, 0);
	}
	if (ft_lstsize(*a) == 3)
		sort_3(a, b);
	if (ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4)
		sort_5(a, b);
	return ;
}

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->content > (*a)->next->next->content)
		ft_r(a, 0);
	if ((*a)->content > (*a)->next->next->content)
		ft_r(a, 0);
	if (ft_is_sort(*a))
		return ;
	if ((*a)->content < (*a)->next->next->content
		&& (*a)->content > (*a)->next->content)
		ft_s(a, 0);
	else
	{
		ft_p(b, a, 0);
		ft_r(a, 0);
		ft_p(a, b, 1);
	}
	return ;
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*parent;
	t_stack	*max;
	int		m;

	m = 1;
	while (ft_lstsize(*a) > 3)
		ft_p(b, a, 0);
	sort_3(a, b);
	while (*b)
	{
		max = get_max(*b);
		up_node(b, max, 1);
		parent = ft_parent(*a, (*b)->content);
		up_node(a, parent, 0);
		ft_p(a, b, 1);
	}
	while (!(ft_is_sort(*a)))
		ft_rr(a, 0);
}

t_stack	*ft_parent(t_stack	*stack, int n)
{
	t_stack	*parent;

	parent = get_min(stack);
	while (stack)
	{
		if (stack->content - n > 0 && parent->content - n < 0)
			parent = stack;
		if (stack->content - n > 0
			&& abs(stack->content - n) <= abs(parent->content - n))
			parent = stack;
		stack = stack->next;
	}
	return (parent);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
