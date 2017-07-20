/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:58:49 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/09 15:37:54 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf/ft_printf.h"

typedef struct		s_tu
{
	char			*n1;
	char			*n2;
}					t_tu;

typedef struct		s_lem
{
	char			*start;
	char			*end;
	char			**salle;
	t_tu			*tube;
	char			**path;
	char			**p;
	int				*fou;
	int				n_t;
	int				nb;
}					t_lem;

void				recup_info(t_lem *l, char **i);
void				resolve(t_lem *l);
void				pars_tube(t_lem *l, char **file, int i, int e);
int					is_number(char *str);
void				aff_struct(t_lem *l);
void				affichage(t_lem *l, char **file);
void				ft_quit(int err);
int					is_salle(char **file, int i);

#endif
