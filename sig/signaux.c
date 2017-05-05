/*
** signaux.c for main in /home/semon_l/rendu/PSU_2016_ftrace/sig
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Wed May  3 12:27:56 2017 luc semon
** Last update Fri May  5 15:51:16 2017 luc semon
*/

#include "signaux.h"

char*	find_name(int sign)
{
  int	i;
  int	x;
  FILE	*fp;
  char	ch;
  char	**tab;
  char	*name;

  i = 0;
  x = 0;
  if (!(name = malloc(sizeof(char) * 1024)))
    exit(0);
  fp = fopen("sign.txt", "r");
  if (fp == NULL)
    exit(0);
  if (!(tab = (char **)malloc(sizeof(char *) * 66)))
    exit(0);
  while (i < 66)
    {
      if (!(tab[i] = (char *)malloc(sizeof(char) * 66)))
	exit(0);
      i++;
    }
  i = 0;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
	{
	  tab[i][x] = '\0';
	  i++;
	  x = 0;
	}
      else
	{
	  tab[i][x] = ch;
	  x++;
	}
    }
  fclose(fp);
  return (tab[sign - 1]);
}
