#include<stdio.h>   

typedef struct 
{ 
  int myArray[10];
} Array;

int C[4][4]={9999,3,6,17,3,9999,15,13,6,15,9999,15,17,13,15,9999};

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
         
         printf("\n %d",find);

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
  Array init;
  init.myArray[0]=1;
  init.myArray[1]=2;
  init.myArray[2]=3;
  int result;
  result = optimal(0,init,3);
  printf("\n The optimal route cost is %d \n",result); 
} 
