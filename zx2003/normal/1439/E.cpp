#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=N*4;
int hb[65539];
inline int hib(int x){return x>>16?hb[x>>16]+16:hb[x&65535];}
inline int lv(int x,int i){return x&((1<<i)-1);}
inline int gettp(const int&x,const int&y,int i){
	int a=x>>i&1,b=y>>i&1;
	return a==0 && b==0?lv(y,i)?lv(x,i)>lv(y,i)?2:3:0:a?1:4;
}
inline int calc(int x,int y){
	if(x<=y)return 0;
	int i=hib(y);return i==-1?x:x-lv(x,i);
}
struct P{
	int x,y;
	inline void in(){cin>>x>>y;}
	inline bool operator!=(const P&rhs)const{return x!=rhs.x || y!=rhs.y;}
	inline bool operator==(const P&rhs)const{return x==rhs.x && y==rhs.y;}
	inline bool operator<(const P&rhs)const{
		int i=max(hib(x^rhs.x),hib(y^rhs.y));
		return i==-1?0:gettp(x,y,i)<gettp(rhs.x,rhs.y,i);
	}
	inline int D(){return x^y;}
};
inline P lca(P u,P v){
	int i=max(hib(u.x^v.x),hib(u.y^v.y));if(i==-1)return u;
	int a=u.x>>i&1,b=u.y>>i&1,c=v.x>>i&1,d=v.y>>i&1;
	if(c==0 && d==0)swap(u,v),swap(a,c),swap(b,d);
	P z=P{u.x>>i+1<<i+1,u.y>>i+1<<i+1};
	if(a==0 && b==0){
		if(c==1)z.x|=calc(lv(u.x,i),lv(u.y,i));
		if(d==1)z.y|=calc(lv(u.y,i),lv(u.x,i));
	}
	return z;
}
int m,i,j,xb,fa[M],v3[N],v4[N],dep[M],st[M],w,tag1[M],tag2[M],ans;
P v1[N],v2[N],a[M];
map<P,int>mp;
map<int,int>mp2;
inline void mdy(int l,int r){if(l)mp2[l]^=1;mp2[r+1]^=1;}
int main(){
	for(i=2;i<65536;++i)hb[i]=hb[i>>1]+1;hb[0]=-1;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>m;for(i=1;i<=m;++i)v1[i].in(),v2[i].in(),a[++xb]=v1[i],a[++xb]=v2[i];
	a[++xb]=P{0,0};sort(a+1,a+xb+1);for(i=xb;i>1;--i)a[++xb]=lca(a[i],a[i-1]);
	sort(a+1,a+xb+1);xb=unique(a+1,a+xb+1)-a-1;for(i=1;i<=xb;++i)mp[a[i]]=i,dep[i]=a[i].D();
	for(i=1;i<=xb;++i){
		for(;w && lca(a[st[w]],a[i])!=a[st[w]];--w);
		st[++w]=i;fa[i]=st[w-1];
	}
	for(i=w;i>1;--i)fa[st[i]]=st[i-1];
	for(i=1;i<=m;++i){
		v3[i]=mp[v1[i]];v4[i]=mp[v2[i]];
		int l=mp[lca(v1[i],v2[i])];
		++tag1[v3[i]];++tag1[v4[i]];tag1[l]-=2;tag2[l]=1;
	}
	for(i=xb;i;--i)tag1[fa[i]]+=tag1[i];
	for(i=2;i<=xb;++i)if(tag1[i])mdy(dep[fa[i]]+1,dep[i]);
	for(i=1;i<=xb;++i)if(!tag1[i] && tag2[i])mdy(dep[i],dep[i]);
	for(auto u:mp2)ans+=u.second;
	cout<<ans<<endl;
}