#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e5+5;
int n,a[maxn],cnt[maxn],b[maxn];
vector<int>pos[maxn];
set<pair<int,int>>s;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		memset(cnt,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++)pos[i].clear();
		for(int i=1;i<=n;i++)pos[a[i]].push_back(i),cnt[a[i]]++;
		s.clear();
		for(int i=1;i<=n;i++)if(cnt[i])s.insert({cnt[i],i});
		vector<int>now;
		int ls=0;
		while(!s.empty())
		{
			int p=s.rbegin()->second;
			if(ls==p)
			{
				s.erase({cnt[p],p});
				if(s.empty())break;
				int p1=s.rbegin()->second;
				s.erase({cnt[p1],p1});
				cnt[p1]--;
				s.insert({cnt[p],p});
				if(cnt[p1])s.insert({cnt[p1],p1});
				ls=p1;
				now.push_back(pos[p1].back());
				pos[p1].pop_back();
			}
			else
			{
				s.erase({cnt[p],p});
				cnt[p]--;
				if(cnt[p])s.insert({cnt[p],p});
				ls=p;
				now.push_back(pos[p].back());
				pos[p].pop_back();
				
			}
		}
		memset(b,0,sizeof b);
		for(int i=0;i+1<now.size();i++)b[now[i+1]]=a[now[i]];
		b[now[0]]=a[now.back()];
		for(int i=1;i<=n;i++)if(!b[i])b[i]=a[i];
		for(int i=1;i<=n;i++)printf("%d ",b[i]);putchar('\n');
	}
	return 0;
}