#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
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
const int maxn=15005;
int n;
vector<PII>vec;
set<int>s[maxn];
vector<int>temp;
inline void calc(int x,int len)
{
	int ed=x+(1<<len)-1;
	FOR(i,1,len)
	{
		for(int j=x;j+(1<<i)-1<=ed;j+=(1<<i))
		{
			FOR(k,j,j+(1<<(i-1))-1)
			{
				if(k+(1<<(i-1))<=ed)vec.push_back(PII(k,k+(1<<(i-1))));
			}
		}
	}
}
int main()
{
	n=gi();
	FOR(i,1,n)s[i].insert(i);
	if((n==1)||(n==2)){printf("0\n");return 0;}
	int ans=0;
	int pos=0;
	set<int>s;
	for(int i=20;i>=0;--i)
	{
		int now=pos+(1<<i);
		if(now>n)continue;
		else calc(pos+1,i),pos=now,temp.push_back(i),s.insert(i);
	}
	sort(temp.begin(),temp.end());
	int us1=(1<<temp[temp.size()-1]);
	int now=n+1;
	FOR(i,temp[0],temp[temp.size()-1]-1)
	{
		int ii=n-(1<<i)+1;
		if(i==temp[0])now-=(1<<i);
		if(s.count(i)&&i!=temp[0])
		{
			int st=now;
			ii=now-(1<<i);
			now-=(1<<i);
			FOR(j,us1+1,(1<<temp[temp.size()-1]))vec.push_back(PII(j,ii++));
			FOR(j,st,n)vec.push_back(PII(j,ii++));
		}
		else
		{
			FOR(j,us1+1,(1<<temp[temp.size()-1]))vec.push_back(PII(j,us1--));
			FOR(j,now,n)
			{
				vec.push_back(PII(j,us1));
				us1--;
			}
		}
	}
	printf("%d\n",(int)(vec.size()));
	FOR(i,0,(int)(vec.size())-1)
	{
		printf("%d %d\n",vec[i].first,vec[i].second);
	}
	return 0;
}

///