/*
** symbol2.c for symbol in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Tue May  2 11:29:57 2017 luc semon
** Last update Fri May  5 15:48:18 2017 luc semon
*/

#include <string.h>
#include "symbol.h"


t_elfTab	*getTab(int fd, int size)
{
  int           nbSymbol;
  int           i;
  int		x;
  t_elfTab      *elfTab;

  x = 0;
  elf = elf_begin(fd, ELF_C_READ, 0);
  elfTab = malloc(sizeof(t_elfTab) * size);
  while((scn = elf_nextscn(elf, scn)) != 0)
    {
      gelf_getshdr(scn, &shdr);
      if(shdr.sh_type == SHT_SYMTAB)
        {
          edata = elf_getdata(scn, edata);
          nbSymbol = shdr.sh_size / shdr.sh_entsize;
	  i = 0;
          while (i < nbSymbol)
            {
              gelf_getsym(edata, i, &sym);
              if (ELF32_ST_TYPE(sym.st_info) == STT_FUNC)
		{
		  elfTab[x].addr = sym.st_value;
		  elfTab[x].name = elf_strptr(elf, shdr.sh_link, sym.st_name);
		  elfTab[x].size = size;
		  x++;
		}
	      i++;
	    }
	  
	}
    }
  return (elfTab);
}

void	printFunction(t_elfTab *tab, unsigned long long addr)
{
  int	i;
  char	*name;

  i = 0;
  while (i < tab[0].size)
    {
      if (tab[i].addr == addr)
	{
	  name = strdup(tab[i].name);
	  if (name[0] < 'a' && name[0] > 'z' || name[0] < 'A' && name[0] > 'Z')
	    printf("Entering function %s at 0x%07x\n", &name[1], tab[i].addr);
	  else
	    printf("Entering function %s at 0x%07x\n", name, tab[i].addr);
	}
      i++;
    }
}


char	*readMyElf(int fd, char *ptr, struct stat elfStats)
{
  if((read(fd, ptr, elfStats.st_size)) < elfStats.st_size)
    {
      perror("read");
      free(ptr);
      close(fd);
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
