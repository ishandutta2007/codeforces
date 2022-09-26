#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

int a[100001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int cur = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			cur = 1; ans = 1;
		}
		else
		{
			if(a[i] > a[i-1])
			{
				cur++;
				ans = max(cur, ans);
			}
			else
			{
				ans = max(cur, ans);
				cur = 1;
			}
		}
	}
	cout << ans;
	return 0;
}