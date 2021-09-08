#include<iostream>
#include<cstring>
int main(void)
{
    using namespace std;
    char animal[20]="bear";
    const char * bird="wren";
    char *ps;
    cout<<animal<<" and ";
    cout<<bird<<"\n";
    cout<<"Enter a kind of animal: ";
    cin>>animal;
    ps=animal;
    cout<<ps<<"! \n";
    cout<<"Before using strcmp(): \n";
    cout<<animal<<" at "<<(int*)animal<<endl;
    cout<<ps<<" at "<<(int*)ps<<endl;
    cout<<"THe first and second character of animal are at:"<<(int*)&(animal[0])<<" "<<(int*)&(animal[1])<<endl;
    ps= new char[strlen(animal)+1];
    strcpy(ps,animal);
    cout<<"After using strcmp():\n";
    cout<<animal<<" at "<<(int*)animal<<endl;
    cout<<ps<<" at "<<(int*)ps<<endl;
    delete []ps;
    return 0;
}