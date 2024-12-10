/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:34:51 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 12:12:02 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	red_cross(void *game)
{
	ft_error(ERR_EXIT, game);
	return (1);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_data(t_game *game)
{
	if (game->data->file)
		free_2d(game->data->file);
	if (game->data->map)
		free_2d(game->data->map);
	if (game->data->flood)
		free_2d(game->data->flood);
	if (game->data->visited)
		free_2d(game->data->visited);
	if (game->data->config)
		free_2d(game->data->config);
	if (game->data->no)
		free(game->data->no);
	if (game->data->so)
		free(game->data->so);
	if (game->data->ea)
		free(game->data->ea);
	if (game->data->we)
		free(game->data->we);
	free(game->data);
}

void	free_textures(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

int	free_game(t_game *game)
{
	if (!game)
		return (0);
	free_data(game);
	free_textures(game);
	if (game->ray)
		free(game->ray);
	free(game);
	return (0);
}
