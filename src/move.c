/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:51:57 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 13:03:53 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_first_push(t_stack **a, t_stack **b)
{
	ft_stack_p(b, a, "pb\n");
	ft_stack_p(b, a, "pb\n");
	if ((*b)->value < (*b)->next->value)
	{
		if ((*a)->value > (*b)->value && (*a)->value < (*b)->next->value)
		{
			ft_stack_r(b, "rb\n");
			ft_stack_p(b, a, "pb\n");
		}
		else
			ft_stack_p(b, a, "pb\n");
	}
	else if ((*b)->value > (*b)->next->value)
	{
		if ((*a)->value < (*b)->value && (*a)->value > (*b)->next->value)
			ft_stack_p(b, a, "pb\n");
		else
		{
			ft_stack_r(b, "rb\n");
			ft_stack_p(b, a, "pb\n");
		}
	}
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
