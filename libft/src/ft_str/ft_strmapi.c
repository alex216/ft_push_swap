/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:59:28 by yliu              #+#    #+#             */
/*   Updated: 2023/11/09 18:30:56 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	if (str == NULL || f == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dst[i] = f(i, *(str + i));
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
