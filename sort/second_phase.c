/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:02 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:01 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	begin_one(t_list **stack_a, t_list **stack_b)
{
	int		pivot;
	t_list	*dup;

	if (ft_lstsize(*stack_b) < 30)
		return ;
	dup = dup_unsorted_nbrs(*stack_b);
	pivot = get_pivots_two(&dup);
	ft_lstclear(&dup, del);
	sort_one(stack_a, stack_b, pivot);
	begin_one(stack_a, stack_b);
}

void	sort_one(t_list **stack_a, t_list **stack_b, int pivot)
{
	while (check_pivs_two(*stack_b, pivot))
	{
		if (*(int *)(*stack_b)->content >= pivot)
			pa(stack_a, stack_b);
		else if (calculate_one(stack_b, pivot) > 0)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int	calculate_one(t_list **stack, int pivot)
{
	t_list	*head;
	t_list	*tail;
	int		rb_count;
	int		rrb_count;

	rb_count = 0;
	rrb_count = 0;
	head = *stack;
	tail = ft_lstlast(*stack);
	while (head && *(int *)head->content < pivot)
	{
		rb_count++;
		head = head->next;
	}
	while (tail && *(int *)tail->content < pivot)
	{
		rrb_count++;
		tail = tail->previous;
	}
	if (rb_count <= rrb_count)
		return (1);
	else
		return (-1);
}

bool	check_pivs_two(t_list *stack_b, int pivot)
{
	t_list	*head;

	head = (stack_b);
	while (head != NULL)
	{
		if (*(int *)head->content >= pivot)
			return (true);
		head = head->next;
	}
	return (false);
}
