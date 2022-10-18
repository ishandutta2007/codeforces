#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200010
using std::vector;
int n, a[MAXN], k;
ll ans;
char s[MAXN], c;
vector<int> cnt;
int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	cin>>s;
	for(int i=1; i<=n+1; ++i)
	{
		if(c!=s[i-1])
		{
			std::sort(cnt.begin(), cnt.end());
			for(int i=0; i<k&&i<cnt.size(); ++i) ans-=cnt[i];
			cnt.clear();
			c=s[i-1];
		}
		cnt.push_back(-a[i]);
	}
	printf("%lld", ans);
	return 0;
}