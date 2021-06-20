#include<iostream>
#include<Windows.h>
#include<fstream>
#include<ctime>
#include<cstdlib>
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
	
	if (year != 2021 && month != 1 && day != 1)
	{
		cout << "Please try to open this file in 1 Jan 2021 ,Today is now the day you can open the file" << endl;
		Sleep(5 * 1000);
		exit(EXIT_FAILURE);
	}
   // string path="C:\\Users\\YE\\Desktop\\1.jpg";
     // string newpath="C:\\Users\\YE\\Desktop\\encoded.jpg";
      //tring decode="C:\\Users\\YE\\Desktop\\decoded.jpg";
        string path="1.jpg";
      string newpath="encoded.jpg";
      string decode="decoded.jpg";
        char c;
/*
    fstream fin (path,ios::in|ios::binary);
    fstream fout(newpath,ios::out|ios::binary);
  
    
    if(!fin.is_open())
    cout<<"file"<<endl;
    if(!fout.is_open())
    cout<<"file2"<<endl;

    while(!fin.eof())
    {
        c=fin.get();
        c= c xor 2017;
        fout<<c;
    }
    fin.close();
    fout.close();
   
   /*/
  fstream ori(newpath,ios::in|ios::binary);
  fstream des(decode,ios::out|ios::binary);
  while(!ori.eof())
    {
        c=ori.get();
        //c=c xor 2017;
        des<<c;
    }
    ori.close();
    des.close();
    Sleep(5 * 1000);
    remove(newpath.c_str());
    remove(decode.c_str());
    
    system("pause");
}