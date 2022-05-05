/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:30:11 by aabduvak          #+#    #+#             */
/*   Updated: 2022/01/07 17:27:09 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

static int	ft_count_leng(int num)
{
	int	i;

	i = 0;
	while (num > 9 || num < -9)
	{
		num = num / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int value)
{
	char	*ret;
	int		leng;
	int		is_negative;

	is_negative = value < 0;
	leng = ft_count_leng(value) + is_negative;
	ret = (char *) malloc(sizeof(char) * (leng + 1));
	if (!ret)
		return (NULL);
	ret[leng--] = '\0';
	while (leng >= 0)
	{
		ret[leng] = ft_abs(value % 10) + '0';
		value /= 10;
		leng--;
	}
	if (is_negative)
		ret[0] = '-';
	return (ret);
}
