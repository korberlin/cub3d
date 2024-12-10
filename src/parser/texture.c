/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:49:49 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 17:10:16 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	assign_floor_ceiling(int *texture, char *src, int i, t_game *game)
{
	char	**temp;
	int		len;

	i += 2;
	while (src[i] && ft_isspace(src[i]))
		i++;
	temp = ft_split(src + i, ',');
	len = 0;
	while (temp[len])
		len++;
	if (len != 3)
		ft_error_2d(ERR_CEIL, game, temp);
	check_all_numbers(temp, game);
	i = -1;
	while (temp[++i])
	{
		texture[i] = ft_atoi(temp[i]);
		if (texture[i] < 0 || texture[i] > 255)
			ft_error_2d(ERR_CEIL, game, temp);
	}
	free_2d(temp);
}

static void	assign_texture(char **texture, char *src, int i)
{
	i += 2;
	while (src[i] && ft_isspace(src[i]))
		i++;
	if ((*texture) == NULL)
		*texture = ft_strdup(src + i);
}

void	check_texture(t_game *game, int i, char *src)
{
	if ((src[i] && src[i + 1]) && (src[i] == 'N' && src[i + 1] == 'O'))
		assign_texture(&game->data->no, src, i);
	else if ((src[i] && src[i + 1]) && (src[i] == 'S' && src[i + 1] == 'O'))
		assign_texture(&game->data->so, src, i);
	else if ((src[i] && src[i + 1]) && (src[i] == 'W' && src[i + 1] == 'E'))
		assign_texture(&game->data->we, src, i);
	else if ((src[i] && src[i + 1]) && (src[i] == 'E' && src[i + 1] == 'A'))
		assign_texture(&game->data->ea, src, i);
	else if ((src[i]) && (src[i] == 'C'))
		assign_floor_ceiling(game->data->c, src, i, game);
	else if ((src[i]) && (src[i] == 'F'))
		assign_floor_ceiling(game->data->f, src, i, game);
}

void	get_textures(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->data->config[++i])
	{
		count_commas(game->data->config[i], game);
		j = -1;
		while (game->data->config[i][++j])
			check_texture(game, j, game->data->config[i]);
	}
	validate_textures(game);
}
