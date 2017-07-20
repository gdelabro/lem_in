/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 19:27:22 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/17 15:07:16 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		connected(t_lem *l, char *n1, char *n2)
{
	int i;

	i = -1;
	while (++i < l->n_t)
		if ((!ft_strcmp(l->tube[i].n1, n1) && !ft_strcmp(l->tube[i].n2, n2)) ||
			(!ft_strcmp(l->tube[i].n1, n2) && !ft_strcmp(l->tube[i].n2, n1)))
			return (1);
	return (0);
}

int		next_connected(t_lem *l)
{
	int i;
	int u;

	i = -1;
	while (l->path[++i])
		;
	--i;
	u = -1;
	while (l->salle[++u] && ft_strcmp(l->salle[u], l->path[i]))
		;
	--u;
	while (l->salle[++u] && i && (!connected(l, l->path[i - 1], l->salle[u]) ||
		in_tab(l->path, l->salle[u])))
		;
	l->path[i] = l->salle[u];
	if (!l->salle[u] && i)
		return (next_connected(l));
	else
		l->path[i] = l->salle[u];
	return (1);
}

int		first_connected(t_lem *l)
{
	int i;
	int u;

	i = -1;
	u = -1;
	while (l->path[++i])
		;
	while (l->salle[++u] && i && (!connected(l, l->path[i - 1], l->salle[u]) ||
			in_tab(l->path, l->salle[u])))
		;
	return (l->salle[u] ? u : -1);
}

void	find_next_one(t_lem *l)
{
	int i;

	i = -1;
	while (l->path[++i])
		;
	if (first_connected(l) != -1)
		l->path[i] = l->salle[first_connected(l)];
	else
		next_connected(l);
}

void	resolve(t_lem *l)
{
	int i;

	l->salle = add_str(l->salle, l->start);
	l->salle = add_str(l->salle, l->end);
	!(l->path = (char**)malloc(sizeof(*l->path)
				* (taille_tab(l->salle) + 1))) ? ft_quit(0) : 0;
	i = -1;
	while (++i < taille_tab(l->salle) + 1)
		l->path[i] = NULL;
	l->path[0] = l->start;
	while (l->path[0] == l->start)
	{
		find_next_one(l);
		if (l->path[0] == l->start && (!l->p || taille_tab(l->path)
			< taille_tab(l->p)) && l->path[taille_tab(l->path) - 1] ==
				l->salle[taille_tab(l->salle) - 1])
		{
			l->p ? free_ancien(l->p) : 0;
			!(l->p = cpy_tab(l->path)) ? ft_quit(0) : 0;
		}
	}
}
