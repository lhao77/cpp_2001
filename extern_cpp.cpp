#include <iostream>

extern "C" void tcpp()
{
	std::cout<<"In cpp tcpp()"<<std::endl;
}

/*
extern "C"
{
	void tc();
}
*/

extern "C" void tc();

//以上2种方式都可以。

int main()
{
	tc();
}

