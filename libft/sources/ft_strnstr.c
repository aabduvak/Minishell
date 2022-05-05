/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:53:19 by aabduvak          #+#    #+#             */
/*   Updated: 2021/12/30 01:53:19 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	
	haystack -> samanlık
	needle -> iğne 
	
	samanlıkta iğne aramak :)
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	jndex;

	jndex = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && jndex < len)
	{
		index = 0;
		while (needle[index] && haystack[index] == needle[index]
			&& ((jndex + index) < len))
			index++;
		if (!needle[index])
			return ((char *)haystack);
		jndex++;
		haystack++;
	}
	return (0);
}
