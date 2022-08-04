/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:44:38 by aabduvak          #+#    #+#             */
/*   Updated: 2022/08/04 23:21:08 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_envp	*swap(t_envp *ptr1, t_envp *ptr2)
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

static void	print_export(t_process *process)
{
	t_envp	*tmp;
	t_envp	*copy;
	char	**envp;

	tmp = process->envp;
	envp = deconstruct(tmp);
	copy = construct(envp);
	bubble_sort(&copy, ft_envpsize(copy));
	while (copy)
	{
		if (contains_char(copy->fullstr, '=') && copy->key[0] != '?')
			printf("declare -x %s=\"%s\"\n", (char *) copy->key, copy->value);
		else if (copy->key[0] != '?')
			printf("declare -x %s\n", (char *) copy->key);
		copy = copy->next;
	}
	free_list(envp);
	ft_envpclear(copy);
}

void	export(t_process *process)
{
	if (process && !*(process->args + 1))
	{
		print_export(process);
		return ;
	}
	process->args = process->args + 1;
	while (*process->args)
	{
		ft_setenv(process);
		process->args = process->args + 1;
	}
}
