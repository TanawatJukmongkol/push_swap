/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:41 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/21 23:47:48 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_ra(t_stack *s)
{
	int	*tmp;

	tmp = shift_stack(s);
	if (!tmp)
		return ;
	push_stack(s, *tmp);
	write(1, "ra\n", 3);
}

void	exe_rb(t_stack *s)
{
	int	*tmp;

	tmp = shift_stack(s);
	if (!tmp)
		return ;
	push_stack(s, *tmp);
	write(1, "rb\n", 3);
}

void	exe_rr(t_stack *sa, t_stack *sb)
{
	int	*tmp;

	tmp = shift_stack(sa);
	if (!tmp)
		return ;
	push_stack(sa, *tmp);
	tmp = shift_stack(sb);
	if (!tmp)
		return ;
	push_stack(sb, *tmp);
	write(1, "rr\n", 3);
}

void	exe_rra(t_stack *s)
{
	int	*tmp;

	tmp = pop_stack(s);
	if (!tmp)
		return ;
	unshift_stack(s, *tmp);
	write(1, "rra\n", 4);
}

void	exe_rrb(t_stack *s)
{
	int	*tmp;

	tmp = pop_stack(s);
	if (!tmp)
		return ;
	unshift_stack(s, *tmp);
	write(1, "rrb\n", 4);
}
