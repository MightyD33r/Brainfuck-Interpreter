#include "header.h"

int main(int argc, char** argv)
{
	cout << "Ay this is some brainfuck stuff" << endl << endl;

	char command[1024] = { 0 };
	
	while (true)
	{
		cin.getline(command, 1024);

		compile(command);

		showFinal();
	}

	system("pause");
	return 0;
}
