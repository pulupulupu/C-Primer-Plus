#include<iostream>

using namespace std;

void n_cheers(char,int);
 int main(void)
 {
     int times;
     char ch;
     cout<<"Enter a character: ";
     cin>>ch;
     while(ch!='q')
     {
         cout<<"Enter an integer: ";
         cin>>times;
         n_cheers(ch,times);
         cout<<"\nEnter another character or press the q-key to quit: ";
         cin>>ch;
     }
     cout<<"The value of times is "<<times<<".\n Bye\n";
    return 0;
 }
void n_cheers(char c, int n)
{
    while(n-->0)
    {
        cout<<c;
    }
}