/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:47:29 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:56:53 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *main_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_main_str(char *main_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free (main_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (main_str[i])
		str[j++] = main_str[i++];
	str[j] = '\0';
	free(main_str);
	return (str);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (i);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (c >= 256)
// 		c = c % 256;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)(s + i));
// 	return ((0));
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char		*new_str;
// 	size_t		i;
// 	size_t		j;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(sizeof(char) * 1);
// 		s1[0] = '\0';
// 	}
// 	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!new_str)
// 		return (0);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		new_str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 		new_str[i++] = s2[j++];
// 	new_str[i] = '\0';
// 	free(s1);
// 	return (new_str);
// }
