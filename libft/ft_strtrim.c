/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:46:55 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:46:55 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start_str;
	char	*end_str;

	if (!s1)
		return (0);
	start_str = (char *)s1;
	end_str = start_str + ft_strlen(s1);
	while (*start_str != 0 && ft_strchr(set, *start_str))
		start_str++;
	while ((start_str < end_str) && ft_strchr(set, *(end_str - 1)))
		end_str--;
	result = ft_substr(start_str, 0, end_str - start_str);
	return (result);
}

// int main()
// {
// 	char *s1 = "Helolo";
// 	char *set = "Hoe";
// 	printf("%s", ft_strtrim(s1, set));
// }