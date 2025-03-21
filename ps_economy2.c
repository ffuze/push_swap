/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_economy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:40:07 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 11:58:58 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create an array holding the number of moves needed to move each element
//  in stackB above the greatest number inferior to it in stackA
int	total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(cost_a);
	abs_b = ft_abs(cost_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	else
		return (abs_a + abs_b);
}

int	fill_costs_array(t_stack *a, t_stack *tmp_b)
{
	t_stack	*tmp_a;
	int		i;
	
	tmp_a = a;
	get_costs(&tmp_a, &tmp_b);
	i = 0;
	while (tmp_a)
	{
		if (tmp_b->index == (tmp_a->index - i))
			return (total_cost(tmp_a->cost_a, tmp_b->cost_b));
		tmp_a = tmp_a->next;
		i++;
	}
	return (0);
}

int	*get_costs_array(t_stack *a, t_stack *b)
{
	// t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		*costs_arr;
	// int		i;
	int		j;

	j = 0;
	tmp_b = b;
	costs_arr = malloc(ft_stacksize(b) * sizeof(int));
	if (!costs_arr)
		return (NULL);
	while (tmp_b)
	{
		costs_arr[j] = fill_costs_array(a, tmp_b);
		/* tmp_a = a;
		i = 0;
		while (tmp_a)
		{
			if (tmp_b->index == (tmp_a->index - i))
			{
				costs_arr[j] = total_cost();
				break;
			}
			tmp_a = tmp_a->next;
			i++;
		} */
		tmp_b = tmp_b->next;
		j++;
	}
	return (costs_arr);
}
