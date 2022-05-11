/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 10:14:20 by bvernimm         ###   ########.fr       */
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
	int	i;

	modify_move(move, 1, 0, count_r((*a)->value, b, 0, len));
	modify_move(move, 2, 0, count_rr((*a)->value, b, 0, len));
	i = 0;
	while (i < len)
	{
		if ((*move)->rb_cost > count_r((*a)->value, b, i, len))
			modify_move(move, 1, i, count_r((*a)->value, b, i, len));
		if ((*move)->rrb_cost > count_rr((*a)->value, b, i, len))
			modify_move(move, 2, i, count_rr((*a)->value, b, i, len));
		i++;
		if ((*a)->next)
			(*a) = (*a)->next;
	}
	printf("r cost : %d, place %d\nrr cost : %d, place %d\n", (*move)->rb_cost, (*move)->r_place, (*move)->rrb_cost, (*move)->rr_place);
	while ((*a)->previous)
		(*a) = (*a)->previous;
	calculate_best_move(a, b,len, move);
	printf("best place : %d, best in a : %d and best in b : %d\n", (*move)->best_place, (*move)->best_in_a, (*move)->best_in_b);
	//push_to_b(a, b, len, move);
}

void	calculate_best_move(t_stack **a, t_stack **b, int len, t_cost	**move)
{
	if ((*move)->rb_cost <= (*move)->rrb_cost)
	{
		(*move)->best_place = (*move)->r_place;
		(*move)->best_in_b = count_r((*a)->value, b, 0, 1);
		if ((*move)->r_place > len / 2)
			(*move)->best_in_a = (len - (*move)->r_place) * -1;
		else
			(*move)->best_in_a = (*move)->r_place;
	}
	else if ((*move)->rb_cost > (*move)->rrb_cost)
	{
		(*move)->best_place = (*move)->rr_place;
		(*move)->best_in_b = count_rr((*a)->value, b, 0, 1) * -1;
		if ((*move)->rr_place > len / 2)
			(*move)->best_in_a = (len - (*move)->rr_place) * -1;
		else
			(*move)->best_in_a = (*move)->rr_place;
	}
}

/*void	push_to_b(t_stack **a, t_stack **b, int len, t_cost	**move)
{
	//print_stack(*a);
	if ((*move)->rb_cost <= (*move)->rrb_cost)
	{
		if ((*move)->r_place <= len /2)
		{
			while ((*move)->r_place > 0)
			{
				ft_stack_r(a, "ra\n");
				(*move)->r_place--;
			}
		}
		else if ((*move)->r_place > len /2)
		{
			while ((*move)->r_place < len)
			{
				ft_stack_rr(a, "rra\n");
				(*move)->r_place++;
			}
		}
	}
	//ft_stack_r(a, "ra\n");
	//ft_stack_r(a, "ra\n");
	//print_stack(*a);
}*/
