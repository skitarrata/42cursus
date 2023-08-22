/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:47:04 by grusso            #+#    #+#             */
/*   Updated: 2021/10/16 14:55:28 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/philosophers.h"

void	ft_exit(t_rules *rules, t_philo *phi)
{
	int	i;

	i = -1;
	while (++i < rules->n_philo && phi[i].pos != 1)
		pthread_join(phi[i].t_id, NULL);
	i = -1;
	while (++i < rules->n_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->meal));
}

void	ft_meal(t_philo *phi, t_rules *rules)
{
	pthread_mutex_lock(&rules->forks[phi->fork_left]);
	ft_print(rules, phi->pos, TAKE);
	pthread_mutex_lock(&rules->forks[phi->fork_right]);
	ft_print(rules, phi->pos, TAKE);
	pthread_mutex_lock(&(rules->meal));
	ft_print(rules, phi->pos, EATING);
	phi->l_meal = ft_time();
	pthread_mutex_unlock(&(rules->meal));
	ft_usleep(rules->t_eat);
	phi->cnt++;
	pthread_mutex_unlock(&rules->forks[phi->fork_left]);
	pthread_mutex_unlock(&rules->forks[phi->fork_right]);
}

void	*ft_thread(void *arg)
{
	t_philo	*phi;
	t_rules	*rules;

	phi = (t_philo *)arg;
	rules = phi->rules;
	if (phi->pos % 2 == 0)
		usleep(15000);
	while (phi->cnt > rules->n_eat || !rules->dieded)
	{
		ft_meal(phi, rules);
		if (rules->all_ate)
			return (NULL);
		ft_print(rules, phi->pos, SLEEPING);
		ft_usleep(rules->t_sleep);
		ft_print(rules, phi->pos, THINKING);
	}
	return (NULL);
}

void	ft_death_loop(t_rules *rules, t_philo *phi)
{
	int	i;

	while (!rules->all_ate)
	{
		i = -1;
		while (++i < rules->n_philo && !rules->dieded)
		{
			pthread_mutex_lock(&(rules->meal));
			if (ft_time() - phi[i].l_meal > rules->t_die)
			{
				ft_print(rules, phi[i].pos, DEAD);
				rules->dieded = 1;
			}
			pthread_mutex_unlock(&(rules->meal));
		}
		if (rules->dieded)
			break ;
		i = 0;
		while (rules->n_eat != -1 && phi[i].cnt >= rules->n_eat
			&& i < rules->n_philo)
			i++;
		if (i == rules->n_philo)
			rules->all_ate = 1;
	}
}

void	ft_philo(t_rules *rules)
{
	int		i;
	t_philo	*phi;
	int		err;

	phi = rules->philo;
	rules->start = ft_time();
	i = -1;
	while (++i < rules->n_philo)
	{
		err = pthread_create(&phi[i].t_id, NULL, ft_thread, &phi[i]);
		if (err != 0)
			ft_error(THREAD_FAIL);
		phi[i].l_meal = ft_time();
	}
	ft_death_loop(rules, phi);
	ft_exit(rules, phi);
}
