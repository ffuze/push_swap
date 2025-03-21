/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 16:04:09 by lemarino         ###   ########.fr       */
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

/* void	move_b_to_top(t_stack **stack_b, t_stack *target)
{
	while (*stack_b != target)
	{
		if (target->cost_b < 0)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	sort_stack_b(t_stack **b)
{
	t_stack	*target;

	get_cost_b(b);
	target = get_cheapest_cost(*b);
	move_b_to_top(b, target);
} */
