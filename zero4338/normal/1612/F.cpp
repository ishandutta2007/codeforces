#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m,k;
int ans;
set<pair<int,int>>pa;
queue<pair<int,int>>q;
int mx[maxn];
int main()
{
	n=read();m=read();
	k=read();while(k--){int a=read(),b=read();if(n<m)swap(a,b);pa.insert({a,b});}
	if(n<m)swap(n,m);
	q.push({1,1});
	while(true)
	{
		while(!q.empty())
		{
			pair<int,int>now=q.front();q.pop();
			if(now.first==n&&now.second==m){printf("%d\n",ans);return 0;}
			int val=now.first+now.second+pa.count({now.first,now.second});
			mx[now.second]=max(mx[now.second],min(n,val));
			mx[min(m,val)]=max(mx[min(m,val)],now.first);
		}
		int now=0;
		for(int i=m;i>=1;i--)
			if(mx[i]>now){q.push({mx[i],i});now=mx[i];}
		ans++;
	}
	return 0;
}