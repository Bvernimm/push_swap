/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/10 15:35:03 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rr(int nb, t_stack **stack_b)
{
	t_stack	*tmp;
	int		rr_cost;

	rr_cost = 2;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1);
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
		return (1);
	return (rr_cost);
}

int	count_r(int nb, t_stack **stack_b)
{
	t_stack	*tmp;
	int		r_cost;

	r_cost = 2;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (1);
	tmp = (*stack_b);
	while (tmp->next)
	{
		if (tmp->value < nb && tmp->next->value > nb)
			break ;
		r_cost++;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return (1);
	return (r_cost);
}

void	modify_move(t_cost **move, int r, int place, int cost)
{
	if (r == 1)
	{
		(*move)->rb_cost = cost;
		(*move)->r_place = place;
	}
	else if (r == 2)
	{
		(*move)->rrb_cost = cost;
		(*move)->rr_place = place;
	}
}

void	sort_100(t_stack **a, t_stack **b, int len, t_cost	**move)
{
	modify_move(move, 1, 0, count_r((*a)->value, b));
	modify_move(move, 2, 0, count_rr((*a)->value, b));
	(*move)->ra_cost = 0;
	while ((*move)->ra_cost < len - 1)
	{
		if ((*move)->rb_cost > count_r((*a)->value, b) + (*move)->ra_cost)
			modify_move(move, 1, (*move)->ra_cost, count_r((*a)->value, b));
		if ((*move)->rrb_cost > count_rr((*a)->value, b) + (*move)->ra_cost)
			modify_move(move, 2, (*move)->ra_cost, count_rr((*a)->value, b));
		(*move)->ra_cost++;
		if ((*a)->next)
			(*a) = (*a)->next;
	}
	printf("r cost : %d, place %d\nrr cost : %d, place %d\n", (*move)->rb_cost, (*move)->r_place, (*move)->rrb_cost, (*move)->rr_place);
}
