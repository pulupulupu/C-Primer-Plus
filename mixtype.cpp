#include<iostream>
struct antarctica_years_end
{
    int year;

};
int main(void)
{
    antarctica_years_end s01,s02,s03;   //���������ṹ����
    s01.year=1998;  
    antarctica_years_end *pa=&s02;  //����ָ��antarctica_years_end�ṹ��ָ��pa��������ָ��s02
    pa->year=1999;  //ͨ��paָ��Ϊs02�ĳ�Ա������ֵ
    antarctica_years_end trio[3];  //������������antarctica_years_end�ṹԪ�ص�����trio
    trio[0].year=2003;  //Ϊtrio����ĵ�һ��Ԫ�ظ�ֵ
    std::cout<<trio->year<<std::endl; //������C++�У�������������Ϊ�����һ��Ԫ�صĵ�ַ���˴���Ϊ��ӡtrio�����һ��Ԫ�صĳ�Ա����year��ֵ����trio[0].year Ҳ����2003
    const antarctica_years_end *arp[3]={&s01,&s02,&s03};  //����ָ�����飬��ʹ��s01,s02,s03�ĵ�ַΪ�������ڵ�ָ���ʼ����ʹ��ָ����Ӧ��λ��
    std::cout<<arp[1]->year<<std::endl;  //��ӡ����ڶ���Ԫ�صĳ�Ա����ֵ����s02.year��ֵ1999 
                                          //Ҳ��ʹ�� std::cout<<(*arp[1]).year<<std::endl 
    const antarctica_years_end **ppa=arp;  //����arpΪָ�����飬�˴�����һ��ָ��ָ���ָ�룬����ָ��arp������˵arp�е�һ��Ԫ��s01
    auto ppb=arp; //��������һ��ָ��ָ���ָ��ppb���˴�ʹ��auto�ؼ����Զ��ж������͡�ָ��ppbͬppa
    std::cout<<(*ppa)->year<<std::endl;   //ͬline 15���˴���ӡarp�����һ��Ԫ����ָ��Ľṹ��Ա������ֵ����s01.year Ҳ��ʹ�������������滻��
                                        // std::cout<<(**ppa).year<<std::endl;
    std::cout<<(*(ppb+1))->year<<std::endl;  //ͬline15 �˴���ӡarp����ڶ���ָ����ָ��Ľṹ�����ĳ�Ա����ֵ����s02.year
    return 0;
}