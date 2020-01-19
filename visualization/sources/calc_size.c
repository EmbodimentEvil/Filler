/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:27:29 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 02:22:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void		calc_size(t_env *env)
{
	int		plateau_height;
	int		plateau_width;

	if (env->plateau->width > env->plateau->height)
		env->math->cell_shift = (env->sdl->sur->w * 0.7) / env->plateau->width;
	else
		env->math->cell_shift = (env->sdl->sur->h * 0.7) / env->plateau->height;
	plateau_height = env->math->cell_shift * env->plateau->height;
	plateau_width = env->math->cell_shift * env->plateau->width;
	env->math->cell_size = env->math->cell_shift * 85 / 100;
	env->math->start_y = (env->sdl->sur->h + 250 - plateau_height
						+ (env->math->cell_shift - env->math->cell_size)) / 2;
	env->math->start_x = (env->sdl->sur->w - 350 - plateau_width
						+ (env->math->cell_shift - env->math->cell_size)) / 2;
	env->math->enemy_score = 0;
	env->math->my_score = 0;
}
