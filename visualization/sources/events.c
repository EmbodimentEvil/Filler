/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:44:00 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 06:52:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static t_plateau	*next_plateau(t_env *env)
{
	if (!env->plateau->next)
		parse(env);
	return ((env->plateau->next) ? env->plateau->next : env->plateau);
}

static t_plateau	*key_events(t_env *env, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_SPACE)
	{
		if (!env->plateau->next)
			parse(env);
		else
			exit (1);
	}
	return ((env->plateau->next) ? env->plateau->next : env->plateau);
}

void				events(t_env *env)
{
	SDL_Event		event;

	while (SDL_PollEvent(&event))
	{
		if (SDL_QUIT == event.type || SDLK_ESCAPE == event.key.keysym.sym)
			env->is_close = true;
		else if (event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			env->is_pause = !(env->is_pause);
		else if (((event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			|| (event.type == SDL_MOUSEBUTTONDOWN
			&& event.button.button == SDL_BUTTON_RIGHT))
			&& env->plateau->prev)
		{
			env->is_pause = true;
			env->plateau = env->plateau->prev;
		}
		else if ((event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			|| (event.type == SDL_MOUSEBUTTONDOWN
			&& event.button.button == SDL_BUTTON_LEFT))
		{
			env->is_pause = true;
			env->plateau = next_plateau(env);
		}
	}
	if (!env->is_pause)
		env->plateau = next_plateau(env);
}
