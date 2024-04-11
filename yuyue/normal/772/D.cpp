#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=1e9+7,M=1e6+10;
struct node{
	LL x,y,z;
	node(LL _=1,LL __=0, LL ___=0){
		x=_; y=__; z=___; 
	}
}a[M];
LL b[M];
node operator +(node A,node B){
	return node(A.x*B.x%mod,(A.y*B.x+B.y*A.x)%mod,(A.x*B.z+A.z*B.x+2ll*A.y*B.y)%mod);
}
int n;
int main(){
	n=read();
	F(i,1,n){
		int x=read();
		a[x]=a[x]+node(2,x,1ll*x*x%mod);
	}
	for (int len=1;len<=100000;len*=10){
		DF(j,999999,0){
			if ((j/len)%10){
				a[j-len]=a[j-len]+a[j];
			}
		}
	}
	F(i,0,999999) b[i]=a[i].z;
	for (int len=1;len<=100000;len*=10){
		F(j,0,999999){
			if ((j/len)%10){
				b[j-len]+=mod-b[j];
				b[j-len]%=mod;
			}
		}
	}
	LL ans=0;
	F(i,0,999999){
		ans^=b[i]*i;
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/