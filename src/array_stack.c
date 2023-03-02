/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:44:04 by tjukmong          #+#    #+#             */
/*   Updated: 2023/03/02 23:46:05 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_stack(t_stack *s)
{
	size_t	indx;

	indx = 0;
	while (indx < s->length)
	{
		if (!get_stack(s, indx))
			continue ;
		free(get_stack(s, indx));
		indx++;
	}
	free(s->data);
}

t_stack	*init_stack(t_stack *s, size_t max_size)
{
	size_t	indx;

	indx = 0;
	s->data = malloc(sizeof(int *) * (max_size));
	if (!s->data)
		return (NULL);
	while (indx < max_size)
	{
		s->data[indx] = NULL;
		indx++;
	}
	s->offset = 0;
	s->max_size = max_size;
	s->length = 0;
	return (s);
}

int	*push_stack(t_stack *s, int data)
{
	if (s->length > s->max_size - 1)
		return (NULL);
	if (!s->data[(s->offset + s->length) % s->max_size])
		s->data[(s->offset + s->length) % s->max_size] = malloc(sizeof(int));
	*s->data[(s->offset + s->length) % s->max_size] = data;
	s->length++;
	return (s->data[(s->offset + s->length) % s->max_size]);
}

int	*unshift_stack(t_stack *s, int data)
{
	if (s->length > s->max_size - 1)
		return (NULL);
	if (s->offset == 0)
		s->offset = s->max_size;
	s->offset--;
	if (!s->data[s->offset % s->max_size])
		s->data[s->offset % s->max_size] = malloc(sizeof(int));
	*s->data[s->offset % s->max_size] = data;
	s->length++;
	return (s->data[(s->offset + s->length) % s->max_size]);
}

int	*shift_stack(t_stack *s)
{
	static int	tmp;

	if (s->length == 0)
		return (NULL);
	tmp = *s->data[s->offset % s->max_size];
	free(s->data[s->offset % s->max_size]);
	s->data[s->offset % s->max_size] = NULL;
	s->offset++;
	if (s->offset > s->max_size - 1)
		s->offset = 0;
	s->length--;
	return (&tmp);
}
