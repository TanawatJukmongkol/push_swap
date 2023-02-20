/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:52:24 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/20 23:53:00 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pop_stack(t_stack *s)
{
	static int	tmp;

	if (s->length == 0)
		return (NULL);
	free(s->data[(s->offset + s->length - 1) % s->max_size]);
	tmp = *s->data[(s->offset + s->length - 1) % s->max_size];
	s->data[(s->offset + s->length - 1) % s->max_size] = NULL;
	s->length--;
	return (&tmp);
}

int	*get_stack(t_stack *s, size_t indx)
{
	return (s->data[(s->offset + indx) % s->max_size]);
}

void	set_stack(t_stack *s, size_t indx, int value)
{
	s->data[(s->offset + indx) % s->max_size] = &value;
}

// Added rrr here, because not enough space.

void	exe_rrr(t_stack *sa, t_stack *sb)
{
	exe_rra(sa);
	exe_rrb(sb);
}
