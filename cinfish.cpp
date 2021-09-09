#include<iostream>

const int MAX=5;
using namespace std;

int main(void)
{
    float fish[MAX];
    int i=0;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout<<"fish#"<<i+1<<":";
    while(i<MAX&&cin>>fish[i])
       if(++i<MAX)
         cout<<"fish#"<<i+1<<":";
    float total=0;
    for(int j=0;j<i;j++)
        total+=fish[j];
    if(i==0)
        cout<<"No fish"<<endl;
    else 
        cout<<total/i<<"=average weight of "<<i<<" fish"<<endl;
        cout<<"Done"<<endl;
    return 0;
}