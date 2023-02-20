/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/20 23:01:37 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		nbr;
	t_stack	stack1;
	t_stack	stack2;

	if (argc < 2)
		return (0);
	init_stack(&stack1, argc - 1);
	init_stack(&stack2, argc - 1);

	for (int i = 1; i < argc; i++) {
		push_stack(&stack1, ft_atoi(argv[i]));
	}

	for (int i = 0; i < stack1.max_size; i++)
	{
		int	*n = get_stack(&stack1, i);
		int *n2 = get_stack(&stack2, i);
		if (n)
			printf("%4d", *n);
		printf(" | ");
		if (n2)
			printf("%4d", *n2);
		printf("\n");
	}
	free(stack1.data);
	return (0);
}