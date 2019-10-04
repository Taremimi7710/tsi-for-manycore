#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define PASS "/proc/meminfo"
#define ERRC "Failed to get Memory Info.\n"
#define MAX  100
#define MID  20

float getmem(int flg)
//int main()
{
  FILE  *fp;
  char  line[MAX];
  char  colm[MID];
  float size  = 0;
  float total = 0;
  float free  = 0;
  float use   = 0;
  float usage = 0;
  int i = 0;

  if((fp = fopen(PASS,"r")) == NULL ){
    fprintf(stderr, ERRC);
  }
  
  while(((fgets(line, MAX, fp)) != NULL) && (i < 4)){
    sscanf(line, "%s %f",&colm, &size);
    if(!strcmp(colm, "MemTotal:")) { total = size; i++; } 
    if(!strcmp(colm, "MemFree:" )) { free = free + size; i++; }
    if(!strcmp(colm, "Buffers:" )) { free = free + size; i++; }
    if(!strcmp(colm, "Cached:"  )) { free = free + size; i++; }
  }

  total = total / 1024 / 1024; //KB -> GB
  free  = free  / 1024 / 1024;   
  use   = total - free;
  usage =  use  / total * 100;
  if( usage > 100){ usage = 100.0; }

  if( flg == 1 ){
    printf("MemoryUsage:%5.2f% \nTotal:%5.2fGB Used:%5.2fGB Free:%5.2fGB\n",usage,total,use,free);
  }
  
  fclose(fp);
  return usage;
}
