#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char array[n + 1];
	
	
	char c = 'x';
	char d;
	int	l, u;
	
	cin >> array;
	
	//cout << array[2];
	
	int i;
	 
	for(i = 0; i < n; i++)
	{
		//cout << i << " : " << endl;
		if(c == 'x')
		{
			if(array[i] != '.')
			{
				c = array[i];
				l = i + 1;
				//cout << "l set to " << l << " and c set to " << c << endl;
				//continue;
			}
		}
		else
		{
			if(array[i] == '.')
			{
				d = array[i - 1];
				u = i;
				//cout << "u set to " << u << " and d set to " << d << endl;
				break;
			}
		}
	}
	
	//cout << l << " " << u << endl;
	if(c == d)
	{
		if(c == 'R')
		{
			cout << l << " " << u + 1;
		}
		else
		{
			cout << u << " " << l - 1;
		}
	}
	else
	{
		if(c == 'R')
		{
			cout << l << " ";
			for(i = l - 1; i < u; i++)
			{
				if(array[i] != c)
				{
					cout << i;
					break;
				}
			}
		}
	}
	return 0;
}