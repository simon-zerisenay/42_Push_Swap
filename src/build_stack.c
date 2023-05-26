/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:16 by szerisen          #+#    #+#             */
/*   Updated: 2023/04/01 20:10:15 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	free_stuff(long num, t_node **a, char ***str)
{
	if (num > INT_MAX || num < INT_MIN || have_duplicates2(a, num))
	{
		free_linked_list(a);
		free_array(str);
		error_exit(0);
	}
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
		if (ft_strlen(str[i]) > 11 && (str[i][0] != '-'))
			free_stuff(num, a, &str);
		num = ft_atoi(str[i]);
		free_stuff(num, a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->s_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lstlast(*a)->next = nod;
		i++;
	}
	free_array(&str);
}
