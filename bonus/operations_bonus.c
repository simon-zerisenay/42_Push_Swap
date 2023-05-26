/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:28:00 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 14:31:56 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_node *stack, char *str)
{
	int	temp;

	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (ft_strncmp(str, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(str, "sb", 2) == 0)
		write(1, "sb\n", 3);
}

void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*temp;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp->next = *stack_1;
	*stack_1 = temp;
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}

void	rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		temp->next = NULL;
		lstlast((*stack))->next = temp;
		if (ft_strncmp(str, "ra", 2) == 0)
			write(1, "ra\n", 3);
		else if (ft_strncmp(str, "rb", 2) == 0)
			write(1, "rb\n", 3);
		cost--;
	}
}

void	reverse_rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;
	t_node	*looping;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (cost < 0)
	{
		temp = lstlast(*stack);
		looping = *stack;
		while (looping->next != NULL && looping->next->data != temp->data)
			looping = looping->next;
		looping->next = NULL;
		temp->next = *stack;
		*stack = temp;
		if (ft_strncmp(str, "rra", 3) == 0)
			write(1, "rra\n", 4);
		else if (ft_strncmp(str, "rrb", 3) == 0)
			write(1, "rrb\n", 4);
		cost++;
	}
}
