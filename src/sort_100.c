/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/10 15:12:02 by bvernimm         ###   ########.fr       */
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
		if (tmp->value > nb && tmp->previous->value < nb)
			break ;
		rr_cost++;
		tmp = tmp->previous;
	}
	if (!tmp->previous)
		return (1);
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
		if (tmp->value < nb && tmp->next->value > nb)
			break ;
		r_cost++;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return (1);
	return (r_cost);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		i;
	t_stack	*tmp;
	t_cost	*move;

	move = malloc(sizeof(t_cost));
	tmp = (*stack_a);
	printf("pushing %d on %d\n", tmp->value, (*stack_b)->value);
	move->r_cost = calculate_r_cost(tmp->value, stack_b);
	move->rr_cost = calculate_rr_cost(tmp->value, stack_b);
	move->r_place = 0;
	move->rr_place = 0;
	i = 0;
	while (i < len - 1)
	{
		if (move->r_cost > calculate_r_cost(tmp->value, stack_b) + i)
		{
			move->r_cost = calculate_r_cost(tmp->value, stack_b) + i;
			move->r_place = i;
		}
		if (move->rr_cost > calculate_rr_cost(tmp->value, stack_b) + i)
		{
			move->rr_cost = calculate_rr_cost(tmp->value, stack_b) + i;
			move->rr_place = i;
		}
		i++;
		if (tmp->next)
			tmp = tmp->next;
	}
	printf("r cost : %d, place %d\nrr cost : %d, place %d\n", move->r_cost, move->r_place, move->rr_cost, move->rr_place);
}
