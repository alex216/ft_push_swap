/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:48 by yliu              #+#    #+#             */
/*   Updated: 2024/01/31 11:53:17 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_four_min(int a, int b, int c, int d)
{
	return (ft_min(ft_min(ft_min(a,b),c),d));
}
