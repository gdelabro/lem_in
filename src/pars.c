/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:33:15 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/17 15:07:08 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		remp_startend(char **file, int i, t_lem *l)
{
	char	**salle;
	int		c;
	char	e;

	c = -1;
	e = 0;
	file[i][2] == 's' ? e = 1 : 0;
	while (file[++i] && (file[i][0] == '#' || file[i][0] == 'L'))
		;
	salle = ft_strsplit(file[i], ' ');
	if (!is_salle(file, i))
		ft_quit(0);
	if (l->salle && (in_tab(l->salle, salle[0]) || in_tab(l->salle, salle[0])))
		ft_quit(0);
	e && !l->start ? l->start = ft_strdup(salle[0]) : 0;
	!e && !l->end ? l->end = ft_strdup(salle[0]) : 0;
	free_ancien(salle);
	return (i);
}

void	init_l(t_lem *l, char **file)
{
	int		i;

	i = -1;
	l->nb = -1;
	l->start = NULL;
	l->end = NULL;
	l->salle = NULL;
	l->tube = NULL;
	l->path = NULL;
	l->p = NULL;
	while (file && file[++i])
		if (!ft_nbmot(file[i], ' '))
			ft_quit(0);
	i = -1;
	while (file && file[++i][0] == '#')
		!ft_strcmp("##start", file[i]) ||
			!ft_strcmp("##end", file[i]) ? ft_quit(0) : 0;
	if (!is_number(file[i]))
		ft_quit(0);
	l->nb = atoi(file[i]);
}

int		is_salle(char **file, int i)
{
	char	**salle;
	int		c;
	int		ret;

	ret = 1;
	c = -1;
	salle = ft_strsplit(file[i], ' ');
	if (taille_tab(salle) != 3)
		ret = 0;
	while (ret && salle[0][++c])
		salle[0][c] == '-' || !is_number(salle[1])
			|| !is_number(salle[2]) ? ft_quit(0) : 0;
	free_ancien(salle);
	return (ret);
}

void	add_salle(t_lem *l, char *file)
{
	char	**salle;

	salle = ft_strsplit(file, ' ');
	if (l->salle && (in_tab(l->salle, salle[0]) ||
			(l->start && !ft_strcmp(salle[0], l->start)) ||
			(l->end && !ft_strcmp(l->end, salle[0]))))
		ft_quit(0);
	l->salle = add_str(l->salle, salle[0]);
	free_ancien(salle);
}

void	recup_info(t_lem *l, char **file)
{
	int		i;
	int		e;

	init_l(l, file);
	if (!taille_tab(file))
		exit(0);
	i = -1;
	while (file && file[++i][0] == '#')
		!ft_strcmp("##start", file[i]) ||
			!ft_strcmp("##end", file[i]) ? ft_quit(0) : 0;
	l->nb = atoi(file[i]);
	while ((e = 1) && file[++i])
	{
		e = 0;
		if (is_salle(file, i))
			add_salle(l, file[i]);
		else if (!ft_strcmp(file[i], "##start") || !ft_strcmp(file[i], "##end"))
			i = remp_startend(file, i, l);
		else if (file[i][0] != '#')
			break ;
	}
	pars_tube(l, file, i, e);
}
