/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:55:38 by bvernimm          #+#    #+#             */
/*   Updated: 2022/05/09 14:16:33 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_valid_digit(argv[i]) == 1)
			ft_error("Not a valid digit\n");
		i++;
	}
	if (check_dup(argv) == 1)
		ft_error("Duplicate\n");
}

int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (i != j)
			{
				if (ft_strcmp(argv[i], argv[j]) == 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_valid_digit(char *str)
{
	long	nb;
	int		i;

	i = 0;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}
