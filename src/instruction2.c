/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:44:41 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/20 23:52:30 by tjukmong         ###   ########.fr       */
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
}

void	exe_rb(t_stack *s)
{
	int	*tmp;

	tmp = shift_stack(s);
	if (!tmp)
		return ;
	push_stack(s, *tmp);
}

void	exe_rr(t_stack *sa, t_stack *sb)
{
	exe_ra(sa);
	exe_rb(sb);
}

void	exe_rra(t_stack *s)
{
	int	*tmp;

	tmp = pop_stack(s);
	if (!tmp)
		return ;
	unshift_stack(s, *tmp);
}

void	exe_rrb(t_stack *s)
{
	int	*tmp;

	tmp = pop_stack(s);
	if (!tmp)
		return ;
	unshift_stack(s, *tmp);
}
