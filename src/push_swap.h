/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:53:36 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/20 21:38:59 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../lib/libft/libft.h"

// array stack methods
typedef struct s_stack
{
	int		**data;
	size_t	offset;
	size_t	max_size;
	size_t	length;
}				t_stack;

// Stack implementation
t_stack	*init_stack(t_stack *s, size_t max_size);
int		*push_stack(t_stack *s, int value);
int		*unshift_stack(t_stack *s, int value);
int		*pop_stack(t_stack *s);
int		*shift_stack(t_stack *s);
int		*get_stack(t_stack *s, size_t indx);
void	set_stack(t_stack *s, size_t indx, int value);
void	swap_stack(t_stack *s, size_t indx1, size_t indx2);

// Instruction
void	exe_sa(t_stack *s);
void	exe_sb(t_stack *s);
void	exe_ss(t_stack *sa, t_stack *sb);
void	exe_pa(t_stack *sa, t_stack *sb);
void	exe_pb(t_stack *sa, t_stack *sb);
void	exe_ra(t_stack *s);
void	exe_rb(t_stack *s);
void	exe_rr(t_stack *sa, t_stack *sb);
void	exe_rra(t_stack *s);
void	exe_rrb(t_stack *s);
void	exe_rrr(t_stack *sa, t_stack *sb);

#endif