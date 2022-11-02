#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int N=100005;
multiset<ll> s[N],S;
ll ans[N],t[N];
int f[N],d[N];
inline ll lzy(int x){
	return t[x]/d[x];
}
void insset(int x){
	if(s[x].size()){
		S.insert(*s[x].begin()+lzy(x));
		S.insert(*s[x].rbegin()+lzy(x));
	}
}
void eraset(int x){
	if(s[x].size()){
		S.erase(S.find(*s[x].begin()+lzy(x)));
		S.erase(S.find(*s[x].rbegin()+lzy(x)));
	}
}
void insdd(int x){
	eraset(f[x]);
	s[f[x]].insert(ans[x]);
	insset(f[x]);
}
void eradd(int x){
	eraset(f[x]);
	s[f[x]].erase(s[f[x]].find(ans[x]));
	insset(f[x]);
}
void inc(int x,ll y,ll z){
	eradd(x); 
	ans[x]+=y+(t[x]-t[x]/(d[x]+1)*d[x])-(t[x]-t[x]/d[x]*(d[x]-1)); 
	insdd(x);
	ll de=t[x]/(d[x]+1)-t[x]/d[x];
	eraset(x); s[x].insert(z); d[x]++; insset(x); eradd(f[x]); ans[f[x]]+=de; insdd(f[x]);
}
void dec(int x,ll y,ll z){
	eradd(x);
	ans[x]+=y+(t[x]-t[x]/(d[x]-1)*(d[x]-2))-(t[x]-t[x]/d[x]*(d[x]-1));
	insdd(x);
	ll de=t[x]/(d[x]-1)-t[x]/d[x];
	eraset(x); s[x].erase(s[x].find(z)); d[x]--; insset(x); eradd(f[x]); ans[f[x]]+=de; insdd(f[x]);
}
int main(){
	int n=read(),q=read();
	For(i,1,n)t[i]=read();
	
	For(i,1,n){
		f[i]=read();
		d[f[i]]++; d[i]+=2;
	}
	For(i,1,n){
		ll zs=t[i]/d[i];
		ans[f[i]]+=zs; ans[i]+=t[i]-(d[i]-1)*zs; 
	}
	For(i,1,n)s[f[i]].insert(ans[i]);
	For(i,1,n)insset(i);
	For(i,1,q){
		int op=read();
		if(op==1){
			int x=read(),y=read();
			dec(f[x],-lzy(x),ans[x]);
			f[x]=y;
			inc(f[x],lzy(x),ans[x]);
		}else if(op==2){
			int x=read();
			writeln(ans[x]+lzy(f[x]));
			//cout<<ans[x]<<" "<<lzy(f[x])<<endl;
		}else {
			wri(*S.begin()); writeln(*S.rbegin());
		}
	}
}