#include<iostream>

using namespace std;

const int MAX=5;

int fill_array(double [],int);
void show_array(const double[],int);
void revalue(double,double [],int);

int main(void)
{
    double properties[MAX];
    int size=fill_array(properties,MAX);
    show_array(properties,size);
    if(size>0)
    {
        cout<<"Enter revaluation factor: ";
        double factor;
        while(!(cin>>factor))
        {
            cin.clear();
            while(cin.get()!='\n')
            {
                continue;
            }
            cout<<"Bad input,please input a number: ";
        }
        revalue(factor,properties,size);
        show_array(properties,size);
    }
    cout<<"Done.\n";
    cin.get();  //receive two inputs to prevent a flash by
    cin.get();
    return 0;
}
int fill_array(double arr[],int limit)
{
    double temp;
    int i;
    for(i=0;i<limit;++i)
    {
        cout<<"Enter value: #"<<(i+1)<<": ";
        cin>>temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cout<<"Bad input;input process terminated.\n";
            break;
        }
        else if(temp<0)
            break;
        arr[i]=temp;
    }
    return i;
}
void show_array(const double arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Property #"<<(i+1)<<": $";
        cout<<arr[i]<<endl;
    }
    return;
}

void revalue(double r,double arr[],int n)
{
    for(int i=0;i<n;i++)
        arr[i]*=r;
    return;
}