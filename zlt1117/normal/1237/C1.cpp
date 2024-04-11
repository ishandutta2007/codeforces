//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define pb push_back
char buf[100000],*p1=buf,*p2=buf;
using namespace std;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=50005;
struct node
{
	int id,x,y,z;
	inline bool operator<(const node &b)const
	{
		if(x==b.x&&y==b.y)return z<b.z;
		if(x==b.x)return y<b.y;
		else return x<b.x;
	}
}a[maxn];
int n,tot;
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i].id=i,a[i].x=gi(),a[i].y=gi(),a[i].z=gi();
}	
inline void solve()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;)
	{
		if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)
		{
			vis[i]=vis[i+1]=1;
			printf("%d %d\n",a[i].id,a[i+1].id);
			i+=2;
		}
		else i++;
	}
	FOR(i,1,n)if(!vis[i])a[++tot]=a[i];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=tot-1;)
	{
		if(a[i].x==a[i+1].x)
		{
			vis[i]=vis[i+1]=1;
			printf("%d %d\n",a[i].id,a[i+1].id);
			i+=2;
		}
		else i++;
	}
	int temp=tot;
	tot=0;
	FOR(i,1,temp)if(!vis[i])a[++tot]=a[i];
	for(int i=1;i<=tot;i+=2)
	{
		printf("%d %d\n",a[i].id,a[i+1].id);
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///