/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:15:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:30:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	find_min_num(t_list **stack)
{
	t_list	*current;
	int		min_num;
	int		num;

	if (!stack || !(*stack))
		return (INT_MAX);
	current = *stack;
	min_num = *(int *)(current->content);
	while (current != NULL)
	{
		num = *(int *)(current->content);
		if (num < min_num)
			min_num = num;
		current = current->next;
	}
	return (min_num);
}

int	find_max(t_list **stack)
{
	t_list	*current;
	int		max;
	int		num;

	if (!stack || !(*stack))
		return (INT_MAX);
	current = *stack;
	max = *(int *)(current->content);
	while (current != NULL)
	{
		num = *(int *)(current->content);
		if (num > max)
			max = num;
		current = current->next;
	}
	return (max);
}

int	find_index(t_list *stack, int num)
{
	t_list	*current;
	int		index;

	index = 0;
	current = stack;
	while (current != NULL)
	{
		if (*(int *)(current->content) == num)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}
