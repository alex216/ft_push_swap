/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:59:49 by yliu              #+#    #+#             */
/*   Updated: 2023/10/05 18:58:19 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*tmp;

	if (dst == NULL || src == NULL)
		return (NULL);
	tmp = dst;
	while (n--)
		*(char *)tmp++ = *(char *)src++;
	return (dst);
}
