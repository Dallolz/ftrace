/*
** strace.h for strace in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 17:17:35 2017 luc semon
** Last update Fri May  5 15:48:00 2017 luc semon
*/

#ifndef _STRACE_H_
# define _STRACE_H_

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
#include "parser.h"

void	parentActionReal(pid_t pid, int status);

#endif
