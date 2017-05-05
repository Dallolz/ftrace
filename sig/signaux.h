/*
** sig.h for sig in /home/semon_l/rendu/PSU_2016_ftrace/sig
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Wed May  3 11:48:30 2017 luc semon
** Last update Fri May  5 15:51:31 2017 luc semon
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/types.h>

#ifndef _SIGNAUX_H_
# define _SIGNAUX_H_

char*	find_name(int);

#endif
