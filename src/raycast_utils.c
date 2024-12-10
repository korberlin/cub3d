/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:05:12 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 16:47:34 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(t_game *game, int x)
{
	game->ray->camera_x = 2 * x / (double)WIDTH - 1;
	game->ray->ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->ray->camera_x;
	game->ray->ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->ray->camera_x;
	game->ray->map_x = (int)(game->player.x);
	game->ray->map_y = (int)(game->player.y);
	if (game->ray->ray_dir_x == 0)
		game->ray->delta_dist_x = 1e30;
	else
		game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
	if (game->ray->ray_dir_y == 0)
		game->ray->delta_dist_y = 1e30;
	else
		game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
	game->ray->hit = 0;
}

void	calculate_wall(t_ray *ray, t_player player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_texture(t_game *game)
{
	if (game->ray->side == 0)
	{
		if (game->ray->ray_dir_x > 0)
			game->ray->texture = &game->textures[EAST];
		else
			game->ray->texture = &game->textures[WEST];
	}
	else
	{
		if (game->ray->ray_dir_y > 0)
			game->ray->texture = &game->textures[SOUTH];
		else
			game->ray->texture = &game->textures[NORTH];
	}
	game->ray->tex_x = (int)(game->ray->wall_x
			* (double)(game->ray->texture->width));
	if (game->ray->side == 0 && game->ray->ray_dir_x > 0)
		game->ray->tex_x = game->ray->texture->width - game->ray->tex_x - 1;
	if (game->ray->side == 1 && game->ray->ray_dir_y < 0)
		game->ray->tex_x = game->ray->texture->width - game->ray->tex_x - 1;
}

void	calculate_step(t_game *game)
{
	if (game->ray->ray_dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->player.x - game->ray->map_x)
			* game->ray->delta_dist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = (game->ray->map_x + 1.0 - game->player.x)
			* game->ray->delta_dist_x;
	}
	if (game->ray->ray_dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->player.y - game->ray->map_y)
			* game->ray->delta_dist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = (game->ray->map_y + 1.0 - game->player.y)
			* game->ray->delta_dist_y;
	}
}
