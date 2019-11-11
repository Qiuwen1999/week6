#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[],char *env[])

{

int i = 0;
int j = 0;
extern char **environ;
for(;env[i];i++)

{

printf("%s\n",env[i]);

}

for(; environ[j];j++)

{

printf("%s\n",environ[j]);

}


printf("%s\n",getenv("PATH"));

return 0;
}
