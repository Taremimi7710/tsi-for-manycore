#include<stdio.h>

#define COLM 16 //1Lines per Thread Count.

void termout(char *model,int thread, int temp, long int *usage)
{
  int r = 0; //RGB Color Level
  int g = 0; 
  int b = 0;
  int t = 0;
  int i, n;  //i:for

  system("clear");

  /*####ClearPoint####*/

  printf("CPU Usage:%s",model);
  printf("%dThread(s) ",thread);
  if( temp > 0 ){ printf("CoreTemp=%d℃",temp); }
  printf("\n");

  /*Usage Draw Start*/

  for(i=0; i<COLM; i++){
    if( thread == i ){ break; }
    printf("+---");
  }
  printf("+\n");

  while(thread > 0){
    for(i=0; i<COLM; i++){
      if( thread == i ){ break; }
      n = usage[++t];
 
      if( n <= 25 ){
        r = 0;
        g = n * 10;
        b = 250;
      }
      if( 25 < n && n <= 50 ){
        r = 0;
        g = 250;
        b = 250 - ((n - 25) * 10 );
      }
      if( 50 < n && n <= 75 ){
        r = (n - 50) * 10;
        g = 250;
        b = 0;
      }
      if( 75 < n && n <= 100 ){
        r = 250;
        g = 250 - ((n - 75) * 10 );
        b = 0;
      }
      if( 100 < n ){
        r = 255;
        g = 0;
        b = 0;
      }
      printf("|\033[48;2;%d;%d;%dm%3d\033[0m",r,g,b,n);
    }
    printf("|\n");

    for(i=0; i<COLM; i++){
      if( thread == i ){ break; }
      printf("+---");
    }
    printf("+\n");
    thread = thread - COLM;
  }
  
  printf("\n");
}





       
