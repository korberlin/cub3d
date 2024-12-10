/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:37:13 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/11 16:51:11 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

void	clear_image(t_txt_data *img)
{
	ft_bzero(img->addr, HEIGHT * img->line_len);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	get_texture_color(t_txt_data *texture, int tex_x, int tex_y)
{
	char	*src;

	src = texture->addr + (tex_y
			* texture->line_len + tex_x * (texture->bpp / 8));
	return (*(unsigned int *)src);
}

void	my_mlx_pixel_put(t_txt_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
