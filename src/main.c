/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:50:32 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/10 11:50:14 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	(void)str;
	write (2, "Error\n", 6);
	exit (0);
}

int	stack_is_sorted(t_stack *stack)
{
	int		i;
	t_stack	*next;

	i = 0;
	next = stack->next;
	while (next)
	{
		if (stack->value > next->value)
			return (1);
		i++;
		stack = stack->next;
		next = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_arg(argv);
	make_stack(&stack_a, argv);
	stack_b = NULL;
	argc--;
	printf("r :%d et rr : %d\n", calculate_r_cost(3, &stack_a), calculate_rr_cost(3, &stack_a));
	/*if (stack_is_sorted(stack_a) != 0)
	{
		if (argc <= 5)
			small_sort(&stack_a, &stack_b, argc);
		else if (argc <= 100)
			sort_100(&stack_a, &stack_b, argc);
		else
			big_sort(&stack_a, &stack_b, argc);
	}*/
	free_stack(&stack_a);
	return (0);
}
