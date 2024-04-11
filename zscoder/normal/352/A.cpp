#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[n];
	int count5 = 0, count0 = 0;
	//this->(1+2+3 or 4)
	for(int i = 0; i < n; i++)
	{
		cin >> array[i];
		if(array[i] == 0)
		{
			count0++;
		}
		else
		{
			count5++;
		}
	}
	if(count0 > 0)
	{
		count5 -= (count5 % 9);
		if(count5 > 0)
		{
			for(int i = 0; i < count5; i++)
			{
				cout << "5";
			}
		}
		if(count5 == 0)
		{
			cout << "0";
		}
		else
		{
			for(int i = 0; i < count0; i++)
			{
				cout << "0";
			}
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}