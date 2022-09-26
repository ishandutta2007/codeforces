#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int array[num];
	int i;
	bool answer = true;
	for(i = 0; i < num; i++)
	{
		cin >> array[i];
	}
	
	int a = 0, b = 0;
	
	for(i = 0; i < num; i++)
	{
		if(array[i] == 25)
		{
			a += 1;
		}
		else if(array[i] == 50)
		{
			b += 1;
			if(a > 0)
			{
				a -= 1;
			}
			else
			{
				answer = false;
				break;
			}
		}
		else
		{
			if(b > 0)
			{
				b -= 1;
				if(a > 0)
				{
					a -= 1;
				}
				else
				{
					answer = false;
				}
			}
			else if(b == 0 && a >= 3)
			{
				a -= 3;
			}
			else
			{
				answer = false;
			}
		}
	}
	
	if(answer)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}