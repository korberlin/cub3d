/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:34:32 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/19 13:34:33 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	extract_width_height(t_game *game)
{
	int	i;
	int	temp;
	int	max_width;

	i = 0;
	max_width = 0;
	while (game->data->map[i])
	{
		temp = 0;
		while (game->data->map[i][temp])
			temp++;
		if (temp > max_width)
			max_width = temp;
		i++;
	}
	game->data->map_height = i;
	game->data->map_width = max_width;
}

void	extract_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->data->map[++i])
	{
		j = -1;
		while (game->data->map[i][++j])
			if (is_player(game->data->map[i][j]))
				parse_player(game, game->data->map[i][j], i, j);
	}
}

void	extract_rest(t_game *game)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 0;
	j = 0;
	while (game->data->file[i] && !is_map(game->data->file[i++]))
		if (!ft_emptyline(game->data->file[i]))
			len++;
	game->data->config = malloc(sizeof(char *) * (len + 1));
	if (!game->data->config)
		ft_error(ERR_MALLOC, game);
	i = 0;
	while (game->data->file[i] && !is_map(game->data->file[i]))
	{
		if (!ft_emptyline(game->data->file[i]))
			game->data->config[j++] = ft_strdup_newline(game->data->file[i]);
		i++;
	}
	game->data->config[j] = NULL;
	if (j > 6)
		ft_error(ERR_EXTRA, game);
	if (j < 6)
		ft_error(ERR_MISS, game);
}

void	extract_map(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (game->data->file[i])
		i++;
	i--;
	while (i >= 0 && ft_emptyline(game->data->file[i]))
		i--;
	j = i;
	while (i >= 0 && is_map(game->data->file[i]))
		i--;
	i++;
	game->data->map = malloc(sizeof(char *) * (j - i + 2));
	k = 0;
	while (i <= j)
		game->data->map[k++] = ft_strdup_newline(game->data->file[i++]);
	game->data->map[k] = 0;
	k = -1;
	while (game->data->map[++k])
		if (ft_emptyline(game->data->map[k]))
			ft_error(ERR_ELEM, game);
	refactor_spaces(game->data);
	extract_width_height(game);
}
