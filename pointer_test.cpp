#include<iostream>
using namespace std;
int main(void)
{
    //int num=1024;
/*   int *pt=new int;
    *pt=1024;
    int *ps=pt;
    cout<<"*pt="<<*pt<<" ,pt="<<pt<<endl;
    cout<<"*ps="<<*ps<<" ,ps="<<ps<<"\n"<<endl;
    delete pt;
    int *pointer=new int;
    cout<<"*pt="<<*pt<<" ,pt="<<pt<<endl;
    cout<<"*ps="<<*ps<<" ,ps="<<ps<<"\n"<<endl;
    *pt=*pt+1;
    cout<<"*pt="<<*pt<<" ,pt="<<pt<<endl;
    cout<<"*ps="<<*ps<<" ,ps="<<ps<<endl;
    cout<<"pointer="<<pointer<<endl; */ 
    int *pt=new int [3];
    for(int i=0;i<3;i++)
    {
       pt[i]=i;
       cout<<"pt["<<i<<"]="<<i<<endl;
    }
    pt+=1;
    for(int i=0;i<3;i++)
    {
       cout<<"pt["<<i<<"]="<<i<<endl;
    }
    cout<<"pt="<<*pt<<endl;
    return 0;
}