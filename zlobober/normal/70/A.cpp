#include <iostream>
#include <cstdio>
using namespace std;

//#define TASK ""

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n;
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		ans = (ans * 3) % 1000003;
	cout << ans;
	return 0;
}