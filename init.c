/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:06:01 by yyasar            #+#    #+#             */
/*   Updated: 2023/08/19 11:11:48 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	philo_init(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->table = table;
	philo->eat_count = 0;
	philo->last_eat = current_time();
	pthread_mutex_init(&table->forks[i], NULL);
}

void	fork_init(t_philo *philo, t_table *table, int i)
{
	if (i - 1 < 0)
		philo->rfork = &table->forks[table->number_of_philo - 1];
	else
		philo->rfork = &table->forks[i - 1];
	philo->lfork = &table->forks[i];
}

void	start_threads(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->stop_count, NULL);
	pthread_mutex_init(&table->count_eat, NULL);
	pthread_mutex_init(&table->eat_last, NULL);
	pthread_mutex_init(&table->is_print, NULL);
	pthread_mutex_init(&table->is_die, NULL);
	i = -1;
	while (++i < table->number_of_philo)
		philo_init(&table->philos[i], table, i);
	i = -1;
	while (++i < table->number_of_philo)
		fork_init(&table->philos[i], table, i);
	i = -1;
	while (++i < table->number_of_philo)
		pthread_create(&table->philos[i].thread,
			NULL, philo_routine, table->philos + i);
	die_check(table);
}
