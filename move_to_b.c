/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:04:37 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:36:41 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	second_max_ok(t_stack *second_max, t_stack *max)
{
	if (((max->cost <= 0 && second_max->cost <= 0)
			|| (max->cost > 0 && second_max->cost > 0))
		&& abs(second_max->cost) < abs(max->cost))
		return (1);
	else
		return (0);
}

t_stack	*get_second_max(t_stack *stack, t_stack *max)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->content == (max->content) - 1)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

//calculer la taille d'un bucket
int	ft_bucket_size(t_stack *stack, int nb_buckets)
{
	int	size;

	size = ft_lstsize(stack);
	if (size % nb_buckets == 0)
		return (size / nb_buckets);
	else
		return ((size + (nb_buckets - size % nb_buckets)) / nb_buckets);
}

void	move_bucket(t_stack **a, t_stack **b, int bucket_size, int n)
{
	int	new_content;
	int	q1;
	int	q2;

	q1 = bucket_size;
	q2 = bucket_size;
	while (ft_lstsize(*a) > 0 && (q1 || q2))
	{
		new_content = (*a)->content;
		if (new_content <= bucket_size * (2 * n + 1)
			&& new_content > bucket_size * 2 * n)
		{
			ft_p(b, a, 0);
			q1--;
		}
		else if (new_content <= bucket_size * (2 * n + 2)
			&& new_content > bucket_size * (2 * n + 1))
		{
			ft_p(b, a, 0);
			ft_r(b, 1);
			q2--;
		}
		else
			ft_r(a, 0);
	}
}
