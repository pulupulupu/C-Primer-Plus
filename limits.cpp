#include<iostream>
#include<climits>

int main(void)
{
    using namespace std;
    int n_int=INT_MAX;
    short n_short=SHRT_MAX;
    long n_long=LONG_MAX;
    long long n_llong=LLONG_MAX;
    cout<<"int is:"<<n_int<<" the size of it is: "<<sizeof(int) <<" bytes."<<endl;
    cout<<"short is:"<<n_short<<" the size of it is: "<<sizeof(short) <<" bytes."<<endl;
    cout<<"long is:"<<n_long<<" the size of it is: "<<sizeof(long) <<" bytes."<<endl;
    cout<<"long long is:"<<n_llong<<" the size of it is: "<<sizeof(long long) <<" bytes."<<endl;
    return 0;
}  