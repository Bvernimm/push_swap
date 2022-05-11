/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:57:49 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 14:54:11 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	tmp = *stack;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	get_val(t_stack **stack, int pos)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (pos > 1)
	{
		tmp = tmp->next;
		pos--;
	}
	return (tmp->value);
}

int	stack_min(t_stack **stack)
{
	int		ret;
	int		i;
	int		smallest;
	t_stack	*tmp;

	tmp = (*stack);
	smallest = tmp->value;
	ret = 1;
	i = 1;
	while (tmp)
	{
		if (smallest > tmp->value)
		{
			smallest = tmp->value;
			ret = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (ret);
}

int	stack_max(t_stack **stack)
{
	int		ret;
	int		i;
	int		biggest;
	t_stack	*tmp;

	tmp = (*stack);
	biggest = tmp->value;
	ret = 1;
	i = 1;
	while (tmp)
	{
		if (biggest < tmp->value)
		{
			biggest = tmp->value;
			ret = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (ret);
}
