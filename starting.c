/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:10:34 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/30 20:35:17 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nice_try(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		*costs_arr;

	costs_arr = get_costs_array(*stack_a, *stack_b);
	match_nodes(stack_a, stack_b, costs_arr);
	head_b = *stack_b;
	head_a = *stack_a;
	while (head_a)
		head_a = head_a->next;
	while (head_b)
		head_b = head_b->next;
	free(costs_arr);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*head_a;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	args = get_arguments(ac, av);
	if (!args)
		return (0);
	stack_a = ft_fill_stack(args);
	create_index(args, stack_a);
	head_a = stack_a;
	stack_a = head_a;
	fill_stack_b(&stack_a, &stack_b);
	while (stack_b)
		nice_try(&stack_a, &stack_b);
	lowest_to_top(&stack_a);
	head_a = stack_a;
	while (stack_a)
		stack_a = stack_a->next;
	stack_a = head_a;
	free_array(args);
	free_stack(&stack_a);
}
