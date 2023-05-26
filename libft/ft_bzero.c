/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:39:54 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:39:54 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)s)[i++] = '\0';
	}
}

// int main()
// {

// 	char str[50] = "Hello world";
// 	// bzero(str, 4);
// 	ft_bzero(&str, 4);
// 	printf("%s", str);
// }