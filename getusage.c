#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define PASS "/proc/stat"
#define ERRC "Failed to get CPU Usage.\n"
#define MAX  100
#define CLOCKRATE 1 //Sec

int getthreads();

void getusage(int thread,long int *sum)
{

  FILE *fp1;
  char ch[20];
  char line[MAX];
  long int user;
  long int nice;
  long int system;
  int  time,i;

  time  = CLOCKRATE * 1000000;// μs

  if((fp1 = fopen(PASS, "r")) == NULL){
    fprintf(stderr, ERRC);
    exit(1);
  }

  for(i=0; i<=thread; i++){ 
    fgets(line, MAX, fp1);
    sscanf(line, "%s %d %d %d", &ch, &user, &nice, &system);
    sum[i] = user + nice + system;
  }

  fclose(fp1);
  usleep(time);

  if((fp1 = fopen(PASS, "r")) == NULL){
    fprintf(stderr, ERRC);
    exit(1);
  }

  for(i=0; i<=thread; i++){
    fgets(line, MAX, fp1);
    sscanf(line, "%s %d %d %d", &ch, &user, &nice, &system);
    sum[i] = (user + nice + system - sum[i]) / CLOCKRATE;
    if(sum[i] > 100){ sum[i] = 100; }
  }

  fclose(fp1);

}
