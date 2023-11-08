/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:47:18 by yliu              #+#    #+#             */
/*   Updated: 2023/11/08 11:20:35 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (src_len + dst_len);
}
