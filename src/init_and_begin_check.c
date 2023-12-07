/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_begin_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:31:57 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	init_and_check_stacks(int argc, char **str, t_list **stack_a)
{
	char	**numbers;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(str[i], ' ');
		if (!numbers)
			print_error("Error");
		i++;
		j = 0;
		while (numbers[j])
		{
			init_stacks(stack_a, numbers[j]);
			free (numbers[j]);
			j++;
		}
		free (numbers);
	}
	if (check_if_duplicated(*stack_a))
	{
		ft_lstclear(stack_a, del);
		print_error("Error");
	}
}

void	init_stacks(t_list **stack_a, char *str)
{
	t_list	*new_node;
	int		*value;

	value = malloc(sizeof(int));
	if (!value)
		print_error("Error");
	if (!validate_num(str))
	{
		free(value);
		print_error("Error");
	}
	*value = ft_atoi(str);
	new_node = ft_lstnew(value);
	if (!new_node)
	{
		free (value);
		ft_lstclear(stack_a, del);
		return ;
	}
	ft_lstadd_back(stack_a, new_node);
}
