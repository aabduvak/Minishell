/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:32:35 by aabduvak          #+#    #+#             */
/*   Updated: 2022/02/16 01:44:42 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_create_str(char const *str, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	ptr = (char *) malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, i + 1);
	return (ptr);
}

static void	*ft_free(char **ptr, int i)
{
	while (i > 0)
		free(ptr[i--]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		leng;
	char	**ptr;

	if (!s)
		return (NULL);
	leng = ft_count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (leng + 1));
	if (!(ptr))
		return (NULL);
	i = -1;
	while (++i < leng)
	{
		while (s[0] == c)
			s++;
		ptr[i] = ft_create_str(s, c);
		if (!ptr[i])
			return (ft_free(ptr, i));
		s = s + ft_strlen(ptr[i]);
	}
	ptr[i] = 0;
	return (ptr);
}
