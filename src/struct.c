/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:15:11 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 13:58:22 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_stack **stack, char **argv)
{
	int	i;

	(*stack) = malloc(sizeof(t_stack));
	if (!(*stack))
		ft_error("malloc error\n");
	(*stack)->previous = NULL;
	(*stack)->value = ft_atoi(argv[1]);
	(*stack)->next = NULL;
	i = 2;
	while (argv[i])
	{
		ft_lstadd_back(stack, ft_atoi(argv[i]));
		(*stack) = (*stack)->next;
		i++;
	}
	while ((*stack)->previous)
		(*stack) = (*stack)->previous;
}

void	ft_lstadd_back(t_stack **stack_a, int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(stack_a);
		ft_error("malloc error\n");
	}
	(*stack_a)->next = new;
	new->previous = (*stack_a);
	new->value = nb;
	new->next = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack)->previous)
		(*stack) = (*stack)->previous;
	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		tmp->value = 0;
		free(tmp);
	}
}
