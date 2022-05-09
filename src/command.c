/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commanc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:52:26 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/09 11:31:00 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_s(t_stack **a, char *command)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	(*a)->previous = NULL;
	tmp->previous = (*a);
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = tmp->next;
	tmp->previous = (*a)->next;
	write (1, command, ft_strlen(command));
}

void	ft_stack_r(t_stack **a, char *command)
{
	t_stack	*last;

	last = (*a);
	while (last->next)
		last = last->next;
	last->next = (*a);
	(*a)->previous = last;
	last = (*a)->next;
	last->previous = NULL;
	(*a)->next = NULL;
	while ((*a)->previous)
		(*a) = (*a)->previous;
	write (1, command, ft_strlen(command));
}

void	ft_stack_rr(t_stack **a, char *command)
{
	t_stack	*last;

	last = (*a);
	while (last->next)
		last = last->next;
	last->next = (*a);
	(*a)->previous = last;
	(*a) = last;
	last = (*a)->previous;
	last->next = NULL;
	(*a)->previous = NULL;
	write (1, command, ft_strlen(command));
}

void	ft_stack_p(t_stack **dest, t_stack **src, char *command)
{
	t_stack	*tmp;

	tmp = (*src);
	(*src) = (*src)->next;
	(*src)->previous = NULL;
	tmp->previous = NULL;
	tmp->next = (*dest);
	if ((*dest) != NULL)
		(*dest)->previous = tmp;
	(*dest) = tmp;
	write (1, command, ft_strlen(command));
}
