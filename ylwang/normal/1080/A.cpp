#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)

using namespace std;

int main()
{
	double n, k;
	cin >> n >> k;
	int a = ceil(2*n/k) + ceil(5*n/k) + ceil(8*n/k);
	cout << a << endl;
	return 0;
}