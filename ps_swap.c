/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:47:34 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/30 20:42:56 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **root)
{
	t_stack	*first;
	t_stack	*second;

	first = (*root);
	second = (*root)->next;
	first->next = second->next;
	second->next = first;
	*root = second;
}

// Swap the first 2 elements at the top of stack a.
void	sa(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_swap(stack_a);
		ft_printf("sa\n");
	}
}

// Swap the first 2 elements at the top of stack b.
void	sb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_swap(stack_b);
		ft_printf("sb\n");
	}
}

// sa and sb at the same time.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		ft_printf("ss\n");
	}
}
