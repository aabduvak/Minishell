/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 01:07:16 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/02 01:07:16 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isexist(const char *src, char c)
{
	while (*src)
	{
		if (*src == c)
			return (1);
		src++;
	}
	return (0);
}

static int	ft_get_first_index(const char *src, const char *set)
{
	size_t	i;

	i = 0;
	while (src[i] && ft_isexist(set, src[i]))
		i++;
	return (i);
}

static int	ft_get_last_index(const char *src, const char *set)
{
	int	i;

	i = (int) ft_strlen(src) - 1;
	while (src[i] && ft_isexist(set, src[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		first;
	int		last;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	first = ft_get_first_index(s1, set);
	last = ft_get_last_index(s1, set);
	if (first > last)
		return (ft_strdup(""));
	str = (char *) malloc(sizeof(char) * (last - first + 2));
	if (!str)
		return (NULL);
	while (first <= last)
		str[i++] = s1[first++];
	str[i] = '\0';
	return (str);
}
