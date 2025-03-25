/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:43:10 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/24 15:36:49 by lemarino         ###   ########.fr       */
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

// ps_listutils.c
t_stack				*ft_fill_stack(char **array);
int					ft_stacksize(t_stack *root);
int					ft_abs(int n);
void				lowest_to_top(t_stack **stack);

// ps_swap.c
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

// ps_rotate.c
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

// ps_revrotate.c
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// ps_push.c
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);

// ps_indexing.c
void				create_index(char **array, t_stack *root);

// ps_selection.c
// void				fill_stack_b(t_stack **stack_a, t_stack **stack_b);
void				push_to_three(t_stack **stack_a, t_stack **stack_b/* , int len_stack_a */);
// void				push_lowest(t_stack **stack_a, t_stack **stack_b, int len_stack_a);

// ps_three_sort.c
void				three_sort(t_stack **stack_a);

// ps_economy.c
void				get_cost_a(t_stack **stack_a);
void				get_cost_b(t_stack **stack_b);
void				get_costs(t_stack **stack_a, t_stack **stack_b);

// ps_economy2.c
int					*get_costs_array(t_stack *a, t_stack *b);
t_stack				*ft_lowest_cost(t_stack *b, int *costs_arr);

// ps_executemoves.c
void				match_nodes(t_stack **a, t_stack **b, int *costs_arr);

// ps_liberate
void				free_stack(t_stack **root);

#endif

// valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all