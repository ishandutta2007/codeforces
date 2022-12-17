#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
using namespace std;
inline int gi()
{
	char ch=getchar();
	int x=0,f=1;
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
struct matrix
{
	ll a[2][2];
	matrix(){memset(a,0xcf,sizeof(a));}
	inline void clear(){memset(a,0xcf,sizeof(a));}
	inline matrix operator*(const matrix &b)const
	{
		matrix temp;
		FOR(i,0,1)
		{
			FOR(j,0,1)
			{
				FOR(k,0,1)
				{
					temp.a[i][j]=max(temp.a[i][j],a[i][k]+b.a[k][j]);
				}
			}
		}
		return temp;
	}
};
inline matrix init(int x){matrix b;b.a[0][0]=0,b.a[1][1]=0,b.a[1][0]=-x,b.a[0][1]=x;return b;}///1->0-0->1+ 
const int maxn=3e5+5;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	matrix val[maxn<<2];
	inline void pushup(int u){val[u]=val[ls]*val[rs];}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)val[u]=init(v);
		else
		{
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,v);
			else update(rs,mid+1,r,x,v);
			pushup(u);
		}
	}
	inline ll query(){return max(val[1].a[0][1],val[1].a[0][0]);}
}tree;
int a[maxn],n,T,l,r,q;
int main()
{
	T=gi();
	while(T--)
	{
		n=gi(),q=gi();
		FOR(i,1,n)a[i]=gi(),tree.update(1,1,n,i,a[i]);
		printf("%lld\n",tree.query());
		FOR(i,1,q)
		{
			l=gi(),r=gi();
			tree.update(1,1,n,l,a[r]);
			tree.update(1,1,n,r,a[l]);
			swap(a[l],a[r]);
			printf("%lld\n",tree.query());
		}
		FOR(i,1,4*n)tree.val[i].clear();
	}
}