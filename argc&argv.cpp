#include<iostream>
#include<cstdlib>

using namespace std;
int main(int argc, char *argv[])
{
    cout<<"argc is :"<<argc<<endl;
    int i=0;
    while(++i<=argc)
     cout<<"argv["<<i<<"] is :"<<argv[i]<<endl;
    system("pause");
    return 0;
}