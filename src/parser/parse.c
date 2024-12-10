/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:09:54 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/22 12:16:00 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_map_last(t_game *game)
{
	int	i;

	i = -1;
	while (game->data->file[++i])
		if (is_map(game->data->file[i]))
			break ;
	game->data->map_start = i;
	i = game->data->map_start;
	while (game->data->file[i] && is_map(game->data->file[i]))
		i++;
	game->data->map_end = i - 1;
	while (game->data->file[i])
	{
		if (!ft_emptyline(game->data->file[i]))
			ft_error(ERR_LAST, game);
		i++;
	}
}

void	reset_data(t_game *game)
{
	game->data->file = 0;
	game->data->map = 0;
	game->data->flood = 0;
	game->data->visited = 0;
	game->data->config = 0;
	game->data->map_height = 0;
	game->data->map_width = 0;
	game->data->dir = 0;
	game->data->x = 0;
	game->data->y = 0;
	game->data->no = 0;
	game->data->so = 0;
	game->data->ea = 0;
	game->data->we = 0;
}

void	check_all_numbers(char **temp, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (ft_isspace(temp[i][j])
			|| (temp[i][j] >= '0' && temp[i][j] <= '9'))
				;
			else
			{
				free_2d(temp);
				ft_error(ERR_CEIL, game);
			}
		}
	}
}

void	copy_file(t_game *game, char *src)
{
	int		fd;
	char	*tmp;
	int		i;

	fd = open(src, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		ft_error(ERR_EMPTY, game);
	i = 1;
	while (tmp && i++)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	if (i < 6)
		ft_error(ERR_ELEM, game);
	game->data->file = malloc(sizeof(char *) * (i + 1));
	i = 0;
	fd = open(src, O_RDONLY);
	game->data->file[0] = get_next_line(fd);
	while (game->data->file[i])
		game->data->file[++i] = get_next_line(fd);
	game->data->file[i] = NULL;
}

void	parse_cub(t_game *game, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error(ERR_MALLOC, game);
	game->data = data;
	reset_data(game);
	validate_path(game, argv);
	copy_file(game, argv[1]);
	validate_order(game);
	extract_rest(game);
	get_textures(game);
	extract_map(game);
	check_map_last(game);
	validate_map(game);
	flood_fill(game);
	extract_player(game);
}
