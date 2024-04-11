#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int n,to;
vector<int>p[6];
int cnt[6][6];
bool check()
{
	for(int i=1;i<(1<<to);i++)
	{
		int sum=0;
		for(int j=0;j<to;j++)if((i>>j)&1)sum+=p[j].size();
		for(int j=0;j<to;j++)if((i>>j)&1)for(int k=j;k<to;k++)if((i>>k)&1)sum-=cnt[j][k];
		if(sum<=0)return false;
	}
	return true;
}
bool solve()
{
	for(int i=0;i<to;i++)
		for(int j=i;j<to;j++)
			if(cnt[i][j])
			{
				if(p[i].size()>1)
				{
					int now=p[i].back();p[i].pop_back();cnt[i][j]--;
					if(check()){printf("%d %d\n",now,p[j][0]);return true;}
					cnt[i][j]++;p[i].push_back(now);
				}
				if(p[j].size()>1)
				{
					int now=p[j].back();p[j].pop_back();cnt[i][j]--;
					if(check()){printf("%d %d\n",now,p[i][0]);return true;}
					cnt[i][j]++;p[j].push_back(now);
				}
			}
	return false;
}
int main()
{
	n=read();to=log10(n)+1;
	for(int i=1;i<n;i++)
	{
		string s,t;cin>>s>>t;
		if(s.size()>t.size())swap(s,t);
		cnt[s.size()-1][t.size()-1]++;
	}
	for(int i=1;i<=n;i++)p[(int)log10(i)].push_back(i);
	if(!check()){puts("-1");return 0;}
	while(solve());
	for(int i=0;i<to;i++)
		for(int j=i;j<to;j++)if(cnt[i][j])printf("%d %d\n",p[i][0],p[j].back());
	return 0;
}