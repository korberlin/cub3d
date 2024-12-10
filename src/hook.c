/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:20 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 16:36:37 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	int		delta_x;
	double	rotation_speed;
	double	old_dir_x;
	double	old_plane_x;

	(void)y;
	delta_x = game->last_mouse_x - x;
	rotation_speed = delta_x * 0.003;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-rotation_speed)
		- game->player.dir_y * sin(-rotation_speed);
	game->player.dir_y = old_dir_x * sin(-rotation_speed)
		+ game->player.dir_y * cos(-rotation_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-rotation_speed)
		- game->player.plane_y * sin(-rotation_speed);
	game->player.plane_y = old_plane_x * sin(-rotation_speed)
		+ game->player.plane_y * cos(-rotation_speed);
	game->last_mouse_x = x;
	return (0);
}

int	press_button(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.forward = 1;
	else if (keycode == KEY_S)
		game->keys.backward = 1;
	else if (keycode == KEY_A)
		game->keys.left = 1;
	else if (keycode == KEY_D)
		game->keys.right = 1;
	else if (keycode == ARR_L)
		game->keys.turn_left = 1;
	else if (keycode == ARR_R)
		game->keys.turn_right = 1;
	else if (keycode == KEY_ESC)
		ft_error(ERR_EXIT, game);
	return (0);
}

int	release_button(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.forward = 0;
	else if (keycode == KEY_S)
		game->keys.backward = 0;
	else if (keycode == KEY_A)
		game->keys.left = 0;
	else if (keycode == KEY_D)
		game->keys.right = 0;
	else if (keycode == ARR_L)
		game->keys.turn_left = 0;
	else if (keycode == ARR_R)
		game->keys.turn_right = 0;
	return (0);
}
