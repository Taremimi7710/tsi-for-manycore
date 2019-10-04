#include<stdio.h>
#include<string.h>

#define PASS "/proc/cpuinfo"
#define ERRC "Failed to get CPU Model.\n"
#define COMP "model name      "
#define MAX  100

void getmodel(char *model)
{

  FILE *fp;
  char line[MAX];
  char colm[MAX];
  int  i=0;

  if((fp = fopen(PASS, "r")) == NULL ){
    fprintf(stderr, ERRC);
    model = "\0";
  }else{
    while((fgets(line, MAX, fp)) != NULL){
      sscanf(line, "%[^:] :%[^:] ",&colm, model);
      if( i++ == 4 ){ break; }  
   }
   fclose(fp); 
  }
}
