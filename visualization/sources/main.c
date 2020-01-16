/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:33:07 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 17:20:23 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static int	show_example_input(void)
{
	system("osascript -e \'display notification\" \
Error input!\" with title \"Warning!\"\'");
	ft_putstr("\033[31mYou must use only \"-pixel\" or \"-gachi\"\033[0m\n");
	return (1);
}

static int	parse_argument(int ac, char **av, int *game_mode)
{
	if (ac != 2)
		*game_mode = Pixel;
	else if (ft_strcmp(av[1], "-pixel") == 0)
		*game_mode = Pixel;
	else if (ft_strcmp(av[1], "-gachi") == 0)
		*game_mode = Gachi;
	else
		return(show_example_input());
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*env;

	env = init_env();
	if (parse_argument(ac, av, &env->game_mode) == 1)
		return (0);	
	init_sdl(env->game_mode, env->sdl);
	change_music(env->game_mode, env->sdl->music);
	parse(env);
	main_loop(env);
	return (0);
}
