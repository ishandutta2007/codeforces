#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n;
char s[maxn],t[maxn];
deque<int>pos[26];
struct Data
{
	struct fenwick
	{
		int b[maxn];
		void clear(){for(int i=1;i<=n;i++)b[i]=0;}
		void change(int p,int x){for(int i=p;i;i-=i&(-i))b[i]+=x;}
		int query(int p){int ret=0;for(int i=p;i<=n;i+=i&(-i))ret+=b[i];return ret;}
	}tr;
	int sum,cnt,rev;
	void clear()
	{
		sum=0;cnt=0;rev=0;tr.clear();
	}
	void insert(int pos)
	{
		sum+=pos-1;
		cnt++;
		rev+=tr.query(pos);
		tr.change(pos,1);
	}
	void del(int pos)
	{
		sum-=pos-1;
		cnt--;
		tr.change(pos,-1);
		rev-=tr.query(pos);
	}
	int val(){return sum-cnt*(cnt-1)/2+rev;}
}S;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);
		S.clear();
		for(int i=0;i<26;i++)pos[i].clear();
		for(int i=1;i<=n;i++)pos[s[i]-'a'].push_back(i);
		int ans=1e10;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<t[i]-'a';j++)
			{
				if(!pos[j].empty())
				{
					S.insert(pos[j].front());
					ans=min(ans,S.val());
					S.del(pos[j].front());
				}
			}
			if(pos[t[i]-'a'].empty())break;
			S.insert(pos[t[i]-'a'].front());
			pos[t[i]-'a'].pop_front();
		}
		if(ans==1e10)puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}