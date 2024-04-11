#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct dat
{
	int ans;bool full;
	int lc,rc,llen,rlen;
};


dat merge(dat L,dat R)
{
	dat X;X.ans=L.ans+R.ans;
	if(L.rc==R.lc&&L.rc!=2)X.ans--;
	if(R.lc==2&&L.rc!=2)X.ans--;
	
	X.full=L.full&&R.full&&(L.rc!=R.lc);
	X.lc=L.lc,X.rc=R.rc;
	if(X.full){X.llen=X.rlen=L.llen+R.llen;return X;}
	
	if(L.full&&R.full)
	{
		X.llen=L.llen-1,X.rlen=R.rlen-1;return X;
	}
	if(L.full)
	{
		X.rlen=R.rlen;
		if(R.lc==(L.rc^1))X.llen=L.llen+R.llen;
		else
		{
			X.llen=max(L.llen-1,0);
			X.ans-=R.llen/2;
		}
		return X;
	}
	if(R.full)
	{
		X.llen=L.llen;
		if(R.lc==(L.rc^1))X.rlen=R.rlen+L.rlen;
		else
		{
			X.rlen=max(R.rlen-1,0);
			X.ans-=L.rlen/2;
		}
		return X;
	}
	
	X.llen=L.llen,X.rlen=R.rlen;
	if(R.lc==(L.rc^1))X.ans-=(L.rlen+R.llen+1)/2;
	else
	{
		X.ans-=L.rlen/2,X.ans-=R.llen/2;
	}
	return X;
}
dat F[3];
void init_F()
{
	F[0].ans=F[1].ans=F[2].ans=1;
	F[0].full=F[1].full=1,F[2].full=0;
	F[0].llen=F[1].llen=F[0].rlen=F[1].rlen=1,F[2].llen=F[2].rlen=0;
	for(int i=0;i<3;i++)F[i].lc=F[i].rc=i;
}
struct SegmentTree
{
	struct nd
	{
		int l,r;
		dat D;
	}t[1000000];
	void upd(int k){t[k].D=merge(t[k<<1].D,t[k<<1|1].D);}
	void build(int l,int r,int k=1)
	{
		t[k].l=l,t[k].r=r;if(l==r){t[k].D=F[2];return;}
		int mid=(l+r)>>1;build(l,mid,k<<1),build(mid+1,r,k<<1|1);upd(k);
	}
	void update(int x,int v,int k=1)
	{
		if(t[k].l==t[k].r){t[k].D=F[v];return;}
		int mid=(t[k].l+t[k].r)>>1;if(x<=mid)update(x,v,k<<1);else update(x,v,k<<1|1);
		upd(k);
	}
	dat query(int l,int r,int k=1)
	{
		if(l<=t[k].l&&t[k].r<=r)return t[k].D;
		int mid=(t[k].l+t[k].r)>>1;
		if(r<=mid)return query(l,r,k<<1);if(l>mid)return query(l,r,k<<1|1);
		return merge(query(l,r,k<<1),query(l,r,k<<1|1));
	}
}T;

int a[300000];bool vis[300000],is_lst[300000];
vector<int> all;

int main()
{
	init_F();
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),all.push_back(a[i]);
	all.push_back(0);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin();
	
	T.build(0,n);T.update(0,2);for(int i=1;i<=n;i++)T.update(i,1);
	
	vis[0]=1;for(int i=n;i>=1;i--)if(!vis[a[i]])vis[a[i]]=1,is_lst[i]=1;
	
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		T.update(a[i],2);
		ans+=T.query(0,a[i]).ans-1;
		if(is_lst[i])T.update(a[i],0);
	}
	printf("%lld",ans);
}