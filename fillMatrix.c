#include<stdio.h>
#include<stdlib.h>

void main()
{
  int n,i,j,temp,limit=100;
  printf("Enter the number of cities: ");
  scanf("%d",&n);
  int a[n][n];
  
  for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      a[i][j]=0;
      
    }
 
  }
 
   for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      if(i==j)
        a[i][j]=99;
      else if(a[i][j]==0)
        a[i][j]=a[j][i]=rand()%20;
    }
  
  }

 for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      printf("%d \t",a[i][j]);
    }
    printf("\n");
  } 
  
}
