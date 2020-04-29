#include<iostream>
#include<vector>

using namespace std;

void print(vector<char> temp)
{
    for(char i:temp)
    cout<<i<<endl;
    //cout<<temp<<endl;   //WRONG 
}

vector<int> &copy(vector<int> &temp)
{
    for(int &i:temp)
       i++;
    return temp;
}

int main(void)
{
    vector<int> temp={1,2,3,4,5,6,7};
    vector<char> charc={'a','b','c','d'};
    //print(charc);
    vector<int> change=copy(temp);
    for(int i:temp)
         cout<<i;
    cout<<"         "<<endl;
    for(int i:change)
       cout<<i<<endl;
    
    return 0;
}