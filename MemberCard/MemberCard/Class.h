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
	enum MemberPriorities { normal, vip };//设置会员等级 枚举
	MemberPriorities MemberPriority;  //会员等级，在MemberCard里初始化为normal 即普通用户
public:                                //一次性氪金10000块后自动升级为vip

	RMB income, outcome, balance;
	MemberCard(int,string,string,string); //:Members(MemberName, PassCode, PhoneNumber);
	~MemberCard(){}
	friend ostream&operator<<(ostream&, const MemberCard&);
	void recharge();
	void cost();
	void query();
	string get_membername();
};