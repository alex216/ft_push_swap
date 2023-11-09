/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:59:56 by yliu              #+#    #+#             */
/*   Updated: 2023/11/09 18:30:07 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src_tmp;
	char	*dst_tmp;

	if (dst == NULL || src == NULL)
		return (NULL);
	src_tmp = (char *)src;
	dst_tmp = (char *)dst;
	if (dst_tmp < src_tmp)
	{
		while (n--)
			*dst_tmp++ = *src_tmp++;
	}
	else if (dst_tmp > src_tmp)
	{
		src_tmp = src_tmp + n - 1;
		dst_tmp = dst_tmp + n - 1;
		while (n--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}
