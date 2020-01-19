/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:53:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 04:28:00 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_STRUCTS_H
# define VS_STRUCTS_H

# include "vs_filler.h"

typedef enum			e_game_mode
{
	Pixel,
	Gachi
}						t_game_mode;

typedef struct			s_rect
{
	int					x;
	int					y;
	int					h;
	int					w;
}						t_rect;

typedef struct			s_math
{
	float				cell_shift;
	float				cell_size;
	int					start_x;
	int					start_y;
	float				my_score;
	float				enemy_score;
}						t_math;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Surface			*sur;
	SDL_Event			event;
	SDL_Surface			*player1;
	SDL_Surface			*player2;
	Mix_Music			*music[2];
}						t_sdl;

typedef struct			s_plateau
{
	int					height;
	int					width;
	char				**map;
	struct s_plateau	*next;
	struct s_plateau	*prev;
}						t_plateau;

typedef struct			s_env
{
	t_sdl				*sdl;
	t_plateau			*plateau;
	t_math				*math;
	bool				is_pause;
	int					game_mode;
}						t_env;

#endif
