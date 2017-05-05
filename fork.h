/*
** fork.h for start in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 12:44:33 2017 luc semon
** Last update Fri May  5 15:50:03 2017 luc semon
*/

#ifndef _FORK_H_
# define _FORK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libelf.h>
#include <gelf.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include "parser.h"
#include "strace.h"
#include "symbol.h"

void	display_usage();
void	arg_check(char **, int);
int     forkMe(char **);
void	start(int ac, char **av);
void	parentAction(pid_t, int, t_elfTab *);

#endif
