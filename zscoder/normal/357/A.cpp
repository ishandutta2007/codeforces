#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int i, n;
	cin >> n;
	int array[n];
	int x, y;
	
	int ans = -1;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	cin >> x;
	cin >> y;
	
	int sum = 0, cumul = 0;
	
	for(i = 0; i < n; i++)
	{
		sum += array[i];
	}
	
	for(i = 0; i < n; i++)
	{
		if(x <= cumul && y >= cumul && x <= sum - cumul && y >= sum - cumul)
		{
			ans = i;
			break;
		}
		else
		{
			cumul += array[i];
		}
	}
	
	cout << ans + 1;
	return 0;
}