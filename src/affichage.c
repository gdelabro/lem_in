/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:47:30 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/17 15:06:59 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	aff_chemin(t_lem *l)
{
	int		i;

	i = -1;
	ft_printf("chemin: %s - ", l->salle[taille_tab(l->salle) - 2]);
	while (l->p[++i + 1])
	{
		ft_printf("%s%s", l->p[i + 1], l->p[i + 2] ? " - " : "\n");
	}
}

int		all_zero(t_lem *l)
{
	int i;

	i = -1;
	while (l->p[++i + 1])
		if (l->fou[i] && i != taille_tab(l->p) - 1)
			return (1);
	return (0);
}

void	aff_tour(t_lem *l)
{
	int i;

	i = taille_tab(l->p) - 1;
	ft_printf("{none}");
	while (--i != -1)
		if (l->fou[i])
		{
			l->fou[i + 1] = l->fou[i];
			ft_printf("\033[3%dmL%d-%s ",
					l->fou[i] % 6 + 1, l->fou[i], l->p[i + 1]);
			--l->fou[i];
		}
}

void	affichage(t_lem *l, char **file)
{
	int i;

	i = -1;
	!l->p ? ft_quit(0) : 0;
	aff_tab(file);
	!(l->fou = (int*)malloc(sizeof(int) * taille_tab(l->p))) ? ft_quit(0) : 0;
	while (++i < taille_tab(l->p) + 1)
		l->fou[i] = 0;
	l->fou[0] = l->nb;
	ft_printf("{bold}\n");
	while (all_zero(l))
	{
		aff_tour(l);
		ft_putendl("");
	}
	l->nb ? ft_printf("{none}{bold}nombre de coup: %d\n",
			l->nb + taille_tab(l->p) - 2) : 0;
	aff_chemin(l);
}
