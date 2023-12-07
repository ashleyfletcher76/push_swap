/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:52:05 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:30:08 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_if_sorted(t_list **stack)
{
	t_list	*current_node;
	int		last_num;

	if (!stack || !(*stack) || !((*stack)->next))
		return (1);
	current_node = *stack;
	last_num = *(int *)(current_node->content);
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		if (*(int *)(current_node->content) < last_num)
			return (0);
		last_num = *(int *)(current_node->content);
	}
	return (1);
}
