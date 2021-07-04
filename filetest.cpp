#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
using namespace std;
//using namespace std::filesystem;

int main(void)
{
    string name="C:\\Users\\YE\\Desktop\\Math";
    fstream fout(name,ios::in|ios::binary);
    if(!fout.is_open())
    {
        cout<<"File does not exist"<<endl;
    }
    /*
    create_directory(name);
     fstream fout(name,ios::in|ios::binary);
    if(!fout.is_open())
    {
        cout<<"File does not exist"<<endl;
    }
    */
    return 0;
}