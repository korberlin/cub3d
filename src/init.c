/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:32 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 16:36:54 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_game *game)
{
	game->minimap.tile_size = 10;
	game->minimap.player_size = 5;
	game->minimap.line_length = 15;
}

void	init_texture(t_game *game, int index, char *path)
{
	game->textures[index].img = mlx_xpm_file_to_image(
			game->mlx, path,
			&(game->textures[index].width),
			&(game->textures[index].height)
			);
	if (!game->textures[index].img)
		ft_error(ERR_TEXT, game);
	game->textures[index].addr = mlx_get_data_addr(
			game->textures[index].img,
			&(game->textures[index].bpp),
			&(game->textures[index].line_len),
			&(game->textures[index].endian)
			);
}

void	init_dir(t_game *game)
{
	if (game->data->dir == NORTH)
		game->player.dir = 1.5 * M_PI;
	else if (game->data->dir == SOUTH)
		game->player.dir = 0.5 * M_PI;
	else if (game->data->dir == WEST)
		game->player.dir = M_PI;
	else
		game->player.dir = 0;
	game->player.dir_x = cos(game->player.dir);
	game->player.dir_y = sin(game->player.dir);
	game->player.plane_x = -FOV_FACTOR * game->player.dir_y;
	game->player.plane_y = FOV_FACTOR * game->player.dir_x;
}

void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	game->player.x = game->data->y + 0.5;
	game->player.y = game->data->x + 0.5;
	game->last_mouse_x = WIDTH / 2;
	game->key = -1;
	game->map_size = game->data->map_width;
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	init_dir(game);
	init_minimap(game);
	init_texture(game, NORTH, game->data->no);
	init_texture(game, SOUTH, game->data->so);
	init_texture(game, WEST, game->data->we);
	init_texture(game, EAST, game->data->ea);
}
