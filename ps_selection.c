/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 17:09:19 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the biggest number among all the numbers < than min_num
// For example:
// Stack A: 3 5 2
// Stack B: 4 7 8
// This function is going to look for a number that is smaller than the number in the stack B
// (min_num) BUT that it is the one that comes closest to min_num
/* t_stack	*get_smallest_n_b(t_stack *stack_a, int min_num)
{
	int		smallest;
	t_stack	*temp;

	smallest = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->nbr < min_num && (temp->nbr > smallest || !smallest))
			smallest = temp->nbr;
		temp = temp->next;
	}
	return (smallest);
}

t_stack	*get_biggest_n_b(t_stack *stack_a, int min_num)
{
	int		biggest;
	t_stack	*temp;

	biggest = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->nbr > min_num && (temp->nbr < biggest || !biggest))
			biggest = temp->nbr;
		temp = temp->next;
	}
	return (biggest);
} */

// Pushes to stack B all numbers in stack A except the biggest three
void	push_to_three(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = ft_stacksize(*stack_a);
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index < (len_stack_a - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}
