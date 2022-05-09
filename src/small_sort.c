/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:55:51 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/09 14:15:13 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 5)
		sort_5(stack_a, stack_b);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 2)
		write (1, "sa\n", 3);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		smallest;

	smallest = stack_min(a);
	if (smallest == 2)
		ft_stack_s(a, "sa\n");
	else if (smallest == 3)
	{
		ft_stack_r(a, "ra\n");
		ft_stack_r(a, "ra\n");
	}
	else if (smallest == 4)
	{
		ft_stack_rr(a, "rra\n");
		ft_stack_rr(a, "rra\n");
	}
	else if (smallest == 5)
		ft_stack_rr(a, "rra\n");
	if (stack_is_sorted(*a) != 0)
	{
		ft_stack_p(b, a, "pb\n");
		sort_4(a, b);
		write (1, "pa\n", 3);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int		smallest;

	smallest = stack_min(a);
	if (smallest == 2)
		ft_stack_s(a, "sa\n");
	else if (smallest == 3)
	{
		ft_stack_rr(a, "rra\n");
		ft_stack_rr(a, "rra\n");
	}
	else if (smallest == 4)
		ft_stack_rr(a, "rra\n");
	if (stack_is_sorted(*a) != 0)
	{
		ft_stack_p(b, a, "pb\n");
		sort_3(a);
		write (1, "pa\n", 3);
		free_stack(b);
	}
}

void	sort_3(t_stack **a)
{
	int		smallest;
	int		biggest;

	smallest = stack_min(a);
	biggest = stack_max(a);
	ft_3_case(smallest, biggest);
}

void	ft_3_case(int smallest, int biggest)
{
	if (smallest == 2 && biggest == 3)
		write (1, "sa\n", 3);
	if (smallest == 3 && biggest == 1)
		write (1, "sa\nrra\n", 7);
	if (smallest == 2 && biggest == 1)
		write (1, "ra\n", 3);
	if (smallest == 1 && biggest == 2)
		write (1, "sa\nra\n", 6);
	if (smallest == 3 && biggest == 2)
		write (1, "rra\n", 4);
}
