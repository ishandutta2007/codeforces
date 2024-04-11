#include<iostream>
#include<cstdio>
#define N 100100
using namespace std;

int n,m,cnt[70],can[N],have[70];
string str,ans;

inline void del(int u,int v)
{
	int i;
	for(i=0; i<64; i++)
	{
		if(i&can[u]) have[i]--;
		if(i&(1 << v)) cnt[i]--;
	}
}

inline void add(int u,int v)
{
	int i;
	for(i=0; i<64; i++)
	{
		if(i&can[u]) have[i]++;
		if(i&(1 << v)) cnt[i]++;
	}
}

inline bool check()
{
	int i;
	for(i=0; i<64; i++)
	{
		if(cnt[i]>have[i]) return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	int i,j,tmp,p;
	cin>>str;
	n=str.size();
	for(i=0; i<str.size(); i++)
	{
		cnt[1 << (str[i]-'a')]++;
	}
	for(i=1; i<64; i++)
	{
		for(j=i-1; j>=0; j--)
		{
			if((j&i)==j)
			{
				cnt[i]=cnt[j]+cnt[j^i];
			}
		}
	}
	cin>>m;
	for(i=1; i<=n; i++) can[i]=63;
	for(i=1; i<=m; i++)
	{
		cin>>p>>str;
		tmp=0;
		for(j=0; j<str.size(); j++)
		{
			tmp|=(1 << (str[j]-'a'));
		}
		can[p]&=tmp;
	}
	for(i=1; i<=n; i++)
	{
		for(j=0; j<64; j++)
		{
			if(can[i]&j) have[j]++;
		}
	}
//	for(i=1;i<=n;i++) cout<<can[i]<<" ";return 0;
	if(!check())
	{
		puts("Impossible");
		return 0;
	}
	for(i=1; i<=n; i++)
	{
		for(j=0; j<6; j++)
		{
			if((1 << j)&can[i])
			{
				del(i,j);
				if(check())
				{
					ans+=(char)(j+'a');
					break;
				}
				add(i,j);
			}
		}
	}
	cout<<ans;
}