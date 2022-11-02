#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
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
const int N=300005;
int rt[N],dep[N],npl[N],ls[N],rs[N],lzy[N];
PI v[N];
vector<int> e[N];
ll ans;
inline void cao(int x,int y){lzy[x]+=y; v[x].fi+=y;}
void pushdown(int x){
	if(lzy[x]){
		cao(ls[x],lzy[x]); cao(rs[x],lzy[x]); lzy[x]=0;
	}
}
int mer(int a,int b){
	if(!a||!b)return a|b;
	pushdown(a); pushdown(b);
	if(v[a]>v[b])swap(a,b);
	rs[a]=mer(rs[a],b);
	if(npl[ls[a]]<npl[rs[a]])swap(ls[a],rs[a]);
	npl[a]=npl[rs[a]]+1;
	return a;
}
void solve(int p,int fa){
	dep[p]=dep[fa]+1;
	for(auto i:e[p])if(i!=fa){
		solve(i,p);
		rt[p]=mer(rt[p],rt[i]);
	}
	if(p>1){
		while(rt[p]&&dep[v[rt[p]].se]>=dep[p])rt[p]=mer(ls[rt[p]],rs[rt[p]]);
		if(!rt[p]){
			puts("-1"); exit(0);
		}
		ans+=v[rt[p]].fi; cao(rt[p],-v[rt[p]].fi);
	}
}
int main(){
	int n=read(),m=read();
	For(i,1,n-1){
		int s=read(),t=read();
		e[s].pb(t); e[t].pb(s);
	}
	For(i,1,m){
		int s=read(),t=read(),c=read();
		v[i]=mp(c,t); 
		rt[s]=mer(rt[s],i);
	}
	solve(1,0);
	cout<<ans<<endl;
}