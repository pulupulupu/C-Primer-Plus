#include<iostream>
#include<vector>
using namespace std;

void init(vector<int> &temp)
{
   for(int i=0;i<10;i++)
      temp.push_back(i);
}
int main(void)
{
    vector<int> number;
    init(number);
   // vector<int> *pointer=&number;
   // pointer++; 
    //cout<<*pointer<<endl;
    auto pointer=number.begin();
    cout<<*pointer<<endl;
    pointer++;
    cout<<*pointer<<endl;
     return 0;
}