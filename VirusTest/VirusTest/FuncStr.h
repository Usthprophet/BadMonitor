#pragma once
//example:			keybd_event(ch, 0, 0, 0);//按下a键				keybd_event(ch, 0, KEYEVENTF_KEYUP, 0);//松开a键

#include<string>
void ClickInOnePosition(char ch,int SITUATION)	//进行单一地确认按键，没有自动松键
{
	keybd_event(ch, 0, SITUATION, 0);//按下a键
}

int FuncStr(std::string FStr)		//在这里注册所有的功能键即可直接使用，返回相应功能键的映射
{
	if (FStr == "Enter") { return VK_RETURN; }
	else if (FStr == "Ctrl") { return VK_CONTROL; }
	else if (FStr == "Alt") { return VK_MENU; }
	else if (FStr == "Shift") { return VK_SHIFT; }
	else if (FStr == "Caps") { return VK_CAPITAL; }
	else if (FStr == "Tab") { return VK_TAB; }
	else if (FStr == "Win") { return VK_LWIN; }
	else if (FStr == "Esc") { return VK_ESCAPE; }
	else if (FStr == "Space") { return VK_SPACE; }
	else if (FStr == "Back") { return VK_BACK; }

	//上下左右
	else if (FStr == "Left") { return VK_LEFT; }
	else if (FStr == "Right") { return VK_RIGHT; }
	else if (FStr == "Up") { return VK_UP; }
	else if (FStr == "Down") { return VK_DOWN; }

	else if (FStr[0] == 'F')		//F1到F12的映射
	{
		int StrLen = FStr.length();

		if (StrLen<=1&& StrLen>=4 &&FStr[1]<'0' && FStr[1]>'9')return -1;
		else
		{
			int num = FStr[1] - '0';
			if (StrLen == 3 && FStr[2] >= '0' &&  FStr[2] <= '9')num = num * 10 + FStr[2] - '0';
			return 111+num;
		}
	}
	return -1;
}

bool ClickFuncStr(std::string FStr)		//一长串的命令字符串进行映射并输入的过程
{
	int ch = FuncStr(FStr);

	if (ch > 0)
	{
		ClickOneLetter((char)ch);
		return true;
	}
	else
	{
		std::cout << "In fun[function,on/off] grammer,the factor of function is wrong:" << FStr << "\n";
		return false;
	}
}

bool ClickFuncStr(std::string FStr, std::string SITUATION)		//一个重载，允许不松键
{
	int ch = FuncStr(FStr);

	if (ch > 0)
	{
		if(SITUATION=="ON")		ClickInOnePosition((char)ch,0);
		else if(SITUATION=="OFF")	ClickInOnePosition((char)ch, KEYEVENTF_KEYUP);
		else
		{
			std::cout << "In fun[function,on/off] grammer,the SITUATION must be ON/OFF,but it is :" << SITUATION << "\n";
		}
		return true;
	}
	else
	{
		std::cout << "In fun[function,on/off] grammer,the factor of function is wrong:" << FStr << "\n";
		return false;
	}
}


void NOOOOOP(std::string tt)
{
	int t = atoi(tt.c_str());
	Sleep(t);
}