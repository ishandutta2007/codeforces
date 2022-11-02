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
const int N=150005;
ld l[N],r[N];
struct data{
	ll p,t,id;
}a[N],b[N];
int n;
ll T;
bool cmp(data a,data b){
	return a.p<b.p;
}
bool cmpt(data a,data b){
 	ll A=(ll)a.t*b.p,B=(ll)b.t*a.p;
	return A==B?a.p<b.p:A<B;
}
bool check(ld c){
	ll sum=0;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[j].t*a[i].p==a[i].t*a[j].p)j++;
		For(k,i,j-1)r[a[k].id]=(1-c*(sum+a[k].t)/T)*a[k].p;
		For(k,i,j-1)sum+=a[k].t;
		For(k,i,j-1)l[a[k].id]=(1-c*sum/T)*a[k].p;
	}
	int dq=n; ld mn=1e100;
	//For(i,1,n)cout<<l[i]<<" "<<r[i]<<endl; puts("");
	Rep(i,n,1){
		while(b[dq].p>b[i].p){
			mn=min(mn,l[b[dq--].id]);
		}
		if(mn<=r[b[i].id])return 0;
	}
	return 1;
}
int main(){
	n=read();
	For(i,1,n)a[a[i].id=i].p=read();
	For(i,1,n)T+=(a[i].t=read());
	For(i,1,n)b[i]=a[i];
	sort(a+1,a+n+1,cmpt);
	sort(b+1,b+n+1,cmp);
	ld l=0,r=1;
	//check(0.31901840491); return 0;
	For(i,1,80){
		ld mid=(l+r)/2;
		if(check(mid))l=mid; else r=mid;
	}
	printf("%.10f",(double)l);
}