#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define pb push_back
#define ll long long
#define trav(v,x) for(auto v:x)
using namespace std;
const int N = 1e6 + 100;

int n;
int a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				cout << "(";
			}
			for(int j = 1; j <= i; j++)
			{
				cout << ")";
			}
			for(int j = 1; j <= n - i; j++)
			{
				cout << "(";
			}
			for(int j = 1; j <= n - i; j++)
			{
				cout << ")";
			}
			cout << '\n';
		}
	}
	return 0;
}