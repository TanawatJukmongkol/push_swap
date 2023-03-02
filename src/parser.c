/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:36:51 by tjukmong          #+#    #+#             */
/*   Updated: 2023/03/03 05:41:05 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error_out(void *mem, void **mem2d)
{
	size_t	i;

	i = 0;
	while (mem2d != NULL && mem2d[i] != NULL)
	{
		free(mem2d[i]);
		i++;
	}
	if (mem2d != NULL)
		free(mem2d);
	if (mem != NULL)
		free(mem);
	write(2, "Error\n", 6);
	exit(0xff);
}

char	**parse_args(int argc, char **argv)
{
	size_t	indx;
	char	*args_raw;
	char	**args_arr;

	indx = 1;
	args_raw = NULL;
	while (indx < argc)
	{
		if (!ft_recat(&args_raw, ft_strdup(argv[indx])))
			error_out(args_raw, NULL);
		if (!ft_recat(&args_raw, ft_strdup(" ")))
			error_out(args_raw, NULL);
		indx++;
	}
	args_arr = ft_split(args_raw, ' ');
	if (args_arr[0] == NULL)
		error_out(args_raw, NULL);
	free(args_raw);
	return (args_arr);
}

size_t	check_invalid_int(char **args_arr)
{
	size_t	indx;
	size_t	n;

	indx = 0;
	while (args_arr[indx])
	{
		n = 0;
		while (args_arr[indx][n])
		{
			if (args_arr[indx][n] == '\t')
				args_arr[indx][n] = ' ';
			if (n == 0 && (args_arr[indx][n] == '+'
				|| args_arr[indx][n] == '-') && n++)
				continue ;
			if (!ft_isdigit(args_arr[indx][n]))
				error_out(NULL, (void **)args_arr);
			n++;
		}
		indx++;
	}
	indx = 0;
	while (args_arr[indx])
		if (ft_strlen(args_arr[indx++]) > 11)
			error_out(NULL, (void **)args_arr);
	return (indx);
}

void	check_double(int *args, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 1)
		return ;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (args[i] == args[j])
				error_out(args, NULL);
			j++;
		}
		i++;
	}
}

int	*parse_input(int argc, char **argv, size_t *len)
{
	size_t	arr_len;
	long	nbr;
	int		*args;
	char	**args_arr;

	args_arr = parse_args(argc, argv);
	arr_len = check_invalid_int(args_arr);
	if (!args_arr)
		return (0);
	args = malloc(sizeof(int) * arr_len);
	if (!args)
		return (0);
	*len = arr_len;
	while (arr_len--)
	{
		nbr = ft_atol(args_arr[arr_len]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_out(NULL, (void **)args_arr);
		args[arr_len] = nbr;
		free(args_arr[arr_len]);
	}
	free(args_arr);
	check_double(args, *len);
	return (args);
}
