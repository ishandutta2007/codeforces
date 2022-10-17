/*********************************************************************
    > File Name: 1385_D.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=(1<<17)+5;

int n;
char s[maxn];
int dp[maxn][18];

int dfs(int x, int l, int r)
{
	if(l == r) return (s[l]!=(x+'a'));
	if(dp[l][x] != -1) return dp[l][x];
	int mid=(l+r)/2;
	int cnt1=0, cnt2=0;
	for(int i=l; i<=r; i++)
		if(s[i] != (x+'a'))
		{
			if(i <= mid) cnt1++;
			else cnt2++;
		}
	dp[l][x]=min(cnt1+dfs(x+1, mid+1, r), cnt2+dfs(x+1, l, mid));
	return dp[l][x];
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		scanf("%s", s+1);
//		memset(dp, -1, sizeof(dp));
		for(int i=1; i<=n; i++)
			for(int j=0; j<18; j++) dp[i][j]=-1;
		int ans=dfs(0, 1, n);
		printf("%d\n", ans);
	}
	return 0;
}