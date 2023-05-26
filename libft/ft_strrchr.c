/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:46:47 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:46:47 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c > 255)
		c = c - 256;
	i = ft_strlen(s);
	if (s[i] == c)
		return ((char *)(s + i));
	while (i--)
	{
		if (s[i] == c)
			return ((char *)(s + i));
	}
	return (0);
}

// int main()
// {
// 	char *s = "Hello World";
// 	char c = '\0';
// 	printf("%s", strrchr(s, c));
// 	printf("\n%s", ft_strrchr(s, c));
// }