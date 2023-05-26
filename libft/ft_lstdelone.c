/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:45 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:42:45 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		exit(1);
	del(lst->content);
	free(lst);
}

// int main()
// {
// 	t_list *lst = malloc(sizeof(t_list));
// 	lst->content = (char *)"hello";
// 	lst->next = malloc(sizeof(t_list));
// 	lst->next->content = (char *)"world";
// 	lst->next->next = NULL;
// 	ft_lstdelone(lst, *del);
// 	t_list *curr = lst;
// 	while (curr != NULL)
// 	{
// 		printf("%s", (char *)curr->content);
// 		curr = curr->next;
// 	}
// }
