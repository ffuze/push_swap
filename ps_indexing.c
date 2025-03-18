/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:01:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/18 15:54:01 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	*sort_list(t_stack *root)
{
	t_stack	*lst;
	t_stack	*begin;
	t_stack	*p;

	lst = root;
	begin = root;
	while (lst)
	{
		p = lst->next;
		while (p)
		{
			if (lst->nbr > p->nbr)
				swap(&lst->nbr, &p->nbr);
			p = p->next;
		}
		lst = lst->next;
	}
	return (begin);
}

// "i" starts from -1 bc I needed to increase it at the beginning of the loop,
//		blame norminette.
void	create_index(char **array, t_stack *root)
{
	t_stack	*tmp;
	t_stack *sortedcpy;
	t_stack	*cpyhead;
	int		i;

	i = -1;
	tmp = root;
	sortedcpy = ft_fill_stack(array);
	cpyhead = sortedcpy;
	sort_list(sortedcpy);
	while (tmp && sortedcpy)
	{
		i++;
		if (tmp->nbr == sortedcpy->nbr)
		{
			tmp->index = i;
			i = -1;
			sortedcpy = cpyhead;
			tmp = tmp->next;
		}
		else
			sortedcpy = sortedcpy->next;
	}
	free_stack(&cpyhead);
}
