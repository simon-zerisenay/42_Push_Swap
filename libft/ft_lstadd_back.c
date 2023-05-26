/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:12 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:42:12 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (!curr)
		*lst = new;
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = new;
	}
}
// int main()
// {
// 	// t_list *lst = malloc(sizeof(t_list));
// 	// if (lst == NULL)
// 	// 	exit(1);
// 	// lst->content = (char *)"15";
// 	// lst->next = NULL;
// 	t_list *new = malloc(sizeof(t_list));
// 	if (new == NULL)
// 		exit(2);
// 	new->content = (char *)"16";
// 	new->next = NULL;
// 	t_list *lst = NULL;
// 	ft_lstadd_back(&lst, new);
// 	t_list *curr = lst;
// 	while (curr != NULL)
// 	{
// 		printf("%s\n", (char *)curr->content);
// 		curr = curr->next;
// 	}
// }