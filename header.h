#include <iostream>

#include <conio.h>

using namespace std;

#define LEN 65536
#define MAX 256

char arr[LEN] = { 0 };
unsigned int p = 0;

int furthest = 0;

void compile(char* command)
{
	for (int i = 0; i < LEN; i ++)
	{
		arr[i] = 0;
	}

	for (int ip = 0; ip < strlen(command); ip++)
	{
		switch (command[ip])
		{
			case '+': //inc
				if (arr[p] < MAX) arr[p]++;
				break;
			case '-': //dec
				if (arr[p] > 0) arr[p]--;
				break;
			case '>': //inc ptr
				if (p < LEN) p++;
				if (p > furthest) furthest = p;
				break;
			case '<': //dec ptr
				if (p > 0) p--;
				break;
			case '.': //out
				cout << arr[p];
				break;
			case ',': //in
				arr[p] = _getch();
				break;
			case '[': //open loop
				if (arr[p] == 0)
				{
					int bracketCount = 1;
					while (bracketCount != 0)
					{
						ip++;
						if (command[ip] == '[') bracketCount++;
						if (command[ip] == ']') bracketCount--;
					}
				}
				break;
			case ']': //close loop
				if (arr[p] != 0)
				{
					int bracketCount = 1;
					while (bracketCount != 0)
					{
						ip--;
						if (command[ip] == ']') bracketCount++;
						if (command[ip] == '[') bracketCount--;
					}
				}
				break;
		}
	}
}

void showFinal()
{
	cout << endl;
	for (int i = 0; i <= furthest; i++)
	{
		if (i == p)
		{
			cout << "{" << int(arr[i]) << "}";
		}
		else if (i == furthest)
		{
			cout << int(arr[i]);
		}
		else
		{
			cout << int(arr[i]) << ", ";
		}
	}
	cout << endl;
}
