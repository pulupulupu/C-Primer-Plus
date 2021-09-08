#include<iostream>
struct antarctica_years_end
{
    int year;

};
int main(void)
{
    antarctica_years_end s01,s02,s03;   //创建三个结构变量
    s01.year=1998;  
    antarctica_years_end *pa=&s02;  //创建指向antarctica_years_end结构的指针pa，并将其指向s02
    pa->year=1999;  //通过pa指针为s02的成员变量赋值
    antarctica_years_end trio[3];  //创建含有三个antarctica_years_end结构元素的数组trio
    trio[0].year=2003;  //为trio数组的第一个元素赋值
    std::cout<<trio->year<<std::endl; //由于在C++中，数组名被解释为数组第一个元素的地址，此处即为打印trio数组第一个元素的成员变量year的值，即trio[0].year 也就是2003
    const antarctica_years_end *arp[3]={&s01,&s02,&s03};  //创建指针数组，并使用s01,s02,s03的地址为该数组内的指针初始化，使其指向相应的位置
    std::cout<<arp[1]->year<<std::endl;  //打印数组第二个元素的成员变量值，即s02.year的值1999 
                                          //也可使用 std::cout<<(*arp[1]).year<<std::endl 
    const antarctica_years_end **ppa=arp;  //由于arp为指针数组，此处创建一个指向指针的指针，将其指向arp，或者说arp中第一个元素s01
    auto ppb=arp; //创建创建一个指向指针的指针ppb，此处使用auto关键字自动判断其类型。指针ppb同ppa
    std::cout<<(*ppa)->year<<std::endl;   //同line 15：此处打印arp数组第一个元素所指向的结构成员变量的值，即s01.year 也可使用以下语句进行替换：
                                        // std::cout<<(**ppa).year<<std::endl;
    std::cout<<(*(ppb+1))->year<<std::endl;  //同line15 此处打印arp数组第二个指针所指向的结构变量的成员变量值，即s02.year
    return 0;
}