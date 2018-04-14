#pragma once

#include<cstdlib>

POINT GetPosition()				//获取当前鼠标位置的方法
{
	POINT point;
	GetCursorPos(&point);
	//std::cout << "The position of mouse (X,Y) is :(" << point.x <<"  "<< point.y << ")\n";
	return point;
}

void MouseRegulation()		//鼠标校准
{
	POINT pointer=GetPosition();
	POINT tempPoint = pointer;

	while (true)
	{
		pointer = GetPosition();
		if (pointer.x != tempPoint.x||pointer.y!=tempPoint.y)
		{
			std::cout <<"x:"<< pointer.x << " y:" << pointer.y<<"\n";
			tempPoint = pointer;
		}
	}
}


/*
		参数参考
		MOUSEEVENTF_LEFTDOWN		这表示鼠标左键按下
		MOUSEEVENTF_LEFTUP			这表示鼠标左键松开
		MOUSEEVENTF_RIGHTDOWN		这表示鼠标右键按下
		MOUSEEVENTF_RIGHTUP			这表示鼠标右键松开
		MOUSEEVENTF_MIDDLEDOWN		这表示鼠标中键按下
		MOUSEEVENTF_MIDDLEUP		这表示鼠标中键松开

*/

void ClickByOnce(POINT point,int SITUATION)				//对某个鼠标的操作进行单次运行
{
	SetCursorPos(point.x, point.y);
	mouse_event(SITUATION, 0, 0, 0, 0); //左键按下  
}

bool ClickByOnce(std::string x,std::string y,std::string POSITION,std::string SITUATION)		//参数对接,将ON/OFF分开
{
	POINT point;
	point.x = atoi(x.c_str());
	point.y = atoi(y.c_str());
	int SITUINT = -1;

	if (SITUATION == "ON")
	{
		if (POSITION == "left")SITUINT = MOUSEEVENTF_LEFTDOWN;
		else if(POSITION=="right")SITUINT = MOUSEEVENTF_RIGHTDOWN;
		else std::cout << "A wrong Grammer for the factor POSITION in Click(With ON/OFF)is:" << POSITION << "\n";
	}
	else if (SITUATION == "OFF")
	{
		if (POSITION == "left")SITUINT = MOUSEEVENTF_LEFTUP;
		else if (POSITION == "right")SITUINT = MOUSEEVENTF_RIGHTUP;
		else std::cout << "A wrong Grammer for the factor POSITION in Click(With ON/OFF)is:" << POSITION << "\n";
	}
	else std::cout << "A mistake in Click (With ON/OFF),the factor of SITUATION must be ON/OFF,but it is:" << SITUATION << "\n";


	if (SITUINT == -1)std::cout << "A wrong situation in Click\n";
	else ClickByOnce(point,SITUINT);

	return true;
}

bool ClickByOnce(std::string x, std::string y, std::string POSITION)		//重载，没有situation,默认点击一下立即松手
{
	POINT point;
	point.x = atoi(x.c_str());
	point.y = atoi(y.c_str());
	int SITUINT = -1;

	if (POSITION == "left")
	{
		SITUINT = MOUSEEVENTF_LEFTDOWN;
		ClickByOnce(point, SITUINT);
		SITUINT = MOUSEEVENTF_LEFTUP;
		ClickByOnce(point, SITUINT);
	}
	else if (POSITION == "right")
	{
		SITUINT = MOUSEEVENTF_RIGHTDOWN;
		ClickByOnce(point, SITUINT);
		SITUINT = MOUSEEVENTF_RIGHTUP;
		ClickByOnce(point, SITUINT);
	}
	else std::cout << "A wrong Grammer for the factor POSITION in Click(Without Facotr)is:" << POSITION << "\n";
	if (SITUINT == -1)std::cout << "A wrong situation in Click(Without Factor)\n";

	return true;
}


