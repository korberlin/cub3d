/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:05:25 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 17:00:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	simulate_move(double new_x, t_player *player, int dir, t_game *game)
{
	double	new_y;

	new_y = 0;
	if (dir == NORTH)
	{
		new_x = player->x + player->dir_x * (MOVE_SPEED);
		new_y = player->y + player->dir_y * (MOVE_SPEED);
	}
	else if (dir == SOUTH)
	{
		new_x = player->x - player->dir_x * (MOVE_SPEED);
		new_y = player->y - player->dir_y * (MOVE_SPEED);
	}
	else if (dir == EAST)
	{
		new_x = player->x - player->dir_y * (MOVE_SPEED);
		new_y = player->y + player->dir_x * (MOVE_SPEED);
	}
	else if (dir == WEST)
	{
		new_x = player->x + player->dir_y * (MOVE_SPEED);
		new_y = player->y - player->dir_x * (MOVE_SPEED);
	}
	attempt_move(new_x, new_y, game->data->map, player);
}

void	attempt_move(double new_x, double new_y, char **map, t_player *player)
{
	if (map[(int)new_y][(int)new_x] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	turn(t_player *player, int dir)
{
	if (dir == WEST)
	{
		player->dir -= TURN_SPEED;
		if (player->dir < 0)
			player->dir += 2 * M_PI;
	}
	if (dir == EAST)
	{
		player->dir += TURN_SPEED;
		if (player->dir > 2 * M_PI)
			player->dir -= 2 * M_PI;
	}
	player->dir_x = cos(player->dir);
	player->dir_y = sin(player->dir);
	player->plane_x = -0.66 * sin(player->dir);
	player->plane_y = 0.66 * cos(player->dir);
}

void	process_input(t_game *game)
{
	double	new_x;

	new_x = 0;
	if (game->keys.forward)
		simulate_move(new_x, &game->player, NORTH, game);
	if (game->keys.backward)
		simulate_move(new_x, &game->player, SOUTH, game);
	if (game->keys.left)
		simulate_move(new_x, &game->player, WEST, game);
	if (game->keys.right)
		simulate_move(new_x, &game->player, EAST, game);
	if (game->keys.turn_left)
		turn(&game->player, WEST);
	if (game->keys.turn_right)
		turn(&game->player, EAST);
}

int	loop(t_game *game)
{
	process_input(game);
	clear_image(&game->img);
	perform_raycasting(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
