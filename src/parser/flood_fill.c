/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:47:02 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 17:03:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_visited(t_game *game, int len, char **visited)
{
	int	i;
	int	j;
	int	row_len;

	visited[len] = 0;
	i = -1;
	while (++i < len)
	{
		row_len = ft_strlen(game->data->flood[i]);
		visited[i] = malloc(sizeof(char) * (row_len + 1));
		if (!visited[i])
			ft_error(ERR_MALLOC, game);
		j = -1;
		while (++j < row_len)
			visited[i][j] = '.';
		visited[i][row_len] = '\0';
	}
	game->data->visited = visited;
}

void	algorithm(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x > (strlen2d(game->data->flood) - 1)
		|| y > (int)(ft_strlen(game->data->flood[x]) - 1))
		return ;
	if (game->data->visited[x][y] == 'v')
		return ;
	game->data->visited[x][y] = 'v';
	if (game->data->flood[x][y] == '1')
		return ;
	if (!game->data->flood[x][y] || ft_isspace(game->data->flood[x][y]))
		ft_error(ERR_WALL, game);
	algorithm(game, x + 1, y);
	algorithm(game, x - 1, y);
	algorithm(game, x, y + 1);
	algorithm(game, x, y - 1);
}

void	check_boundaries(t_game *game, int x, int y)
{
	char	**temp;
	int		rows;
	int		len_x_minus1;
	int		len_x;
	int		len_x_plus1;

	temp = game->data->flood;
	rows = strlen2d(temp);
	if (x - 1 < 0 || x + 1 >= rows)
		ft_error(ERR_WALL, game);
	len_x_minus1 = ft_strlen(temp[x - 1]);
	len_x = ft_strlen(temp[x]);
	len_x_plus1 = ft_strlen(temp[x + 1]);
	if (y < 0 || y >= len_x_minus1 || y >= len_x || y >= len_x_plus1)
		ft_error(ERR_WALL, game);
	if (y - 1 < 0 || y + 1 >= len_x)
		ft_error(ERR_WALL, game);
}

void	check_beginning(t_game *game, int x, int y)
{
	char	**temp;

	temp = game->data->flood;
	check_boundaries(game, x, y);
	if (ft_isspace(temp[x - 1][y]) || ft_isspace(temp[x + 1][y]) ||
		ft_isspace(temp[x][y - 1]) || ft_isspace(temp[x][y + 1]))
		ft_error(ERR_WALL, game);
	algorithm(game, x, y);
}

void	flood_fill(t_game *game)
{
	char	**flood;
	char	**visited;
	int		len;
	int		i;

	len = 0;
	while (game->data->map[len])
		len++;
	flood = malloc(sizeof(char *) * (len + 1));
	visited = malloc(sizeof(char *) * (len + 1));
	i = -1;
	flood[len] = 0;
	while (game->data->map[++i])
		flood[i] = ft_strdup(game->data->map[i]);
	game->data->flood = flood;
	init_visited(game, len, visited);
	i = -1;
	while (game->data->flood[++i])
	{
		len = -1;
		while (game->data->flood[i][++len])
			if (is_player(game->data->flood[i][len]))
				check_beginning(game, i, len);
	}
}
