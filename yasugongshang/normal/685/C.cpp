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
const ll inf=4e18;
struct data{
	ll a,b,c;
};
ll _L[4],_R[4];
ll L[4],R[4];
bool check(ll mid){
	For(o,0,1){
		For(i,0,3){_L[i]=L[i]-mid; _R[i]=R[i]+mid;}
		For(i,0,3){
			if((_L[i]&1)!=o)_L[i]++;
			if((_R[i]&1)!=o)_R[i]--;
		}
		//if(mid==610826845990701819)cout<<_L[1]+_L[2]+_L[3]<<" "<<_L[0]<<" "<<_R[1]+_R[2]+_R[3]<<" "<<_R[0]<<endl;
		if(max(_L[1]+_L[2]+_L[3],_L[0])<=min(_R[1]+_R[2]+_R[3],_R[0])&&_L[1]<=_R[1]&&_L[2]<=_R[2]&&_L[3]<=_R[3])return 1;
	}
	return 0;
}
data sol(ll mid){
	For(o,0,1){
		For(i,0,3){_L[i]=L[i]-mid; _R[i]=R[i]+mid;}
		For(i,0,3){
			if((_L[i]&1)!=o)_L[i]++;
			if((_R[i]&1)!=o)_R[i]--;
		}
		if(max(_L[1]+_L[2]+_L[3],_L[0])<=min(_R[1]+_R[2]+_R[3],_R[0])&&_L[1]<=_R[1]&&_L[2]<=_R[2]&&_L[3]<=_R[3]){
			ll A=_L[1],B=_L[2],C=_L[3];
			if(A+B+C<_L[0]){A+=min(_L[0]-A-B-C,_R[1]-_L[1]);}
			if(A+B+C<_L[0]){B+=min(_L[0]-A-B-C,_R[2]-_L[2]);}
			if(A+B+C<_L[0]){C+=min(_L[0]-A-B-C,_R[3]-_L[3]);}
			return (data){(A+B)/2,(A+C)/2,(B+C)/2};
		}
	}
}
int main(){
	//freopen("std.in","r",stdin);
	int T=read();
	while(T--){
		int n=read();
		For(i,0,3){L[i]=-inf; R[i]=inf;}
		For(i,1,n){
			ll x=read(),y=read(),z=read();
			L[0]=max(L[0],x+y+z);
			L[1]=max(L[1],x+y-z);
			L[2]=max(L[2],x+z-y);
			L[3]=max(L[3],y+z-x);
			R[0]=min(R[0],x+y+z);
			R[1]=min(R[1],x+y-z);
			R[2]=min(R[2],x+z-y);
			R[3]=min(R[3],y+z-x);
		}
		//For(i,0,3)cout<<L[i]<<" "<<R[i]<<endl;
		ll l=0,r=3e18;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid))r=mid; else l=mid+1;
		}//cout<<l<<endl;
		data t=sol(l);
		wri(t.a); wri(t.b); writeln(t.c);
	}
}
/*
610826845990701819
*/