#pragma once

#include<string>
#include<fstream>
#include<sstream>



//用于文件读写的操作

//从文件读入到string里  
std::string readFileIntoString(const char * filename)
{
	std::ifstream ifile(filename);
	//将文件读入到ostringstream对象buf中  
	std::ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	//返回与流对象buf关联的字符串  
	return buf.str();
}

int testText()
{
	//文件名  
	char * fn = "a.txt";
	std::string str;
	str = readFileIntoString(fn);
	std::cout << str << std::endl;
	system("pause");

	return 0;
}