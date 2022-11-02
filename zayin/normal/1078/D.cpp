#include<bits/stdc++.h>
#define L(i)	T[i].L
#define R(i)	T[i].R
#define maxh 20
#define maxn 305000
using namespace std;

int n,a[maxn];

struct node
{
	int L,R;
	node(int _L=0,int _R=0)	{
		L=_L,R=_R;
	}
	
	int len()	{
		return R-L+1;
	}
	
	node operator * (const node& N)	const	{
		return node(min(L,N.L),max(R,N.R));
	}
};

struct Tree
{
	node T[maxn<<2];
	
	void build(node pos[],int k,int l,int r)
	{
		if (l==r)
			T[k]=pos[l];
		else
		{
			int mid=(l+r)>>1;
			build(pos,k<<1,l,mid);
			build(pos,k<<1|1,mid+1,r);
			T[k]=T[k<<1]*T[k<<1|1];
		}
	}
	
	void build(node pos[])	{
		build(pos,1,1,3*n);
	}
	
	node query(int k,int l,int r,node N)
	{
		if (N.L<=l&&r<=N.R)	return T[k];
		if (N.L>r||l>N.R)	return node(maxn,-maxn);
		int mid=(l+r)>>1;
		return query(k<<1,l,mid,N)*query(k<<1|1,mid+1,r,N);
	}
	
	node query(node N)	{
		return query(1,1,3*n,N);
	}
}	T[maxh];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]),a[i+n]=a[i+2*n]=a[i];
}

int Log2[maxn]={-1};
node pos[maxh][maxn];

void solve()
{
	for (int i=1;i<=3*n;++i)
		Log2[i]=Log2[i-1]+!(i&(i-1));
		
	for (int i=1;i<=3*n;++i)
		pos[0][i]=node(max(i-a[i],1),min(3*n,i+a[i]));
	T[0].build(pos[0]);
	
	for (int j=1;(1<<j)<=3*n;++j)
	{
		for (int i=1;i<=3*n;++i)
			pos[j][i]=T[j-1].query(pos[j-1][i]);
		T[j].build(pos[j]);
	}
	
	/*for (int j=0;(1<<j)<=3*n;++j)
	{
		cout<<j<<":"<<endl;
		for (int i=1;i<=3*n;++i)
			printf("%d:(%d %d)\n",i,pos[j][i].L,pos[j][i].R);
		cout<<"--------------------------"<<endl;
	}*/
	
	for (int i=1;i<=n;++i)
	{
		int ans=0;
		node N=node(i+n,i+n);
		for (int j=Log2[3*n];~j;--j)
		{
			node nxt=T[j].query(N);
			if (nxt.len()>=n)	continue;
			ans+=(1<<j);
			N=nxt;
		}
		
		if (N.len()<n)
			++ans;
		printf("%d ",ans);
	}
	putchar('\n');
}

int main()
{
	init();
	solve();
	return 0;
}