/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/02 02:11:22 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (FT_TRUE);
		str++;
	}
	return (FT_FALSE);
}

t_envp	*swap(t_envp *ptr1, t_envp *ptr2)
{
	t_envp	*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

static void	buble_sort_helper(int i, t_envp **h, int *swapped)
{
	int		j;
	t_envp	*p1;
	t_envp	*p2;

	j = -1;
	while (++j < i)
	{
		p1 = *h;
		p2 = p1->next;
		if (ft_strcmp(p1->key, p2->key) > 0)
		{
			*h = swap(p1, p2);
			*swapped = 1;
		}
		h = &(*h)->next;
	}
}

static void	bubble_sort(t_envp **head, int count)
{
	t_envp		**h;
	int			i;
	int			swapped;

	i = -1;
	while (++i <= count)
	{
		swapped = 0;
		h = head;
		buble_sort_helper(count - i - 1, h, &swapped);
		if (!swapped)
			break ;
	}
}

void	export(t_process *process)
{
	t_envp	*tmp;
	t_envp	*copy;
	char	**envp;

	if (process && !*(process->args + 1))
	{
		tmp = process->envp;
		envp = deconstruct(tmp);
		copy = construct(envp);
		bubble_sort(&copy, ft_envpsize(copy));
		while (copy)
		{
			printf("declare -x %s=\"%s\"\n", (char *) copy->key, copy->value);
			copy = copy->next;
		}
		free_list(envp);
		ft_envpclear(copy);
		return ;
	}
	ft_setenv(process);
}
