/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:47:09 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 14:48:53 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	validate_path(t_game *game, char **argv)
{
	int	len;
	int	fd;

	len = ft_strlen(argv[1]);
	if ((argv[1][len - 1] != 'b') || (argv[1][len - 2] != 'u')
		|| (argv[1][len - 3] != 'c') || (argv[1][len - 4] != '.'))
		return (ft_error(ERR_EXT, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(ERR_PATH, game));
	else
		close(fd);
}

void	validate_order(t_game *game)
{
	int	i;
	int	map_exist;

	map_exist = 0;
	i = -1;
	while (game->data->file[++i])
		if (is_map(game->data->file[i]))
			map_exist = 1;
	if (!map_exist)
		ft_error(ERR_MISS, game);
	i = strlen2d(game->data->file);
	while (game->data->file[--i])
	{
		if (ft_emptyline(game->data->file[i]))
		{
			i--;
			continue ;
		}
		if (is_map(game->data->file[i]))
			return ;
		else if (is_texture(game->data->file[i]))
			ft_error(ERR_ORDER, game);
		i--;
	}
}

void	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->data->map[0][++i])
		if (game->data->map[0][i] != '1' && !ft_isspace(game->data->map[0][i]))
			ft_error(ERR_WALL, game);
	check_middle_lines(game);
	j = -1;
	i = 0;
	while (game->data->map[i])
		i++;
	i--;
	while (game->data->map[i][++j])
		if (game->data->map[i][j] != '1' && !ft_isspace(game->data->map[i][j]))
			ft_error(ERR_WALL, game);
	check_player_count(game);
}

void	validate_textures(t_game *game)
{
	int	fd;

	check_texture_extension(game->data->no, game);
	check_texture_extension(game->data->so, game);
	check_texture_extension(game->data->we, game);
	check_texture_extension(game->data->ea, game);
	fd = open(game->data->no, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_TEXT, game);
	close(fd);
	fd = open(game->data->we, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_TEXT, game);
	close(fd);
	fd = open(game->data->so, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_TEXT, game);
	close(fd);
	fd = open(game->data->ea, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_TEXT, game);
	close(fd);
}
