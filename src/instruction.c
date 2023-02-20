/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:21:12 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/20 23:28:55 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_sa(t_stack *s)
{
	int	tmp1;
	int	tmp2;

	if (s->length < 2)
		return ;
	tmp1 = *get_stack(s, 1);
	if (!tmp1)
		return ;
	tmp2 = *get_stack(s, 0);
	set_stack(s, 0, tmp1);
	set_stack(s, 1, tmp2);
}

void	exe_sb(t_stack *s)
{
	int	tmp1;
	int	tmp2;

	if (s->length < 2)
		return ;
	tmp1 = *get_stack(s, 1);
	if (!tmp1)
		return ;
	tmp2 = *get_stack(s, 0);
	set_stack(s, 0, tmp1);
	set_stack(s, 1, tmp2);
}

void	exe_ss(t_stack *sa, t_stack *sb)
{
	exe_sa(sa);
	exe_sb(sb);
}

void	exe_pa(t_stack *sa, t_stack *sb)
{
	int	*tmp;

	tmp = shift_stack(sb);
	if (!tmp)
		return ;
	push_stack(sa, *tmp);
}

void	exe_pb(t_stack *sa, t_stack *sb)
{
	int	*tmp;

	tmp = shift_stack(sa);
	if (!tmp)
		return ;
	push_stack(sb, *tmp);
}
