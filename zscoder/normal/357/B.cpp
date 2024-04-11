#include <iostream>

using namespace std;


int f(int x)
{
	if(x % 3 == 0)
	{
		return 3;
	}
	else
	{
		return x % 3;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	
	int array[3][m];
	int color[n];
	
	int i;
	
	
	for(i = 0; i < m; i++)
	{
		cin >> array[0][i] >> array[1][i] >> array[2][i];
		array[0][i] -= 1;
		array[1][i] -= 1;
		array[2][i] -= 1;
	}
	
	for(i = 0; i < n; i++)
	{
		color[i] = 0;
	}
	
	for(i = 0; i < m; i++)
	{
		if(color[array[0][i]] == 0 && color[array[1][i]] == 0 && color[array[2][i]] == 0)
		{
			color[array[0][i]] = 1;
			color[array[1][i]] = 2;
			color[array[2][i]] = 3;
		}
		else if(color[array[0][i]] != 0 && color[array[1][i]] ==  0 && color[array[2][i]] == 0)
		{
			color[array[1][i]] = f(color[array[0][i]] + 1);
			color[array[2][i]] = f(color[array[0][i]] + 2);
		}
		else if(color[array[1][i]] != 0 && color[array[0][i]] == 0 && color[array[2][i]] == 0)
		{
			color[array[0][i]] = f(color[array[1][i]] + 1);
			color[array[2][i]] = f(color[array[1][i]] + 2);
		}
		else if(color[array[2][i]] != 0 && color[array[1][i]] == 0 && color[array[0][i]] == 0)
		{
			color[array[1][i]] = f(color[array[2][i]] + 1);
			color[array[0][i]] = f(color[array[2][i]] + 2);
		}
		else if(color[array[0][i]] == 0 && color[array[1][i]] != 0 && color[array[2][i]] != 0)
		{
			color[array[0][i]] = f(color[array[1][i]] + 1);
			if(color[array[0][i]] == color[array[2][i]])
			{
				color[array[0][i]] += 1;
				color[array[0][i]] = f(color[array[0][i]]);
			}
		}
		else if(color[array[1][i]] == 0 && color[array[0][i]] != 0 && color[array[2][i]] != 0)
		{
			color[array[1][i]] = f(color[array[0][i]] + 1);
			if(color[array[1][i]] == color[array[2][i]])
			{
				color[array[1][i]] += 1;
				color[array[1][i]] = f(color[array[1][i]]);
			}
		}
		else if(color[array[2][i]] == 0 && color[array[1][i]] != 0 && color[array[0][i]] != 0)
		{
			color[array[2][i]] = f(color[array[1][i]] + 1);
			if(color[array[2][i]] == color[array[0][i]])
			{
				color[array[2][i]] += 1;
				color[array[2][i]] = f(color[array[2][i]]);
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		cout << color[i] << " ";
	}
	return 0;
}