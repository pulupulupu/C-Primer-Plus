#include<iostream>
#include<string>
int main(void)
{
    using namespace std;
    string str1="penguin";
    string str2,str3;

    cout<<"You can assign one string object to another str2=str1\n";
    str2=str1;
    cout<<"str1 is "<<str1<<", str2 is "<<str2<<endl;
    cout<<"You can assign a C-style string to an string object. \n";
    str2="buzzard";
    cout<<"str2: "<<str2<<endl;
    cout<<"You can concatenate strings: str3=str1+str2 \n";
    str3=str1+str2;
    cout<<"str3: "<<str3<<endl;
    cout<<"You can append strings. \n";
    str1+=str2;
    cout<<"str1: "<<str1<<endl;
    cout<<"str1+=str2 yields str1 = "<<str1<<endl;
    str2+=" for a day";
    cout<<"str2 += \" for a day \" yields str2 = "<<str2<<endl;
    return 0;
}