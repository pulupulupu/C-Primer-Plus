#include<iostream>
int main(void)
{
    using namespace std;
 /*    int a=20,b=20;
    cout<<"a= "<<a<<"; b="<<b<<endl;
    cout<<"a++ ="<<a++<<"; ++b="<<++b<<endl;
    cout<<"a= "<<a<<"; b="<<b<<endl; */
    int x=5;
    x=2*x++*(3-++x);
    cout<<x;
    return 0;
}