/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:03:21 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/07 13:33:35 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//remplacer les nombres de a par leur index
//(en utilisant la liste dupliquee dans put_index)
void	put_new_content(t_stack **a, t_stack **a_index)
{
	t_stack	*curr;
	t_stack	*curr_index;

	curr = *a;
	curr_index = *a_index;
	while (curr)
	{
		curr->content = curr_index->content;
		curr = curr->next;
		curr_index = curr_index->next;
	}
	ft_lstclear(a_index);
}

//duplique a
//dans la nouvelle liste, chaque nombre est 
// remplace par son index
//la nouvelle liste est utilisee dans 
//put_new_content pour appliquer l'index a la liste a
void	put_index(t_stack **a)
{
	t_stack	*a_index;
	t_stack	*curr1;
	t_stack	*curr2;
	t_stack	*curr3;
	int		n;

	curr1 = *a;
	a_index = ft_copy_lst(*a);
	curr3 = a_index;
	while (curr1)
	{
		n = 0;
		curr2 = *a;
		while (curr2)
		{
			if (curr2->content < curr1->content)
				n++;
			curr2 = curr2->next;
		}
		curr3->content = n + 1;
		curr3 = curr3->next;
		curr1 = curr1->next;
	}
	put_new_content(a, &a_index);
}

//creer la pile a
t_stack	*create_a(char **argv)
{
	t_stack		*a;
	t_stack		*tmp;
	int			i;

	a = ft_lstnew(ft_atoi(argv[1]));
	if (!a)
		return (NULL);
	i = 2;
	tmp = a;
	while (argv[i])
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_atoi(argv[i])));
		tmp = tmp->next;
		i++;
	}
	return (a);
}

//verifier que les arguments sont ok avant de creer a
int	parse(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!ft_str_is_int(argv[i]))
			return (0);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//verifier qu'un caractere est un digit
//(fonction utilisee dans la fonction parse)
int	ft_str_is_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	j = 0;
	while ((str + i)[j])
	{
		if (!ft_isdigit((str + i)[j]))
			return (0);
		j++;
	}
	if (j == 10)
	{
		if ((str[0] == '-' && ft_strncmp(STR_INT_MIN, str + i, 10) < 0)
			|| (str[0] == '+' && ft_strncmp(STR_INT_MAX, str + i, 10) < 0))
			return (0);
	}
	if (j > 10)
		return (0);
	return (1);
}

// int main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	a = create_a(argv);
// 	printf("%d", ft_mediane(a));
// 	return (0);
// }