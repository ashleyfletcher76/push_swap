/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:39:16 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	init_and_check_stacks(argc, argv, &stack_a);
	if (check_if_sorted(&stack_a) == 1)
	{
		ft_lstclear(&stack_a, del);
		return (0);
	}
	sort_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	return (0);
}
