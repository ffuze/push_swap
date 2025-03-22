/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:52:45 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/22 18:49:58 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_stack(char **array)
{
	t_stack	*new_node;
	t_stack *root;
	t_stack	*prev;
	int	i;

	i = 1;
	new_node = NULL;
	while(array[i])
	{
		prev = new_node;
		new_node = ft_calloc(1, sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node -> nbr = ft_atoi(array[i]);
		if (i == 1)
			root = new_node;
		else
			prev->next = new_node;
		i++;
	}
	return (root);
}

// Counts the number of nodes in a stack.
int	ft_stacksize(t_stack *root)
{
	int	count;
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

void	lowest_to_top(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp->index != 0)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > ft_stacksize(*stack))
	{
		while ((*stack)->index != 0)
			rra(stack);
	}
	else
	{
		while ((*stack)->index != 0)
			ra(stack);
	}
}
