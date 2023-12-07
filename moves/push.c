/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:15:37 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = temp;
	*stack_a = temp;
	temp->previous = NULL;
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = temp;
	*stack_b = temp;
	temp->previous = NULL;
	ft_putendl_fd("pb", 1);
}

//stack_a is updated to point(the next node) to what was the second node
//the next for temp is now updated to the old first node in stack_b
//*stack_b head now points to temp
