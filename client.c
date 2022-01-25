 #include <unistd.h>    
 #include <sys/types.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>

void	send_null(int pid)
{
	int	i = 0;

	while (i++ != 8)
		kill(pid, SIGUSR1);
}


void	conversion_char(int pid, char c)
{
   int		i;
   int		bitshift;

   bitshift = -1;
   while (++bitshift < 8)
   {
   	if (c & 0x80 >> bitshift)
   		kill(pid, SIGUSR1);
      else
   		kill(pid, SIGUSR2);
      usleep(100);
   }
}

void  launch(int pid, char **av)
{
   // int j;

   // j = 0;
   // while (av[2][j])
   // {
   //    conversion_char(pid, av[2][j]);
   //    j++;
   // }
   // send_null(pid);
   int i;
   int j;
   int bitshift;

   j = 0;
   i = 0;
   while (1)
   {
      bitshift = 7;
      while (bitshift >= 0)
      {
         j = (av[2][i] & (1 << bitshift));
   	   if (j > 0)
   		   kill(pid, SIGUSR1);
         else
   	   	kill(pid, SIGUSR2);
         usleep(100);
         bitshift--;
      }
      if (av[2][i] == '\0')
         break;
      i++;
   }
}

int	main(int argc, char *argv[])
{
   int		pid;

   pid = atoi(argv[1]);
   launch(pid,argv);
   return (0);
}
