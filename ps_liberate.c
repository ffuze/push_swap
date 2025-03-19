/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_liberate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:55:51 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/19 16:17:39 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **root)
{
	t_stack	*tmp;
	if (!root || !(*root))
		return ;
	while (*root)
	{
		tmp = (*root)->next;
		printf(RED"%d\n"NO_COLOR, (*root)->nbr);//##################
		free(*root);
		*root = tmp;
	}
	tmp = NULL;
}
