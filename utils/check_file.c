/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:33:59 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:35 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	validate_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (ft_strncmp(str, "0", 1) == 0)
		return (1);
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num == 0)
	{
		print_error("Error");
		return (0);
	}
	return (1);
}

int	check_if_duplicated(t_list *first_node)
{
	t_list	*current;
	t_list	*checker;

	current = first_node;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->content == NULL || checker->content == NULL)
			{
				checker = checker->next;
				continue ;
			}
			if (*(int *)(current->content) == *(int *)(checker->content))
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
