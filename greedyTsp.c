#include <stdio.h>

int a[1000][1000]={0};
int visited[1000]={1,0};
int n;

// Create a hamiltonian graph of n nodes with random distances assigned.
fillMatrix(int n)
{
  int i,j;
  
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

 // Print the adjacency matrix
 for(i=0;i<n;i++)
  { 
    for(j=0;j<n;j++)
    {
      printf("%d \t",a[i][j]);
    }
    printf("\n");
  } 
}

void greedyCalculate()
{
  int cost = 0;     
   int currentCity=0;
   int i; 
  
  
  for(i=1;i<n;i++)
  {
    
    // get the shortest distance from this node to the next.
    int less = 99999999;
    int j,nextJump;
    for(j=0;j<n;j++)
    {
      if(!(j==currentCity || visited[j]==1)) 
      {
	
        if(less > a[currentCity][j])
        {
	 less = a[currentCity][j];
	 nextJump=j;
        }
      }
    } 
    
    printf(" %d ---> ",nextJump);
    cost = cost + a[currentCity][nextJump];
    visited[nextJump]=1;
    currentCity=nextJump;
  }
  
  printf(" 0. \n");
  cost = cost + a[currentCity][0];
  printf("Cost of the route: %d \n", cost);
}

void main()
{
   
   
   printf("Enter the number of cities: ");
   scanf("%d",&n);

   printf("\n The adjacency matrix of the random Hamiltonian Graph is: \n");
   fillMatrix(n);
   
   printf("\n Without the loss of generality, assuming the tour starts from node 0. The solution is : \n  0 ---> ");
  
   greedyCalculate();
   
}
  
  

