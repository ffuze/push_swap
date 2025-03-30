/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/30 20:42:35 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lowest(t_stack **stack_a, t_stack **stack_b, int len_stack_a)
{
	while (ft_stacksize(*stack_a) > (len_stack_a / 2)
		&& (*stack_a)->index < (len_stack_a - 3))
	{
		if ((*stack_a)->index > (len_stack_a / 2))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

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
