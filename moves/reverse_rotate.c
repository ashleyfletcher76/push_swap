/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:36:48 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:31:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*before_last;
	t_list	*last_node;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last_node = ft_lstlast(*stack);
	before_last = before_lst_last(*stack);
	if (before_last)
		before_last->next = NULL;
	else
		return ;
	last_node->next = *stack;
	(*stack)->previous = last_node;
	*stack = last_node;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}

t_list	*before_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
