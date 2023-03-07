/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:42:55 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:03 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		nb_buckets;

	if (!(parse(argc, argv)))
		return (0);
	a = create_a(argv);
	if (!a)
		return (0);
	if (ft_is_sort(a))
		return (0);
	put_index(&a);
	b = NULL;
	nb_buckets = 5;
	if (argc == 501)
		nb_buckets = 17;
	else if (argc == 101)
		nb_buckets = 10;
	if (ft_lstsize(a) <= 5)
		sort_small_stack(&a, &b);
	else
		sort_big_stack(&a, &b, nb_buckets);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
