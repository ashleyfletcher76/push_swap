/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_phase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:26 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:30:52 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	begin(t_list **stack_a, t_list **stack_b)
{
	int		pivot;
	t_list	*dup;

	dup = dup_stack(stack_a);
	pivot = get_pivots_one(&dup);
	ft_lstclear(&dup, del);
	sort(stack_a, stack_b, pivot);
	if (ft_lstsize(*stack_a) < 15)
		return ;
	begin(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*current;

	current = *stack_a;
	while (current != NULL && check_pivs_first(*stack_a, pivot))
	{
		if (*(int *)current->content <= pivot)
		{
			pb(stack_b, stack_a);
			current = *stack_a;
		}
		else
			ra(stack_a);
		current = *stack_a;
	}
}

bool	check_pivs_first(t_list *stack_a, int pivot)
{
	t_list	*head;

	head = (stack_a);
	while (head != NULL)
	{
		if (*(int *)head->content <= pivot)
			return (true);
		head = head->next;
	}
	return (false);
}
