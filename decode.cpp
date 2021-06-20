#include<iostream>
#include<Windows.h>
#include<fstream>
#include<ctime>
#include<string>


using namespace std;

//int main(int argc, char * argv[])
int main(void)
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	cout << time.wYear <<" "<<time.wMonth<<" "<<time.wDay<<endl;
	int year = time.wYear;
	int month = time.wMonth;
	int day = time.wDay;
	/*
	if (year != 2021 && month != 1 && day != 1)
	{
		cout << "Please try to open this file in 1 Jan 2021 ,Today is now the day you can open the file" << endl;
		Sleep(5 * 1000);
		exit(EXIT_FAILURE);
	}*/
	string newfile = "decoded.encode";

	char c;
	
	fstream decode(newfile, ios::in);
	while (!decode.eof())
	{
		c = decode.get();
	    c=c xor 2017;
		cout << c;

	}
	decode.close();
	system("pause");
}