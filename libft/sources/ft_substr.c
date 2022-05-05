/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:22:06 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/02 00:22:06 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t leng)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (start + ft_strlen(str) < leng)
		leng = start + ft_strlen(str);
	res = (char *) malloc(sizeof(char) * (leng + 1));
	if (!res)
		return (NULL);
	while (i < leng && str[start] && start < ft_strlen(str))
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
