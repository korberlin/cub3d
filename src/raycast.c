/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:05:25 by azsonmez          #+#    #+#             */
/*   Updated: 2024/11/11 16:50:42 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	perform_dda(t_game *game)
{
	if (game->ray->side_dist_x < game->ray->side_dist_y)
	{
		game->ray->side_dist_x += game->ray->delta_dist_x;
		game->ray->map_x += game->ray->step_x;
		game->ray->side = 0;
	}
	else
	{
		game->ray->side_dist_y += game->ray->delta_dist_y;
		game->ray->map_y += game->ray->step_y;
		game->ray->side = 1;
	}
	if (game->ray->map_x >= 0 && game->ray->map_x < game->data->map_width
		&& game->ray->map_y >= 0 && game->ray->map_y < game->data->map_height)
	{
		if (game->data->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->hit = 1;
	}
	else
	{
		game->ray->hit = 1;
		game->ray->perp_wall_dist = 1000;
	}
}

void	draw_vertical(t_game *game, int x)
{
	game->ray->y = game->ray->draw_start;
	while (game->ray->y < game->ray->draw_end)
	{
		game->ray->tex_y = (int)game->ray->tex_pos
			& (game->ray->texture->height - 1);
		game->ray->tex_pos += game->ray->step;
		game->ray->color = get_texture_color(game->ray->texture,
				game->ray->tex_x, game->ray->tex_y);
		if (game->ray->side == 1)
			game->ray->color = (game->ray->color >> 1) & 8355711;
		my_mlx_pixel_put(&game->img, x, game->ray->y, game->ray->color);
		game->ray->y++;
	}
}

void	draw_floor_ceiling(t_game *game, int x)
{
	game->ray->ceiling_color = rgb_to_int(game->data->c[0],
			game->data->c[1], game->data->c[2]);
	game->ray->floor_color = rgb_to_int(game->data->f[0],
			game->data->f[1], game->data->f[2]);
	game->ray->y = 0;
	while (game->ray->y < game->ray->draw_start)
		my_mlx_pixel_put(&game->img, x, game->ray->y++,
			game->ray->ceiling_color);
	game->ray->y = game->ray->draw_end;
	while (game->ray->y < HEIGHT)
		my_mlx_pixel_put(&game->img, x, game->ray->y++,
			game->ray->floor_color);
}

void	perform_raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, x);
		calculate_step(game);
		while (game->ray->hit == 0)
			perform_dda(game);
		calculate_wall(game->ray, game->player);
		calculate_texture(game);
		game->ray->step = 1.0 * game->ray->texture->height
			/ game->ray->line_height;
		game->ray->tex_pos = (game->ray->draw_start - HEIGHT
				/ 2 + game->ray->line_height / 2) * game->ray->step;
		draw_vertical(game, x);
		draw_floor_ceiling(game, x);
		x++;
	}
}
