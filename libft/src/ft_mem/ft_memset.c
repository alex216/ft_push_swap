/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:15:25 by yliu              #+#    #+#             */
/*   Updated: 2023/10/05 18:59:20 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp;

	if (str == NULL)
		return (NULL);
	tmp = str;
	while (n > 0)
	{
		*tmp++ = (unsigned char)c;
		n--;
	}
	return (str);
}
