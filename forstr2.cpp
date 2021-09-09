#include<iostream>
#include<string>
int main(void)
{
    using namespace std;
    cout<<"Enter a word: ";
    string word;
    
    //getline(cin,word); 带空格输入的string输入
    cin>>word;
    char temp;
    for(int i=word.size()-1,j=0;i>j;i--,j++)
    {
        temp=word[i];
        word[i]=word[j];
        word[j]=temp;
    }
    cout<<word<<endl;
    return 0;
}