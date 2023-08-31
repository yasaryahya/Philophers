/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:05:37 by yyasar            #+#    #+#             */
/*   Updated: 2023/08/24 17:35:10 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_args(void)
{
	printf(" ______________________________________ \n");
	printf("|\033[31m      Please enter 4 or 5 arguments   \033[0m|\n");
	printf("|______________________________________|\n");
	return (0);
}

static int	input_ac_control(int ac, char **av)
{
	register int	i;

	i = 1;
	if (ac <= 4 || ac >= 7)
		return (ft_check_args());
	while (i < ac)
	{
		if (is_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_max(char **av)
{
	register int	i;

	i = 1;
	while (av[i])
	{
		if (unsigned_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_control(int ac, char **av)
{
	if (input_ac_control(ac, av) == 0)
		return (ft_err("Incorret argument!\n"));
	if (ft_check_max(av) == 0)
		return (ft_err("Invalid argument!\n"));
	return (1);
}
