/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:35 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/30 20:39:00 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[0] == '0' && str[1] != '\0')
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str[1] == '0' && str[2] != '\0')
		return (0);
	return (1);
}

int	search_dups(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (ft_printf(RED"Error\n"NO_COLOR), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(char **args)
{
	int		i;
	long	num;

	if (!args || !args[0])
		return (ft_printf(RED"Error\n"NO_COLOR), 0);
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

char	**exclude_executable(int ac, char **av)
{
	char	**array;
	int		i;
	int		j;

	i = 1;
	j = 0;
	array = ft_calloc(ac, sizeof(char *));
	if (!array)
		return (NULL);
	while (av[i])
	{
		array[j] = ft_strdup(av[i]);
		if (!array[j])
			return (NULL);
		i++;
		j++;
	}
	return (array);
}

char	**get_arguments(int ac, char **av)
{
	char	**args;

	args = NULL;
	if (ac == 2)
	{
		if (av[1][0] == '\0' || !ft_parsing(&av[1]))
			return (ft_printf(RED"Error\n"NO_COLOR), NULL);
		else if (is_valid_number(av[1]) == 1)
			return (NULL);
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			return (ft_printf(RED"Error\n"NO_COLOR), free_array(args), NULL);
	}
	else if (ac > 2)
		args = exclude_executable(ac, av);
	if (ft_parsing(args) && search_dups(args))
		return (args);
	else
		return (ft_printf(RED"Error\n"NO_COLOR), free_array(args), NULL);
}
