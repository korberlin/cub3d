/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:12:56 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/19 13:22:15 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libs.h"

//Init
void	init_win(t_game *game);
void	init_minimap(t_game *game);
void	init_texture(t_game *game, int index, char *path);
void	init_dir(t_game *game);

// Hooks & Loop
int		press_button(int key, t_game *game);
int		release_button(int key, t_game *game);
void	simulate_move(double new_x, t_player *player, int dir, t_game *game);
void	attempt_move(double new_x, double new_y, char **map, t_player *player);
void	process_input(t_game *game);
int		loop(t_game *game);
void	turn(t_player *player, int dir);
int		mouse_move(int x, int y, t_game *game);

//Utils
void	clear_image(t_txt_data *img);
int		rgb_to_int(int r, int g, int b);
int		get_texture_color(t_txt_data *texture, int tex_x, int tex_y);
void	my_mlx_pixel_put(t_txt_data *data, int x, int y, int color);

//Extract
void	extract_width_height(t_game *game);
void	extract_map(t_game *game);
void	extract_rest(t_game *game);
void	extract_player(t_game *game);

//Extract Utils
void	refactor_spaces(t_data *data);
void	replace_tabs(t_data *data, char *new, int i);

//Parser Utils
void	reset_data(t_game *game);
void	check_map_last(t_game *game);
int		is_map(char *str);
int		is_player(char c);
int		is_texture(char *src);

//Parser
void	parse_cub(t_game *game, char **argv);
void	get_textures(t_game *game);
int		strlen2d(char **str);
void	parse_player(t_game *game, char c, int x, int y);

//Flood Fill
void	init_visited(t_game *game, int len, char **visited);
void	algorithm(t_game *game, int x, int y);
void	check_boundaries(t_game *game, int x, int y);
void	check_beginning(t_game *game, int x, int y);
void	flood_fill(t_game *game);

// Validate
void	validate_path(t_game *game, char **argv);
void	validate_order(t_game *game);
void	validate_map(t_game *game);
void	validate_textures(t_game *game);
void	check_middle_lines(t_game *game);
void	check_all_numbers(char **temp, t_game *game);
void	check_player_count(t_game *game);
void	check_texture(t_game *game, int i, char *src);
void	check_texture_extension(char *str, t_game *game);
void	count_commas(char *str, t_game *game);
void	flood_fill(t_game *game);

//Free & Error
int		red_cross(void *game);
void	free_2d(char **str);
void	free_data(t_game *game);
void	free_textures(t_game *game);
int		free_game(t_game *game);
void	print_error(int i);
void	print_error_2(int i);
void	ft_error(int i, t_game *game);
void	ft_error_2d(int err, t_game *game, char **temp);

// Minimap
void	draw_minimap(t_game *game);
void	draw_tiles(t_game *game);
void	draw_player(t_game *game);
void	draw_rectangle_tile(t_game *game, int x, int y, int color);
void	draw_rectangle_player(t_game *game, int x, int y, int color);

//Raycast
void	init_ray(t_game *game, int x);
void	calculate_step(t_game *game);
void	perform_dda(t_game *game);
void	calculate_wall(t_ray *ray, t_player player);
void	calculate_texture(t_game *game);
void	draw_vertical(t_game *game, int x);
void	draw_floor_ceiling(t_game *game, int x);
void	perform_raycasting(t_game *game);

#endif
