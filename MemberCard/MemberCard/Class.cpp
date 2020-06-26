#include "Class.h"


RMB::RMB(int y = 0, int j = 0, int f = 0)
{
	this->yuan = y;
	this->jiao = j;
	this->fen= f;
}
RMB::RMB(double x)
{
	int n = int((x + 0.005) * 100);
	yuan = n / 100;
	jiao = (n - yuan * 100) / 10;
	fen = n % 10;
}
RMB::operator double()
{
	return (yuan + jiao * 0.1 + fen * 0.01);
}
ostream & operator<<(ostream&output, const RMB &m)
{
	output << m.yuan << "圆" << m.jiao << "角" << m.fen << "分" << endl;
	return output;
}
istream & operator>>(istream&input, RMB &m)
{
	cout << "圆: ";
	input >> m.yuan;
	cout << "角: ";
	input >> m.jiao;
	cout << "分: ";
	input >> m.fen;
	return input;
}
Members::Members(int MemberNumber,string Name,string PassCode,string PhoneNumber)
{
	this->MemberNumber = MemberNumber;
	this->MemberName = Name;
	this->PassCode = PassCode;
	this->PhoneNumber = PhoneNumber;

}
Members::~Members()
{
}
ostream&operator<<(ostream&output, Members Member)
{
	output << "the information of member:" << endl;
	output.fill(' ');
	output <<left<< "number" <<setw(15)<< "name" << setw(15) << "phone" << endl;
    output <<left<< Member.MemberNumber << setw(15) << Member.MemberName << setw(15) << Member.PhoneNumber << endl;
	return output;
}
MemberCard::MemberCard(int MemberNumber,string MemberName, string PassCode, string PhoneNumber) :Members(MemberNumber,MemberName, PassCode, PhoneNumber)
{
	balance = 0;
	income = 0;
	outcome = 0;
	this->MemberNumber;
	this->MemberName = MemberName;
	this->PassCode = PassCode;
	this->PhoneNumber = PhoneNumber;
	this->MemberPriority = normal;
	
}
ostream&operator<<(ostream&output, const MemberCard& Membercard)
{
	//output << "the information of member:" << endl;
	//output.fill(' ');
	//output <<left<<setw(15)<< "number" << setw(15) << "name" << setw(15) << "phone" << "balance" << endl;
	output <<left<<setw(15)<<Membercard.MemberNumber<<setw(15)<<Membercard.MemberName <<  setw(15) << Membercard.PhoneNumber << Membercard.balance << endl;
	return output;
}
void MemberCard::recharge()
{
	cout << "How much do you want to recharge?" << '\n' << "please input the money : " << endl;
	cin >> income;
	balance = balance + income;
	cout << "your balance : " << balance << endl;
	if (income > 10000)    //一次性氪金10000块，升级成为vip
		MemberPriority = vip;
} 
void MemberCard::cost()
{
	string TempPassCode;
	cout << "please input your passcode : " << endl;
	cin >> TempPassCode;
	if (TempPassCode==PassCode)
	{
		cout << "please input the money you cost : " << endl;
		cin >> outcome;
		if (outcome > balance)
		{
			cout << "your balance is not enough ! " << endl;
		}
		else
		{
			if (MemberPriority == vip)
				balance = balance - 0.3*outcome;
			balance = balance - outcome;
			cout << "your balance : " << balance;
		}
	}
	else
	{
		cout << "your code is wrong ! " << endl;
	}
}
void MemberCard::query() { cout << "your balance : " << balance; }
string MemberCard::get_membername() { return MemberName; }