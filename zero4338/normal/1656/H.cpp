#include<bits/stdc++.h>
typedef __int128 ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
void print(ll x)
{
	static char out[50];
	static int tp;
	tp=0;
	do out[tp++]='0'+x%10,x/=10;while(x);
	for(int i=tp-1;i>=0;i--)putchar(out[i]);
}
int T;
const int maxn=1e3+5;
int n,m;
ll a[2][maxn];
bool del[2][maxn];
struct seg
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{ll d;}t[maxn<<2];
	void build(int u,int l,int r,ll &v0,ll v1[])
	{
		if(l==r){t[u].d=v0/__gcd(v0,v1[l]);return;}
		int mid=(l+r)>>1;
		build(L(u),l,mid,v0,v1);build(R(u),mid+1,r,v0,v1);
		t[u].d=__gcd(t[L(u)].d,t[R(u)].d);
	}
	void del(int p,int u,int l,int r)
	{
		if(l==r){t[u].d=0;return;}
		int mid=(l+r)>>1;
		if(mid>=p)del(p,L(u),l,mid);
		else del(p,R(u),mid+1,r);
		t[u].d=__gcd(t[L(u)].d,t[R(u)].d);
	}
	#undef L
	#undef R
}tr[2][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		generate_n(a[0]+1,n,read);
		generate_n(a[1]+1,m,read);
		memset(del[0],0,sizeof(bool)*(n+1));
		memset(del[1],0,sizeof(bool)*(m+1));
		for(int i=1;i<=n;i++)tr[0][i].build(1,1,m,a[0][i],a[1]);
		for(int i=1;i<=m;i++)tr[1][i].build(1,1,n,a[1][i],a[0]);
		while(true)
		{
			int pos=-1;
			for(int i=1;i<=n;i++)
				if(!del[0][i]&&tr[0][i].t[1].d!=1){pos=i;break;}
			if(pos!=-1)
			{
				del[0][pos]=1;
				for(int i=1;i<=m;i++)tr[1][i].del(pos,1,1,n);
				continue;
			}
			for(int i=1;i<=m;i++)
				if(!del[1][i]&&tr[1][i].t[1].d!=1){pos=i;break;}
			if(pos!=-1)
			{
				del[1][pos]=1;
				for(int i=1;i<=n;i++)tr[0][i].del(pos,1,1,m);
				continue;			
			}
			break;
		}
		int cnta=0,cntb=0;
		for(int i=1;i<=n;i++)if(!del[0][i])cnta++;
		for(int i=1;i<=m;i++)if(!del[1][i])cntb++;
		if(cnta&&cntb)
		{
			puts("YES");
			printf("%d %d\n",cnta,cntb);
			for(int i=1;i<=n;i++)if(!del[0][i])print(a[0][i]),putchar(' ');putchar('\n');
			for(int i=1;i<=m;i++)if(!del[1][i])print(a[1][i]),putchar(' ');putchar('\n');
		}
		else puts("NO");
	}
	return 0;
}