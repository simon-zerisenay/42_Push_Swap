/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:44:21 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:44:21 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	else
		while (len--)
			*(char *)dst++ = *(char *)src++;
	return (ret);
}

// int main()
// {
// 	char str1[50] = "ABCDEF";
// 	char str2[50] = "ABCDEF";
// 	char str3[50] = "ABCDEF";
// 	char str4[50] = "ABCDEF";
// 	memcpy(str1, str4, 4);
// 	printf("%s", str1);
// 	memmove(str2, str4, 4);
// 	printf("\n%s", str2);
// 	ft_memmove(str3, str4, 4);
// 	printf("\n%s", str3);
// }