/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:02:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 08:39:36 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void		render_figure(t_rect tmp, int color, t_sdl *sdl)
{
	SDL_Rect	rect;

	rect.x = tmp.x;
	rect.y = tmp.y;
	rect.h = tmp.h;
	rect.w = tmp.w;
	SDL_FillRect(sdl->sur, &rect, color);
}

static void		render_background(t_sdl *sdl)
{
	render_figure((t_rect){0, 0, sdl->sur->h, sdl->sur->w},
					set_rgb(82, 82, 122), sdl);
}

static void		render_borders(t_sdl *sdl)
{
	render_figure((t_rect){0, 0, 10, sdl->sur->w},
					set_rgb(31, 31, 46), sdl);
	render_figure((t_rect){0, sdl->sur->h - 10, 10, sdl->sur->w},
					set_rgb(31, 31, 46), sdl);
	render_figure((t_rect){0, 0, sdl->sur->h, 10},
					set_rgb(31, 31, 46), sdl);
	render_figure((t_rect){sdl->sur->w - 10, 0, sdl->sur->h, 10},
					set_rgb(31, 31, 46), sdl);
}

static void		render_score(t_env *env)
{
	t_rect		rect;

	rect = (t_rect){30, 130, 25, env->sdl->sur->w};
	rect.w = env->sdl->sur->w * env->math->my_score
				/ (env->math->my_score + env->math->enemy_score);
	if (env->game_mode == Pixel)
		render_texture_man(rect.w - 50, 30, env);
	else
		render_texture_ricardo(rect.w - 290, -155, env);
	render_figure(rect, MY_COLOR, env->sdl);
	rect.y += 130;
	rect.w = env->sdl->sur->w * env->math->enemy_score
				/ (env->math->my_score + env->math->enemy_score);
	if (env->game_mode == Pixel)
		render_texture_robot(rect.w - 80, 160, env);
	else
		render_texture_gachi(rect.w - 77, -23, env);
	render_figure(rect, ENEMY_COLOR, env->sdl);
}

void			render(t_env *env)
{
	render_background(env->sdl);
	render_map(env);
	render_score(env);
	render_borders(env->sdl);
}
