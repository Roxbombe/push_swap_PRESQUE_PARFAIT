/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:41:33 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/03 14:28:12 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//intervertir les deux premiers
void	ft_s(t_stack **stack, int n)
{
	int	tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (n == 0)
		ft_printf("sa\n");
	else if (n == 1)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	int	tmp_1;
	int	tmp_2;

	if (!(*a) || !(*b))
		return ;
	tmp_1 = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp_1;
	tmp_2 = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp_2;
	ft_printf("ss\n");
}

//mettre le premier d'une pile stack2 au sommet de stack1
void	ft_p(t_stack **stack_1, t_stack **stack_2, int n)
{
	if (!(*stack_2))
		return ;
	ft_lstadd_front(stack_1, ft_lstnew((*stack_2)->content));
	ft_lstdelone(stack_2);
	if (n == 0)
		ft_printf("pb\n");
	else if (n == 1)
		ft_printf("pa\n");
}

//mettre le premier en dernier et tout faire monter
void	ft_r(t_stack **stack, int n)
{
	t_stack	*curr;
	t_stack	*next;
	int		tmp;

	if (!(*stack))
		return ;
	curr = (*stack);
	next = (*stack)->next;
	tmp = (*stack)->content;
	while (next)
	{
		curr->content = next->content;
		next = next->next;
		curr = curr->next;
	}
	curr->content = tmp;
	if (n == 0)
		ft_printf("ra\n");
	else if (n == 1)
		ft_printf("rb\n");
}

//mettre le dernier en premier et tout faire descendre
void	ft_rr(t_stack **stack, int n)
{
	t_stack	*curr;
	t_stack	*next;
	int		tmp_content;
	int		tmp2_content;

	if (!(*stack))
		return ;
	curr = (*stack);
	next = (*stack)->next;
	tmp_content = curr->content;
	while (next)
	{
		tmp2_content = next->content;
		next->content = tmp_content;
		curr = curr->next;
		next = next->next;
		tmp_content = tmp2_content;
	}
	(*stack)->content = tmp_content;
	if (n == 0)
		ft_printf("rra\n");
	else if (n == 1)
		ft_printf("rrb\n");
}
