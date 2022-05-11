/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:50:32 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 11:05:10 by bvernimm         ###   ########.fr       */
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
	t_cost	*move;

	move = malloc(sizeof(t_cost));
	if (!move)
		ft_error("malloc error\n");
	check_arg(argv);
	make_stack(&stack_a, argv);
	stack_b = NULL;
	argc--;
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	ft_stack_p(&stack_b, &stack_a, "pb\n");
	print_stack(stack_a);
	printf(" -- \n");
	print_stack(stack_b);
	//print_stack(stack_a);
	//printf("\nr :%d et rr : %d\n", calculate_r_cost(11, &stack_a), calculate_rr_cost(11, &stack_a));
	if (stack_is_sorted(stack_a) != 0)
	{
		if (argc <= 5)
			small_sort(&stack_a, &stack_b, argc);
		else if (argc <= 100)
			sort_100(&stack_a, &stack_b, argc - 5, &move);
			//sort_100(&stack_a, &stack_b, argc, &move);
	}
	printf(" result : \n");
	print_stack(stack_a);
	printf(" -- \n");
	print_stack(stack_b);
	free_stack(&stack_a);
	return (0);
}
