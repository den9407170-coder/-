#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a{};
	for (int i = 1; i <= 10; i++)
	{
		a++;
		cout << a << " " << "index = " << i << endl;
		/*if (i == 5)
		{
		return 0;
		}*/
	}
}
