#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" ,stdout);
	int n, k;
	cin >> n >> k;
	k--;
	const int N = 1050;
	int A[N];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	while (!A[k])
	{
		k = (k + 1) % n;
	}
	cout << k + 1;
}