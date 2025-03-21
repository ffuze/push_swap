/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:43:10 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 11:53:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MACROS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~*/
# define NO_COLOR "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define CYAN "\033[36m"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STRUCTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef	struct		s_stack
{
	int				nbr;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

t_stack	*ft_fill_stack(char **array);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
size_t	ft_stacksize(t_stack *root);
void	create_index(char **array, t_stack *root);
void	get_cost_a(t_stack **stack_a);///##############
void	get_cost_b(t_stack **stack_b);
void	get_costs(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **root);
void	three_sort(t_stack **stack_a);
int		ft_abs(int n);
int		*get_costs_array(t_stack *a, t_stack *b);
// t_stack	*get_cheapest_cost(t_stack *stack);
// void	sort_stack_b(t_stack **b);

#endif

// valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all