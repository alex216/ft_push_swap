/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 08:39:05 by yliu              #+#    #+#             */
/*   Updated: 2023/10/05 18:57:34 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	if (str == NULL)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
