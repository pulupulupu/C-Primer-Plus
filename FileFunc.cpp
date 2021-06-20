#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void file_it(ostream &os, double fo, const double fel[],int n);

const int LIMIT=5;

int main(void)
{
    ofstream fout;
    const char *fn="ep-data.txt";
    fout.open(fn);
    if(!fout.is_open())
    {
        cout<<"Can't open"<<endl;
        exit(EXIT_FAILURE);
    }
    double objective;
    cout<<"enter the focal length of your telescope objective in mm: ";
    cin>>objective;
    double esp[LIMIT];
    cout<<"Enter the focal lengths, in mm, of "<<LIMIT
        <<"eyepieces:"<<endl;
    for (int i=0;i<LIMIT;i++)
    {
        cout<<"Eyepiece # "<<i+1<<":";
        cin>>esp[i];
    } 
    file_it(fout,objective,esp,LIMIT);
    file_it(cout,objective,esp,LIMIT);
    cout<<"Done!"<<endl;
    return 0;
}
void file_it(ostream &os, double fo, const double fel[],int n)
{
    ios_base::fmtflags initial;
    initial=os.setf(ios_base::fixed);
    os.precision(0);
    os<<"Focal length of objective: "<<fo<<" mm"<<endl;
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os<<"f.1. eyepiece";
    os.width(15);
    os<<"magnification"<<endl;
    for(int i=0;i<n;i++)
    {
        os.width(12);
        os<<fel[i];
        os.width(15);
        os<<int(fo/fel[i]+0.5)<<endl;
    }
    os.setf(initial);
}