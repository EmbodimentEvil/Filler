/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 04:44:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_FUNCTIONS_H
# define VS_FUNCTIONS_H

# include "vs_filler.h"

/*
**	calc_size.c
*/
void			calc_size(t_env *env);

/*
**	change_music.c
*/
void			change_music(int game_mode, Mix_Music **music);

/*
**	events.c
*/
void			key_events(t_env *env, SDL_Event event);
void			mouse_events(t_env *env, SDL_Event event);

/*
**	init.c
*/
char			**init_map(const int height);
t_plateau		*init_plateau(void);
t_env			*init_env(void);

/*
**	init_sdl.c
*/
void			init_sdl(int game_mode, t_sdl *sdl);

/*
**	main_loop.c
*/
void			main_loop(t_env *env);

/*
**	parse.c
*/
void			parse(t_env *env);

/*
**	render.c
*/
void			render(t_env *env);

/*
**	scaled_texture.c
*/
void		render_texture_man(int x, int y, t_env *env);
void		render_texture_robot(int x, int y, t_env *env);
void		render_texture_ricardo(int x, int y, t_env *env);
void		render_texture_gachi(int x, int y, t_env *env);

/*
**	utils.c
*/
int			set_rgb(int red, int green, int blue);
SDL_Rect	set_rect_size(int x, int y, int h, int w);

#endif
