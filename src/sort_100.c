/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/10 11:54:36 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rr_cost(int nb, t_stack **stack_b)
{
	t_stack	*tmp;
	int		rr_cost;

	rr_cost = 2;
	if (!stack_b || !(*stack_b)->next)
		return (1);
	tmp = (*stack_b);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->previous)
	{
		if (tmp->value < nb && tmp->previous->value > nb)
			break ;
		rr_cost++;
		tmp = tmp->previous;
	}
	return (rr_cost);
}

int	calculate_r_cost(int nb, t_stack **stack_b)
{
	t_stack	*tmp;
	int		r_cost;

	r_cost = 2;
	if (!stack_b || !(*stack_b)->next)
		return (1);
	tmp = (*stack_b);
	while (tmp->next)
	{
		if (tmp->value > nb && tmp->next->value < nb)
			break ;
		r_cost++;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return (1);
	return (r_cost);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	r_cost;
	int	rr_cost;

	r_cost = calculate_r_cost((*stack_a)->value, stack_b);
	rr_cost = calculate_rr_cost((*stack_a)->value, stack_b);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	cost;
	int	min;
	int	i;
	int	pos;

	min = calculate_cost((*stack_a)->value, stack_b);
	i = 1;
	pos = 1;
	while (i < len)
	{
		cost = calculate_cost((*stack_a)->value, stack_b) + i;
		if (min > cost)
		{
			pos = i;
			min = cost;
		}
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	move_to_b(stack_a, stack_b, pos);
	sort_100(stack_a, stack_b, len - 1);
}
