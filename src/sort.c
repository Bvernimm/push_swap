/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/12 11:26:14 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	modify_move(t_cost **move, int value, int place, int cost)
{
	if (cost < 0)
	{
		(*move)->rb_cost = -1 * cost;
		(*move)->r_place = place;
		(*move)->r_value = value;
	}
	else if (cost > 0)
	{
		(*move)->rrb_cost = cost;
		(*move)->rr_place = place;
		(*move)->rr_value = value;
	}
}

void	sort_100(t_stack **a, t_stack **b, int len, t_cost	**move)
{
	int	i;

	modify_move(move, (*a)->value, 0, -1 * count_r((*a)->value, b, 0, len));
	modify_move(move, (*a)->value, 0, count_rr((*a)->value, b, 0, len));
	i = 0;
	while (i < len)
	{
		if ((*move)->rb_cost > count_r((*a)->value, b, i, len))
			modify_move(move, (*a)->value, i, -count_r((*a)->value, b, i, len));
		if ((*move)->rrb_cost > count_rr((*a)->value, b, i, len))
			modify_move(move, (*a)->value, i, count_rr((*a)->value, b, i, len));
		i++;
		if ((*a)->next)
			(*a) = (*a)->next;
	}
	while ((*a)->previous)
		(*a) = (*a)->previous;
	calculate_best_move(b, len, move);
	push_to_b(a, b, move);
	if ((*a))
		sort_100(a, b, len - 1, move);
	else
		back_to_a(a, b);
}
