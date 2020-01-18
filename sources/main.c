/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/18 19:41:18 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_env	*env;

	if (!(env = init_env()))
		return (1);
	if (!parse_player(env))
		return (1);
	if (!init_sub_struct(env))
		return (0);
	while (true)
	{
		if (!parse_plateau(env))
			return (ft_free(Endgame, env));
		if (!(env->plateau->heatmap = init_heatmap(env->plateau->height,
													env->plateau->width)))
			return (ft_free(Fail, env));
		if (!parse_piece(env))
			return (ft_free(Fail, env));
		math_heatmap(env);
		math_best_pos(env);
		print_coords(env->x, env->y);
		reset_coords(&env->x, &env->y);
		ft_free(End_turn, env);
	}
	ft_free(Endgame, env);
	return (0);
}
//  clear ; make ; ./resources/filler_vm -p1 ./sleonia.filler -p2 resources/players/carli.filler -f resources/maps/map01
//  clear ; make ; ./resources/filler_vm -p1 resources/players/carli.filler -p2 ./sleonia.filler -f resources/maps/map01