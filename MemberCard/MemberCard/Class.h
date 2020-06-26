#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class RMB
{
	int yuan, jiao, fen;
public:
	RMB(int, int, int);
	RMB(double );
	operator double();
	~RMB() {};
	friend ostream & operator<<(ostream&, const RMB&);
	friend istream & operator>>(istream&, RMB&);


};

class Members
{
protected:
	string MemberName, PassCode, PhoneNumber;
	int MemberNumber;
	
public:
	Members(int,string,string,string);
	
	~Members();
	friend ostream & operator<<(ostream&,Members);
	// friend istream&operator>>(istream&input, Members Member);
};

class MemberCard :public RMB, public Members
{
	enum MemberPriorities { normal, vip };//���û�Ա�ȼ� ö��
	MemberPriorities MemberPriority;  //��Ա�ȼ�����MemberCard���ʼ��Ϊnormal ����ͨ�û�
public:                                //һ����봽�10000����Զ�����Ϊvip

	RMB income, outcome, balance;
	MemberCard(int,string,string,string); //:Members(MemberName, PassCode, PhoneNumber);
	~MemberCard(){}
	friend ostream&operator<<(ostream&, const MemberCard&);
	void recharge();
	void cost();
	void query();
	string get_membername();
};