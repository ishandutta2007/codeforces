#include<bits/stdc++.h>
#define tag(k)	T[k].tag
#define maxm 6
#define maxn 2000050
using namespace std;
typedef long long LL;

int n,m,q;

struct node
{
	int tag;
	int s,f[2][maxm];
	
	node(int x=0)	{
		s=0,tag=0;
		f[x][0]=0,f[x][m]=0;
		for (int i=1;i<m;++i)
			f[x][i]=i+1;
		
		f[x^1][0]=1,f[x^1][m]=0;
		for (int i=1;i<m;++i)
			f[x^1][i]=i+1;
	}
	
	void rev()	{
		s^=1,tag^=1;
	}
	
	int* operator [] (const int& i)	{
		return f[i];
	}
	
	node operator * (const node& R)	const	{
		node ans=node(s);
		for (int ns=0;ns<=1;++ns)
			for (int i=0;i<=m;++i)
				ans[ns][i]=f[ns^s][R.f[ns^R.s][i]];
		return ans;
	}
	
}	T[maxn<<2];

ostream& operator << (ostream& os,const node& N)	{
	for (int s=0;s<=1;++s)		{
		os<<"( ";
		for (int i=0;i<=m;++i)
			cout<<N.f[s^N.s][i]<<" ";
		os<<") ";
	}
	return os;
}

void build(int k,int l,int r)
{
	if (l==r)
	{
		LL x;
		scanf("%lld",&x);
		T[k]=node(x&1);
	} else
	{
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		T[k]=T[k<<1]*T[k<<1|1];
	}
}

void init()
{
	scanf("%d%d%d",&n,&m,&q);
	build(1,1,n);
}

void godown(int k)
{
	if (!tag(k))	return ;
	T[k<<1].rev(),T[k<<1|1].rev();
	tag(k)=0;
}

void change(int k,int l,int r,int a,int b)
{
	if (a<=l&&r<=b)
		T[k].rev();
	else
	{
		godown(k);
		int mid=(l+r)>>1;
		if (a<=mid)
			change(k<<1,l,mid,a,b);
		if (b>mid)
			change(k<<1|1,mid+1,r,a,b);
		T[k]=T[k<<1]*T[k<<1|1];
	}
	
//	cout<<"change:"<<k<<" "<<l<<" "<<r<<" "<<T[k]<<endl;
}

node query(int k,int l,int r,int a,int b)
{
	if (a<=l&&r<=b)
	{
//		cout<<"return:"<<k<<" "<<l<<" "<<r<<" "<<T[k]<<endl;
		return T[k];
	}
	godown(k);
	int mid=(l+r)>>1;
	if (b<=mid)	return query(k<<1,l,mid,a,b);
	if (a>mid)	return query(k<<1|1,mid+1,r,a,b);
	return query(k<<1,l,mid,a,b)*query(k<<1|1,mid+1,r,a,b);
}

void solve()
{
	while (q--)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if (op==1)
		{
			LL x;
			scanf("%lld",&x);
			if (x&1)
				change(1,1,n,l,r);
		} else
		{
			node N=query(1,1,n,l,r);
			printf(N[N.s][0]==1?"2\n":"1\n");
//			cout<<"ans:"<<N<<endl;
		}
	}
}

int main()
{
	init();
	solve();
	return 0;
}