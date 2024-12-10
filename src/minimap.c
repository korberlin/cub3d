/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:05:18 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/14 11:49:48 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_minimap(t_game *game)
{
	draw_tiles(game);
	draw_player(game);
}

void	draw_tiles(t_game *game)
{
	int	map_x;
	int	map_y;
	int	x;
	int	y;
	int	line_length;

	map_y = 0;
	while (map_y < game->data->map_height)
	{
		map_x = 0;
		line_length = ft_strlen(game->data->map[map_y]);
		while (map_x < game->data->map_width)
		{
			x = map_x * game->minimap.tile_size;
			y = map_y * game->minimap.tile_size;
			if (map_x < line_length && game->data->map[map_y][map_x] == '1')
				draw_rectangle_tile(game, x, y, 0x000000);
			else
				draw_rectangle_tile(game, x, y, 0xFFFFFF);
			map_x++;
		}
		map_y++;
	}
}

void	draw_player(t_game *game)
{
	int	player_screen_x;
	int	player_screen_y;

	player_screen_x = (int)(game->player.x * game->minimap.tile_size);
	player_screen_y = (int)(game->player.y * game->minimap.tile_size);
	draw_rectangle_player(game,
		player_screen_x - game->minimap.player_size / 2,
		player_screen_y - game->minimap.player_size / 2,
		0xFF0000);
}

void	draw_rectangle_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	j = y;
	while (j < y + game->minimap.tile_size)
	{
		i = x;
		while (i < x + game->minimap.tile_size)
		{
			my_mlx_pixel_put(&game->img, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_rectangle_player(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	j = y;
	while (j < y + game->minimap.player_size)
	{
		i = x;
		while (i < x + game->minimap.player_size)
		{
			my_mlx_pixel_put(&game->img, i, j, color);
			i++;
		}
		j++;
	}
}
