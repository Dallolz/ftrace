/*
** symbol.h for symbol in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Tue May  2 16:20:47 2017 luc semon
** Last update Fri May  5 15:48:53 2017 luc semon
*/

#ifndef SYMBOL_H_
# define SYMBOL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libelf.h>
#include <gelf.h>

static Elf64_Ehdr *elf_header;
static Elf *elf;
static Elf_Scn *scn;
static Elf_Data *edata;
static Elf64_Sym sym;
static Elf64_Shdr shdr;


typedef struct s_elfTab {
  unsigned long long	addr;
  char*			name;
  int			size;
} t_elfTab; 


t_elfTab	*symbolFinder(char **argv);
char		*allocPtr(struct stat elf_stats, int );
void		getInfoFromFd(int, struct stat*);
int		openFile(char *);
int		countNbFunc(int);
t_elfTab	*getTab(int, int);
void		printFunction(t_elfTab *, unsigned long long);
char		*readMyElf(int, char *, struct stat);
#endif
