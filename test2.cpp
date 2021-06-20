#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{
    string path="C:\\Users\\YE\\Desktop\\test\\newtest\\1.jpeg";
    fstream fin(path,ios::in|ios::binary);

	char c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;
     c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;
	 c=fin.get();
	cout<<(int)c<<endl;


}