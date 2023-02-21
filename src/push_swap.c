/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/22 04:01:39 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	valid(t_stack *s)
{
	size_t	indx;
	int		nbr;

	indx = 0;
	if (s->length != s->max_size || !get_stack(s, 0))
		return (0);
	nbr = *get_stack(s, 0);
	while (indx < s->length)
	{
		if (nbr > *get_stack(s, indx))
			return (0);
		nbr = *get_stack(s, indx);
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

char	*ft_recat(char **dst, char *str)
{
	size_t	dlen;
	size_t	slen;
	char	*tmp;

	dlen = 0;
	slen = 0;
	if (!str)
		return (*dst);
	if (!dst || *dst == NULL)
	{
		*dst = str;
		return (*dst);
	}
	dlen = ft_strlen(*dst);
	slen = ft_strlen(str);
	tmp = malloc(dlen + slen + 1);
	tmp[dlen + slen] = '\0';
	while (slen-- > 0)
		tmp[dlen + slen] = str[slen];
	free(str);
	while (dlen-- > 0)
		tmp[dlen] = (*dst)[dlen];
	free(*dst);
	*dst = tmp;
	return (*dst);
}

int	*parse_input(int argc, char **argv, size_t *len)
{
	size_t	indx;
	char	*args_raw;
	char	**args_arr;
	int		*args;

	indx = 1;
	args_raw = NULL;
	while (indx < argc)
	{
		ft_recat(&args_raw, ft_strdup(argv[indx]));
		ft_recat(&args_raw, ft_strdup(" "));
		indx++;
	}
	indx = 0;
	if (!args_raw)
	{
		free(args_raw);
		return (0);
	}
	args_arr = ft_split(args_raw, ' ');
	free(args_raw);
	if (!args_arr)
		return (0);
	while (args_arr[indx])
		indx++;
	args = malloc(sizeof(int) * indx);
	if (!args)
		return (0);
	*len = indx;
	while (indx--)
	{
		args[indx] = ft_atoi(args_arr[indx]);
		free(args_arr[indx]);
	}
	free(args_arr);
	return (args);
}

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
	init_stack(&stack1, len);
	init_stack(&stack2, len);
	indx = 0;
	while (len--)
	{
		push_stack(&stack1, args[indx]);
		indx++;
	}
	free(args);
	indx = 0;
	while (!valid(&stack1) && indx < sizeof(int) * 8)
	{
		radix(&stack1, &stack2, indx);
		while (stack2.length)
			exe_pa(&stack1, &stack2);
		indx++;
	}
	while (!valid(&stack1))
		exe_rra(&stack1);

	// for (int i = 0; i < stack1.max_size; i++)
	// {
	// 	int	*n = get_stack(&stack1, i);
	// 	int *n2 = get_stack(&stack2, i);
	// 	if (n)
	// 		printf("%-2d", *n);
	// 	else
	// 	 	printf("  ");
	// 	printf(" | ");
	// 	if (n2)
	// 		printf("%2d", *n2);
	// 	printf("\n");
	// }
	free_stack(&stack1);
	free_stack(&stack2);
	return (0);
}
