#include<iostream>
#include<cstdlib>

using namespace std;
int main(int argc, char *argv[])
{
    cout<<"argc is :"<<argc<<endl;
    int i=0;
    while(i++<argc)
     cout<<"argv["<<i-1<<"] is :"<<argv[i-1]<<endl;
    system("pause");
    return 0;
}