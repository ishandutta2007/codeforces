//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=10005;
int n,p[maxn],a[maxn];
inline int query(int t,int i,int j,int x)
{
	//if(t==1)return max(min(x,a[i]),min(x+1,a[j]));	
	//else return min(max(x,a[i]),max(x+1,a[j]));
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	int ret;cin>>ret;
	return ret;
}
inline void answer()
{
	printf("! ");
	FOR(i,1,n)printf("%d ",p[i]);
	puts("");
	fflush(stdout);
}
inline void init()
{

}
inline void input()
{
	cin>>n;
	//FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	for(int i=1;i<=n;i+=2)
	{
		int x=i,y=i+1;
		if(i==n)x=i-1,y=i;
		int val1=query(1,x,y,n-1);
 		int val2=query(2,x,y,1);
		swap(val1,val2);
		if(val1==2)
		{
			if(query(2,x,y,1)==1)
			{
				p[x]=1,p[y]=val2;
				if(val2==n-1)
				{
					if(query(1,x,y,n-1)==n||query(1,y,x,n-1)==n)
					{
						p[y]=n;
					}
				}
				if(val2==n)
				{
					p[y]=n;
				}
				continue;
			}
			if(query(2,y,x,1)==1)
			{
				p[y]=1,p[x]=val2;
				if(val2==n-1)
				{
					if(query(1,x,y,n-1)==n||query(1,y,x,n-1)==n)
					{
						p[x]=n;
					}
				}
				if(val2==n)
				{
					p[x]=n;
				}
				continue;
			}
		}
		if(val2==n-1)
		{
			if(query(1,x,y,n-1)==n)
			{
				p[y]=n,p[x]=val1;
				continue;
			}
			else if(query(1,y,x,n-1)==n)
			{
				p[x]=n,p[y]=val1;
				continue;
			}
		}
		if(val1==val2)val1--;
		if(val2==val1+1)
		{
			if(query(2,x,y,val1)==val1)
			{
				p[x]=val1,p[y]=val2;
			}
			else
			{
				p[x]=val2,p[y]=val1;
			}
		}
		else
		{
			if(query(1,x,y,val1+1)>val1+1)
			{
				p[x]=val1,p[y]=val2;
			}
			else
			{
				p[x]=val2,p[y]=val1;
			}
		}
	}
	answer();
}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}