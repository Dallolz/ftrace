/*
** test.c for test in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 09:46:16 2017 luc semon
** Last update Fri May  5 15:49:06 2017 luc semon
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int	toto()
{
  int	pid;

  pid = getpid();
  printf("PID : %d\n\n\n\n", pid);
  //  while (1);
  printf("YPY");
  return (0);
}

int	main(int ac, char **av)
{
  int	pid;

  pid = getpid();
  kill(pid, 2);
  toto();
  return (0);
}
