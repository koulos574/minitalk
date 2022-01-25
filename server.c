 #include <unistd.h>    
 #include <sys/types.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>

void  signal_sigusr(int signum)
{
   static char c = 0xFF;
   static int  bits = 0;
   static char buf[1000];
   static int  len;

   if (signum == SIGUSR1)
   {
      // write(1,"1",1);
      c |= 0x80 >> bits;
   }
   else if (signum == SIGUSR2)
   {
      // write(1,"0",1);
      c ^= 0x80 >> bits;
   }

   bits++;
   if (bits == 8)
   {
      buf[len++] = c;
      if (c == '\0' || len >= 1000)
      {
         write(1, buf, len - (c == '\0'));
			len = 0;
      }
      //write(1, &c, 1);
      bits = 0;
   	c = 0xFF;
   }
}

int	main(void)
{
   pid_t pid;

   pid = getpid();
   write(1, "Please find the pid: ", 21);
   printf("%d\n", pid);
   signal(SIGUSR1, signal_sigusr);
   signal(SIGUSR2, signal_sigusr);
   while (1)
      pause();
}










// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*dest;

// 	i = 0;
// 	dest = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		dest[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (dest);
// }

// char	*ft_strnew(size_t size)
// {
// 	char *s;

// 	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
// 		return (NULL);
// 	ft_memset(s,0,sizeof(char)*size + 1);
// 	return (s);
// }

// size_t		ft_strlen(const char *s)
// {
// 	size_t i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	ft_putchar(char z)
// {
// 	write(1, &z, 1);
// }

// void	ft_putstr(char *s)
// {
// 	if (s == NULL)
// 		return ;
// 	while (*s)
// 		ft_putchar(*s++);
// }

// char	*ft_strjoin(char  *s1, char  *s2)
// {
// 	char *res;
// 	size_t i;
// 	size_t j;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	j = 0;
// 	i = -1;
// 	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
// 			+ 1))))
// 		return (NULL);
// 	while (s1[++i])
// 		res[i] = s1[i];
// 	while (s2[j])
// 		res[i++] = s2[j++];
// 	res[i] = '\0';
// 	return (res);
// }

// void  signal_sigusr(int signum)
// {
//    static char c = 0xFF;
//    static int  bits = 0;
//    static char *buf;
//    char *ret;

//    if (!buf)
//       buf = ft_strnew(1);
//    if (signum == SIGUSR1)
//    {
//       // write(1,"1",1);
//       c |= 0x80 >> bits;
//    }
//    else if (signum == SIGUSR2)
//    {
//       // write(1,"0",1);
//       c ^= 0x80 >> bits;
//    }
//    bits++;
//    if (bits == 8)
//    {
//       write(1,"\n",1);
//    	if (c)
//       {
//          if (!(ret = (char *)malloc(sizeof(char) * 2)))
// 		      return ;
//          ret[0] = c;
// 	      ret[1] = '\0';
//          buf = ft_strjoin(buf,ret);
//       }
//       else if (!c)
//          ft_putstr(buf);
//       bits = 0;
//    	c = 0xFF;
//    }
// }
