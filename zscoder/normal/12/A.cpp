#include <iostream>

using namespace std;

int main()
{
	char array[3][4];
	int i, j, k, l;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			cin >> array[i][j];
		}
	}
	
	
	bool ans = true;
	for(k = 0; k < 3; k++)
	{
		if(array[k][0] != array[2-k][2])
		{
			ans = false;
			break;
		}
	}
	
	if(ans)
	{
		for(l = 0; l < 3; l++)
		{
			if(array[0][l] != array[2][2-l])
			{
				ans = false;
				break;
			}
		}
	}
	  
	if(ans) 
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}