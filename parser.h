/*
** parser.h for parser in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 11:22:43 2017 luc semon
** Last update Fri May  5 15:47:38 2017 luc semon
*/

#ifndef _PARSER_H_
# define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>

char	**parseMySysTable();
char	**gotoParsing(FILE *fp, char **tab);

#endif
