/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:24:28 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/10 16:25:14 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	aff_struct(t_lem *l)
{
	int i;

	i = -1;
	ft_printf("---nb de fourmis: %d\n", l->nb);
	ft_printf("---start: %s\n", l->start);
	ft_printf("---end: %s\n", l->end);
	ft_printf("---rooms---\n");
	aff_tab(l->salle);
	ft_printf("---tubes---\n");
	while (++i < l->n_t)
		ft_printf("%s  -  %s\n", l->tube[i].n1, l->tube[i].n2);
}
