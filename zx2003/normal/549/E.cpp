#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const double eps=1e-12;
struct P{
int x,y;
inline void in(){scanf("%d%d",&x,&y);}
inline bool operator==(const P&rhs){return x==rhs.x && y==rhs.y;}
inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
inline int len2()const{return x*x+y*y;}
inline double len()const{return sqrt(len2());}
}a[N],b[N];
typedef vector<P>V;
inline int cross(const P&a,const P&b){return a.x*b.y-b.x*a.y;}
inline int dot(const P&a,const P&b){return a.x*b.x+a.y*b.y;}
inline bool cmpP1(const P&a,const P&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
inline V CH(V v){
	static P tmp[N],st[N];
	int w=0;
	sort(v.begin(),v.end(),cmpP1);
	for(P u:v){for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])<=0;--w);st[++w]=u;}
	memcpy(tmp+1,st+1,w*(sizeof tmp[0]));
	int ow=w;w=0;
	reverse(v.begin(),v.end());
	for(P u:v){for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])<=0;--w);st[++w]=u;}
	if(tmp[ow]==st[1])--ow;if(w && st[w]==tmp[1])--w;
	memcpy(tmp+ow+1,st+1,w*(sizeof tmp[0]));
	return V(tmp+1,tmp+ow+w+1);
}
int n,m,i,nxt[N];
V u;
void ck(P p,P q){
	double L=-1e180,R=-L,zz=(p-q).len2();
	for(i=1;i<=n;++i){
		int x=cross(q-p,a[i]-p),y=dot(p-a[i],q-a[i]);
		if(x==0){if(y>0)return;continue;}
		if(x>0)L=max(L,y*1.0/x);else R=min(R,y*1.0/x);
		if(L>=R-eps || (fabs(R-zz)<eps && fabs(L+zz)<eps))return;
	}
	for(i=1;i<=m;++i){
		int x=cross(q-p,b[i]-p),y=dot(p-b[i],q-b[i]);
		if(x==0){if(y<=0)return;continue;}
		if(x>0)R=min(R,y*1.0/x);else L=max(L,y*1.0/x);
		if(L>=R-eps || (fabs(R-zz)<eps && fabs(L+zz)<eps))return;
	}
	puts("YES");exit(0);
}
inline double R(const P&a,const P&b,const P&c){return dot(b-c,a-c)*1.0/cross(b-c,a-c);}
void solve(int x){
	int y=nxt[x],z;double mx=-1e180,r;
	ck(u[x],u[y]);if(nxt[y]==x)return;
	for(;y=nxt[y],y!=x;){
		r=R(u[x],u[nxt[x]],u[y]);
		if(r>mx)mx=r,z=y;
	}
	y=nxt[x];nxt[x]=z;solve(z);nxt[z]=y;solve(y);
}
inline void work(){
	u=CH(V(a+1,a+n+1));
	for(i=0;i+1<u.size();++i)nxt[i]=i+1;nxt[i]=0;
	solve(0);
}
int main(){
	scanf("%d%d",&n,&m);for(i=1;i<=n;++i)a[i].in();for(i=1;i<=m;++i)b[i].in();
	if(n==1 || m==1){puts("YES");return 0;}
	work();for(i=1;i<=max(n,m);++i)swap(a[i],b[i]);swap(n,m);work();puts("NO");
	return 0;
}