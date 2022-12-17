//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
#define sz(x) (int)(x.size())
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
int T,n,m;
struct node
{
	int x[3],y[3];
	node(int a1,int b1,int a2,int b2,int a3,int b3)
	{
		x[0]=a1,x[1]=a2,x[2]=a3;
		y[0]=b1,y[1]=b2,y[2]=b3;
	}
	inline void output()
	{
		FOR(i,0,2)printf("%d %d ",x[i],y[i]);
	}
};
const int maxn=105;
vector<node>vec;
int a[maxn][maxn];
char s[maxn];
inline void init()
{
	memset(a,0,sizeof(a));
	vec.clear();
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)
	{
		scanf("%s",s+1);
		FOR(j,1,m)a[i][j]=s[j]-'0';
	}
}
inline void change(int a1,int b1,int a2,int b2,int a3,int b3)
{
	vec.pb(node(a1,b1,a2,b2,a3,b3));
	a[a1][b1]^=1,a[a2][b2]^=1,a[a3][b3]^=1;
}
inline void solve()
{
	FOR(i,1,n-2)
	{
		FOR(j,1,m-1)
		{
			if(a[i][j]==0&&a[i][j+1]==0)continue;
			else
			{
				if(a[i][j]==0)
				{
					change(i,j+1,i+1,j,i+1,j+1);
				}
				else if(a[i][j+1]==1)
				{
					change(i,j,i,j+1,i+1,j);
				}
				else
				{
					change(i,j,i+1,j,i+1,j+1);
				}
			}
		}
	}
	FOR(i,1,m-1)
	{
		if(a[n-1][i]==1&&a[n][i]==1)
		{
			change(n-1,i,n,i,n-1,i+1);
		}
		else if(a[n-1][i]==1)
		{
			change(n-1,i,n,i+1,n-1,i+1);
		}
		else if(a[n][i]==1)
		{
			change(n,i,n-1,i+1,n,i+1);
		}
	}
	if(a[n][m]==1&&a[n-1][m]==1)
	{
		change(n-1,m-1,n-1,m,n,m-1);
		change(n-1,m-1,n,m-1,n,m);
	}
	else if(a[n-1][m]==1)
	{
		change(n-1,m,n-1,m-1,n,m-1);
		change(n-1,m-1,n,m,n-1,m);
		change(n,m-1,n,m,n-1,m);
	}
	else if(a[n][m]==1)
	{
		change(n,m,n-1,m-1,n,m-1);
		change(n-1,m-1,n,m,n-1,m);
		change(n,m-1,n,m,n-1,m);
	}
	printf("%d\n",sz(vec));
	for(auto x:vec)
	{
		x.output();
		printf("\n");
	}
//	FOR(i,1,n)
//	{
//		FOR(j,1,m)
//		{
//			cerr<<a[i][j];
//		}
//		cerr<<endl;
//	}
}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}