#include<stdio.h>
#define MAX 100

int   getthread();
void  getmodel(char *);
void  getusage(int,long int *);
int   gettemp();
void  termout(char *,int,int,long int *);
float getmem(int);
void  termmem(float);


int main()
{

  char  model[MAX];
  int   thread;
  long int   *usage;
  int   temp;
  float mem;
  
  thread = getthread();
  getmodel(model);
  usage = malloc(sizeof(long int) * thread + 1);

  while(1){

    getusage(thread,usage);
    termout(model,thread,gettemp(),usage);
    termmem(getmem(1));

  }

//hoge

  return 0;
}
