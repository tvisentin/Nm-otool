/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 10:19:40 by tvisenti          #+#    #+#             */
/*   Updated: 2017/10/31 16:44:16 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_offlist			*order_off(t_offlist *lst)
{
	t_offlist	*cur;
	uint32_t	tmp;
	int			stop;

	cur = lst;
	stop = 1;
	while (stop)
	{
		stop = 0;
		cur = lst;
		while (cur->next)
		{
			if (cur->off > cur->next->off)
			{
				stop = 1;
				tmp = cur->off;
				cur->off = cur->next->off;
				cur->next->off = tmp;
			}
			cur = cur->next;
		}
	}
	return (lst);
}

struct nlist		*fill_array(struct nlist *tab, uint32_t nsyms)
{
	uint32_t		i;
	struct nlist	*tab2;

	tab2 = (struct nlist*)malloc(sizeof(struct nlist) * nsyms);
	i = 0;
	while (i < nsyms)
	{
		tab2[i] = tab[i];
		i++;
	}
	return (tab2);
}

struct nlist		*bubble_sort(char *stringtable, struct nlist *tab,
	uint32_t nsyms)
{
	uint32_t		i;
	uint32_t		j;
	struct nlist	*new_tab;
	struct nlist	temp;

	i = 0;
	new_tab = fill_array(tab, nsyms);
	while (i < nsyms)
	{
		j = 0;
		while (j < nsyms)
		{
			if (ft_strcmp(stringtable + new_tab[i].n_un.n_strx,
				stringtable + new_tab[j].n_un.n_strx) < 0)
			{
				temp = new_tab[i];
				new_tab[i] = new_tab[j];
				new_tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_tab);
}

struct nlist_64		*fill_array_64(struct nlist_64 *tab, uint32_t nsyms)
{
	uint32_t		i;
	struct nlist_64	*tab2;

	tab2 = (struct nlist_64*)malloc(sizeof(struct nlist_64) * nsyms);
	i = 0;
	while (i < nsyms)
	{
		tab2[i] = tab[i];
		i++;
	}
	return (tab2);
}

struct nlist_64		*bubble_sort_64(char *stringtable, struct nlist_64 *tab,
	uint32_t nsyms)
{
	uint32_t		i;
	uint32_t		j;
	struct nlist_64	*new_tab;
	struct nlist_64	temp;

	i = 0;
	new_tab = fill_array_64(tab, nsyms);
	while (i < nsyms)
	{
		j = 0;
		while (j < nsyms)
		{
			if (ft_strcmp(stringtable + new_tab[i].n_un.n_strx,
				stringtable + new_tab[j].n_un.n_strx) < 0)
			{
				temp = new_tab[i];
				new_tab[i] = new_tab[j];
				new_tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_tab);
}
