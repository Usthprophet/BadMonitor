#include<iostream>
#include<windows.h>

#include"TypeKeyBoard.h"
#include"FuncStr.h"
#include"MouseEvent.h"
#include"FileControl.h"
#include"JudgeLetter.h"

using namespace std;

// kc ku   
 
//#pragma comment (lib,"Urlmon.lib") 
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 


int main(int argc, char* argv[])
{




	std::string FileStr = argv[1];

	//FileStr = "asd.txt";

	JudgeLetter::Test(FileStr);
	return 0;
}