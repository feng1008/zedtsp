# include <stdio.h>
 
int a[100];

void fillArray(int n)
{
   int i;
   for(i=0;i<n;i++)
     a[i]=i+1;
}

void display(int n)
{
  int i;
  printf("\n"); 
  for(i=0;i<n;i++)
     printf("\t %d",a[i]);
}

void swap (int *numOne, int *numTwo)
{
    int temp;
    temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}
  
 void permute(int i, int n) 
{
   int j; 
   if (i == n)
     display(n+1);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(i+1, n);
          swap((a+i), (a+j)); 
       }
   }
} 

 


int main()
{
   int n;
   printf("Enter the number of Cities:");
   scanf("%d",&n);
   fillArray(n);
   permute(0,n-1);
   printf("\n");
   return 0;
}
