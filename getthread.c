#include<stdio.h>
#include<unistd.h>

#define PASS "/sys/devices/system/cpu/online"
#define ERRC "Failed to Get CPU Info\n"

int getthread()
{
  FILE *fp;
  int num,num2;

  if((fp = fopen(PASS,"r")) == NULL ){
    fprintf(stderr, ERRC);
    exit(1);
   }

  fscanf(fp,"%d-%d",&num,&num2);

  fclose(fp);

  return num2+1;
}
