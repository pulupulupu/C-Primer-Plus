#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;
//基于范围的for循环
int main(void)
{
    /*
    vector<int> number;
    for(int i=0;i<10;i++)
        number.push_back(i);
    for(int i:number)
       cout<<i<<endl;
       */
    for (int i: { 0,1,2,3,4,5,6,7,8,9})
       cout<<i<<endl;
    system("pause");
    return 0;
}