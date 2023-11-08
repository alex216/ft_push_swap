/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:57:30 by yliu              #+#    #+#             */
/*   Updated: 2023/10/05 18:56:25 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst_ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	if (size * count == 0)
		return (malloc(0));
	dst_ptr = malloc(size * count);
	if (dst_ptr == NULL)
		return (NULL);
	ft_bzero(dst_ptr, (size * count));
	return (dst_ptr);
}
