/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:49:37 by yliu              #+#    #+#             */
/*   Updated: 2023/10/05 22:22:25 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ans;

	if (s == NULL)
		return (NULL);
	ans = NULL;
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (*(s + i) == (char)c)
			ans = (char *)(s + i);
		i++;
	}
	return (ans);
}
