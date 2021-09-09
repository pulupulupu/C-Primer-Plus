// cctypes.cpp --using the ccytpe.h library
#include<iostream>
#include<cctype>
int main(void)
{
    using namespace std;
    cout<<"Enter text for analysis,and type @"
          "to teriminate input.\n";
    char ch;
    int whitspace=0;
    int digits=0;
    int chars=0;
    int punct=0;
    int others=0;
    cin.get(ch);
    while(ch!='@')
    {
        if(isalpha(ch))  //is it an alphabetic character?
            chars++;
        else if(isspace(ch)) //is it a whitespace character?
            whitspace++;
        else if(isdigit(ch))  //is it a digit?
            digits++;
        else if(ispunct(ch))  //is it a punctuation?
            punct++;
        else
            others++;
        cin.get(ch);
    }
    cout<<chars<<" letters, "
        <<whitspace<<" whitespaces, "
        <<digits<<" digits, "
        <<punct<<" punctuations, "
        <<others<<" others.\n";
    return 0;
}