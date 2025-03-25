/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_executemoves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:34:18 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/24 19:06:51 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cost < 0: rotate.
// Cost > 0: reverse rotate.
// Cost = 0: push (pa).
// Costs with equal sign mean that a certain amount of moves can be executed
//  at the same time (rr and rrr)

static void	double_rotations(t_stack **a, t_stack **b, \
											t_rotations	*rot_counter)
{
	if (rot_counter->a_rots > 0 && rot_counter->b_rots > 0)
	{
		rrr(a, b);
		rot_counter->a_rots--;
		rot_counter->b_rots--;
	}
	else if (rot_counter->a_rots < 0 && rot_counter->b_rots < 0)
	{
		rr(a, b);
		rot_counter->a_rots++;
		rot_counter->b_rots++;
	}
}

static void	single_rotations(t_stack **a, t_stack **b, \
											t_rotations	*rot_counter)
{
	if (rot_counter->a_rots > 0)
	{
		rra(a);
		rot_counter->a_rots--;
	}
	else if (rot_counter->a_rots < 0)
	{
		ra(a);
		rot_counter->a_rots++;
	}
	if (rot_counter->b_rots > 0)
	{
		rrb(b);
		rot_counter->b_rots--;
	}
	else if (rot_counter->b_rots < 0)
	{
		rb(b);
		rot_counter->b_rots++;
	}
}

void	identify_moves(t_stack **a, t_stack **b, t_stack *node_a, \
														t_stack *node_b)
{
	t_rotations	rot_counter;

	rot_counter.a_rots = node_a->cost_a;
	rot_counter.b_rots = node_b->cost_b;
	while (rot_counter.a_rots != 0 || rot_counter.b_rots != 0)
	{
		if ((rot_counter.a_rots > 0 && rot_counter.b_rots > 0) || \
						(rot_counter.a_rots < 0 && rot_counter.b_rots < 0))
			double_rotations(a, b, &rot_counter);
		else
			single_rotations(a, b, &rot_counter);
	}
	pa(b, a);
}

// Finds the best node in stack A to put below the
//  cheapest node to push from stackB 
void	match_nodes(t_stack **a, t_stack **b, int *costs_arr)
{
	t_stack	*cheapest_node;
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	t_stack	*tmp_a2;
	int		i;

	i = 1;
	cheapest_node = ft_lowest_cost(*b, costs_arr);
	tmp_a = *a;
	tmp_b = cheapest_node;
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
