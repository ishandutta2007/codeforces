#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	int x,y;
	P(int X=0,int Y=0){x=X,y=Y;}
	bool operator==(const P &b)const{return x==b.x && y==b.y;}
	inline void out(){printf("%d %d\n",x,y);}
	inline double len(){return sqrt(1ll*x*x+1ll*y*y);}
};
P operator+(P a,P b){return P(a.x+b.x,a.y+b.y);}
P operator-(P a,P b){return P(a.x-b.x,a.y-b.y);}
P operator*(P a,int b){return P(a.x*b,a.y*b);}
P operator/(P a,int b){return P(a.x/b,a.y/b);}
ll cross(P a,P b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
inline bool cmp(const P&a,const P&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
inline vector<P>CH(vector<P>v){
	static const int N=1e4;
	static P tmp[N],st[N];
	int w=0;
	sort(v.begin(),v.end(),cmp);
	for(P u:v){for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])<=0;--w);st[++w]=u;}
	memcpy(tmp+1,st+1,w*(sizeof tmp[0]));
	int ow=w;w=0;
	reverse(v.begin(),v.end());
	for(P u:v){for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])<=0;--w);st[++w]=u;}
	if(tmp[ow]==st[1])--ow;if(w && st[w]==tmp[1])--w;
	memcpy(tmp+ow+1,st+1,w*(sizeof tmp[0]));
	return vector<P>(tmp+1,tmp+ow+w+1);
}
const int L=1e5;
int n,x,y,v,i,j,id;
vector<P>a;
inline void addseg(P p,int d,int k){
	if(p.x<0)d-=-p.x,p.y+=k*-p.x,p.x=0;
	if(p.y<0){if(k==-1)return;d-=-p.y,p.x+=-p.y,p.y=0;}
	if(p.y>L){if(k==1)return;d-=p.y-L,p.x+=p.y-L,p.y=L;}
	if(d<0 || p.x>L)return;
assert(0<=p.x && p.x<=L && 0<=p.y && p.y<=L);
	d=min(d,L-p.x);d=min(d,k>0?L-p.y:p.y);
	a.push_back(p);a.push_back(p+P(d,d*k));
}
double r,nr;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&v);
		if(x+y<=v)a.push_back(P(0,0));
		if(L-x+y<=v)a.push_back(P(L,0));
		if(x+L-y<=v)a.push_back(P(0,L));
		if(L-x+L-y<=v)a.push_back(P(L,L));
		addseg(P(x-v,y),v,1);addseg(P(x,y+v),v,-1);
		addseg(P(x-v,y),v,-1);addseg(P(x,y-v),v,1);
	}
for(auto u:a)assert(0<=u.x && u.x<=L && 0<=u.y && u.y<=L);
	a=CH(a);a.push_back(a[0]);a.push_back(a[1]);
	for(i=0;i+2<a.size();++i){
		P p=a[i+2]-a[i],q=a[i+1]-a[i];
		nr=fabs(p.len()*q.len()*(p-q).len()/cross(p,q));
		if(nr>=r)r=nr,id=i;
	}
	for(j=0;j<3;++j)a[id+j].out();
	return 0;
}