#include<stdio.h>

void termmem(float usage)
{
  int r=0,g=0,b=0;
  int n;
  int i=0;
  

  printf("+---------------------------------------------------+------+\n");
  printf("|");

  for(n=0; n<100; n+=2){

    if( n <= 25 ){
      g = n * 10;
      b = 250;
    }

    if( 25 < n && n <= 50 ){
      g = 250;
      b = 250 - ((n - 25) * 10 );
    }

    if( 50 < n && n <= 75 ){
      r = (n - 50) * 10;
      g = 250;
    }

    if( 75 < n && n < 100 ){
      r = 250;
      g = 250 - ((n - 75) * 10 );
    }

    i = (int)usage;
    printf("\033[48;2;%d;%d;%dm \033[0m",r,g,b);
    if( n == i || i == n+1 ){ printf("#"); }

  }
  printf("|%5.1f%|\n",usage);
  printf("+---------------------------------------------------+------+\n");
}

