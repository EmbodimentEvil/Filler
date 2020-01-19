/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:02:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 05:02:20 by sleonia          ###   ########.fr       */
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
					set_rgb(224, 224, 224), sdl);
}

static void		render_borders(t_sdl *sdl)
{
	render_figure((t_rect){0, 0, 10, sdl->sur->w},
					set_rgb(65, 95, 65), sdl);
	render_figure((t_rect){0, sdl->sur->h - 10, 10, sdl->sur->w},
					set_rgb(65, 95, 65), sdl);
	render_figure((t_rect){0, 0, sdl->sur->h, 10},
					set_rgb(65, 95, 65), sdl);
	render_figure((t_rect){sdl->sur->w - 10, 0, sdl->sur->h, 10},
					set_rgb(65, 95, 65), sdl);
}

static void		render_map(t_env *env)
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
			if (env->plateau->map[y][x] == '.')
			{
				SDL_FillRect(env->sdl->sur, &rect, set_rgb(244, 231, 185));
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
	}
}

// void		draw_status(t_vs *vs)
// {
// 	SDL_Rect	rect;
// 	SDL_Color	red;
// 	SDL_Color	blue;

// 	red = init_color(200, 53, 48, 255);
// 	blue = init_color(78, 150, 207, 255);
// 	rect = (SDL_Rect){ 0, 0, WIDTH, 10 };
// 	draw_rect(vs, &rect, blue);
// 	rect.w = WIDTH * vs->p1_counter / (vs->p1_counter + vs->p2_counter);
// 	draw_rect(vs, &rect, red);
// 	rect = (SDL_Rect){ 0, HEIGHT - 10, WIDTH, 10 };
// 	if (vs->p1_counter > vs->p2_counter)
// 		draw_rect(vs, &rect, red);
// 	else if (vs->p2_counter > vs->p1_counter)
// 		draw_rect(vs, &rect, blue);
// }

static void		render_score(t_env *env)
{
	t_rect		rect;
	// int			n_digits;
	// int			sum_score;
	// float		percent;

	// sum_score = env->math->my_score + env->math->enemy_score;
	rect = (t_rect){30, 130, 10, env->sdl->sur->w};
	// rect.w = env->sdl->sur->w * 10 / (10 + 20);
	// rect.w = env->sdl->sur->w * env->math->my_score / (env->math->my_score + env->math->enemy_score);
	render_figure(rect, MY_COLOR, env->sdl);
	rect.y += 130;
	// rect.w = env->sdl->sur->w * 20 / (10 + 20);
	// rect.w = env->sdl->sur->w * env->math->my_score / (env->math->my_score + env->math->enemy_score);
	render_figure(rect, ENEMY_COLOR, env->sdl);
}

void			render(t_env *env)
{
	render_background(env->sdl);
	render_map(env);
	render_score(env);
	render_borders(env->sdl);
	if (env->game_mode == Pixel)
	{
		render_texture_man(0, 0, env);
		render_texture_robot(0, 0, env);
	}
	else
	{
		render_texture_ricardo(0, 0, env);
		render_texture_gachi(0, 0, env);
	}
}
