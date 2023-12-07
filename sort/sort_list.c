/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:51:30 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:10 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size >= 3 && size <= 10)
		small_sort(stack_a, stack_b, size);
	else if (size >= 11)
	{
		begin(stack_a, stack_b);
		pa(stack_a, stack_b);
		small_sort(stack_a, stack_b, ft_lstsize(*stack_a));
		begin_one(stack_a, stack_b);
		begin_two(stack_a, stack_b);
		sort_using_max(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_using_max(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		pos;
	int		middle;
	int		size;

	size = ft_lstsize(*stack_b);
	middle = size / 2;
	max = find_max(stack_b);
	while ((*stack_b)->next != NULL)
	{
		pos = find_index(*stack_b, max);
		if (*(int *)(*stack_b)->content == max)
		{
			pa(stack_a, stack_b);
			max = find_max(stack_b);
			size--;
			middle = size / 2;
		}
		else if (pos <= middle)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
