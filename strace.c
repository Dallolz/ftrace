/*
** strace.c for strace in /home/semon_l/redu/PSU_2016_ftrace
** 
** Made by luc semon
** Login   <semon_l@epitech.net>
** 
** Started on  Mon May  1 13:53:03 2017 luc semon
** Last update Fri May  5 15:47:52 2017 luc semon
*/

#include "strace.h"

void				parentActionReal(pid_t pid, int status)
{
  struct user_regs_struct	regStruct;
  unsigned short		opcode;
  unsigned short		retcode;
  char				**sysCallName;

  sysCallName = parseMySysTable();
  wait4(pid, &status, 0, NULL);
  while (!WIFEXITED(status))
    {
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
      wait4(pid, &status, 0, NULL);
      ptrace(PTRACE_GETREGS, pid, NULL, &regStruct);
      opcode = ptrace(PTRACE_PEEKTEXT, pid, regStruct.rip, NULL);
      retcode = ptrace(PTRACE_PEEKUSER, pid, 8 * RAX, NULL);
      if (opcode == 0x050F)
	{
          printf("%s", sysCallName[regStruct.rax]);
          printf("(0x%02x 0x%02x 0x%02x) = %d%c", regStruct.rdi,
		 regStruct.rsi, regStruct.rdx, retcode, 10);
	}
    }
  ptrace(PTRACE_DETACH, pid, NULL, NULL);
}
