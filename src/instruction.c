/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:21:12 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/22 00:39:32 by tjukmong         ###   ########.fr       */
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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	exe_ss(t_stack *sa, t_stack *sb)
{
	int	tmp1;
	int	tmp2;

	if (sa->length < 2)
		return ;
	tmp1 = *get_stack(sa, 1);
	if (!tmp1)
		return ;
	tmp2 = *get_stack(sa, 0);
	set_stack(sa, 0, tmp1);
	set_stack(sa, 1, tmp2);
	if (sb->length < 2)
		return ;
	tmp1 = *get_stack(sb, 1);
	if (!tmp1)
		return ;
	tmp2 = *get_stack(sb, 0);
	set_stack(sb, 0, tmp1);
	set_stack(sb, 1, tmp2);
	write(1, "ss\n", 3);
}

void	exe_pa(t_stack *sa, t_stack *sb)
{
	int	*tmp;

	tmp = shift_stack(sb);
	if (!tmp)
		return ;
	unshift_stack(sa, *tmp);
	write(1, "pa\n", 3);
}

void	exe_pb(t_stack *sa, t_stack *sb)
{
	int	*tmp;

	tmp = shift_stack(sa);
	if (!tmp)
		return ;
	unshift_stack(sb, *tmp);
	write(1, "pb\n", 3);
}
