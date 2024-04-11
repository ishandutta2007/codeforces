#include <iostream>
using namespace std;

int main()
{
	int n;
	int zv[102];
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> zv[i];
	int a, b;
	cin >> a >> b;
	a--, b--;
	int ans = 0;
	for (int i = a; i < b; i++)
		ans += zv[i];
	cout << ans;
	return 0;
}