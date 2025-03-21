/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_executemoves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:34:18 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 22:52:01 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cost < 0: rotate.
// Cost > 0: reverse rotate.
// Cost = 0: push (pa).
// Costs with equal sign mean that a certain amount of moves can be executed
//  at the same time (rr and rrr)
void	identify_moves(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	int	a_rots;
	int	b_rots;

	a_rots = node_a->cost_a;
	b_rots = node_b->cost_b;
	while (a_rots != 0 && b_rots != 0)
	{
		if (a_rots > 0 && b_rots > 0)
		{
			rrr(a, b);
			a_rots--;
			b_rots--;
		}
		else if (a_rots < 0 && b_rots < 0)
		{
			rr(a, b);
			a_rots++;
			b_rots++;
		}
		else
		{
			if (a_rots > 0)
			{
				rra(a);
				a_rots--;
			}
			else if (a_rots < 0)
			{
				ra(a);
				a_rots++;
			}
			if (b_rots > 0)
			{
				rrb(b);
				b_rots--;
			}
			else if (b_rots < 0)
			{
				rb(b);
				b_rots++;
			}
		}
	}
	pa(b, a);
}

// Finds the best node in stack A to put below the
//  cheapest node to push from stackB 
void	match_nodes(t_stack **a, t_stack **b, int *costs_arr)
{
	t_stack *cheapest_node;
	t_stack *tmp_b;
	t_stack	*tmp_a;
	t_stack	*tmp_a2;
	int		i;

	i = 1;
	cheapest_node = ft_lowest_cost(*b, costs_arr);
	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		tmp_a2 = *a;
		while (tmp_a2)
		{
			if (tmp_b->index == (tmp_a2->index - i))
				return (identify_moves(a, b, tmp_a2, tmp_b));
			tmp_a2 = tmp_a2->next;
		}
		i++;
	}
}
