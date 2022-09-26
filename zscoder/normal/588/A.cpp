#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cstdlib>
#include <functional>

using namespace std;
int a[100001], p[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int min_price = 10000000;
	long long cost = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> p[i];
		min_price = min(min_price, p[i]);
		cost += a[i]*min_price;
	}
	cout << cost;
	return 0;
}