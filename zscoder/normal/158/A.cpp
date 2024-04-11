#include <iostream>

using namespace std;

int main()
{
	int n, k;
	
	cin >> n;
	cin >> k;
	
	int array[n];
	
	int i;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	int count = 0;
	for(i = 0; i < n; i++)
	{
		if(array[i] >= array[k - 1] && array[i] > 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	
	cout << count;
	return 0;
}