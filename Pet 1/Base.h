#pragma once
class Base
{
public:
	bool patency = true;
	bool eatable = false;
	char texture = 'O';
	unsigned short x = 0, y = 0;
	Base(char text, bool patency, bool eatable = false) : texture(text), patency(patency), eatable(eatable)
	{
	}
	Base(){}
};

