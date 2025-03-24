/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/24 17:39:14 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lowest(t_stack **stack_a, t_stack **stack_b, int len_stack_a)
{
	// int	len_stack_a;

	// len_stack_a = ft_stacksize(*stack_a);
	while (ft_stacksize(*stack_a) > (len_stack_a / 2))
	{
		if((*stack_a)->index < (len_stack_a / 2) && (*stack_a)->index < (len_stack_a - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		// printf(RED"len_stack_a iniziale: %d, len attuale: %d\n"NO_COLOR, len_stack_a, ft_stacksize(*stack_a));//##########
	}
}

void	push_to_three(t_stack **stack_a, t_stack **stack_b, int len_stack_a)
{
	// int	len_stack_a;

	// len_stack_a = ft_stacksize(*stack_a);
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index < (len_stack_a - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		// printf(YELLOW"len_stack_a iniziale: %d, len attuale: %d\n"NO_COLOR, len_stack_a, ft_stacksize(*stack_a));//##########
	}
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = ft_stacksize(*stack_a);
	if (len_stack_a > 6)
		push_lowest(stack_a, stack_b, len_stack_a);
	if (len_stack_a > 2)
	{
		push_to_three(stack_a, stack_b, len_stack_a);
		three_sort(stack_a);
	}
}