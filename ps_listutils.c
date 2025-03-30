/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:52:45 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/30 20:38:45 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_stack(char **args)
{
	t_stack	*new_node;
	t_stack	*root;
	t_stack	*prev;
	int		i;

	i = 0;
	new_node = NULL;
	while (args[i])
	{
		prev = new_node;
		new_node = ft_calloc(1, sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nbr = ft_atoi(args[i]);
		if (i == 0)
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
	int		count;
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
	if (i > ft_stacksize(*stack) / 2)
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

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
