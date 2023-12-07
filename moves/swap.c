/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:47:42 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->previous = first;
	second->next = first;
	first->previous = NULL;
	second->previous = NULL;
	*stack = second;
}

void	sa(t_list **stack_a)
{
	swap (stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap (stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap (stack_a);
	swap (stack_b);
	ft_putendl_fd("ss", 1);
}

//first set to the first node and second set to the next from the first
//first next points to what the second next was pointing to, i.e. the third node
//the next for the second is now to the furst, which is now the second node
