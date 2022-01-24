 #include <unistd.h>    
 #include <sys/types.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>

void  signal_sigusr1(int signum)
{ 
   (void)signum;
   printf("1");
}

void  signal_sigusr2(int signum)
{
   (void)signum;
   printf("0");

}

int	main(void)
{
   pid_t pid;

   pid = getpid();
   printf("please find the pid : %d\n", pid);
   signal(SIGUSR1, signal_sigusr1);
   signal(SIGUSR2, signal_sigusr2);
   while (1)
      pause();
}