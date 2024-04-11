#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned long long int n, k;
	cin >> n;
	cin >> k;
	unsigned long long int i = n/2 + n%2;
	if(k <= i)
	{
		cout << (2*k - 1) << endl;
	}
	else
	{
		cout << (2*(k - i)) << endl;
	}
	return 0;
}