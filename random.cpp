#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main(void)
{
 srand ((unsigned) time(NULL));
 int i=rand()%2;
 if(i==0)
  std::cout<<"����"<<std::endl;
  else
  {
    //std::cout<<"A"<<endl;
      std::cout<<"������"<<std::endl;
  }
system("pause");
  return 0;
}

