/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:01:36 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 05:17:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void		init_sdl_music(Mix_Music **music)
{
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
		ft_exit((char *)SDL_GetError());
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	// Mix_VolumeMusic(128);
	Mix_VolumeMusic(0);
	if (!(music[0] = Mix_LoadMUS("assets/music/pixel_song.mp3")))
		ft_exit((char *)SDL_GetError());
	if (!(music[1] = Mix_LoadMUS("assets/music/ricardo.mp3")))
		ft_exit((char *)SDL_GetError());
}

static void		load_textures(int game_mode, t_sdl *sdl)
{
	if (game_mode == Pixel)
	{
		if (!(sdl->player1 = IMG_Load("assets/images/man.png")))
			ft_exit((char *)SDL_GetError());
		if (!(sdl->player2 = IMG_Load("assets/images/robot.png")))
			ft_exit((char *)SDL_GetError());
	}
	else if (game_mode == Gachi)
	{
		if (!(sdl->player1 = IMG_Load("assets/images/gachi_boy.png")))
			ft_exit((char *)SDL_GetError());
		if (!(sdl->player2 = IMG_Load("assets/images/ricardo.png")))
			ft_exit((char *)SDL_GetError());
	}
}

void			init_sdl(int game_mode, t_sdl *sdl)
{
	SDL_Surface		*sur_icon;
	SDL_Surface		*conv_sur_icon;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit((char *)SDL_GetError());
	if (!(sdl->win = SDL_CreateWindow("FILLER",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									WIDTH, HEIGHT,
									SDL_WINDOW_FULLSCREEN_DESKTOP)))
		ft_exit((char *)SDL_GetError());
	if (!(sdl->sur = SDL_GetWindowSurface(sdl->win)))
		ft_exit((char *)SDL_GetError());
	load_textures(game_mode, sdl);
	init_sdl_music(sdl->music);
	if (!(sur_icon = IMG_Load("./assets/images/icon.png")))
			ft_exit((char *)SDL_GetError());
	if (!(conv_sur_icon = SDL_ConvertSurface(sur_icon, sdl->sur->format, 0)))
		ft_exit((char *)SDL_GetError());
	SDL_SetWindowIcon(sdl->win, conv_sur_icon);
	SDL_FreeSurface(sur_icon);
	SDL_FreeSurface(conv_sur_icon);
}
