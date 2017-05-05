/*
** main.c for main in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 09:26:36 2017 luc semon
** Last update Fri May  5 15:49:50 2017 luc semon
*/

#include <stdio.h>
#include <stdlib.h>
#include "fork.h"
#include "./sig/signaux.h"

int	main(int ac, char **av)
{
  if (ac < 2)
    exit(printf("Usage : ./ftrace <commande>\n"));
  start(ac, av);
  return (0);
}
