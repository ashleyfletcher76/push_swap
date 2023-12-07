/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:15:55 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*dup_stack(t_list **stack)
{
	t_list	*head;
	t_list	*stack_temp;
	t_list	*new_node;
	int		*copied_content;

	head = *stack;
	stack_temp = NULL;
	while (head != NULL)
	{
		copied_content = malloc(sizeof(int));
		if (!copied_content)
			print_error("Error");
		*copied_content = *(int *)(head->content);
		new_node = ft_lstnew(copied_content);
		ft_lstadd_back(&stack_temp, new_node);
		head = head->next;
	}
	organise_temp_stack(&stack_temp);
	return (stack_temp);
}

void	organise_temp_stack(t_list **stack)
{
	t_list	*current;
	t_list	*min;
	t_list	*head;

	head = *stack;
	while ((head)->next)
	{
		min = head;
		current = (head)->next;
		while (current)
		{
			if (*(int *)current->content < *(int *)min->content)
				min = current;
			current = current->next;
		}
		helper_swapper(head, min);
		head = (head)->next;
	}
}

void	helper_swapper(t_list *first, t_list *second)
{
	int	temp_value;

	temp_value = *(int *)first->content;
	*(int *)first->content = *(int *)second->content;
	*(int *)second->content = temp_value;
}

t_list	*find_unsorted(t_list *stack)
{
	int	last_num;

	last_num = INT_MAX;
	while (stack != NULL && *(int *)(stack->content) <= last_num)
	{
		last_num = *(int *)(stack->content);
		stack = stack->next;
	}
	return (stack);
}

t_list	*dup_unsorted_nbrs(t_list *stack)
{
	t_list	*start_of_unsorted;

	start_of_unsorted = find_unsorted(stack);
	return (dup_stack(&start_of_unsorted));
}
