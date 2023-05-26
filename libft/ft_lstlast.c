/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:43:06 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:43:06 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list *lst = malloc(sizeof(t_list));
// 	char *s = "3";
// 	char *s2 = "4";
// 	char *s3 = "5";

// 	lst->content = s;
// 	lst->next = malloc(sizeof(t_list));
// 	lst->next->content = s2;
// 	lst->next->next = malloc(sizeof(t_list));
// 	lst->next->next->content = s3;
// 	lst->next->next->next = NULL;
// 	printf("%s", (char *)ft_lstlast(lst)->content);
// }