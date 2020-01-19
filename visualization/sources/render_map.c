/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 08:14:13 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 08:38:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void		fill_sur(int x, int y, SDL_Rect rect, t_env *env)
{
	if (env->plateau->map[y][x] == '.')
	{
		SDL_FillRect(env->sdl->sur, &rect, set_rgb(41, 41, 61));
	}
	else if (ft_toupper(env->plateau->map[y][x]) == 'O')
	{
		SDL_FillRect(env->sdl->sur, &rect, ENEMY_COLOR);
		env->math->enemy_score++;
	}
	else if (ft_toupper(env->plateau->map[y][x]) == 'X')
	{
		SDL_FillRect(env->sdl->sur, &rect, MY_COLOR);
		env->math->my_score++;
	}
	else
		ft_exit(ERROR_INPUT);
}

void			render_map(t_env *env)
{
	SDL_Rect	rect;
	int			x;
	int			y;

	y = -1;
	calc_size(env);
	rect.w = env->math->cell_size;
	rect.h = env->math->cell_size;
	while (++y < env->plateau->height)
	{
		x = -1;
		while (++x < env->plateau->width)
		{
			rect.x = env->math->start_x + x * env->math->cell_shift;
			rect.y = env->math->start_y + y * env->math->cell_shift;
			fill_sur(x, y, rect, env);
		}
	}
}
