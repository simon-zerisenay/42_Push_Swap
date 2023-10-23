/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:27:42 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/30 16:29:40 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	have_duplicates2(t_node **a, long num)
{
	t_node	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->data == (int)num)
			return (1);
		temp = temp->next;
	} 
	return (0);
}

void	create_stack(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN || have_duplicates2(a, num))
			error_exit(0);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		if (!*a)
			(*a) = nod;
		else
			lstlast(*a)->next = nod;
		i++;
	}
	free_array(&str);
}
