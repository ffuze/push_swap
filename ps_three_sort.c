/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/24 12:29:24 by lemarino         ###   ########.fr       */
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
