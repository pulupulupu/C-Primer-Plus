#include<iostream>
#include<Windows.h>
#include<fstream>
#include<ctime>
#include<string>


using namespace std;

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
	string name = "1.tex";
	string newfile = "decoded.encode";

	char c;
	
	fstream fin(name, ios::in);
	fstream fout(newfile, ios::out);

	if (!fout.is_open())
		cout << "file" << endl;
	if (!fin.is_open())
		cout << "file" << endl;
	
	while (!fin.eof())
	{
		c = fin.get();
		c=c xor 2017;
		fout<<c;  
	}
	
	fin.close();
	fout.close();
	cout << endl;
	
	
	system("pause");
}