#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[2][n];
	int sum = 0;
	int max = 0;
	int i;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[0][i] >> array[1][i];
	}
	
	for(i = 0; i < n; i++)
	{
		sum -= array[0][i];
		sum += array[1][i];
		if(max < sum)
		{
			max = sum;
		}
	}
	
	cout << max;
	return 0;
}