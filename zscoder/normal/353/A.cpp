#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[2][n];
	int i;
	bool ans = false;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[0][i] >> array[1][i];
	}
	
	int s1 = 0, s2 = 0;
	
	for(i = 0; i < n; i++)
	{
		s1 += array[0][i];
		s2 += array[1][i];
	}
	
	if(s1 %2 != s2 % 2)
	{
		cout << -1;
	}
	
	else if(s1 % 2 == 0 && s2 % 2 == 0)
	{
		cout << 0;
	}
	
	else
	{
		for(i = 0; i < n; i++)
		{
			if(array[0][i] % 2 != array[1][i] % 2)
			{
				ans = true;
				break;
			}
		}
		if(ans)
		{
			cout << 1;
		}
		else
		{
			cout << -1;
		}
	}
	
	return 0;
}