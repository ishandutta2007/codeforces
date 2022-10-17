#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 200100
using namespace std;

int n,m,Q;
db sy,l[N],r[N],sum[N],zl,zr,x,y,ans;
struct Node
{
	db x,y;
}bj[2][N],tmp,L,R;

inline bool lef(Node u,Node v,Node w)
{
	if(u.x==v.x) return w.x<u.x;
	db t;
	t=v.x-(v.x-u.x)*(v.y-w.y)/(v.y-u.y);
	return w.x<t;
}

inline db ask(int u)
{
	db p,q;
	if(bj[0][u].x==x) p=x;
	else
	{
		p=x-(x-bj[0][u].x)*(y-sy)/y;
	}
	if(bj[1][u].x==x) q=x;
	else
	{
		q=x-(x-bj[1][u].x)*(y-sy)/y;
	}
	return max((db)0,min(q,zr)-max(p,zl));
}

int main()
{
	int i,j,p,q,mid,a,b;
	cin>>sy>>zl>>zr>>n;
	L.y=R.y=sy,L.x=zl,R.x=zr;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf",&l[i],&r[i]);
		sum[i]=sum[i-1]+r[i]-l[i];
		bj[0][i].y=0,bj[0][i].x=l[i];
		bj[1][i].y=0,bj[1][i].x=r[i];
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lf%lf",&x,&y);
		ans=0;
		tmp.x=x,tmp.y=y;
		for(p=1,q=n;p<q;)
		{
			mid=((p+q)>>1);
			if(lef(tmp,bj[0][mid],L)) q=mid;
			else p=mid+1;
		}
		a=p-1;
		for(p=1,q=n;p<q;)
		{
			mid=((p+q)>>1);
			if(!lef(tmp,bj[1][mid],R)) p=mid+1;
			else q=mid;
		}
		b=p;
		printf("%.10f\n",ask(a)+ask(b)*(a!=b)+max((db)0,sum[b-1]-sum[a])*(y-sy)/y);
	}
}