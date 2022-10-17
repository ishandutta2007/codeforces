#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,q,a[N],B;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<int>v[N];

int cnt;

struct T{
	int l,r,ls,rs;
	pii sum;
}t[N*2+1];

pii merge(pii a,pii b)
{
	if(a.fs==b.fs)
		return mp(a.fs,a.sd+b.sd);
	else
	{
		if(a.sd>b.sd)
			return mp(a.fs,a.sd-b.sd);
		else
			return mp(b.fs,b.sd-a.sd);
	}
}

void update(int x)
{
	t[x].sum=merge(t[t[x].ls].sum,t[t[x].rs].sum);
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].sum=mp(a[l],1);
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

pii query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].sum;
	int mid=(t[x].l+t[x].r)>>1;
	pii ret=mp(0,0);
	if(l<=mid)
		ret=merge(ret,query(t[x].ls,l,r));
	if(r>mid)
		ret=merge(ret,query(t[x].rs,l,r));
	return ret;
}

int main()
{
	scanf("%d%d",&n,&q);
	B=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[a[i]].push_back(i);
	build(1,n);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int w=query(1,l,r).fs;
		int len=r-l+1;
		int tot=upper_bound(v[w].begin(),v[w].end(),r)-lower_bound(v[w].begin(),v[w].end(),l);
		if(tot<=(len+1)/2)
			puts("1");
		else
		{
			int l=0,r=len-1;
			while(r-l>1)
			{
				int mid=(l+r)>>1;
				if((tot-mid)<=(len+1-mid)/2)
					r=mid;
				else
					l=mid;
			}
			printf("%d\n",r+1);
		}
	}
}