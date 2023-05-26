/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_sorting_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:56 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/27 15:19:02 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sort_int_array(int **tab, int size)
{
	int	i;
	int	temp;
	int	*new;

	new = *tab;
	i = 0;
	while (i < (size - 1))
	{
		if (new[i] > new[i + 1])
		{
			temp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	*tab = new;
}

void	assign_index(int len, t_node **stack, int *sorted_list)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == sorted_list[i])
			{
				temp->s_index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	add_sorting_index(t_node **stack)
{
	int		len;
	t_node	*temp;
	int		i;
	int		*sorted_list;

	temp = *stack;
	len = find_len(*stack);
	sorted_list = malloc(sizeof(int) * len);
	if (!sorted_list)
		return ;
	i = 0;
	while (temp)
	{
		sorted_list[i++] = temp->data;
		temp = temp->next;
	}
	sort_int_array(&sorted_list, len);
	temp = *stack;
	assign_index(len, &temp, sorted_list);
	*stack = temp;
	free(sorted_list);
}
