/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:52:45 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 11:54:49 by lemarino         ###   ########.fr       */
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

int	ft_abs(int n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

/* int	get_lowest_number(t_stack *stack)
{
	t_stack	*temp;
	int	lowest;

	temp = stack;
	if (!temp)
		return (NULL);
	while (temp)
	{
		if (temp->nbr < temp->next->nbr)
			lowest = stack;
		temp = temp->next;
	}
	return (lowest);
} */
