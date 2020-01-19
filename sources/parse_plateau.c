/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plateau.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:59:32 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 08:53:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool	parse_plateau_size(t_env *env)
{
	char	*line;
	char	**split;

	if (get_next_line(0, &line) != 1)
		return (false);
	if (!(split = ft_strsplit(line, ' ')))
	{
		ft_strdel(&line);
		return (false);
	}
	ft_strdel(&line);
	if (ft_len_arr(split) < 3)
	{
		ft_destroy_string_arr(split);
		return (false);
	}
	env->plateau->height = ft_atoi(split[1]);
	env->plateau->width = ft_atoi(split[2]);
	ft_destroy_string_arr(split);
	if (env->plateau->height < 0 || env->plateau->width < 0)
		return (false);
	return (true);
}

static bool	read_plateau_loop(int i, char *line, char **split, t_env *env)
{
	while (++i < env->plateau->height)
	{
		if (get_next_line(0, &line) != 1)
			return (false);
		if (!(split = ft_strsplit(line, ' ')))
		{
			ft_strdel(&line);
			return (false);
		}
		ft_strdel(&line);
		if (ft_len_arr(split) < 2)
		{
			ft_destroy_string_arr(split);
			return (false);
		}
		if (!(env->plateau->map[i] = ft_strdup(split[1])))
		{
			ft_destroy_string_arr(split);
			return (false);
		}
		ft_destroy_string_arr(split);
	}
	return (true);
}

static bool	read_plateau_map(t_env *env)
{
	char	*line;
	char	**split;

	line = NULL;
	split = NULL;
	return (read_plateau_loop(-1, line, split, env));
}

bool		parse_plateau(t_env *env)
{
	char	*line;

	if (!parse_plateau_size(env))
		return (false);
	if (get_next_line(0, &line) != 1)
		return (false);
	ft_strdel(&line);
	if (!(env->plateau->map = init_map(env->plateau->height + 1)))
		return (false);
	if (!read_plateau_map(env))
	{
		ft_destroy_string_arr(env->plateau->map);
		return (false);
	}
	return (true);
}
