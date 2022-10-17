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
const int inf=1e9,M=2e5+10;
LL ans;
int mx,a[M],b[M],n,lmx[M],rmx[M],lmi[M],rmi[M];
void work(int o){
	F(i,0,2*mx) lmx[i]=rmx[i]=-inf,lmi[i]=rmi[i]=inf;
	F(i,1,n){
		int x=a[i]+b[i],y=a[i]-b[i];
		if (o) x++,y++;
		x/=2; y/=2;
		if (((a[i]+b[i])&1)==o){
			lmx[x+mx]=max(lmx[x+mx],y);
			rmx[x+mx]=max(rmx[x+mx],y);
			lmi[x+mx]=min(lmi[x+mx],y);
			rmi[x+mx]=min(rmi[x+mx],y);
		}
	}
	F(i,1,2*mx) lmx[i]=max(lmx[i-1],lmx[i]),lmi[i]=min(lmi[i-1],lmi[i]);
	DF(i,2*mx-1,0) rmx[i]=max(rmx[i+1],rmx[i]),rmi[i]=min(rmi[i+1],rmi[i]);
	F(i,0,2*mx-1){
		int lb=max(lmi[i],rmi[i+1]),rb=min(lmx[i],rmx[i+1]);
		if (lb<=rb) ans+=rb-lb;
	}
}
int main(){
	n=read();
	F(i,1,n){
		a[i]=read(); b[i]=read();
		mx=max(mx,abs(a[i]));
		mx=max(mx,abs(b[i]));
	}
	work(0); work(1);
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