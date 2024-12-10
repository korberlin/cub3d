/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:11:00 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/19 12:54:28 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# define WIDTH 1920
# define HEIGHT 1280
# define FOV 1.047198
# define RAY_S 0.01
# define ANGLE_S 0.00097
# define MOVE_SPEED 0.1
# define TURN_SPEED 0.05
# define OFFSET 0.6
# define FOV_FACTOR 0.66

typedef enum s_err
{
	ERR_ARGC,
	ERR_EXT,
	ERR_ELEM,
	ERR_MISS,
	ERR_EXTRA,
	ERR_CEIL,
	ERR_EMPTY,
	ERR_MAP,
	ERR_TEXT,
	ERR_XPM,
	ERR_ORDER,
	ERR_WALL,
	ERR_MALLOC,
	ERR_PATH,
	ERR_EXIT,
	ERR_LAST,
	ERR_PLAYERCOUNT
}				t_err;

typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	MINI_BG,
	MINI_W,
	MINI_P,
	FLOOR,
	CEILING,
}				t_dir;

typedef enum s_keys
{
	KEY_W = 'w',
	KEY_A = 'a',
	KEY_S = 's',
	KEY_D = 'd',
	KEY_ESC = 65307,
	ARR_L = 65361,
	ARR_R = 65363,
}				t_keys;

typedef enum e_color
{
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	RED = 0xFF0000,
	GREEN = 0x00FF00
}	t_color;

#endif
