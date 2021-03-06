/*
*
* Dynamic Programming Solution for Travelling salesman problem.
* Author : Afaque Hussain
* Input : 'n' the number of cities
*
*/

#include<stdio.h>   

typedef struct 
{ 
  int myArray[100];
} Array;

int C[100][100]={0};

// Create a hamiltonian graph of n nodes with random distances assigned.
fillMatrix(int n)
{
  int i,j;
  
   for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      if(i==j)
        C[i][j]=9999;
      else if(C[i][j]==0)
        C[i][j]=C[j][i]=rand()%20;
    }
  
  }

 // Print the adjacency matrix
 for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      printf("%d \t",C[i][j]);
    }
    printf("\n");
  } 
}


int optimal(int i, Array S,int count)
{
  if(count==0)
    return C[i][0];
  else
    {
      int min=999999,j=0,k=0,temp=0,find=0;
      for(k=0;k<count;k++)
      {
         
         int temp = S.myArray[0];
         S.myArray[0] = S.myArray[k];
         S.myArray[k] = temp;

         Array T;
         for(j=1;j<count;j++)
             T.myArray[j-1]=S.myArray[j];
 
         find = C[i][S.myArray[0]] + optimal(S.myArray[0],T,count-1);
         
         

         if(find < min)
           {
              min = find;
           }
      }
      
      return min;
    }
}

void main()
{
  int n,i;
  printf("Enter the number of cities: ");
  scanf("%d",&n);

  printf("\nThe adjacency matrix of the random Hamiltonian Graph is: \n");
  fillMatrix(n);

  Array init;

  for(i=1;i<n;i++)
  {
    init.myArray[i-1]=i;
  }
 
  int result;
  result = optimal(0,init,n-1);
  printf("\n The optimal route cost is %d \n",result); 
} 
