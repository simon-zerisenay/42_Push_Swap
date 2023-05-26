/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:47:05 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:47:05 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (!s)
		return (0);
	i = start;
	while (s[i] != '\0' && (i - start) < len)
		i++;
	substring = (char *)malloc((i + 1 - start) * sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (s[start] != '\0' && start < ft_strlen(s) && i < len)
	{
		substring[i++] = s[start++];
	}
	substring[i] = '\0';
	return (substring);
}

// int main()
// {
// 	char	*str = "01234";
// 	size_t	size = 10;

// 	char	*ret = ft_substr(str, 10, size);
// 	printf("%s", ret);
// }