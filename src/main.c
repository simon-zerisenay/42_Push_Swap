/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:50 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/29 16:34:02 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_position(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest(b);
		reorder_a_and_b(cheapest_pos, a, b);
		push(a, b, "pa");
	}
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_linked_list(a);
		exit(0);
	}
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
	{
		midpoint_sorting(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	sort_stack_a(a, 0);
	free_linked_list(&b);
	return ;
}

static char	*brew_a_string(char **argv, char **container)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
		{	
			free(*container);
			error_exit(0);
		}
		*container = ft_strjoin(*container, argv[i++]);
		*container = ft_strjoin(*container, " ");
	}
	return (*container);
}

int	main(int ac, char **av)
{
	t_node	*a;
	char	*container;

	if (ac >= 2)
	{
		container = NULL;
		container = brew_a_string(av, &container);
		if (!is_valid_input(&container) || !have_duplicates(&container))
			error_exit(0);
		a = NULL;
		create_stack(&container, &a);
		add_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}	
	return (0);
}
