/*
** fork.c for start in /home/semon_l/rendu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 12:26:03 2017 luc semon
** Last update Fri May  5 15:46:27 2017 luc semon
*/


#include "fork.h"
#include "symbol.h"
#include "./sig/signaux.h"

void	display_usage()
{
  printf("Usage : ./strace [-s] [-p <pid>|<command>]\n");
  exit(0);
}

void	start(int ac, char **av)
{
  forkMe(av);
}

int	forkMe(char **av)
{
  pid_t		child;
  int		status;
  int		fd;
  t_elfTab	*tabSymbol;

  tabSymbol = symbolFinder(av);
  child = fork();
  if (child == -1)
    {
      perror("Fork error");
      exit(0);
    }
  if (child == 0)
    {
      ptrace(PTRACE_TRACEME, 0, NULL, NULL);
      kill(getpid(), SIGSTOP);
      execvp(av[1], av);
    }
  else
    parentAction(child, status, tabSymbol);
  return (0);
}

void				parentAction(pid_t pid, int status, t_elfTab *tabSymbol)
{
  struct user_regs_struct	regStruct;
  unsigned long			opcode;
  unsigned long			retcode;
  char				**sysCallName;
  unsigned long long		addr;
  unsigned int			offset;
  int				stat;
  char				*name;

  if (!(name = malloc(sizeof(char *) * 1024)))
    exit(0);
  stat = 0;
  sysCallName = parseMySysTable();
  wait4(pid, &status, 0, NULL);
  while (WIFSTOPPED(status) && (WSTOPSIG(status) == SIGTRAP || WSTOPSIG(status) == SIGSTOP))
    {
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
      wait4(pid, &status, 0, NULL);
      ptrace(PTRACE_GETREGS, pid, NULL, &regStruct);
      opcode = ptrace(PTRACE_PEEKTEXT, pid, regStruct.rip, NULL);
      retcode = ptrace(PTRACE_PEEKUSER, pid, 8 * RAX, NULL);
      if ((opcode & 0xFF) == 0xe8)
      	{
	  offset = (int)(opcode >> 8);
	  addr = regStruct.rip + offset + 5;	  
	  addr = (addr & 0xFFFFFFFF);
	  printFunction(tabSymbol, addr);
	  
	}
      if ((opcode & 0xFFFF) == 0xD0FF)
	  printFunction(tabSymbol, regStruct.rax);
      if ((opcode & 0xFFFF) == 0xd2ff)
	  printFunction(tabSymbol, regStruct.rdx);
      if ((opcode & 0xFFFF) == 0xc3)
	{
	  printf("Leaving function \n");
	}
      if ((opcode & 0xFFFF) == 0x050F)
	{
	  printf("Syscall %s", &sysCallName[regStruct.rax][1]);
	  if (sysCallName[regStruct.rax][0] == '0')
	    printf("() = 0x%01x%c", retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '1')
	    printf("(0x%02x) = 0x%01x%c", regStruct.rdi,
		   retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '2')
	    printf("(0x%02x 0x%02x) = 0x%01x%c", regStruct.rdi,
		   regStruct.rsi, retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '3')
	    printf("(0x%02x 0x%02x 0x%02x) = 0x%01x%c", regStruct.rdi,
		   regStruct.rsi, regStruct.rdx, retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '4')
	    printf("(0x%02x 0x%02x 0x%02x 0x%02x) = 0x%01x%c", regStruct.rdi,
		   regStruct.rsi, regStruct.rdx, regStruct.rcx, retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '5')
	    printf("(0x%02x 0x%02x 0x%02x 0x%02x 0x%02x) = 0x%01x%c", regStruct.rdi,
		   regStruct.rsi, regStruct.rdx, regStruct.rcx, regStruct.r8, retcode, 10);
	  else if (sysCallName[regStruct.rax][0] == '6')
	    printf("(0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x) = 0x%01x%c", regStruct.rdi,
		   regStruct.rsi, regStruct.rdx, regStruct.rcx, regStruct.r8, regStruct.r9, retcode, 10);
      	}
    }
  if (WIFSTOPPED(status))
    {
      stat = WSTOPSIG(status);
      name = find_name(stat);
      printf("Received signal %s\n", name);
    }
  ptrace(PTRACE_DETACH, pid, NULL, NULL);
}
