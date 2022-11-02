#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
#define ull unsigned long long
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
const int N=1000005,mod=1e9+7;
int n,m,l[N],r[N];
inline ull rnd(){
	ull t=0;
	for(int i=0;i<10;i++)t=t<<10^rand();
	return t;
}
ull ha[N],ff[N],gg[N],s[N],S[N];
map<ull,ll> M1,M2;
ll ans,F[N];
int main(){
	n=read(); m=read(); swap(n,m);
	for(int i=1;i<=n;i++)F[i]=F[i-1]+(ll)i*(i+1)/2;
	for(int i=1;i<=m;i++){
		l[i]=read(); r[i]=read(); ha[i]=rnd();
		ff[l[i]]^=ha[i]; gg[r[i]+1]^=ha[i];
	}
	M1[0]++;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^ff[i]^gg[i];
		S[i]=S[i-1]^s[i];
		ff[i]^=ff[i-1]; gg[i]^=gg[i-1];
		if(M1.count(ff[i]^S[i])){
			ans+=M1[ff[i]^S[i]]*i-M2[ff[i]^S[i]];
		}
		M1[gg[i+1]^gg[i]^S[i]]++; M2[gg[i+1]^gg[i]^S[i]]+=i;
		//cout<<(gg[i+1]^S[i])<<" "<<(ff[i]^S[i])<<" "<<ff[i]<<endl;
	}
	int dq=0;
	for(int i=1;i<=n;i++)if(s[i]==0)dq++; else {
		ans-=F[dq]; dq=0;
	}
	ans-=F[dq];
	cout<<ans<<endl;
}