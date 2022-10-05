#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second

const int m=10;

struct node{
	pii p[11];
}nil, tr[808000];

node operator + (node a,node b){
	static int tong[202000];
	for (int i=1;i<=m;++i){
		tong[a.p[i].se]+=a.p[i].fi;
		tong[b.p[i].se]+=b.p[i].fi;
	}
	vector<pii>vec;
	for (int i=1;i<=m;++i){
		if (tong[a.p[i].se]) vec.push_back({tong[a.p[i].se],a.p[i].se}); tong[a.p[i].se]=0;
		if (tong[b.p[i].se]) vec.push_back({tong[b.p[i].se],b.p[i].se}); tong[b.p[i].se]=0;
	}
	sort(vec.begin(),vec.end());
	node c=nil;
	for (int i=1;i<=m&&i<=vec.size();++i)
		c.p[i]=vec[vec.size()-i];
	return c;
}

int n, q, p, org[202000];

int laz[808000];

void U(int x){
	tr[x]=tr[x<<1]+tr[x<<1|1];
}
void PT(int x,int l,int r,int id){
	tr[x]=nil; tr[x].p[1]={r-l+1,id};
	laz[x]=id;
}
void D(int x,int l,int r){
	int mid=l+r>>1;
	if (laz[x]){
		PT(x<<1,l,mid,laz[x]);
		PT(x<<1|1,mid+1,r,laz[x]);
		laz[x]=0;
	}
}

void build(int x,int l,int r){
	if (l==r){
		tr[x]=nil; tr[x].p[1]={1,org[l]};
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	U(x);
}
void cg(int x,int l,int r,int st,int en,int id){
	st=max(st,l); en=min(en,r);
	if (st>en) return;
	if (st==l&&en==r){
		PT(x,l,r,id); return;
	}
	D(x,l,r); int mid=l+r>>1;
	cg(x<<1,l,mid,st,en,id);
	cg(x<<1|1,mid+1,r,st,en,id);
	U(x);
}
node que(int x,int l,int r,int st,int en){
	st=max(st,l); en=min(en,r);
	if (st>en) return nil;
	if (st==l&&en==r){
		return tr[x];
	}
	D(x,l,r); int mid=l+r>>1;
	return que(x<<1,l,mid,st,en)
		+  que(x<<1|1,mid+1,r,st,en);
}

int main(){
	cin>>n>>q>>p;
	for (int i=1;i<=n;++i) scanf("%d",&org[i]);
	build(1,1,n);
	for (;q--;){
		int t, l, r;
		scanf("%d%d%d",&t,&l,&r);
		if (t==1){
			int x; scanf("%d",&x);
			cg(1,1,n,l,r,x);
		}else{
			node res=que(1,1,n,l,r);
			vector<int>ans;
			for (int i=1;i<=100/p;++i)
				if (res.p[i].se) ans.push_back(res.p[i].se);
			printf("%d",(int)ans.size());
			for (auto o:ans) printf(" %d",o);
			puts("");
		}
	}
}