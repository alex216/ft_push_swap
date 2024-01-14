/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:45:33 by yliu              #+#    #+#             */
/*   Updated: 2024/01/11 11:54:48 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	while (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		flag;
	long	n;

	n = 0;
	flag = 1;
	if (str == NULL)
		exit(ENOMEM);
	while (is_space(*str) != '\0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (flag * n > (LONG_MAX - (*str - '0')) / 10)
			return (errno = ERANGE, (int)LONG_MAX);
		if (flag * n < (LONG_MIN + (*str - '0')) / 10)
			return (errno = ERANGE, (int)LONG_MIN);
		n = n * 10 + (*str - '0');
		str++;
	}
	return ((int)(flag * n));
}
