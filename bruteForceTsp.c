/*
*
* Brute force Solution for Travelling salesman problem.
* Author : Afaque Hussain
* Input : 'n' the number of cities
*
*/



# include <stdio.h>
# include <stdlib.h> 

int a[100][100]={0}; // Holding the Adjacency Matrix
int b[100]={0};      // Array to hold the node numbers form 0 to n-1
int min=999;         // Variable to hold the minimum cost
int minTour[100]={0};// Array to hold opitmal route

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

// Create nodes from 0 to n-1
void fillArray(int n)
{
   int i;
   for(i=0;i<n;i++)
     b[i]=i;
}

// Display all possible routes and also the cost associated with each.
void display(int n)
{
  int i,cost=0;
  printf("\n 0"); 
  for(i=1;i<n;i++)
  {
     cost = cost + a[b[i-1]][b[i]];
     printf("--> %d",b[i]);
  }
  printf("--> 0");
  cost = cost + a[b[i-1]][b[0]];
  printf("\t Cost: %d",cost);

// Record the minimum cost and route. 
  if(min>cost)
  {
    min=cost;
    for(i=1;i<n;i++)
      minTour[i]=b[i];
  }
}

// Function to swap two numbers 
void swap (int *numOne, int *numTwo)
{
    int temp;
    temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}
  
// Function to permute all the numbers from 0 to n-1 
void permute(int i, int n) 
{
   int j; 
   if (i == n)
     display(n+1);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((b+i), (b+j));
          permute(i+1, n);
          swap((b+i), (b+j)); 
       }
   }
} 

void main()
{
  int n,i;

  printf("Enter the number of cities: ");
  scanf("%d",&n);

  printf("\nThe adjacency matrix of the random Hamiltonian Graph is: \n");
  fillMatrix(n);
  
  fillArray(n);
  
  printf("\nWithout the loss of generality, assuming the tour starts from node 0. All possible routes are: \n");
  
  permute(1,n-1);
  
  printf("\n The minimum cost tour is %d. And the optimal route is :\n",min);
  for(i=0;i<n;i++)
    printf("%d -->",minTour[i]);

  printf("0 \n");
  
}
