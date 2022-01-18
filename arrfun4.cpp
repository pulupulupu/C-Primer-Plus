//arrfun.cpp --function with a array range 
#include<iostream>
const int Arsize=8;
int sum_arr(const int *,const int *) ;
int main(void)
{
    using namespace std;
    int cookies[Arsize]={1,2,4,8,16,32,64,128};
    
    int sum=sum_arr(cookies,cookies+Arsize);
    cout<<"Total cookies eaten: "<<sum<<endl;
    sum=sum_arr(cookies,cookies+3);
    cout<<"First three eaters ate " <<sum<<" cookies\n";
    sum=sum_arr(cookies+4,cookies+8);
    cout<<"Last three eaters ate " <<sum<<" cookies\n";
    return 0;
}
int sum_arr(const int *begin,const int *end )
{
    const int *pt;
    int total=0;
    for(pt=begin;pt!=end;pt++)
    {
        total+=*pt;
    }
    return total;
}