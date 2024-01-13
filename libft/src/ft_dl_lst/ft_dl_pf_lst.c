/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_pf_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:52 by yliu              #+#    #+#             */
/*   Updated: 2024/01/13 00:38:01 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*get_char_content(t_lst *lst_p)
{
	return (lst_p->payload_p->char_content);
}

// void	ft_dl_pf_lst(t_lst **lst_p)
// {
// 	if (!(*lst_p))
// 		return ;
// 	ft_printf("#####start#####[size:%d]\n[->]", ft_dl_lstsize(*lst_p));
// 	while (!(*lst_p)->is_sentinel)
// 	{
// 		ft_printf("%s", get_char_content(*lst_p));
// 		*lst_p = (*lst_p)->next_p;
// 		ft_printf(" -> ");
// 	}
// 	ft_printf("[%d]", (*lst_p)->is_sentinel);
// 	ft_printf(" -> %s", get_char_content((*lst_p)->next_p));
//
//
// 	ft_printf("\n[<-]");
// 	*lst_p = (*lst_p)->prev_p;
// 	while (!(*lst_p)->is_sentinel)
// 	{
// 		ft_printf("%s", get_char_content(*lst_p));
// 		*lst_p = (*lst_p)->prev_p;
// 		ft_printf(" -> ");
// 	}
// 	ft_printf("[%d]", (*lst_p)->is_sentinel);
// 	ft_printf(" -> %s", get_char_content((*lst_p)->prev_p));
// 	ft_printf("\n");
// 	return ;
// }

void	ft_dl_pf_lst(t_lst *lst_p)
{
	if (!lst_p)
		return ;
	ft_printf("#####start#####[size:%d]\n[->]", ft_dl_lstsize(lst_p));
	while (!lst_p->is_sentinel)
	{
		ft_printf("%s", get_char_content(lst_p));
		lst_p = lst_p->next_p;
		ft_printf(" -> ");
	}
	ft_printf("[%d]", lst_p->is_sentinel);
	ft_printf(" -> %s", get_char_content(lst_p->next_p));


	ft_printf("\n[<-]");
	lst_p = lst_p->prev_p;
	while (!lst_p->is_sentinel)
	{
		ft_printf("%s", get_char_content(lst_p));
		lst_p = lst_p->prev_p;
		ft_printf(" -> ");
	}
	ft_printf("[%d]", lst_p->is_sentinel);
	ft_printf(" -> %s", get_char_content(lst_p->prev_p));
	ft_printf("\n");
	return ;
}
