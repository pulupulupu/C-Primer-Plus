#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

int main(void)
{
    string filename="test.txt";
    fstream file;
    file.open(filename,ios_base::out|ios_base::app);
    file.fill('#');
    file<<setw(10)<<"Filename";
    file<<setw(10)<<"Text"<<endl;
    file<<setw(10)<<"1"<<".txt"<<endl;
    return 0;
}