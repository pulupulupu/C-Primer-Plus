#include<iostream>
#include<string>
#include<vector>
#include"Class.h"

using namespace std;
void FindMember(vector<MemberCard>&,bool);



int main(void)
{
	int choice;
	vector<MemberCard> MemberCards;
	do
	{
		cout << "please choice:\n";
		cout << "1 : new member, 2 : recharge, 3 : purchase , 4 :list all members,other number is over! " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "input information of new member : " << endl;
			string MemberName, PassCode, PhoneNumber;
			cout << "please input name: " << endl;
			cin >> MemberName;
			cout << "please input code: " << endl;
			cin >> PassCode;
			cout << "please input phone number : " << endl;
			cin >> PhoneNumber;
			int MemberNumber = MemberCards.size();
			MemberCard NewMemberCard(MemberNumber,MemberName, PassCode, PhoneNumber); //�����»�Ա
			MemberCards.push_back(NewMemberCard); //����Ա��ӵ���Ա������

			cout.fill(' ');//���������ʽ
			cout << left << setw(15) << "number" << setw(15) << "name" << setw(15) << "phone" << "balance" << endl;
			cout << NewMemberCard << endl;
			break;
		}
		case 2:
			FindMember(MemberCards,true);
			break;
		case 3:
			FindMember(MemberCards,false);
			break;
		case 4://�г����л�Ա����
		{
			cout.fill(' ');
			cout << left << setw(15) << "number" << setw(15) << "name" << setw(15) << "phone" << "balance" << endl;
			for (MemberCard i : MemberCards)
			  cout << i << endl;
			break;
		}
		default:
			choice = 0;
		}
	}while (choice);
	return 0;
}
void FindMember(vector<MemberCard>& MemberCards,bool LoginCode)
{
	string TempMemberName;
	cout << "please input your name : " << endl;
	cin >> TempMemberName;
	for (MemberCard &i : MemberCards)//���һ�Ա
	{
		if (TempMemberName == i.get_membername())
		{
			if (LoginCode)
				i.recharge();
			else
				i.cost();
			break;
		}
	}
}
