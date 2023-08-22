/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:46:50 by grusso            #+#    #+#             */
/*   Updated: 2021/10/16 14:59:29 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "is dead"
# define END "THE END\n"
# define PAR "THERE ARE NOT ARGUMENTS\n"
# define THREAD_FAIL "FAILED TO CREATE THREAD\n"
# define BAD_PAR "BAD PARAMETER\n"

typedef struct s_philo
{
	int				pos;
	int				cnt;
	int				fork_left;
	int				fork_right;
	long int		l_meal;
	pthread_t		t_id;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	int				n_philo;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	int				n_eat;
	int				all_ate;
	long int		start;
	int				dieded;
	pthread_mutex_t	meal;
	pthread_mutex_t	forks[250];
	t_philo			philo[250];
}					t_rules;

int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		ft_error(char *text);
long int	ft_time(void);
void		ft_usleep(int length);
void		ft_print(t_rules *rules, int phil, char *str);
void		ft_philo(t_rules *rules);

#endif