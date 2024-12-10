/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:47:16 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 14:47:19 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_texture_extension(char *str, t_game *game)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		ft_error(ERR_XPM, game);
	if (!(str[len - 1] != 'm' && str[len - 2] != 'p'
			&& str[len - 3] != 'x' && str[len - 4] != '.'))
		return ;
	else
		ft_error(ERR_XPM, game);
}

void	check_middle_lines(t_game *game)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	while (game->data->map[++i])
	{
		j = -1;
		len = ft_strlen(game->data->map[i]) - 1;
		while (game->data->map[i][++j])
		{
			while (ft_isspace(game->data->map[i][j]))
				j++;
			while (ft_isspace(game->data->map[i][len]))
				len--;
			break ;
		}
		if (game->data->map[i][j] != '1' || game->data->map[i][len] != '1')
			ft_error(ERR_WALL, game);
	}
}

void	check_player_count(t_game *game)
{
	int		player;
	int		i;
	int		j;
	char	c;

	i = -1;
	player = 0;
	while (game->data->map[++i])
	{
		j = -1;
		while (game->data->map[i][++j])
		{
			c = game->data->map[i][j];
			if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
				player++;
		}
	}
	if (player != 1)
		ft_error(ERR_PLAYERCOUNT, game);
}
