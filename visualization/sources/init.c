/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:46:47 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 07:06:24 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

char			**init_map(const int height)
{
	char		**map;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * height)))
		return (NULL);
	return (map);
}

t_plateau		*init_plateau(void)
{
	t_plateau	*plateau;

	plateau = (t_plateau *)ft_safe_malloc(sizeof(t_plateau));
	plateau->height = 0;
	plateau->width = 0;
	plateau->map = NULL;
	plateau->next = NULL;
	plateau->prev = NULL;
	return (plateau);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env *)ft_safe_malloc(sizeof(t_env));
	env->sdl = (t_sdl *)ft_safe_malloc(sizeof(t_sdl));
	env->math = (t_math *)ft_safe_malloc(sizeof(t_math));
	env->plateau = NULL;
	env->is_close = false;
	env->is_pause = true;
	return (env);
}
