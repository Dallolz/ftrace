/*
** symbol.c for testsymbol in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Tue May  2 10:22:26 2017 luc semon
** Last update Fri May  5 15:48:40 2017 luc semon
*/

#include "symbol.h"

t_elfTab	*symbolFinder(char **argv)
{
  int		fd;
  int		nbFunc;
  char		*ptr;
  char		*file;
  struct stat	elfStats;
  t_elfTab	*tab;

  file = argv[1];
  fd = openFile(file);
  getInfoFromFd(fd, &elfStats);
  ptr = allocPtr(elfStats, fd);
  ptr = readMyElf(fd, ptr, elfStats);
  if(elf_version(EV_CURRENT) == EV_NONE)
    perror("lib elf");
  nbFunc = countNbFunc(fd);
  tab = getTab(fd, nbFunc);
  close(fd);
  free(ptr);
  return (tab);
}

char	*allocPtr(struct stat elfStats, int fd)
{
  char	*ptr;

  if((ptr = (char *) malloc(elfStats.st_size)) == NULL)
    {
      perror("malloc");
      close(fd);
      exit(EXIT_FAILURE);
    }
  return (ptr);
}


void	getInfoFromFd(int fd, struct stat *elfStats)
{
  if((fstat(fd, elfStats)))
    {
      perror("fstat");
      close(fd);
      exit(EXIT_FAILURE);
    }
}
int	openFile(char *file)
{
  int	fd;
  
  if((fd = open(file, O_RDWR)) == -1)
    {
      perror("open");
      exit(EXIT_FAILURE);
    }
  return (fd);
}

int	countNbFunc(int fd)
{
  int		symbol_count;
  int		i;
  t_elfTab	*elfTab;
  int		counter;

  counter = 0;
  elf = elf_begin(fd, ELF_C_READ, NULL);
  while((scn = elf_nextscn(elf, scn)) != NULL)
    {
      gelf_getshdr(scn, &shdr);
      if(shdr.sh_type == SHT_SYMTAB)
        {
	  edata = elf_getdata(scn, edata);
	  symbol_count = shdr.sh_size / shdr.sh_entsize;
	  for(i = 0; i < symbol_count; i++)
	    {
	      gelf_getsym(edata, i, &sym);
	      if (ELF32_ST_TYPE(sym.st_info) == STT_FUNC)
		counter++;
	    }	  
	}
    }
  return (counter);
}
