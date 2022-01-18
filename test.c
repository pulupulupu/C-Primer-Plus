#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define row 3
#define col 3
// void test(int *T, int col, int row)
// {
//     for(int i=0;i<col;i++)
//     for(int j=0;j<row;j++)
//         printf("%d",T[3*i+j]);
//     return ;
// }
int main(void)
{
//    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     for (int i=0;i<3;i++)
//         for(int j=0;j<3;j++)
//             printf("%d\n",a[i][j]);
    // int a[9]={1,2,3,4,5,6,7,8,9};
    // test(a,3,3);
    int *a=(int*)malloc(9*sizeof(int));
     for(int i=0;i<col;i++)
        for(int j=0;j<row;j++)
            scanf("%d",&a[3*i+j]);

     for(int i=0;i<col;i++)
        for(int j=0;j<row;j++)
            printf("%d",a[3*i+j]);

    return 0;
}