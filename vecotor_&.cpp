#include<iostream>
#include<vector>


using namespace std;

class Str
{
public:
    int code;
    int statements;
};
 vector<Str> strname;
 auto pointer=strname.begin();
int main(void)
{
   
    for(int i=0;i<10;i++)
    {
        Str temp;
        temp.code=i;
        temp.statements=i+1;
        strname.push_back(temp);
    }
   //auto i=strname.begin();
  // cout<<(*i).statements<<endl;
  pointer=strname.begin();
  cout<<(*pointer).code;

    return 0;
}
