#include<stdio.h>
#include<string.h>

#define PASS_A   "/sys/class/hwmon/hwmon"
#define PASS_B   "/temp1_input"
#define ERRHWMON "Hardware Monitor not found\n"
#define MAX 100
#define CHALLE 20

int gettemp()
{
  FILE *fp1;
  char c[MAX];
  int i=0;
  int temp;

  while(1){
  snprintf(c, MAX, "%s%d%s", PASS_A, i, PASS_B);
  if((fp1 = fopen(c, "r")) != NULL ){ break; }
  i++;
  if( i > CHALLE ){ fprintf(stderr, ERRHWMON); return -1; }
  }

  if((fscanf(fp1, "%d",  &temp)) == EOF ){
    fprintf(stderr,"EOF\n");
  }

  temp = temp / 1000;

  fclose(fp1);

  return temp;
}               
