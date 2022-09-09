#include<bits/stdc++.h>
using namespace std;
inline void upi(int&a,const int&b){a>b?a=b:0;}
inline void upa(int&a,const int&b){a<b?a=b:0;}
typedef pair<int,int>P;
const int N=1e5+5,BS=355,BL=305;
int n,W,q,i,k,a[N],ans[N];
P qu[N];
inline void operator+=(P&a,const P&b){upi(a.first,b.first);upa(a.second,b.second);}
inline int calc(const P&a,const P&b){return max(a.second,b.second)-min(a.first,b.first);}
inline int calc(const P&a){return a.second-a.first;}
struct segtree{
	int M;
	P t[N*3];
	void ini(){
		for(M=1;M<n+2;M<<=1);
		for(i=1;i<=n;++i)t[i+M]={a[i],a[i]};
		for(;i<M;++i)t[i+M]={0,1<<30};
		for(i=M-1;i;--i)t[i]=t[i<<1],t[i]+=t[i<<1|1];
	}
	inline int query(int l,int v){
		l+=M-1;
		P z={1<<30,0},nz;
		for(;nz=z,(l&1) || (nz+=t[l^1],calc(nz)<=v);l>>=1,z=nz);
		for(l^=1;l<M;){
			nz=z,nz+=t[l<<1];
			if(calc(nz)<=v)z=nz,l=l<<1|1;else l<<=1;
		}
		return l-M;
	}
}T;
struct BLOCK{
	int be,en,a[BL],xb;
	P ev[BL*BL/2];int evcnt,pp;
	struct node{int ch[2],fa,sz;}t[BL];
	inline void upd(const int&x){t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+1;}
	inline int dir(const int&x,const int&y){return t[x].ch[1]==y;}
	inline void setc(const int&x,const int&y,const int&o){t[x].ch[o]=y;t[y].fa=x;}
	inline bool nrt(const int&x){return t[t[x].fa].ch[0]==x || t[t[x].fa].ch[1]==x;}
	inline void rotate(int x){
		int y=t[x].fa,z=t[y].fa,o;
		if(nrt(y))setc(z,x,dir(z,y));t[x].fa=z;
		o=dir(y,x);setc(y,t[x].ch[!o],o);setc(x,y,!o);upd(y);
	}
	inline void splay(int x){
		for(;nrt(x);rotate(x)){
			int y=t[x].fa,z=t[y].fa;
			if(nrt(y))rotate(dir(z,y)==dir(y,x)?y:x);
		}
		upd(x);
	}
	inline void access(int x){int y=0,ox=x;for(;x;x=t[x].fa)splay(x),setc(x,y,1),upd(x),y=x;splay(ox);}
	void ini(){
		int i,j;
		for(i=be;i<=en;++i)a[++xb]=::a[i];
		for(i=1;i<=xb;++i){
			int mn=a[i],mx=a[i];
			for(j=i+1;j<=xb;++j)if(a[j]<mn || a[j]>mx){
				ev[++evcnt]={mx-mn,i<<10|j};
				upi(mn,a[j]);upa(mx,a[j]);
			}
			ev[++evcnt]={mx-mn,i<<10};
		}
		sort(ev+1,ev+evcnt+1);
	}
	inline void mdy(int v){
		for(;pp<evcnt && ev[pp+1].first<=v;){
			int x=ev[++pp].second,y=x&1023;x>>=10;
			access(x);
			t[t[x].ch[0]].fa=0;t[x].ch[0]=0;upd(x);t[x].fa=y;
		}
	}
	inline void ask(int&x,int&ans){
		access(x);ans+=t[x].sz;
		for(;t[x].ch[0];x=t[x].ch[0]);splay(x);
	}
}b[BS];
int bel[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>W>>q;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i)bel[i]=(i-1)/(BL-5)+1;
	for(i=1;i<=n;++i)b[bel[i]].en=i;for(i=n;i;--i)b[bel[i]].be=i;
	for(i=1;i<=bel[n];++i)b[i].ini();T.ini();
	for(i=1;i<=q;++i)cin>>k,qu[i]={W-k,i};
	sort(qu+1,qu+q+1);
	for(i=1;i<=q;++i){
		int&ass=ans[qu[i].second];
		k=1;
		for(;k<=n;){
			b[bel[k]].mdy(qu[i].first);
			int bb=bel[k];k=k-b[bb].be+1;
			b[bb].ask(k,ass);k+=b[bb].be-1;
			k=T.query(k,qu[i].first);
		}
	}
	for(i=1;i<=q;++i)cout<<ans[i]-1<<'\n';
	return 0;
}