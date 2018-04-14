#pragma once

//所有键盘操作的集合


void ClickOneLetter(char ch)			//用于进行一个字母的书写	
{
	keybd_event(ch, 0, 0, 0);//按下a键
	keybd_event(ch, 0, KEYEVENTF_KEYUP, 0);//松开a键
}


void LowerCase(char ch)
{
	//小写字母差一个大小写的阶位
	ClickOneLetter(ch - ('a' - 'A'));
}

void ShiftClick(char ch)
{
	keybd_event(16, 0, 0, 0);//按下Shift键
	ClickOneLetter(ch);
	keybd_event(16, 0, KEYEVENTF_KEYUP, 0);//松开Shift键
}


bool DotExchange(char &ch)		//标点符号的转换		非shift
{
	if (ch == '[') { ch = 219; return true; }
	else if (ch == ']') { ch = 221; return true; }
	else if (ch == ',') { ch = 188; return true; }
	else if (ch == '.') { ch = 190; return true; }
	else if (ch == '/') { ch = 220; return true; }
	else if (ch == '-') { ch = 189; return true; }
	else if (ch == '=') { ch = 187; return true; }
	return false;
}

bool DotExchangeAdvanced(char &ch)		//标点符号的 shift转换
{
	if (ch == '!') { ch = '1'; return true; }
	else if (ch == '@') { ch = '2'; return true; }
	else if (ch == '#') { ch = '3'; return true; }
	else if (ch == '$') { ch = '4'; return true; }
	else if (ch == '%') { ch = '5'; return true; }
	else if (ch == '^') { ch = '6'; return true; }
	else if (ch == '&') { ch = '7'; return true; }
	else if (ch == '*') { ch = '8'; return true; }
	else if (ch == '(') { ch = '9'; return true; }
	else if (ch == ')') { ch = '0'; return true; }
	if (ch == '{') { ch = 219; return true; }
	else if (ch == '}') { ch = 221; return true; }
	else if (ch == '<') { ch = 188; return true; }
	else if (ch == '>') { ch = 190; return true; }
	else if (ch == '?') { ch = 220; return true; }
	else if (ch == '+') { ch = VK_ADD; return true; }

	return false;
}

bool CharMapped(char ch)			//总函数
{
	//数字
	if (ch >= '0'&&ch <= '9')ClickOneLetter(ch);
	//小写字母
	else if (ch >= 'a'&&ch <= 'z')LowerCase(ch);
	//大写字母
	else if (ch >= 'A'&&ch <= 'Z')ShiftClick(ch);
	//符号的映射及转换，待定		//这里显示的是一层，即不需要shift驱动
	else if (DotExchange(ch) == true)ClickOneLetter(ch);
	//shift的进阶符号
	else if (DotExchangeAdvanced(ch) == true)ShiftClick(ch);

	else
	{
		std::cout << "Can not analysis this symbol,the ASC2 Value of this symbol is：" << ch << std::endl;
		return false;
	}
		
	return true;
}

bool CharMapped(std::string Str)		//函数联合
{
	for (int i = 0; i < Str.length(); i++)
	{
		if (CharMapped(Str.at(i)) == false)
		{
			std::cout << "One of the symbol in type function has been crashed\n";
			return false;
		}
	}
	return true;
}