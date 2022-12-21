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
const int maxn=1e5+5;
int T,n,a[maxn],k,now[maxn];
vector<int>v;
set<int>s,s2;
int main()
{
	T=gi();
	while(T--)
	{
		s.clear(),v.clear(),s2.clear();
		n=gi(),k=gi();
		FOR(i,1,n)
		{
			a[i]=gi();
			if(k%2==0&&a[i]==k/2)v.push_back(i);
			else if(s.count(a[i]))now[i]=0;
			else if(s2.count(a[i]))now[i]=1;
			else now[i]=0,s.insert(a[i]),s2.insert(k-a[i]);
		}
		FOR(i,0,(int)(v.size())/2-1)now[v[i]]=1;
		FOR(i,(int)(v.size())/2,(int)(v.size())-1)now[v[i]]=0;
		FOR(i,1,n)printf("%d ",now[i]);
		printf("\n");
	}
	return 0;
}