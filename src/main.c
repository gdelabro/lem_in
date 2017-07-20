/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 12:58:00 by gdelabro          #+#    #+#             */
/*   Updated: 2017/07/18 13:53:35 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_quit(int err)
{
	(void)err;
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	check_newline(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			str[i + 1] = 0;
	}
}

char	**take_input(void)
{
	char	*file;
	char	line[47];
	char	*tmp;
	int		ret;

	file = NULL;
	tmp = NULL;
	while ((ret = read(0, line, 46)) > 0)
	{
		line[ret] = 0;
		tmp = file;
		file = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
	}
	file ? check_newline(file) : ft_quit(0);
	tmp = (char*)ft_strsplit(file, '\n');
	(ft_strlen(file) > 0 && file[0] == '\n') || !tmp ? ft_quit(0) : 0;
	ft_strdel(&file);
	return ((char**)tmp);
}

int		main(void)
{
	t_lem	*l;
	char	**i;

	i = NULL;
	!(l = (t_lem*)malloc(sizeof(t_lem))) ? ft_quit(0) : 0;
	!(i = take_input()) ? ft_quit(0) : 0;
	recup_info(l, i);
	resolve(l);
	affichage(l, i);
	return (0);
}
