/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_phase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:26:56 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	begin_two(t_list **stack_a, t_list **stack_b)
{
	int		pivot;
	t_list	*dup;

	if (check_if_sorted(stack_a))
		return ;
	dup = dup_unsorted_nbrs(*stack_a);
	pivot = get_pivots_three(&dup);
	ft_lstclear(&dup, del);
	sort_two(stack_a, stack_b, pivot);
	begin_two(stack_a, stack_b);
}

void	sort_two(t_list **stack_a, t_list **stack_b, int pivot)
{
	while (check_pivs_first(*stack_a, pivot))
	{
		if (*(int *)(*stack_a)->content <= pivot)
			pb(stack_b, stack_a);
		else if (calculate_two(stack_a, pivot) > 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	calculate_two(t_list **stack, int pivot)
{
	t_list	*head;
	t_list	*tail;
	int		ra_count;
	int		rra_count;

	ra_count = 0;
	rra_count = 0;
	head = *stack;
	tail = ft_lstlast(*stack);
	while (head && *(int *)head->content > pivot)
	{
		ra_count++;
		head = head->next;
	}
	while (tail && *(int *)tail->content > pivot)
	{
		rra_count++;
		tail = tail->previous;
	}
	if (ra_count <= rra_count)
		return (1);
	else
		return (-1);
}
