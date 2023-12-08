/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:31:19 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/08 14:18:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

int		main(int argc, char **argv);

void	init_and_check_stacks(int argc, char **str, t_list **stack_a);
void	init_stacks(t_list **stack_a, char *str);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
t_list	*before_lst_last(t_list *lst);

int		check_if_sorted(t_list **stack);
void	sort_list(t_list **stack_a, t_list **stack_b);

int		get_pivots_one(t_list **stack);
int		get_pivots_two(t_list **stack);
int		get_pivots_three(t_list **stack);
int		get_value(t_list *head, int n);

int		find_index(t_list *stack, int min_num);
int		find_min_num(t_list **stack);
int		find_max(t_list **stack);

void	sort_three(t_list **stack_a);
void	small_sort(t_list **stack_a, t_list **stack_b, int size);
void	move_min_to_top(t_list **stack, int min_num);
void	sort_using_max(t_list **stack_a, t_list **stack_b);

void	begin(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b, int pivot);
bool	check_pivs_first(t_list *stack_a, int pivot);

void	begin_one(t_list **stack_a, t_list **stack_b);
void	sort_one(t_list **stack_a, t_list **stack_b, int pivot);
int		calculate_one(t_list **stack, int pivot);
bool	check_pivs_two(t_list *stack_b, int pivot);

void	begin_two(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack_a, t_list **stack_b, int pivot);
int		calculate_two(t_list **stack, int max);

t_list	*dup_stack(t_list **stack);
void	organise_temp_stack(t_list **stack);
void	helper_swapper(t_list *first, t_list *second);
t_list	*find_unsorted(t_list *stack);
t_list	*dup_unsorted_nbrs(t_list *stack);

int		validate_num(char *str);
int		check_if_duplicated(t_list *first_node);

void	print_error(char *str);
void	del(void *content);
void	my_free(char **str);

#endif
