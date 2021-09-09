#include<iostream>
#include<string>
int main(void)
{
    using namespace std;
    cout<<"Enter a word: ";
    string word;
    //char word[20];
    //getline(cin,word); 带空格输入的string输入
    cin>>word;
    for(int i=word.size()-1;i>=0;i--)
    {
        cout<<word[i];
    }
    cout<<"Bye! \n";
    return 0;
}