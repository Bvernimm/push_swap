/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 11:12:25 by bvernimm         ###   ########.fr       */
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
	printf("r cost : %d, place %d, value %d\n", (*move)->rb_cost, (*move)->r_place, (*move)->r_value);
	printf("rr cost : %d, place %d, value %d\n", (*move)->rrb_cost, (*move)->rr_place, (*move)->rr_value);
	while ((*a)->previous)
		(*a) = (*a)->previous;
	calculate_best_move(b, len, move);
	printf("best place : %d, best in a : %d and best in b : %d\n", (*move)->best_place, (*move)->best_in_a, (*move)->best_in_b);
	push_to_b(a, b, move);
}

void	push_to_b(t_stack **a, t_stack **b, t_cost	**move)
{
	while ((*move)->best_in_a > 0 && (*move)->best_in_b > 0)
	{
		ft_stack_2(a, b, "rr\n");
		(*move)->best_in_a--;
		(*move)->best_in_b--;
	}
	while ((*move)->best_in_a < 0 && (*move)->best_in_b < 0)
	{
		ft_stack_2(a, b, "rrr\n");
		(*move)->best_in_a++;
		(*move)->best_in_b++;
	}
	push_to_b_bis(a, b, move);
}

void	push_to_b_bis(t_stack **a, t_stack **b, t_cost	**move)
{
	while ((*move)->best_in_a > 0)
	{
		ft_stack_r(a, "ra\n");
		(*move)->best_in_a--;
	}
	while ((*move)->best_in_b > 0)
	{
		ft_stack_r(b, "rb\n");
		(*move)->best_in_b--;
	}
	while ((*move)->best_in_a < 0)
	{
		ft_stack_rr(a, "rra\n");
		(*move)->best_in_a++;
	}
	while ((*move)->best_in_b < 0)
	{
		ft_stack_rr(b, "rrb\n");
		(*move)->best_in_b++;
	}
	ft_stack_p(b, a, "pb\n");
}
