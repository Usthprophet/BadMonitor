#include<iostream>
#include<windows.h>

#include"TypeKeyBoard.h"
#include"FuncStr.h"
#include"MouseEvent.h"
#include"FileControl.h"
#include"JudgeLetter.h"

using namespace std;

// kc ku   
 
#pragma comment (lib,"Urlmon.lib") 
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
int main(int argc, char* argv[])
{
	JudgeLetter::Test("abc.txt");
	return 0;
}