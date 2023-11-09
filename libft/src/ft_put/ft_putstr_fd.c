/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:44:25 by yliu              #+#    #+#             */
/*   Updated: 2023/11/09 18:30:45 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		write(fd, "(null)\n", 7);
	else
		write(fd, s, ft_strlen(s));
}
