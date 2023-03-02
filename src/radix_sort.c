/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:32:56 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/28 05:07:37 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	smallest_index(t_stack *s)
{
	int		nbr;
	size_t	indx;
	size_t	n_indx;

	n_indx = 0;
	indx = 0;
	nbr = *get_stack(s, 0);
	while (indx < s->length)
	{
		if (nbr > *get_stack(s, indx))
		{
			n_indx = indx;
			nbr = *get_stack(s, indx);
		}
		indx++;
	}
	return (n_indx);
}

int	valid(t_stack *s, size_t sindx)
{
	size_t	indx;
	int		nbr;

	indx = 0;
	if (s->length != s->max_size)
		return (0);
	nbr = *get_stack(s, (sindx + indx) % s->length);
	while (indx < s->length)
	{
		if (nbr > *get_stack(s, (sindx + indx) % s->length))
			return (0);
		nbr = *get_stack(s, (sindx + indx) % s->length);
		indx++;
	}
	return (1);
}

int	radix(t_stack *sa, t_stack *sb, int ittr)
{
	size_t	indx;
	int		flag;

	indx = 0;
	flag = 0;
	while (indx < sa->max_size)
	{
		if (!(*get_stack(sa, 0) & (1 << ittr)))
		{
			exe_pb(sa, sb);
			flag = 1;
		}
		else
			exe_ra(sa);
		indx++;
	}
	return (flag);
}

void	sort_radix(t_stack *stack1, t_stack *stack2)
{
	size_t	small;
	size_t	indx;

	indx = 0;
	small = smallest_index(stack1);
	while (!valid(stack1, small) && indx < sizeof(int) * 8)
	{
		radix(stack1, stack2, indx);
		while (stack2->length)
			exe_pa(stack1, stack2);
		indx++;
		small = smallest_index(stack1);
	}
	while (!valid(stack1, 0))
		exe_rra(stack1);
}
