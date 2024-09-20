#include "philo_header.h"



/*
#The input defintion : 
       ./philo 5 800 200 200 7
       ?5-> The number of philo
       ?800 -> The time a philosopher will die if he desn't eat
       ?200 -> The time it takes a philosopher to eat
       ?200 -> The time it take a philosopher to sleep
       ?7 ->  Number of the philo should eat before terminating the program
*/


int main(int ac , char**av){

       t_control control;
       t_philo_data philos[PHILO_MAX];
       pthread_mutex_t fork[PHILO_MAX];
       if (ac < 5 || ac > 6){
              throw_error(1);
              return 1;
       }
       if(!is_valid(av))
              return 1;
       init_control(&control, philos);
       init_fork(fork, ft_atoi(av[1]));
       init_philosophers(philos,&control,fork, av);
       thread_creation(&control, fork);
       return 0;
            
         
}