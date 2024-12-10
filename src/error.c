/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:23 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 16:34:30 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error(int i)
{
	if (i == ERR_MALLOC)
		printf("Memory Allocation failed\n");
	if (i == ERR_ARGC)
		printf("This game takes only one argument (map with .cub extension)\n");
	if (i == ERR_PATH)
		printf("Map can not be found or permission denied\n");
	if (i == ERR_EXT)
		printf("Map extension should be in .cub extension\n");
	if (i == ERR_ELEM)
		printf("Map file does not meet with the requirements\n");
	if (i == ERR_EMPTY)
		printf("Map is empty\n");
	if (i == ERR_MISS)
		printf("Map is missing an element\n");
	if (i == ERR_CEIL)
		printf("Ceiling or Floor does not match with the map requirements\n");
	if (i == ERR_EXTRA)
		printf("Map includes an extra element\n");
}

void	print_error_2(int i)
{
	if (i == ERR_WALL)
		printf("Map walls does not comply with standards\n");
	if (i == ERR_ORDER)
		printf("Map is not in the correct order\n");
	if (i == ERR_TEXT)
		printf("Texture file can not be opened\n");
	if (i == ERR_XPM)
		printf("Texture file must have xpm extension\n");
	if (i == ERR_LAST)
		printf("There is an extra element after map in the map file\n");
	if (i == ERR_PLAYERCOUNT)
		printf("Player count is not equal to one\n");
	if (i == ERR_EXIT)
		printf("Game ended by user.\n");
}

void	ft_error(int i, t_game *game)
{
	if (i != ERR_EXIT)
		printf("Error\n");
	print_error(i);
	print_error_2(i);
	if (game)
		free_game(game);
	if (i == ERR_EXIT)
		exit(0);
	exit(1);
}

void	ft_error_2d(int err, t_game *game, char **temp)
{
	if (temp)
		free_2d(temp);
	ft_error(err, game);
}
