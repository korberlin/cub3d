/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:05:28 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 12:15:50 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_ray	*ray;

	if (argc != 2)
		ft_error(ERR_ARGC, NULL);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error(ERR_MALLOC, NULL);
	parse_cub(game, argv);
	init_win(game);
	ft_bzero(&game->keys, sizeof(t_keys_state));
	ray = malloc(sizeof(t_ray));
	if (!ray)
		ft_error(ERR_MALLOC, game);
	game->ray = ray;
	game->ray->texture = NULL;
	mlx_hook(game->win, 2, 1L << 0, press_button, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win, 3, 1L << 1, release_button, game);
	mlx_hook(game->win, 17, 1L << 2, red_cross, game);
	mlx_loop_hook(game->mlx, &loop, game);
	mlx_loop(game->mlx);
}
