#pragma GCC optimize(4)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define iter map<int,int>::iterator
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2005,maxm=1e6+5;
int mp[maxm];
int n,m,a[maxn],b[maxn],c[maxn],d[maxn],max1,ans=1e9;
int main()
{
	memset(mp,-1,sizeof(mp));
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
	FOR(i,1,m)c[i]=gi(),d[i]=gi();
	int now=0,cnt=0;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			now=max(now,max(0,c[j]-a[i]+1));
			if(c[j]>=a[i])
			{
				mp[c[j]-a[i]+1]=max(mp[c[j]-a[i]+1],max(0,d[j]-b[i]+1));
				cnt++;	
			}	
		} 
	}
	ans=now;
	vector<PII>v;
	if(cnt==0){printf("%d\n",ans);return 0;}
	v.push_back(PII(0,mp[0]));
	FOR(i,1,(int)(1e6))if(mp[i]!=-1)v.push_back(PII(i,mp[i]));
	vector<PII>::iterator it=v.end();--it;
	vector<PII>::iterator temp=v.end();
	for(;it!=v.begin();--it,--temp)
	{
		vector<PII>::iterator temp1=--it;++it;
		if(temp!=v.end())(*it).second=max((*it).second,(*temp).second);
		ans=min(ans,(*temp1).first+(*it).second);
	}
	printf("%d\n",ans);
	return 0;
}//