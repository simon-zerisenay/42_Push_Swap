/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:46:05 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:46:05 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	if (size == 0)
		return (j);
	i = 0;
	while (src[i] != '\0' && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

// int main()
// {
// 	char *src = "";
// 	char dst[20];
// 	printf("%zu", strlcpy(dst, src, 5));
// 	printf("\n%s", dst);
// 	printf("%zu", ft_strlcpy(dst, src, 5));
// 	printf("\n%s", dst);
// }