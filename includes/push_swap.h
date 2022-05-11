/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:49:24 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/11 10:04:03 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>//to_remove

typedef struct s_stack
{
	struct s_stack	*previous;
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_cost
{
	int	rrb_cost;
	int	rr_place;
	int	rb_cost;
	int	r_place;
	int	best_place;
	int	best_in_a;
	int	best_in_b;
}				t_cost;

/*tmp*/
void	print_stack(t_stack *stack);//to_remove

/*main*/
void	ft_error(char *str);
int		stack_is_sorted(t_stack *stack);

/*check_stack*/
void	check_arg(char **argv);
int		check_dup(char **argv);
int		ft_is_valid_digit(char *str);

/*small_sort*/
void	small_sort(t_stack **stack_a, t_stack **stack_b, int len);
void	sort_5(t_stack **a, t_stack **b);
void	sort_4(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);

/*sort_100*/
int		count_r(int nb, t_stack **stack_b, int ra, int len);
int		count_rr(int nb, t_stack **stack_b, int ra, int len);
void	modify_move(t_cost **move, int r, int place, int cost);
void	sort_100(t_stack **stack_a, t_stack **stack_b, int len, t_cost	**move);
void	calculate_best_move(t_stack **a, t_stack **b, int len, t_cost	**move);
void	push_to_b(t_stack **a, t_stack **b, int len, t_cost	**move);

/*big_sort*/
void	big_sort(t_stack **stack_a, t_stack **stack_b, int len);

/*utils*/
int		ft_strlen(const char *str);
int		ft_strcmp(char *str1, char	*str2);
long	ft_atoi(const char *str);

/*struct*/
void	make_stack(t_stack **stack, char **argv);
void	ft_lstadd_back(t_stack **stack_a, int nb);
void	free_stack(t_stack **stack);
int		stack_min(t_stack **stack);
int		stack_max(t_stack **stack);

/*command*/
void	ft_stack_s(t_stack **a, char *command);
void	ft_stack_r(t_stack **a, char *command);
void	ft_stack_rr(t_stack **a, char *command);
void	ft_stack_p(t_stack **dest, t_stack **src, char *command);

#endif