/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/22 15:29:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort_checks(t_stack **a, t_stack *first,
	t_stack *second, t_stack *third)
{
	if (first->nbr < second->nbr && second->nbr > third->nbr \
												&& first->nbr < third->nbr)
	{
		rra(a);
		sa(a);
	}
	else if (first->nbr < second->nbr && second->nbr > third->nbr \
												&& first->nbr > third->nbr)
		rra(a);
	else if (first->nbr > second->nbr && second->nbr > third->nbr \
												&& third->nbr < first->nbr)
	{
		sa(a);
		rra(a);
	}
	else if (first->nbr > second->nbr && second->nbr < third->nbr \
												&& third->nbr < first->nbr)
		ra(a);
	else if (first->nbr > second->nbr && second->nbr < third->nbr \
												&& third->nbr > first->nbr)
		sa(a);
}

void	three_sort(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = (*a);
	second = (*a)->next;
	third = (*a)->next->next;
	three_sort_checks(a, first, second, third);
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
