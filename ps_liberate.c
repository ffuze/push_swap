/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_liberate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:55:51 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/12 22:55:51 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **root)
{
	t_stack	*tmp;

	while (*root)
	{
		tmp = (*root)->next;
		free(*root);
		*root = tmp;
	}
}
