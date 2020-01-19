/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 02:09:07 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/19 04:44:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

int				set_rgb(int red, int green, int blue)
{
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

// SDL_Rect		*set_rect_size(int x, int y, int h, int w)
// {
// 	SDL_Rect 	*rect;

// 	rect = ft_safe_malloc(sizeof(SDL_Rect *));
// 	rect.x = x;
// 	rect.y = y;
// 	rect.h = h;
// 	rect.w = w;
// 	return (rect);
// }
