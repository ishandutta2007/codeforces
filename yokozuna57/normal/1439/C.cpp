#include <bits/stdc++.h>
using namespace std;

#define sc second

typedef long long ll;
const ll INF=1000000000;

struct seg{
	struct str{
		ll q,val,m,M;
		str(ll q_,ll val_,ll m_,ll M_){ q=q_; val=val_; m=m_; M=M_; }
		str(ll a,ll b){ q=a; val=m=M=b; }
		str(){q=-1; val=m=M=INF;}
	};
	int sz;
	vector<str> a;
	void recal(int i){
		a[i].val=a[2*i+1].val+a[2*i+2].val;
		a[i].m=min(a[2*i+1].m,a[2*i+2].m);
		a[i].M=max(a[2*i+1].M,a[2*i+2].M);
	}
	void init(int n){
		sz=1;
		while(sz<n)sz*=2;
		a=vector<str>(2*sz-1);
	}
	void run(){
		for(int i=sz-2;i>=0;i--)recal(i);
	}
	void upd(int s,int t,ll x,int k,int l,int r){
		if(t<=l||r<=s||a[k].m>=x)return;
		if(s<=l&&r<=t){
			if(a[k].M<=x){
				a[k]=str(x,x*(r-l),x,x);
				return;
			}
			else {
				a[k].q=x;
			}
		}
		if(a[k].q!=-1){
			upd(l,r,a[k].q,2*k+1,l,(l+r)/2);
			upd(l,r,a[k].q,2*k+2,(l+r)/2,r);
			a[k].q=-1;
		}
		upd(s,t,x,2*k+1,l,(l+r)/2);
		upd(s,t,x,2*k+2,(l+r)/2,r);
		recal(k);
	}
	ll sum(int s,int t,int k,int l,int r){
		if(t<=l||r<=s)return 0;
		if(s<=l&&r<=t)return a[k].val;
		if(a[k].q!=-1){
			upd(l,r,a[k].q,2*k+1,l,(l+r)/2);
			upd(l,r,a[k].q,2*k+2,(l+r)/2,r);
			a[k].q=-1;
		}
		ll chl=sum(s,t,2*k+1,l,(l+r)/2);
		ll chr=sum(s,t,2*k+2,(l+r)/2,r);
		return chl+chr;
	}
	int lower_bound(ll x,int k,int l,int r){
		//cerr<<x<<" "<<k<<" "<<l<<" "<<r<<endl;
		if(k>=sz-1){
			if(a[k].val>=x)return l;
			else return r;
		}
		if(a[k].q!=-1){
			upd(l,r,a[k].q,2*k+1,l,(l+r)/2);
			upd(l,r,a[k].q,2*k+2,(l+r)/2,r);
			a[k].q=-1;
		}
		if(a[2*k+1].val>=x)return lower_bound(x,2*k+1,l,(l+r)/2);
		else return lower_bound(x-a[2*k+1].val,2*k+2,(l+r)/2,r);
	}
	int val(int i){
		int x=i+sz-1;
		int ret=a[x].val;
		while(x>0){
			x=(x-1)/2;
			if(a[x].q!=-1)ret=a[x].q;
		}
		return ret;
	}
}seg;

int n,q;
int a[200010];

map<ll,ll> M;
void add(int x,int y){
	auto itr=M.upper_bound(y);
	if(itr!=M.end()&&itr->sc>=x)return;
	if(itr!=M.begin()){
		itr--;
		while(1){
			if(itr->sc>x)break;
			if(itr==M.begin()){
				M.erase(itr);
				break;
			}
			M.erase(itr--);
		}
	}
	M[y]=x;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	seg.init(n);
	for(int i=0;i<n;i++){
		seg.a[seg.sz-1+i]=seg::str(-1,a[i]);
		add(i,a[i]);
	}
	seg.run();
	
	for(;q>0;q--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		x--;
		if(t==1){
			seg.upd(0,x+1,y,0,0,seg.sz);
			add(x,y);
		}
		else {
			int ret=0;
			int loc=x;
			int zan=y;
			while(loc<n&&zan>0){
				if(1){
					int l=seg.lower_bound(seg.sum(0,loc,0,0,seg.sz)+zan+1,0,0,seg.sz);
					ret+=l-loc;
					zan-=seg.sum(loc,l,0,0,seg.sz);
					loc=l;
				}
				if(1){
					int l;
					auto itr=M.upper_bound(zan);
					if(itr==M.begin())l=n;
					else l=max(loc,(int)itr->sc+1);
					/*int l=loc,r=n;
					while(l<r){
						int mid=(l+r)/2;
						if(seg.val(mid)<=zan)r=mid;
						else l=mid+1;
					}*/
					loc=l;
				}
			}
			printf("%d\n",ret);
		}
	}
}