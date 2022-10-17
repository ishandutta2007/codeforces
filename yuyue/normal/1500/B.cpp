#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define int LL
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
void exgcd(LL a,LL b,LL &x,LL &y){
	if (!b) {
		x=1; y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=x*(a/b);
}
int n,m,a[M],b[M],o;
LL p,q,t[M],K,x,y;
void init(){
	o=__gcd(n,m);
	exgcd(n,m,x,y);	
	p=m/o,q=n/o;
	if (x<0){
		LL k=(-x+p-1)/p; x+=k*p; y-=k*q; 
	}
	else{
		LL k=(x)/p; x-=k*p; y+=k*q;
	}	
//	cout<<x<<" "<<y<<" ?? \n";
}
int ha[M],hb[M];
LL chk(LL rd){
	LL ret=0;
	F(i,0,n-1){
		int del=hb[a[i]]-i;
		if (del%o!=0 || hb[a[i]]==-1) continue;
		del/=o;
		LL tx=x*del,ty=y*del;
		if (tx<0){
			LL k=(-tx+p-1)/p; tx+=k*p,ty-=k*q; 
		}
		else{
			LL k=(tx)/p; tx-=k*p,ty+=k*q;
		}
		if (tx<=rd) ret=(ret+(rd-tx)/p+1);
//		cout<<del<<" "<<tx<<" "<<ty<<" "<<ret<<"  nmd \n";
	}
	return (rd+1)*n-ret;
}
signed main(){
//	cerr<<((-1+-1)>>1)<<'\n';
	n=read(); m=read(); K=read(); 
	F(i,1,2*max(n,m)) hb[i]=-1;
	F(i,0,n-1) a[i]=read();
	F(i,0,m-1) b[i]=read();
	if (n<m) swap(a,b),swap(n,m);
	init();
	F(i,0,m-1) hb[b[i]]=i;
	LL l=-1,r=K+1,ga=-1;
//	cout<<chk(0)<<"\n";
	
	while (l<=r){
		LL mid=(l+r>>1);
		if (chk(mid)<K) l=mid+1,ga=mid;
		else r=mid-1;
	}
	LL now=chk(ga),day=1ll*(ga+1)*n;
//	cout<<now<<" "<<ga<<"   ggg\n";
	if (now==K){
		cout<<day<<"\n";
		return 0;
	}
	F(i,0,n-1){
		int ia=(day+i)%n,ib=(day+i)%m;
		if (a[ia]^b[ib]) now++;
		if (now==K){
			cout<<day+i+1<<"\n";
			return 0;
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
3 8 410320365
1 3 2
1 6 4 3 5 7 2 8

1 1 55
1
2
*/