/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:34 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/23 13:31:24 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}