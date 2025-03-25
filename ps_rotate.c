/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:58:08 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/22 18:43:01 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Variables are named after the position they will occupy at the end
void	ft_rotate(t_stack **root)
{
	t_stack	*last;
	t_stack	*first;
	t_stack *tmp;
	
	last = *root;
	first = (*root)->next;
	tmp = *root;
	tmp = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
	*root = first;
}

//  Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_rotate(stack_a);
		ft_printf(MAGENTA"ra\n"NO_COLOR);
	}
	else
		ft_printf(RED"Could't rotate stack_a."NO_COLOR);
}

//  Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_b);
		ft_printf(MAGENTA"rb\n"NO_COLOR);
	}
	else
		ft_printf(RED"Could't rotate stack_b."NO_COLOR);
}

// ra and rb at the same time
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		ft_printf(MAGENTA"rr\n"NO_COLOR);
	}
	else
		ft_printf(RED"Could't rotate stacks."NO_COLOR);
}
