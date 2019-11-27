#include"my.h"

int main()
{
  pid_t p;
 int fd[2],rn,wn,psize;
 char rbuf[10],wbuf[30];
 memset(rbuf,0,sizeof(rbuf));
 memset(wbuf,0,sizeof(wbuf));
 pipe(fd);
// psize=fcntl(fd[0],?F_GEIPIPE_SZ);
// printf("pipe size = %d\n",pize);
 p = fork();
 if(p<0)
  {
    perror("forkfailed\n");
    return -1;
  }
 else if(p==0)
  {
    int i;
    close(fd[0]);
    sprintf(rbuf,"1");
    for( i = 0;i<65537;i++)
      
        write(fd[1],wbuf,sizeof(wbuf));
            close (fd[1]);
    exit(0);
  }
else{
     wait(NULL);
     close(fd[1]);
     while(1)
       {
         rn=read(fd[0],rbuf,sizeof(rbuf));
         printf("[parent] read form pipe %d byte.\n",rn);
         if(rn == 0)
           {
            printf("[parent]read error.\n");
            break;
           }
       }
     close(fd[0]);
     return 0;
     }
}
