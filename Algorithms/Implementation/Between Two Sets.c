/*info: used structure for this implementaion for practicing pointers and structures*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct tag
{
      int a_size;
      int *A;
      int b_size;
      int *B;
}tSetStruct;


int GCD(int a,int b)
{
      while(b > 0)
      {
            int temp = b;
            b = a%b;
            a = temp;
      }
      return a;
}

int LCM(int a,int b)
{
      return a*(b/GCD(a,b));
}

int findLcm(int input[],int size)
{
      int ret = input[0];
      
      for (int i = 1; i < size ;i++ )
      {
            ret = LCM(ret,input[i]);
      }
      return ret;
}

int findGCD(int input[],int size)
{
      int ret = input[0];
      for (int i = 1 ;i < size;i++)
      {
            ret = GCD(ret,input[i]);
      }
      return ret;
}

int getTotalX(tSetStruct *vPtr) 
{
    int L = findLcm(vPtr->A,vPtr->a_size);
    int G = findGCD(vPtr->B,vPtr->b_size);
    
    int count = 0;
    for(int i = L,j=2;i<=G;i=L*j,j++)
    {
       if(G%i==0)
      {
          count++;
      }
    }
    
    return count;
}

int main() 
{
      tSetStruct var;

      int i;
      
      scanf("%i %i",&var.a_size,&var.b_size);
      var.A = malloc(sizeof(int) * var.a_size);
      
      
      for(i = 0; i < var.a_size ;i++ )
      {
            scanf("%d",&var.A[i]);
      }
      
      var.B = malloc(sizeof(int) * var.b_size);
      
      for(i = 0; i < var.b_size ;i++ )
      {
            scanf("%d",&var.B[i]);
      }

      int x = getTotalX(&var);
      printf("%d",x);
}
