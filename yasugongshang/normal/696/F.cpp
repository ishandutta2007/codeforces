#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const ld eps=1e-9,inf=1e18;
const int N=905;
inline int dcmp(ld a){
	return fabs(a)<=eps?0:(a>0?1:-1);
}
struct pt{
	ld x,y;
	inline pt operator + (const pt &p)const{return (pt){x+p.x,y+p.y};}
	inline pt operator - (const pt &p)const{return (pt){x-p.x,y-p.y};}
	inline pt operator * (const ld &v)const{return (pt){x*v,y*v};}
	inline ld operator * (const pt &p)const{return x*p.x+y*p.y;}
	inline ld len(){return sqrt(x*x+y*y);}
};
typedef vector<pt> pig;
inline ld cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
inline ld Angle(pt a){return atan2(a.y,a.x);}
inline ld S(pig v){
	if(v.size()<=2)return 0;
	ld sum=cross(v.back(),v[0]);
	For(i,0,v.size()-2)sum+=cross(v[i],v[i+1]);
	return sum/2;
}
struct line{
	pt s,t;
};
inline ld Angle(line a){return Angle(a.t-a.s);}
inline pt jd(line a,line b){
	pt u=a.s-b.s,v=a.t-a.s,w=b.t-b.s;
	ld t=cross(w,u)/cross(v,w);
	return a.s+v*t;
}
ld ang[N];
line zs[N];
bool cmp(int a,int b){
	ld A=ang[a],B=ang[b];
	int t=dcmp(A-B);
	return t==0?dcmp(cross(zs[a].t-zs[a].s,zs[b].t-zs[a].s))<0:t<0;
}
bool check(line a,line b,line c){
	pt o=jd(b,c);
	ld tmp=cross(a.t-a.s,o-a.s);
	return dcmp(tmp)<=0;
}
bool px(line a,line b){
	return fabs(cross(a.t-a.s,b.t-b.s))==0;
}
pig half(vector<line> v){//puts("zyk");
	static line q[N];
	int l=1,r=0;
	pig p;
	for(auto i:v){
		while(l<r&&check(i,q[r],q[r-1]))r--;
		while(l<r&&check(i,q[l],q[l+1]))l++;
		q[++r]=i; //cout<<l<<" "<<r<<endl;
	}
	//cout<<l<<" "<<r<<endl;
	while(l<r&&check(q[l],q[r],q[r-1]))r--;
	while(l<r&&check(q[r],q[l],q[l+1]))l++;  
	if(l+1>=r)return p;
	For(i,l,r-1)p.pb(jd(q[i],q[i+1]));
	p.pb(jd(q[r],q[l]));
	//for(auto i:p)cout<<i.x<<" "<<i.y<<endl;
	return p;
}
pt a[N];
int n,sor[N],vis[N];
pt chu(pt a){
	return (pt){a.y,-a.x};
}
pig check(int l,int r){
	memset(vis,0,sizeof(vis));
	For(i,l,r-1)vis[i%n]=1; 
	vector<line> v; ld lst=-inf;
	For(i,0,3*n-1)if(sor[i]>=2*n||vis[sor[i]/2]){
		if(dcmp(ang[sor[i]]-lst)){lst=ang[sor[i]]; v.pb(zs[sor[i]]);}
	}
	return half(v);
}
pig solve(ld mid){
	For(i,0,n-1){
		zs[2*i]=(line){a[i],a[(i+1)%n]};
		zs[2*i+1]=(line){a[(i+1)%n],a[i]};
	}
	For(i,0,2*n-1){
		pt jj=chu(zs[i].t-zs[i].s);
		ld ab=1/(zs[i].t-zs[i].s).len();
		zs[i].s=zs[i].s+jj*ab*mid;
		zs[i].t=zs[i].t+jj*ab*mid;
	}
	For(i,0,n-1)zs[i+2*n]=(line){a[i],a[(i+1)%n]};
	For(i,0,3*n-1){sor[i]=i; ang[i]=Angle(zs[i]);}
	sort(sor,sor+3*n,cmp);
	pig ans;
	int j=0;
	For(i,0,n-1){
		pig x,y;
		while(j<i+n&&(y=check(i,j+1)).size())x=y,j++;//cout<<i<<" "<<j<<" "<<x.size()<<" "<<endl;
		if(j==i+n){
			ans.pb(x[0]); ans.pb(x[0]); return ans;
		}
		y=check(j,i+n);  //cout<<y.size()<<" "<<j<<" "<<ans.size()<<endl;
		if(y.size()){
			ans.pb(x[0]); ans.pb(y[0]); return ans;
		}
	}
	return ans;
}
int main(){
	n=read();
	For(i,0,n-1){
		a[i].x=read(); a[i].y=read(); a[i+n]=a[i];
	}
	int j=0;
	ld ans=1e100; PI jb;
	ld L=0,R=40000;
	while(L+max((ld)1,L)*2e-7<R){
		ld mid=(L+R)/2; //cout<<L<<" "<<R<<endl;
		if(solve(mid).size())R=mid; else L=mid;
	}
	printf("%.9f\n",(double)R);
	//cout<<jb.fi<<" fjzzq "<<jb.se<<" "<<solve(2,6).fi<<" "<<solve(6,2+n).fi<<endl;
	pig jjl=solve(R);
	pt zs=jjl[0];
	printf("%.9f %.9f\n",(double)zs.x,(double)zs.y);
	zs=jjl[1];
	printf("%.9f %.9f\n",(double)zs.x,(double)zs.y);
}