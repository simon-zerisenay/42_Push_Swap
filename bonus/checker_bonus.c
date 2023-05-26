/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:27:18 by szerisen          #+#    #+#             */
/*   Updated: 2023/04/01 19:54:09 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	checker(t_node **a, t_node **b)
{
	char	*instructions;
	int		i;

	instructions = ft_strdup("0");
	while (instructions)
	{
		if (instructions)
			free(instructions);
		instructions = get_next_line(0);
		if (instructions)
			i = ft_strlen(instructions) - 1;
		if (instructions)
			val_and_use_ins(a, b, instructions, i);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	do_both(t_node **a, t_node **b, char *ins, int i)
{
	if (!ft_strncmp(ins, "rr", i))
		rotate_both(a, b, 1, 1);
	else if (!ft_strncmp(ins, "rrr", i))
		reverse_rotate_both(a, b, -1, -1);
	else if (!ft_strncmp(ins, "ss", i))
		swap_both(a, b, 1, 1);
	else
		return (0);
	return (1);
}

void	val_and_use_ins(t_node **a, t_node **b, char *ins, int i)
{
	if (ins)
	{
		if (!ft_strncmp(ins, "sa", i))
			swap(*a, " ");
		else if (!ft_strncmp(ins, "sb", i))
			swap(*b, " ");
		else if (!ft_strncmp(ins, "pa", i))
			push(a, b, " ");
		else if (!ft_strncmp(ins, "pb", i))
			push(b, a, " ");
		else if (!ft_strncmp(ins, "ra", i))
			rotate(a, " ", 1);
		else if (!ft_strncmp(ins, "rb", i))
			rotate(b, " ", 1);
		else if (!ft_strncmp(ins, "rra", i))
			reverse_rotate(a, " ", -1);
		else if (!ft_strncmp(ins, "rrb", i))
			reverse_rotate(b, " ", -1);
		else if (do_both(a, b, ins, i))
			return ;
		else
			error_exit(0);
	}
}

static char	*brew_a_string(char **argv, char **storage)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
		{	
			free(*storage);
			error_exit(0);
		}
		*storage = ft_strjoin(*storage, argv[i++]);
		*storage = ft_strjoin(*storage, " ");
	}
	return (*storage);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*storage;

	if (argc > 2)
	{
		storage = NULL;
		storage = brew_a_string(argv, &storage);
		if (!is_valid_input(&storage) || !have_duplicates(&storage))
			error_exit(0);
		a = NULL;
		b = NULL;
		create_stack(&storage, &a);
		checker(&a, &b);
		free_linked_list(&a);
	}	
	return (0);
}
