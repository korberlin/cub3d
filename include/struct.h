/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:43:54 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 17:13:20 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_keys_state
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
}	t_keys_state;

typedef struct s_data
{
	char	**file;
	char	**map;
	char	**flood;
	char	**visited;
	char	**config;
	int		map_width;
	int		map_height;
	int		map_start;
	int		map_end;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		f[3];
	int		c[3];
	int		dir;
	int		x;
	int		y;

}	t_data;

typedef struct t_txt_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_txt_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;

	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_minimap
{
	int	tile_size;
	int	player_screen_x;
	int	player_screen_y;
	int	player_size;
	int	line_length;
	int	line_end_x;
	int	line_end_y;
}	t_minimap;

typedef struct s_ray
{
	double		camera_x;
	double		camera_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			y;
	int			tex_y;
	int			color;
	int			ceiling_color;
	int			floor_color;
	t_txt_data	*texture;
}	t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				debug;
	t_player		player;
	t_minimap		minimap;
	int				key;
	int				last_mouse_x;
	t_txt_data		img;
	t_data			*data;
	int				map_size;
	t_txt_data		textures[4];
	t_keys_state	keys;
	t_ray			*ray;
}	t_game;

#endif
