 #include <unistd.h>    
 #include <sys/types.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>

// void	conversion_char(int pid, char c)
// {
//    int		i;
//    int		bitshift;

//    bitshift = -1;
//    while (++bitshift < 8)
//    {
//    	if (c & 0x80 >> bitshift)
//    		kill(pid, SIGUSR1);
//       else
//    		kill(pid, SIGUSR2);
//    }
// }

// void  launch(int pid, char **av)
// {
//    int i;

//    i = 0;
//    while (av[2][i])
//    {
//       conversion_char(pid, av[2][i]);
//       i++;
//    }
// }

int	main(int argc, char *argv[])
{
   int		pid;

   pid = atoi(argv[1]);
   kill(pid, SIGUSR1);
   kill(pid, SIGUSR2);
   // launch(pid,argv);
   return (0);
}
