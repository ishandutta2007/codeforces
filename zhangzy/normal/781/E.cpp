#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct L{
	int hei,l,r,har;
}l[101000],tt;
struct Nd{
	int typ,hei,har;
};
map<int,vector<Nd> >mp;
map<int,int>hid,wid;
map<int,int>::iterator it,nex;
int h,w,n,tot,f[404000],to[404000],mod=(1e9)+7;
int ans;

void U(int &x,int y){
	if ((x+=y)>=mod) x-=mod;
}

namespace seg{
	int rt,cnt;
	struct trnd{
		int lc,rc,mx;
	}tr[8202333];
	int A(int &x,int l,int r,int p,int v){
		if (!x) x=++cnt;
		if (l==r) return tr[x].mx=v;
		int mid=l+r>>1;
		if (p<=mid) A(tr[x].lc,l,mid,p,v);
		else A(tr[x].rc,mid+1,r,p,v);
		tr[x].mx=max(tr[tr[x].lc].mx,tr[tr[x].rc].mx);
	}
	int Q(int x,int l,int r,int p){
		if (tr[x].mx<=p||l>p) return 0;
		if (l==r) return l;
		int mid=l+r>>1,res;
		res=Q(tr[x].rc,mid+1,r,p);
		if (res) return res;
		return Q(tr[x].lc,l,mid,p);
	}
}

void doit(vector<Nd>&the){
	for (auto o:the) if (!o.typ){
		to[o.har]=hid[seg::Q(seg::rt,1,h,o.hei-1)];
	}
	for (auto o:the) if (o.typ){
		seg::A(seg::rt,1,h,o.hei,o.har);
	}
}

int cal(int x){
	if (~f[x]) return f[x];
	if (!to[x]) return f[x]=1;
	f[x]=0;
	U(f[x],l[to[x]].l==1? cal(to[x]<<1|1): cal(to[x]<<1|0));
	U(f[x],l[to[x]].r==w? cal(to[x]<<1|0): cal(to[x]<<1|1));
	return f[x];
}

int main(){
	cin>>h>>w>>n; wid[0]=wid[w]=0;
	for (int i=1;i<=n;++i){
		scanf("%d%d%d%d",&tt.hei,&tt.l,&tt.r,&tt.har);
		tt.har+=tt.hei;
		wid[tt.l-1]=wid[tt.r]=0;
		mp[tt.l-1].push_back((Nd){1,tt.hei,tt.har});
		mp[tt.r].push_back((Nd){1,tt.hei,0});
		mp[tt.l-1].push_back((Nd){0,tt.hei,i<<1|0});
		mp[tt.r+1].push_back((Nd){0,tt.hei,i<<1|1});
		hid[tt.hei]=i; l[i]=tt;
	}
	tot=n*2+2;
	for (it=wid.begin();it!=wid.end();++it){
		wid[it->fi]=++tot;
		if (it->fi) mp[it->fi].push_back((Nd){0,h+1,tot});
	}
	for (auto o:mp) doit(o.se);
	memset(f,-1,sizeof f);
	for (it=wid.begin();;++it){
		nex=++it; --it;
		if (nex==wid.end()) break;
		//printf("%d::(%d)\n",nex->fi,to[nex->se]);
		//printf("(%d,%d) %d\n",it->fi,nex->fi,cal(nex->se));
		U(ans,1ll*(nex->fi-it->fi)*cal(nex->se)%mod);
	}
	cout<<ans;
}