/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:35:47 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 17:08:02 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_player(t_game *game, char c, int x, int y)
{
	game->data->x = x;
	game->data->y = y;
	if (c == 'N')
		game->data->dir = NORTH;
	if (c == 'S')
		game->data->dir = SOUTH;
	if (c == 'W')
		game->data->dir = WEST;
	if (c == 'E')
		game->data->dir = EAST;
}

int	is_texture(char *src)
{
	int	i;

	i = 0;
	while (ft_isspace(src[i]))
		i++;
	if ((src[i] && src[i + 1]) && (src[i] == 'N' && src[i + 1] == 'O'))
		return (1);
	else if ((src[i] && src[i + 1]) && (src[i] == 'S' && src[i + 1] == 'O'))
		return (1);
	else if ((src[i] && src[i + 1]) && (src[i] == 'W' && src[i + 1] == 'E'))
		return (1);
	else if ((src[i] && src[i + 1]) && (src[i] == 'E' && src[i + 1] == 'A'))
		return (1);
	else if ((src[i]) && (src[i] == 'C'))
		return (1);
	else if ((src[i]) && (src[i] == 'F'))
		return (1);
	return (0);
}

void	count_commas(char *str, t_game *game)
{
	int	i;
	int	comma;

	i = 0;
	if (str[0] == 'F' || str[0] == 'C')
	{
		comma = 0;
		while (str[i++])
			if (str[i] == ',')
				comma++;
	}
	else
		comma = 2;
	if (comma != 2)
		ft_error(ERR_CEIL, game);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((ft_isspace(str[i])) || (str[i] == '1' || str[i] == '0'
					|| str[i] == 'N' || str[i] == 'W'
					|| str[i] == 'S' || str[i] == 'E')))
			return (0);
		if (ft_emptyline(str))
			return (0);
		i++;
	}
	return (1);
}

int	strlen2d(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
