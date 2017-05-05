/*
** parser.c for parser in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 11:11:18 2017 luc semon
** Last update Fri May  5 15:47:18 2017 luc semon
*/

#include "parser.h"

char	**gotoParsing(FILE *fp, char **tab)
{
  char	ch;
  int	i;
  int	x;

  i = 0;
  x = 0;
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
  return (tab);
}

char	**parseMySysTable()
{
  FILE	*fp;
  char	**tab;
  int	i;

  i = 0;
  fp = fopen("sys2.txt", "r");
  if (fp == NULL)
    {
      perror("Error while opening the file\n");
      exit(EXIT_FAILURE);
    }
  if (!(tab = (char **)malloc(sizeof(char *) * 314)))
    exit(0);
  while (i < 314)
    {
      if (!(tab[i] = (char *)malloc(sizeof(char) * 30)))
	exit(0);
      i++;
    }
  return (gotoParsing(fp, tab));
}
