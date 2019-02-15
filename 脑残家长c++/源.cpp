#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<windows.h>
#define GMEM_MOVEABLE 0x0002
#define CF_TEXT 1
using namespace std;

void SetDataToClip(char txt[1000000])
{
	// 打开剪贴板   
	if(!OpenClipboard(NULL) || !EmptyClipboard())
	{
		printf("打开或清空剪切板出错！/n");
		return;
	}

	HGLOBAL hMen;

	// 分配全局内存    
	hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(txt) + 1) * sizeof(string)));

	if(!hMen)
	{
		printf("分配全局内存出错！/n");
		// 关闭剪切板    
		CloseClipboard();
		return;
	}

	// 把数据拷贝考全局内存中   
	// 锁住内存区    
	LPSTR lpStr= (LPSTR)GlobalLock(hMen);

	// 内存复制   
	memcpy(lpStr, txt, ((strlen(txt)) * sizeof(TCHAR)));
	// 字符结束符    
	lpStr[strlen(txt)] = (TCHAR)0;
	// 释放锁    
	GlobalUnlock(hMen);

	// 把内存中的数据放到剪切板上   
	SetClipboardData(CF_TEXT, hMen);
	CloseClipboard();

	return;
}

int main()
{
	char k;
start:
	{
		string people;
		printf("请输入QQ群人数:\n");
		cin >> people;
		//SetDataToClip(people);
		string event1;
		printf("请输入事件1:\n");
		cin >> event1;

		string event2;
		printf("请输入事件2:\n");
		cin >> event2;

		string str1 = "你们这个是什么群啊?你们这是害人不浅啊你们这个群!麻烦你们，真的太过分了!你们搞这个群干什么?我儿子每一科的成绩都不过那个平均分呐，他现在初二!你叫我儿子怎么办啊!他还不到高中啊好不好!你们这是什么群啊?你们害死我儿子了!谁是群主?快点出来你们群主!再不来我去报警了啊!我跟你们说你们这一帮人啊，一天到晚啊搞这些什么";//ev1
		string str2 = "啊什么";//ev2
		string str3 = "啊会害死你们哒！你们没有前途?我跟你说你们这";//people
		string str4 = "多个人好好学习不好吗，一天到晚在";//ev2
		string str5 = "有什么意思，有什么意思啊!麻烦你们重视一下你们生活的目标好不好?有一点学习目标好不好?一天到晚";//ev2
		string str6 = "是不是人啊?你们一天到晚";//ev2
		string str7 = "不好好学习,会没前途的!";//ev2
		string str8 = "害死人!";

		string outtxt = str1 + event1 + str2 + event2 + str3 + people + str4 + event1 + str5 + event1 + str6 + event1 + str7 + event1 + str8;
		cout << outtxt << endl;

		char out2[1000000];
		strcpy_s(out2, outtxt.c_str());
		//cout << out2 << endl;
		SetDataToClip(out2);
		cout << "\n\n\n\n" << endl;
		cout << "这段文字复制到了剪切板\n" << endl;
	}
	cout << "需要再生成一段吗？(输入y回车继续,输入f怒斥阿姨)" << endl;
	cin >> k;
	if (k == 'y')
		goto start;
	else if (k == 'f')
	{
		char out3[10000]="阿姨，您好，本群除了你儿子以外，成员跨越全球，人均985，211毕业，当然还有国外高校的，掌握多种科学技术知识与神学理论，清楚分析全球各国时政新闻，从属行业包括但不限于政治家，数学家，历史学家，计算机行业，航空航天体系，军事指挥体系（绝大部分曾担任国家高级军事指挥官，拥有丰富作战经验）对所有领域都有深入涉及，请问：你儿子算什么东西？";
		SetDataToClip(out3);
		cout << "怒斥阿姨的文字复制到了剪切板\n" << endl;
	}
	else
		system("pause");
	return 0;
}