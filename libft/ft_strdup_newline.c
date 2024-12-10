/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:31:08 by gkoksal           #+#    #+#             */
/*   Updated: 2024/07/24 15:17:42 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_newline(const char *s1)
{
	size_t	len;
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		i++;
		len++;
	}
	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
