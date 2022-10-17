/*********************************************************************
    > File Name: 1385_F.cpp
    > Author: yuki
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> cnt;

struct cmp
{
	bool operator() (int i, int j)
	{
		return cnt[i] < cnt[j];
	}
};

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		vector<vector<int>> mp(n+1);
		vector<int> num(n+1, 0);
		for(int i=1; i<n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			mp[x].push_back(y);
			mp[y].push_back(x);
			num[x]++;
			num[y]++;
		}
		if(k == 1)
		{
			printf("%d\n", n-1);
			continue;
		}
		cnt=vector<int>(n+1, 0);
		for(int i=1; i<=n; i++)
		{
			if(num[i] == 1)
			{
				cnt[i]=-1;
				continue;
			}
			for(auto j : mp[i])
				if(num[j] == 1) cnt[i]++;
		}
		priority_queue<int, vector<int>, cmp> pq;
		vector<bool> vis(n+1, 0);
		for(int i=1; i<=n; i++)
			if(cnt[i] >= k)
			{
				pq.push(i);
				vis[i]=1;
			}
		if(pq.empty())
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		while(!pq.empty())
		{
			int now=pq.top();
//			printf("!%d %d\n", now, cnt[now]);
			pq.pop();
			vis[now]=0;
			cnt[now]-=k;
			num[now]-=k;
			ans++;
			if(cnt[now] >= k)
			{
				pq.push(now);
				vis[now]=1;
			}
			if(num[now] == 1)
			{
				num[now]=0;
				for(auto nxt : mp[now])
				{
					if(num[nxt] == 0) continue;
					cnt[nxt]++;
					if(!vis[nxt] && cnt[nxt]>=k)
					{
						pq.push(nxt);
						vis[nxt]=1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}