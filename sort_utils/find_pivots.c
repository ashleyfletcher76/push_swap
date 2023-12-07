/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:52:22 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:30:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_pivots_one(t_list **stack)
{
	return (get_value(*stack, ft_lstsize(*stack) / 2));
}

int	get_pivots_two(t_list **stack)
{
	return (get_value(*stack, ft_lstsize(*stack) / 5));
}

int	get_pivots_three(t_list **stack)
{
	return (get_value(*stack, ft_lstsize(*stack) / 15));
}

int	get_value(t_list *head, int n)
{
	while (n-- > 0 && head)
		head = head->next;
	return ((*(int *)head->content));
}
