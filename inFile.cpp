#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

const int SIZE=12;

using namespace std;

int main(void)
{
    char filename[SIZE];
    cout<<"Input file name"<<endl;
    cin.getline(filename,SIZE);
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open())
       exit(EXIT_FAILURE);
    float value;
    float sum=0.0;
    int count=0;
    inFile>>value;
    while(inFile.good())
      {
          ++count;
          sum+=value;
          inFile>>value;
      }
      if(inFile.eof())
          cout<<"End of file reached\n";
      else if(inFile.fail())
         cout<<"INput terminated by data mismatch.\n";
      else 
      cout<<"Input terminated for unknown reason\n";
      if(count==0)
         cout<<"No data processed\n";
       else
       {
           cout<<"Items read:"<<count<<endl;
           cout<<"Sum:"<<sum<<endl;
           cout<<"Aver:"<<sum/count<<endl;
       }
       inFile.close();
       return 0;
}
