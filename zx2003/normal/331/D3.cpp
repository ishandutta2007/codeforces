#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct seg{int l,r,c;bool operator<(const seg&rhs)const{return r<rhs.r;}};
set<seg>s;
typedef long long ll;
typedef set<seg>::iterator IT;
const ll inf=1e16;
inline int idxx(char c){
	if(c=='U')return 0;if(c=='R')return 1;
	if(c=='D')return 2;return 3;
}
struct P{
	int x,y;
	inline void in(){cin>>x>>y;}
}e[N];char cc[N];int fir[N];
struct jt{
	int o,x,y,z;
	inline void in(){
		int a,b,c,d;
		cin>>a>>b>>c>>d;if(a==c)x=a,y=b,z=d,o=z>y?0:2;else x=b,y=a,z=c,o=z>y?1:3;
	}
}a[N];
vector<int>b[N];
int n,m,q,i,j;
int f0[55][N];ll f1[55][N];
inline void ins(seg z){
	if(z.l>z.r)swap(z.l,z.r);
	IT it1,it2;seg t;
	it1=s.lower_bound((seg){0,z.l,0});
	if(it1!=s.end() && it1->l<z.l){
		t=*it1,s.erase(it1++),s.insert((seg){t.l,z.l-1,t.c});
		if(t.r>z.r)s.insert((seg){z.r+1,t.r,t.c});
	}
	for(;it1!=s.end() && it1->r<=z.r;s.erase(it1++));
	if(it1!=s.end() && it1->l<=z.r)t=*it1,s.erase(it1),s.insert((seg){z.r+1,t.r,t.c});
	s.insert(z);
}
inline void work(int o){
	int i,j,x,y;IT it;
	for(i=1;i<=n;++i)if((a[i].o^o)&1)b[a[i].x].push_back(i);else{
		x=o<2?max(a[i].y,a[i].z):min(a[i].y,a[i].z);
		if(a[i].o==o)b[x].push_back(-i);b[x].push_back(N+i);
	}
	for(i=1;i<=q;++i)if(cc[i]==o)b[o&1?e[i].x:e[i].y].push_back(-N-i);
	for(i=o<2?m:0;0<=i && i<=m;i+=o<2?-1:1){
		for(j=0;j<b[i].size();++j)if(x=b[i][j],x>0 && x<N)ins((seg){a[x].y,a[x].z,x});
		for(j=0;j<b[i].size();++j)if(x=b[i][j],x<0 && x>-N){
			y=a[-x].x;it=s.lower_bound((seg){0,y,0});
			if(it!=s.end() && it->l<=y)f0[0][-x]=it->c;
		}
		for(j=0;j<b[i].size();++j)if(x=b[i][j],x>N)ins((seg){a[x-N].x,a[x-N].x,x-N});
		for(j=0;j<b[i].size();++j)if(x=b[i][j],x<-N){
			y=o&1?e[-N-x].y:e[-N-x].x;it=s.lower_bound((seg){0,y,0});
			if(it!=s.end() && it->l<=y)fir[-N-x]=it->c;
		}		
	}
	for(i=0;i<=m;++i)b[i].clear();s.clear();
}
inline int getd2(int x,int y){
	if(!y){
		if(cc[x]==0)return m-e[x].y;
		if(cc[x]==1)return m-e[x].x;
		if(cc[x]==2)return e[x].y;
		return e[x].x;
	}	
	int z=cc[x]&1?e[x].x:e[x].y;
	if((cc[x]^a[y].o)&1)return abs(a[y].x-z)+abs((cc[x]&1?e[x].y:e[x].x)-a[y].z);else{
		int p=abs(a[y].y-z),q=abs(a[y].z-z);
		return 1ll*(a[y].y-z)*(z-a[y].z)>=0?abs(z-a[y].z):
			(p<q?p+abs(a[y].z-a[y].y):q);
	}
}
inline P getp(int i){
	P z=(P){a[i].x,a[i].z};
	if(a[i].o&1)swap(z.x,z.y);return z;
}
inline void ot(int x,int y,ll t){
	static const int f1[4]={0,1,0,-1},f2[4]={1,0,-1,0};
	int zz=getd2(x,y);
	t=min(t,ll(zz));
	if(!y){
		if(cc[x]==0)cout<<e[x].x<<' '<<e[x].y+t<<'\n';
		if(cc[x]==1)cout<<e[x].x+t<<' '<<e[x].y<<'\n';
		if(cc[x]==2)cout<<e[x].x<<' '<<e[x].y-t<<'\n';
		if(cc[x]==3)cout<<e[x].x-t<<' '<<e[x].y<<'\n';
		return;
	}
	int z=cc[x]&1?e[x].x:e[x].y;
	if((((cc[x]^a[y].o)&1) && abs(a[y].x-z)>=t) || !((cc[x]^a[y].o)&1))
		cout<<e[x].x+t*f1[cc[x]]<<' '<<e[x].y+t*f2[cc[x]]<<'\n';else{
		P p=getp(y);
		cout<<p.x-(zz-t)*f1[a[y].o]<<' '<<p.y-(zz-t)*f2[a[y].o]<<'\n';
	}
}
ll tt[N];
inline bool ckk(int x,int i){
	if((a[i].o&1) && a[i].x==e[x].y && 1ll*(a[i].y-e[x].x)*(e[x].x-a[i].z)>=0)return 1;
	if(!(a[i].o&1) && a[i].x==e[x].x && 1ll*(a[i].y-e[x].y)*(e[x].y-a[i].z)>=0)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=n;++i)a[i].in();
	cin>>q;for(i=1;i<=q;++i)e[i].in(),cin>>cc[i]>>tt[i],cc[i]=idxx(cc[i]);
	for(i=0;i<4;++i)work(i);
	for(i=1;i<=n;++i){
		cc[0]=a[i].o,e[0]=getp(i);
		f1[0][i]=getd2(0,f0[0][i]);
	}
	for(i=1;i<55;++i)for(j=1;j<=n;++j)f0[i][j]=f0[i-1][f0[i-1][j]],
		f1[i][j]=min(inf,f1[i-1][f0[i-1][j]]+f1[i-1][j]);
	for(i=1;i<=q;++i){
		if(fir[i] && ckk(i,fir[i]))cc[i]=a[fir[i]].o;
		if(tt[i]<=getd2(i,fir[i])){ot(i,fir[i],tt[i]);continue;}
		tt[i]-=getd2(i,fir[i]);
		int x=fir[i];
		for(j=54;j>=0;--j)if(f0[j][x] && f1[j][x]<tt[i])tt[i]-=f1[j][x],x=f0[j][x];
		if(x){
			cc[0]=a[x].o;e[0]=getp(x);
			ot(0,f0[0][x],tt[i]);
		}else ot(i,0,getd2(i,fir[i]));
	}
	return 0;
}