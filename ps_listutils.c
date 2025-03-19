/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:22:28 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/19 16:34:02 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Counts the number of nodes in a stack.
size_t	ft_stacksize(t_stack *root)
{
	size_t	count;
	t_stack	*tmp;

	tmp = root;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp -> next;
	}
	return (count);
}


void	three_sort(t_stack **a)
{
	int *first;
	int *second;
	int *third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first < second && second > third && first < third)
		rra(a);
	else if (first < second && second > third && first > third)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && second > third && third < first)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && third < first)
		ra(a);
	else if (first > second && second < third && third > first)
		sa(a);
}
