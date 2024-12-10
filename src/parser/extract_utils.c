/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:21:04 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/19 13:35:20 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	refactor_spaces(t_data *data)
{
	char	*new_line;
	int		i;
	int		j;
	int		tabs;
	int		len;

	i = -1;
	while (data->map[++i])
	{
		tabs = 0;
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == '\t')
				tabs++;
		len = ft_strlen(data->map[i]) + (tabs * 3);
		new_line = malloc(sizeof(char) * (len + 1));
		replace_tabs(data, new_line, i);
	}
}

void	replace_tabs(t_data *data, char *new_line, int i)
{
	char	*temp;
	int		j;
	int		k;

	temp = data->map[i];
	j = 0;
	k = 0;
	while (temp[j])
	{
		if (temp[j] == '\t')
		{
			new_line[k++] = ' ';
			new_line[k++] = ' ';
			new_line[k++] = ' ';
			new_line[k++] = ' ';
		}
		else
			new_line[k++] = temp[j];
		j++;
	}
	new_line[k] = '\0';
	data->map[i] = new_line;
	free(temp);
}
