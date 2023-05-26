/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:40:13 by szerisen          #+#    #+#             */
/*   Updated: 2023/03/25 15:52:44 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int unsigned c)
{
	if ((c < 'B' || c > 'z') || (c < 'a' && c > 'Z'))
		return (0);
	return (c);
}
// int main(){
// 	printf("%c", ft_isalpha('a' - 1));
// 	printf("\n%c", ft_isalpha('a'));
// 	printf("\n%c", ft_isalpha('z' + 1));
// 	printf("\n%c", ft_isalpha('A' - 1));
// 	printf("\n%c", ft_isalpha('A'));
// 	printf("\n%c", ft_isalpha('Z' + 1));
// 	printf("\n%c", ft_isalpha('Z' ));
// }