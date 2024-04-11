#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int N=3e5+5;

long long btree[4*N],lazy[4*N];
long long sumt[4*N];
pair<pair<int,int>,int> arr[N];
int nn[N];
int n,q;

char tt[N]; int a[N],b[N];

void prob(int node,int l,int r)
{
	btree[node]+=lazy[node];
	if(l!=r)
	{
		lazy[node<<1]+=lazy[node];
		lazy[(node<<1)|1]+=lazy[node];
	}
	lazy[node]=0;
}

void update(int node,int l,int r,int ql,int qr,long long v)
{
	prob(node,l,r);
	if(r<ql||qr<l) return;
	if(ql<=l&&r<=qr)
	{
		lazy[node]+=v;
		prob(node,l,r);
		return;
	}
	int mid=(l+r)>>1;
	update(node<<1,l,mid,ql,qr,v);
	update((node<<1)|1,mid+1,r,ql,qr,v);
	btree[node]=max(btree[node<<1],btree[(node<<1)|1]);
}

long long query(int node,int l,int r,int ql,int qr)
{
	prob(node,l,r);
	if(qr<l||r<ql) return 0;
	if(ql<=l&&r<=qr)return btree[node];
	int mid=(l+r)>>1;
	return max(query(node<<1,l,mid,ql,qr),query((node<<1)|1,mid+1,r,ql,qr));
}

void updatesum(int node,int l,int r,int ind,long long v)
{
	if(r<ind||ind<l) return;
	if(l==r)
	{
		sumt[node]+=v;
		return;
	}
	int mid=(l+r)>>1;
	updatesum(node<<1,l,mid,ind,v);
	updatesum((node<<1)|1,mid+1,r,ind,v);
	sumt[node]=sumt[node<<1]+sumt[(node<<1)|1];
}

long long sum(int node,int l,int r,int ql,int qr)
{
	if(qr<l||r<ql) return 0;
	if(ql<=l&&r<=qr) return sumt[node];
	int mid=(l+r)>>1;
	return sum(node<<1,l,mid,ql,qr)+sum((node<<1)|1,mid+1,r,ql,qr);
}

int main()
{
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf(" %c %d",&tt[i],&a[i]);
		if(tt[i]=='+')
		{
			scanf("%d",&b[i]);
			arr[n++]={{a[i],b[i]},i};
		}
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		nn[arr[i].S]=i;
	}
	// btree[i] = a[i]-(sum(b[i-1])
	for(int i=0;i<q;i++)
	{
		if(tt[i]=='+')
		{
			int me=nn[i];
			update(1,0,n-1,me,me,a[i]);
			update(1,0,n-1,me+1,n-1,-b[i]);
			updatesum(1,0,n-1,me,b[i]);
		}
		else if(tt[i]=='-')
		{
			a[i]--;
			int me=nn[a[i]];
			update(1,0,n-1,me,me,-a[a[i]]);
			update(1,0,n-1,me+1,n-1,b[a[i]]);
			updatesum(1,0,n-1,me,-b[a[i]]);
		}
		else
		{
			int ind=lower_bound(arr,arr+n,make_pair(make_pair(a[i],(1<<30)),(1<<30)))-arr;
			//cout << "IND " << ind << " " << a[i] << "  " << arr[ind].F.F << " " << arr[ind].F.S << endl;
			long long tt=query(1,0,n-1,0,ind-1)+sum(1,0,n-1,0,ind-1);
			printf("%lld\n",max(tt-a[i],0LL));
		}
	}
}