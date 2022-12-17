//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=505;
set<int>S1,S2; 
int n,k;
inline void init()
{
	
}
inline void input()
{
	n=gi(),k=gi();
}
inline int Query(vector<int>v)
{
	assert((int)(v.size())==k);
	printf("? ");
	for(int x:v)printf("%d ",x);
	puts("");
	fflush(stdout);
	int ret=gi();
	return ret;
}
inline void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int d[maxn],pre[maxn];
inline void solve()
{
	queue<int>q;q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		FOR(j,0,k)
		{
			if(u+k-j*2>0&&u+k-j*2<=n&&u>=j&&u+k-j<=n&&!d[u+k-j*2])
			{
				d[u+k-j*2]=d[u]+1;
				pre[u+k-j*2]=u;
				q.push(u+k-j*2);
			}
		}
	}
	if(!d[n])return puts("-1"),void();
	int x=n;vector<int>vec;
	while(x)vec.pb(x),x=pre[x];
	reverse(vec.begin(),vec.end());
	FOR(i,1,n)S1.insert(i);
	int sum=0,now=0;
	for(int x:vec)
	{
		vector<int>v,v1,v2;
		int res=(k+now-x)/2;
		FOR(j,1,k)
		{
			if(res)v.pb(*S2.begin()),v1.pb(*S2.begin()),S2.erase(S2.begin()),res--;
			else v.pb(*S1.begin()),v2.pb(*S1.begin()),S1.erase(S1.begin());
		}
		sum^=Query(v);
		for(int x:v1)S1.insert(x);
		for(int x:v2)S2.insert(x);
		//puts("S1");for(int x:S1)printf("%d ",x);puts("");
		//puts("S2");for(int x:S2)printf("%d ",x);puts("");
		now=x;
	}
	answer(sum);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}