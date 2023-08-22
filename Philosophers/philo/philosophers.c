/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:06 by grusso            #+#    #+#             */
/*   Updated: 2021/10/16 14:57:05 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

static void	ft_parse(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(BAD_PAR);
}

void	ft_init_philo(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n_philo)
	{
		rules->philo[i].pos = i + 1;
		rules->philo[i].fork_left = i;
		rules->philo[i].fork_right = (i + 1) % rules->n_philo;
		rules->philo[i].rules = rules;
		rules->philo[i].cnt = 0;
	}
}

void	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
}

static void	ft_init(t_rules *rules, int argc, char *argv[])
{
	rules->n_philo = ft_atoi(argv[1]);
	rules->t_die = ft_atoi(argv[2]);
	rules->t_eat = ft_atoi(argv[3]);
	rules->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->n_eat = ft_atoi(argv[5]);
	else
		rules->n_eat = -1;
	rules->dieded = 0;
	rules->all_ate = 0;
	ft_init_philo(rules);
	ft_init_mutex(rules);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_rules	rules;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error(PAR);
	while (++i < argc)
		ft_parse(argv[i]);
	ft_init(&rules, argc, argv);
	ft_philo(&rules);
	ft_error(END);
}
