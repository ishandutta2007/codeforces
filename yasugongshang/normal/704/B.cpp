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
const int N=5005;
ll x[N],a[N],b[N],c[N],d[N],ans;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll cal(int x,int y){
	return x<y?a[y]+d[x]:b[y]+c[x];
}
int main(){
	int n=read(),s=read(),e=read();
	For(i,1,n)x[i]=read();
	For(i,1,n)a[i]=read()+x[i];
	For(i,1,n)b[i]=read()-x[i];
	For(i,1,n)c[i]=read()+x[i];
	For(i,1,n)d[i]=read()-x[i];
	if(min(s,e)==1)ans=cal(s,e);
	else ans=cal(s,1)+cal(1,e);
	For(i,2,n){
		if(i==s)q.push(d[i]-c[i]);
		else if(i==e)q.push(b[i]-a[i]);
		else{
			ans+=a[i]+c[i];
			if(i<s)q.push(b[i]-a[i]);
			if(i<e)q.push(d[i]-c[i]);
			ans+=q.top(); q.pop();
			if(i>s)q.push(b[i]-a[i]);
			if(i>e)q.push(d[i]-c[i]);
		}
	}
	cout<<ans<<endl;
}