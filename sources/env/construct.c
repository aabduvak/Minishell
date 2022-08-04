/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:39:15 by arelmas           #+#    #+#             */
/*   Updated: 2022/08/04 22:51:40 by aabduvak         ###   ########.fr       */
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
	int		count;
	t_envp	*tmp;

	count = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_envp	*ft_envpnew(char *str)
{
	t_envp	*first;
	char	*tmp;

	tmp = ft_strchr(str, '=');
	first = malloc(sizeof(t_envp));
	if (!first)
		return (NULL);
	first->key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(tmp));
	if (!(tmp + 1))
		first->value = ft_strdup("");
	else
		first->value = ft_substr(tmp + 1, 0, ft_strlen(tmp) - 1);
	first->fullstr = strdup(str);
	first->next = NULL;
	return (first);
}

t_envp	*construct(char	**envp)
{
	int			idx;
	static int	init = 0;
	t_envp		*envl;

	if (!envp)
		return (0);
	idx = 0;
	envl = 0;
	while (envp[idx])
		ft_envpadd_back(&envl, ft_envpnew(envp[idx++]));
	if (!init++)
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
