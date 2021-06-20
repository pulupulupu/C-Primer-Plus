#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
void exchange(int A[],int n)
{
    int low=0,high=n-1;
    int temp;
    if(n%2==0)
       while(high!=low+1)
       {
           temp=A[high];
           A[high]=A[low];
           A[low]=temp;
           high--;
           low++;
       }
    else
      while(high!=low)
      {
            temp=A[high];
           A[high]=A[low];
           A[low]=temp;
           high--;
           low++;
      }
    
}
int main(void)
{
     srand ((unsigned) time(NULL));
     int A[10],i;
     for( i=0;i<10;i++)
        A[i]=rand()%10;
    for(i=0;i<10;i++)
      cout<<A[i]<<" ";
    exchange(A,10);
    cout<<endl;
      for(i=0;i<10;i++)
      cout<<A[i]<<" ";
}
