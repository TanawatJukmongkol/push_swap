/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/03/02 23:42:36 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*args;
	size_t	indx;
	size_t	len;
	t_stack	stack1;
	t_stack	stack2;

	if (argc < 2)
		return (0);
	args = parse_input(argc, argv, &len);
	if (!args)
		return (0);
	init_stack(&stack1, len);
	init_stack(&stack2, len);
	indx = 0;
	while (len--)
	{
		push_stack(&stack1, args[indx]);
		indx++;
	}
	free(args);
	sort_radix(&stack1, &stack2);
	free_stack(&stack1);
	free_stack(&stack2);
	return (0);
}
