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
const int M=2e5+10;
int a[M];
double ta[M],tb[M];
int n,L;
bool chk(double tim){
	double pa=L;
	F(i,1,n+1){
		if (ta[i]>=tim){
			pa=a[i-1]+(tim-ta[i-1])*i;
			break;
		}
	}
	double bp=0;
	DF(i,n,0){
		if (tb[i]>=tim){
			bp=a[i+1]-(tim-tb[i+1])*(n-i+1);
			break;
		}
	}
	return pa<=bp;
}
int main(){
	int T=read();
	while(T--){
		n=read(); L=read();
		F(i,1,n) a[i]=read();
		a[0]=0; a[n+1]=L; ta[0]=tb[n+1]=0;
		F(i,1,n+1){
			ta[i]=ta[i-1]+(a[i]-a[i-1])/(1.0*i);
		}
		DF(i,n,0){
			tb[i]=tb[i+1]+(a[i+1]-a[i])/(1.0*(n-i+1));
		}	
		long double l=0,r=1e9,ans;
		while (r-l>=1e-9){
			long double mid=(l+r)/2.0;
//			cout<<l<<" "<<r<<" "<<mid<<"\n";
			if (chk(mid)) ans=mid,l=mid+1e-9;
			else r=mid-1e-9;
		}
		
		cout<<fixed<<setprecision(10)<<ans<<"\n";
	}
	return 0;
}