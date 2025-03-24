/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:10:34 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/24 17:38:50 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nice_try(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*headA;
	t_stack	*headB;
	int		*costs_arr;

	costs_arr = get_costs_array(*stack_a, *stack_b);
	match_nodes(stack_a, stack_b, costs_arr);

	headB = *stack_b;
	headA = *stack_a;
	while (headA)
	{
		// printf(GREEN"%d\n"NO_COLOR, headA->nbr);//##################
		headA = headA->next;
	}
	while(headB)
	{
		// printf(CYAN"%d\n"NO_COLOR, headB->nbr);//##################
		headB = headB->next;
	}
	free(costs_arr);
	// printf(RED"NEXT::\n"NO_COLOR);//##################
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;
	t_stack	*headA;
	// t_stack	*headB;

	if (ac <= 2)
		return (0);
	// if (ac == 2)
	// 	av = ft_split(av[1], ' ');
	
	stack_a = ft_fill_stack(av);
	headA = stack_a;
	create_index(av, stack_a);
	// while (stack_a)
	// {
	// 	printf(GREEN"%d\n"NO_COLOR, stack_a->nbr);//##################
	// 	// printf(RED"%d\n"NO_COLOR, stack_a->index);//##################
	// 	stack_a = stack_a->next;
	// }
	stack_a = headA;

	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// push_to_three(&stack_a, &stack_b);
	fill_stack_b(&stack_a, &stack_b);
	// three_sort(&stack_a);
	// get_costs(&stack_a, &stack_b);

	// headB = stack_b;
	// headA = stack_a;
	// while (stack_a)
	// {
	// 	printf(GREEN"%d\n"NO_COLOR, stack_a->nbr);//##################
	// 	printf(YELLOW"%d\n"NO_COLOR, stack_a->index);//##################
	// 	stack_a = stack_a->next;
	// }
	// while(stack_b)
	// {
	// 	printf(CYAN"%d\n"NO_COLOR, stack_b->nbr);//##################
	// 	printf(MAGENTA"%d\n"NO_COLOR, stack_b->index);//##################
	// 	stack_b = stack_b->next;
	// }

	// stack_a = headA;
	// stack_b = headB;
	while (stack_b)
	{
		nice_try(&stack_a, &stack_b);
	}

	/* int	i = 0;
	costs_arr = get_costs_array(stack_a, stack_b);
	while (i < ft_stacksize(stack_b))
	{
		printf(MAGENTA"Cost for  B node %d: %d\n"NO_COLOR, i, costs_arr[i]);//##################
		i++;
		}
		match_nodes(&stack_a, &stack_b, costs_arr);
		headB = stack_b;
		stack_a = headA; */

	lowest_to_top(&stack_a);
	headA = stack_a;
	while (stack_a)
	{
		printf(YELLOW"%d; "NO_COLOR, stack_a->nbr);//##################
		stack_a = stack_a->next;
	}
	// stack_b = headB;
	// while(stack_b)
	// {
	// 	printf(CYAN"%d\n"NO_COLOR, stack_b->nbr);//##################
	// 	stack_b = stack_b->next;
	// }
	// stack_b = headB;
	// free(costs_arr);
	stack_a = headA;
	free_stack(&stack_a);
	// free_stack(&stack_b);
	
}
