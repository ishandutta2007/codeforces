#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,P=1e9+7;

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int tot,rt[N];

struct T{
	int ls,rs;
	int lcm;
}t[N*150];

void insert(int x,int &y,int l,int r,int p,int v)
{
	y=++tot;
	t[y]=t[x];
	t[y].lcm=1ll*t[y].lcm*v%P;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		insert(t[x].ls,t[y].ls,l,mid,p,v);
	else
		insert(t[x].rs,t[y].rs,mid+1,r,p,v);
}

ll query(int x,int L,int R,int l,int r)
{
	if(!x)
		return 1;
	if(l<=L&&R<=r)
		return t[x].lcm;
	int mid=(L+R)>>1;
	ll ret=1;
	if(l<=mid)
		ret=ret*query(t[x].ls,L,mid,l,r)%P;
	if(r>mid)
		ret=ret*query(t[x].rs,mid+1,R,l,r)%P;
	return ret;
}

int n,m,a[N],inv[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

stack<pii>st[N];

int main()
{
	scanf("%d",&n);
	inv[1]=1;
	for(int i=2;i<=200000;i++)
		inv[i]=1ll*inv[P%i]*(P-P/i)%P;
	t[0].lcm=1;
	int las=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			rt[i]=rt[i-1];
			continue;
		}
		int x=a[i];
		for(int j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				int vp=0;
				while(x%j==0)
					x/=j,vp++;
				int ov=vp;
				while(!st[j].empty()&&vp)
				{
					int mn=min(vp,st[j].top().sd);
					insert(las,rt[i],1,n,st[j].top().fs,qpow(inv[j],mn));
					las=rt[i];
					pii tmp=st[j].top();
					st[j].pop();
					tmp.sd-=mn;
					if(tmp.sd)
						st[j].push(tmp);
					vp-=mn;
				}
				st[j].push(mp(i,ov));
				insert(las,rt[i],1,n,i,qpow(j,ov));
				las=rt[i];
			}
		}
		if(x!=1)
		{
			int j=x;
			int vp=1;
			int ov=vp;
			while(!st[j].empty()&&vp)
			{
				int mn=min(vp,st[j].top().sd);
				insert(las,rt[i],1,n,st[j].top().fs,qpow(inv[j],mn));
				las=rt[i];
				pii tmp=st[j].top();
				st[j].pop();
				tmp.sd-=mn;
				if(tmp.sd)
					st[j].push(tmp);
				vp-=mn;
			}
			st[j].push(mp(i,ov));
			insert(las,rt[i],1,n,i,qpow(j,ov));
			las=rt[i];
		}
	}
	ll last=0;
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+last)%n+1,r=(r+last)%n+1;
		if(l>r)
			swap(l,r);
		printf("%lld\n",last=query(rt[r],1,n,l,r));
	}
}