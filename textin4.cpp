// textin4.cpp --reading chars with cin.get()
#include<iostream>
int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	while ((ch=cin.get())!=EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << endl << count << " characters read\n";
	return 0;
}