#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,B=1e3,C=N/B+5;
int n,q,a[N],i,x,y,bs,bel[N],Lst;
set<int>s[N];int lb[N],rb[N],mr[N],ans;
struct segtree{
	int M,T[N<<2];
	inline void upd(int i){
		T[i]=max(T[i<<1],T[i<<1|1]);
	}
	inline void ini(){
		int i;for(M=1;M<n+2;M<<=1);
		for(i=1;i<=n;++i)T[i+M]=mr[i]?s[a[i]].size():0;
		for(i=M-1;i;--i)upd(i);
	}
	inline void mdy(int i){
		for(T[i+M]=mr[i]?s[a[i]].size():0,i+=M;i>>=1;upd(i));
	}
	inline int ask(int l,int r){
		int ans=0;
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(!(l&1))ans=max(ans,T[l^1]);
			if(r&1)ans=max(ans,T[r^1]);
		}
		return ans;
	}
}T;
struct BLK{
	int be,en,mx,mid,st[B+5],w,su[B+5],pm[B+5];
	inline void build(){
		int i,j,ri=0,lst=be-1;w=0;
		st[0]=be-1;
		for(i=be;i<=en;++i){
			if(mr[i]>ri)ri=mr[i],mid=i;if(!mr[i] && st[0]==i-1)++st[0];
			pm[i-be+1]=ri;
			if(i==ri){
				int mx=0;if(lst==be-1)lst=st[0];
				for(j=lst+1;j<=ri;++j)mx=max(mx,(int)s[a[j]].size());
				lst=i;st[++w]=i;su[w]=su[w-1]+mx;
			}
		}
		mx=ri;
	}
	inline void work(int&pmx){
		if(!w || st[w]<pmx){
			if(en==n || (pmx<en && mid>(pmx=max(pm[pmx-be+1],pmx))))ans+=T.ask(Lst+1,pmx),Lst=pmx;
			pmx=max(pmx,mx);
			return;
		}
		int l=0,r=w,m;
		for(;l<r;){
			m=l+r>>1;
			if(pmx<=st[m])r=m;else l=m+1;
		}
		pmx=max(pm[pmx-be+1],pmx);if(pmx<st[l])ans+=T.ask(Lst+1,pmx),Lst=pmx;
		ans+=T.ask(Lst+1,st[l])+su[w]-su[l];
		Lst=st[w];pmx=mx;
	}
}b[C];
inline void mdy(int i,int v){
	mr[i]=v;T.mdy(i);b[bel[i]].build();
}
inline void mdy(int c,int i,int v){
	if(v==-1)s[c].erase(i);else s[c].insert(i);
	int nl,nr;
	if(s[c].empty())nl=nr=0;else nl=*s[c].begin(),nr=*s[c].rbegin();
	if(nl!=lb[c] || nr!=rb[c]){
		if(v==1){
			if(lb[c]!=nl && lb[c])mdy(lb[c],0);
		}
		lb[c]=nl;rb[c]=nr;
	}
	if(nl)mdy(nl,nr);
	if(v==1 && i!=nl)mdy(i,0);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;++i){
		cin>>a[i];
		s[a[i]].insert(i);
		bel[i]=(i-1)/B+1;
		b[bel[i]].en=i;
	}
	for(i=n;i;--i)b[bel[i]].be=i;bs=bel[n];
	for(i=1;i<N;++i)if(!s[i].empty())mr[lb[i]=*s[i].begin()]=rb[i]=*s[i].rbegin();
	for(i=1;i<=bs;++i)b[i].build();T.ini();
	x=Lst=0;for(i=1;i<=bs;++i)b[i].work(x);cout<<n-ans<<'\n';
	for(;q--;){
		cin>>x>>y;
		if(a[x]!=y){
			int oc=a[x];a[x]=y;mdy(oc,x,-1);mdy(y,x,1);
			x=Lst=ans=0;for(i=1;i<=bs;++i)b[i].work(x);
		}
		cout<<n-ans<<'\n';
	}
	return 0;
}