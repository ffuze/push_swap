/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/20 19:34:23 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the biggest number among all the numbers < than min_num
// For example:
// Stack A: 3 5 2
// Stack B: 4 7 8
// This function is going to look for a number that is smaller than the number in the stack B
// (min_num) BUT that it is the one that comes closest to min_num
t_stack *get_smallest_n_b(t_stack *stack_a, int min_num)
{
	t_stack	*smallest;
	t_stack *temp;

	smallest = NULL;
	temp = stack_a;
	while (temp)
	{
		if (temp->nbr < min_num && (temp->nbr > smallest || !smallest))
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

t_stack *get_biggest_n_b(t_stack *stack_a, int min_num)
{
	t_stack	*biggest;
	t_stack *temp;

	biggest = NULL;
	temp = stack_a;
	while (temp)
	{
		if (temp->nbr > min_num && (temp->nbr < biggest || !biggest))
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

void	*get_correct_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	size_t len_stack_a;

	temp = *stack_a;
	len_stack_a = ft_stacksize(temp);
	while (ft_stacksize(temp) > 3)
	{
		if (temp->index < (len_stack_a - 4))
			pb(stack_a, stack_b);
		temp = temp->next;
	}
}
