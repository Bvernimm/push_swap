/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:07:50 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 11:08:27 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rr(int nb, t_stack **stack_b, int ra, int len)
{
	t_stack	*tmp;
	int		rr_cost;

	if (ra > len / 2)
		ra = len - ra;
	rr_cost = 2;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1 + ra);
	tmp = (*stack_b);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->previous)
	{
		if (tmp->value > nb && tmp->previous->value < nb)
			break ;
		rr_cost++;
		tmp = tmp->previous;
	}
	if (!tmp->previous)
		return (1 + ra);
	return (rr_cost + ra);
}

int	count_r(int nb, t_stack **stack_b, int ra, int len)
{
	t_stack	*tmp;
	int		r_cost;

	if (ra > len / 2)
		ra = len - ra;
	r_cost = 2;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1 + ra);
	tmp = (*stack_b);
	while (tmp->next)
	{
		if (tmp->value < nb && tmp->next->value > nb)
			break ;
		r_cost++;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return (1 + ra);
	return (r_cost + ra);
}

void	calculate_best_move(t_stack **b, int len, t_cost	**move)
{
	if ((*move)->rb_cost <= (*move)->rrb_cost)
	{
		(*move)->best_place = (*move)->r_place;
		(*move)->best_in_b = count_r((*move)->r_value, b, 0, 5) - 1;
		if ((*move)->r_place > len / 2)
			(*move)->best_in_a = (len - (*move)->r_place) * -1;
		else
			(*move)->best_in_a = (*move)->r_place;
	}
	else if ((*move)->rb_cost > (*move)->rrb_cost)
	{
		(*move)->best_place = (*move)->rr_place;
		(*move)->best_in_b = (count_rr((*move)->rr_value, b, 0, 6) - 1) * -1;
		if ((*move)->rr_place > len / 2)
			(*move)->best_in_a = (len - (*move)->rr_place) * -1;
		else
			(*move)->best_in_a = (*move)->rr_place;
	}
}
