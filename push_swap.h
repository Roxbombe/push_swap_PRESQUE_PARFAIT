/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:44:24 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:58 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STR_INT_MIN "2147483647"
# define STR_INT_MAX "2147483648"

# include <stdio.h>
# include <stdlib.h>
# include "myprintf/ft_printf.h"
# include "libft/libft.h"

typedef struct t_stack
{
	int				content;
	int				cost;
	struct t_stack	*next;
	struct t_stack	*previous;
}	t_stack;

void	sort_3(t_stack **a, t_stack **b);
void	sort_small_stack(t_stack **a, t_stack **b);
void	sort_big_stack(t_stack **a, t_stack **b, int NB_BUCKETS);
void	sort_n(t_stack **a, t_stack **b);
void	up_node(t_stack **stack, t_stack *node, int n);
t_stack	*create_a(char **argv);
int		parse(int argc, char **argv);
void	put_new_content(t_stack **a, t_stack **a_index);
void	put_index(t_stack **a);
t_stack	*ft_lstnew(int content);
void	ft_lstclear(t_stack **stack);
void	ft_lstadd_back(t_stack **a, t_stack *new);
void	ft_lstdelone(t_stack **stack);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_p(t_stack **stack_1, t_stack **stack_2, int n);
void	ft_s(t_stack **stack, int n);
void	ft_r(t_stack **stack, int n);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **stack, int n);
int		ft_str_is_int(char *str);
int		ft_is_sort(t_stack *stack);
int		ft_lstsize(t_stack *stack);
t_stack	*ft_copy_lst(t_stack *lst);
void	set_cost(t_stack **stack);
int		abs(int nb);
t_stack	*get_max(t_stack *stack);
void	move_bucket(t_stack **a, t_stack **b, int bucket_size, int n);
int		ft_bucket_size(t_stack *stack, int nb_buckets);
int		second_max_ok(t_stack *second_max, t_stack *max);
t_stack	*get_second_max(t_stack *stack, t_stack *max);
t_stack	*get_min(t_stack *stack);
t_stack	*ft_parent(t_stack	*stack, int n);
void	sort_5(t_stack **a, t_stack **b);
void	sort_3(t_stack **a, t_stack **b);
#endif
