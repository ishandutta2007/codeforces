#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
LL gcd(LL x,LL y){
	return (y ? gcd(y,x%y) : x); 
}
int n,m;
LL a[M];
int main(){
	n=read(); m=read();
	LL d=0;
	F(i,1,n){
		a[i]=read();
		if (i>1){
			LL tmp=abs(a[i]-a[i-1]);
			d=gcd(tmp,d);
		}
	}
	F(i,1,m){
		LL x=read();
		cout<<gcd(d,x+a[1])<<" ";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/