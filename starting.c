/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:10:34 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/19 16:32:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_stack(char **array)
{
	t_stack	*new_node;
	t_stack *root;
	t_stack	*prev;
	int	i;

	i = 1;
	new_node = NULL;
	while(array[i])
	{
		prev = new_node;
		new_node = ft_calloc(1, sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node -> nbr = ft_atoi(array[i]);
		if (i == 1)
			root = new_node;
		else
			prev->next = new_node;
		i++;
	}
	return (root);
}


int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;
	t_stack	*headA;
	t_stack	*headB;

	if (ac <= 2)
		return (0);
	// if (ac == 2)
	// 	av = ft_split(av[1], ' ');
	
	stack_a = ft_fill_stack(av);
	headA = stack_a;
	// create_index(av, stack_a);
	while (stack_a)
	{
		printf(GREEN"%d\n"NO_COLOR, stack_a->nbr);//##################
		stack_a = stack_a->next;
	}
	stack_a = headA;
	
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	headB = stack_b;
	headA = stack_a;
	
	// headA = stack_a;
	get_costs(&stack_a, &stack_b);
	while (stack_a)
	{
		printf(GREEN"%d\n"NO_COLOR, stack_a->nbr);//##################
		printf(YELLOW"%d\n"NO_COLOR, stack_a->cost_a);//##################
		stack_a = stack_a->next;
	}
	while(stack_b)
	{
		printf(CYAN"%d\n"NO_COLOR, stack_b->nbr);//##################
		printf(MAGENTA"%d\n"NO_COLOR, stack_b->cost_b);//##################
		stack_b = stack_b->next;
	}

	// stack_a = headA;
	// get_cost_a(&stack_a);
	// while (stack_a)
	// {
	// 	printf(MAGENTA"%d\n"NO_COLOR, stack_a->cost_a);//##################
	// 	stack_a = stack_a->next;
	// }
	// stack_b = headB;
	// while(stack_b)
	// {
	// 	printf(CYAN"%d\n"NO_COLOR, stack_b->nbr);//##################
	// 	stack_b = stack_b->next;
	// }
	stack_b = headB;
	stack_a = headA;
	free_stack(&stack_a);
	free_stack(&stack_b);
	
}
