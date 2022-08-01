/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:39:15 by arelmas           #+#    #+#             */
/*   Updated: 2022/07/31 17:31:41 by arelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_envpadd_back(t_envp **lst, t_envp *new)
{
	t_envp	*item;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	item = *lst;
	while (item->next != NULL)
		item = item->next;
	item->next = new;

}

int	ft_envpsize(t_envp *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_envp	*ft_envpnew(char *str)
{
	t_envp	*first;
	char	**parse;

	parse = ft_split(str, '=');
	if (!parse)
		return (NULL);
	first = malloc(sizeof(t_envp));
	if (!first)
		return (NULL);
	first->key = parse[0];
	if (!parse[1])
		first->value = ft_strdup("");
	else
		first->value = parse[1];
	first->fullstr = strdup(str);
	first->next = NULL;
	free(parse);
	return (first);
}

t_envp	*construct(char	**envp)
{
	int		idx;
	t_envp	*envl;

	if (!envp)
		return (0);
	idx = 0;
	envl = 0;
	while (envp[idx])
		ft_envpadd_back(&envl, ft_envpnew(envp[idx++]));
	ft_envpadd_back(&envl, ft_envpnew("?=0"));
	return (envl);
}

void	ft_envpdelone(t_envp *lst, void (*del) (void *))
{
	if (!lst)
		return ;
	del(lst->key);
	del(lst->value);
	del(lst->fullstr);
	free(lst);
}
