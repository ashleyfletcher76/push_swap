/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:41:04 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:50 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first_node = *stack;
	last_node = ft_lstlast(*stack);
	*stack = first_node->next;
	(*stack)->previous = NULL;
	last_node->next = first_node;
	first_node->previous = last_node;
	first_node->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate (stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	rotate (stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
	ft_putendl_fd("rr", 1);
}

//checks if stack is empty or pointer to stack is empty
//first == first node
//look for last_node, assign value
//now assign *stack to point to the next node from the first_node, i.e 2nd node
//first node(which is now going to be last) points to NULL
