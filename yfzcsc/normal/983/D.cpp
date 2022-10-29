#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
struct wxh{
	int l,r,col;
};
int vis[maxn];
struct Data{
	int mn,mx,vmn,vmx;
	Data(){mn=mx=vmx=vmn=-1;}
	set<int>st1,st2;
	void cal(){
		while(st1.size()&&vis[*st1.rbegin()])
			st2.insert(*st1.rbegin()),st1.erase(*st1.rbegin());
		vmn=st2.size()?*st2.rbegin():-1;
		vmx=st1.size()?*st1.rbegin():-1;
	}
}s[maxn<<2];
vector<wxh>G[maxn];
int n,m,lx[maxn],ly[maxn],tpx,tpy;
int ax[maxn],ay[maxn],bx[maxn],by[maxn];
void upd(int o,int l,int r){
	if(l==r){
		s[o].mn=s[o].vmn;
		s[o].mx=s[o].vmx<s[o].mn?-1:s[o].vmx;
		return ;
	}
	int ls=o<<1,rs=o<<1|1;
	s[o].mn=max(s[o].vmn,min(s[ls].mn,s[rs].mn));
	s[o].mx=max(s[o].vmx<s[o].mn?-1:s[o].vmx,max(s[ls].mx,s[rs].mx)<s[o].vmn?-1:max(s[ls].mx,s[rs].mx));
}
void ins(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		s[o].st1.insert(x);
		s[o].cal();
		upd(o,l,r);
//		printf("[%d,%d]",l,r,s[o].mx,s[o].mn);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)ins(o<<1,l,mid,ql,qr,x);
	if(qr>mid)ins(o<<1|1,mid+1,r,ql,qr,x);
	upd(o,l,r);
}
void del(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		s[o].st2.erase(x);
		s[o].st1.erase(x);
		s[o].cal();
		upd(o,l,r);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)del(o<<1,l,mid,ql,qr,x);
	if(qr>mid)del(o<<1|1,mid+1,r,ql,qr,x);
	upd(o,l,r);
}
void move(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		s[o].cal();
		upd(o,l,r);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)move(o<<1,l,mid,ql,qr);
	if(qr>mid)move(o<<1|1,mid+1,r,ql,qr);
	upd(o,l,r);
}
int main(){
//	freopen("D.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&ax[i],&ay[i],&bx[i],&by[i]);
		lx[++tpx]=ax[i],lx[++tpx]=bx[i];
		ly[++tpy]=ay[i],ly[++tpy]=by[i];
	}
	sort(lx+1,lx+tpx+1),tpx=unique(lx+1,lx+tpx+1)-lx-1;
	sort(ly+1,ly+tpy+1),tpy=unique(ly+1,ly+tpy+1)-ly-1;
	for(int i=1;i<=n;++i){
		ax[i]=lower_bound(lx+1,lx+tpx+1,ax[i])-lx;
		bx[i]=lower_bound(lx+1,lx+tpx+1,bx[i])-lx;
		ay[i]=lower_bound(ly+1,ly+tpy+1,ay[i])-ly;
		by[i]=lower_bound(ly+1,ly+tpy+1,by[i])-ly;
		--by[i];
		G[ax[i]].push_back(wxh{ay[i],by[i],i});
		G[bx[i]].push_back(wxh{ay[i],by[i],-i});
	}
	for(int i=1;i<=tpx;++i){
		for(int j=0;j<G[i].size();++j){
			if(G[i][j].col<0)del(1,1,tpy,G[i][j].l,G[i][j].r,-G[i][j].col);
			else ins(1,1,tpy,G[i][j].l,G[i][j].r,G[i][j].col);
		}
		while(s[1].mx!=-1)vis[s[1].mx]=true
		//,printf("[%d]",s[1].mx)
		,move(1,1,tpy,ay[s[1].mx],by[s[1].mx]);
	}
	int ans=1;
	for(int i=1;i<=n;++i)if(vis[i])ans++;
	printf("%d",ans);
}