/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:45:58 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:45:58 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dest_len;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + src_len);
	while (src[index] != '\0' && ((dest_len + 1) < size))
	{
		dst[dest_len] = src[index];
		index++;
		dest_len++;
	}
	dst[dest_len] = '\0';
	return (dest_len + ft_strlen(&src[index]));
}
// int main()
// {
// 	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
// 	// char dst[50] = "there is no stars in the sky";
// 	char dest2[50] = "there is no stars in the sky";

// 	size_t size = ft_strlen(src) + 4;
// 	printf("%zu", ft_strlcat(NULL, src, 0));
// 	printf("\n%zu", strlcat(NULL, src, 0));
// 	printf("\n%zu", size);
// 		printf("\n%zu", ft_strlen(dest2));
// }