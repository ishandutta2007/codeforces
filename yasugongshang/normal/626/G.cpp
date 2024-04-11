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
const int N=200005;
int n,t,q,p[N],tf[N],l[N];
struct data{
	pair<ld,int> mx,mn;
	ld ans;
	void upd(int x){
		mx.se=mn.se=x;
		ans=min((ld)tf[x]/(l[x]+tf[x]),(ld)0.5);
		mx.fi=tf[x]>=l[x]?0:((ld)(tf[x]+1)/(l[x]+tf[x]+1)-ans)*p[x];
		mn.fi=tf[x]?(tf[x]>l[x]?0:((ans-(ld)(tf[x]-1)/(l[x]+tf[x]-1))*p[x])):1e100;
		ans*=p[x];
	}
}tr[1<<19|2];
void push_up(int nod){
	tr[nod].ans=tr[nod<<1].ans+tr[nod<<1|1].ans;
	tr[nod].mx=max(tr[nod<<1].mx,tr[nod<<1|1].mx);
	tr[nod].mn=min(tr[nod<<1].mn,tr[nod<<1|1].mn);
}
void ins(int l,int r,int pos,int nod){
	if(l==r){
		tr[nod].upd(l); return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)ins(l,mid,pos,nod<<1);
	else ins(mid+1,r,pos,nod<<1|1);
	push_up(nod);
}
void build(int l,int r,int nod){
	if(l==r){
		tr[nod].upd(l); return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
int main(){
	n=read(),t=read(),q=read();
	For(i,1,n)p[i]=read();
	For(i,1,n)l[i]=read(); 
	build(1,n,1);
	For(i,1,t){
		int id=tr[1].mx.se;
		tf[id]++;;
		ins(1,n,id,1);
	}
	while(q--){
		int ty=read(),id=read();
		l[id]+=ty==1?1:-1;
		ins(1,n,id,1);
		if(tr[1].mx>tr[1].mn){
			int a=tr[1].mx.se,b=tr[1].mn.se;
			tf[a]++; tf[b]--;
			ins(1,n,a,1);
			ins(1,n,b,1);
		}
		printf("%.10f\n",(double)tr[1].ans);
	}
}