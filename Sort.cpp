#include<iostream>
#include<cstdlib>
#include<time.h>

int Partition(int A[],int low,int high)
{
    int pivot=A[low];
    while(low<high)
    {
        while(low<high&&A[high]>=pivot) 
        --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot)
         ++low;
        A[high]=A[low];
    } 
    A[low]=pivot;
    return low;
}
void QuickSort(int A[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(A,low,high);
        QuickSort(A,low,pivot-1);
        QuickSort(A,pivot+1,high);
    }
}
void BubbleSort(int A[],int n)
{
    bool flag;
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        flag=false;
        for(j=n-1;j>i;j--)
        {
            if(A[j-1]>A[j])
            {
                temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
                flag=true;
            }
        }
        if(flag=false)
        return;
    }
}
void InsertSort(int A[],int n)
{
    int i,j,temp;
    for(i=2;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            temp=A[i];
            for(j=i-1;temp<A[j];--j)
               A[j+1]=A[j];
            A[j+1]=temp;
        }
    }
}
void SelectSort(int A[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
          if(A[j]<A[min])
             min=j;
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
void AdjustDown(int A[],int k,int len)
{
    int temp,i;
    temp=A[k];
    for(i=2*k;i<=len;i*=2)
    {
        if(i<len&&A[i]<A[i+1])
            i++;
        if(temp>=A[i])  break;
        else
        {
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=temp;
}
void BuildMaxHeap(int A[],int len)
{
    for(int i=len/2;i>0;i--)
        AdjustDown(A,i,len);
}
void HeapSort(int A[],int len)
{
    int i,temp;
    BuildMaxHeap(A,len);
    for(i=len;i>1;i--)
    {
        temp=A[1];
        A[1]=A[i];
        A[i]=temp;
        AdjustDown(A,1,i-1);
    }
}
int main(void)
{
    int A[10];
    srand ((unsigned) time(NULL));
    for(int i=0;i<10;i++)
    {
        A[i]=rand()%10;
       std::cout<<A[i]<<" ";
    }
   // QuickSort(A,0,9);
   //BubbleSort(A,10);
     // InsertSort(A,10);
   // SelectSort(A,10);
    HeapSort(A,10);   //堆排序的排序范围为[1,n-1] 因此，第一个元素无法被排到
    std::cout<<std::endl;
    for(int i=0;i<10;i++)
    {
        std::cout<<A[i]<<" ";
    }
}