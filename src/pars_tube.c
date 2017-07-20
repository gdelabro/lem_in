/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 18:50:55 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/17 15:13:26 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		is_number(char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 &&
			ft_strcmp("2147483647", str) < 0))
		return (0);
	return (1);
}

int		tube_test(t_lem *l, char *file)
{
	char	**tube;
	int		ret;

	ret = 1;
	tube = NULL;
	tube = ft_strsplit(file, '-');
	if (!tube || taille_tab(tube) != 2)
		ret = 0;
	else if (!ft_strcmp(tube[0], tube[1]))
		ret = 0;
	else if (!in_tab(l->salle, tube[0]) &&
			ft_strcmp(tube[0], l->start) && ft_strcmp(tube[0], l->end))
		ret = 0;
	else if (!in_tab(l->salle, tube[1]) &&
			ft_strcmp(tube[1], l->start) && ft_strcmp(tube[1], l->end))
		ret = 0;
	free_ancien(tube);
	return (ret);
}

void	add_tube(t_lem *l, char **file, int i)
{
	int		c;
	char	**tab;
	int		a;

	c = -1;
	a = 0;
	while (file && file[++i] && a < l->n_t)
		if (file[i][0] != '#')
		{
			tab = ft_strsplit(file[i], '-');
			l->tube[++c].n1 = tab[0];
			l->tube[c].n2 = tab[1];
			free(tab);
			a++;
		}
}

void	pars_tube(t_lem *l, char **file, int i, int e)
{
	int		c;
	int		u;

	c = 0;
	u = --i;
	if (!l->start || !l->end || l->nb == -1 || e)
		ft_quit(0);
	while (file && file[++i])
	{
		if (file[i][0] == '#')
			;
		else if (ft_nbmot(file[i], ' ') != 1 || ft_nbmot(file[i], '-') != 2
			|| file[i][0] == '-' || file[i][ft_strlen(file[i] - 1)] == '-'
			|| !tube_test(l, file[i]))
			break ;
		else
			++c;
	}
	l->n_t = c;
	!c ? ft_quit(0) : 0;
	!(l->tube = (t_tu*)malloc(sizeof(*l->tube) * c + 1)) ? ft_quit(0) : 0;
	add_tube(l, file, u);
}
