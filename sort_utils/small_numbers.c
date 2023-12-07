/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:51:04 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:30:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*head;

	while (!check_if_sorted(stack_a))
	{
		head = *stack_a;
		if (*(int *)head->content > *(int *)head->next->content
			&& *(int *)head->content < *(int *)head->next->next->content)
			sa(stack_a);
		else if (*(int *)head->content > *(int *)head->next->content
			&& *(int *)head->content > *(int *)head->next->next->content)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	min_num;
	int	nums_pushed;

	nums_pushed = 0;
	while (size > 3)
	{
		min_num = find_min_num(stack_a);
		move_min_to_top(stack_a, min_num);
		pb(stack_b, stack_a);
		size = ft_lstsize(*stack_a);
		nums_pushed++;
	}
	sort_three(stack_a);
	while (nums_pushed > 0)
	{
		pa(stack_a, stack_b);
		nums_pushed--;
	}
}

void	move_min_to_top(t_list **stack, int min_num)
{
	int		position;
	int		middle_stack;
	t_list	*current;

	position = find_index(*stack, min_num);
	middle_stack = ft_lstsize(*stack) / 2;
	current = *stack;
	while (*(int *)current->content != min_num)
	{
		if (position <= middle_stack)
			ra(stack);
		else
			rra(stack);
		current = (*stack);
	}
}
