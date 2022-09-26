#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>

using namespace std;

#define INF = 200000000;
typedef long long ll;
typedef vector<int> vi;

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	cin >> a >> b;
	vi A;
	vi B;
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		A.push_back(x);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(A.at(a - 1) < B.at(m - b))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}