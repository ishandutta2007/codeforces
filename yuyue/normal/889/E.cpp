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
int n;
LL a[M];
map<LL,LL> dp;
void upd(LL x,LL y){
	dp.count(x) ? dp[x]=max(dp[x],y) : dp[x]=y;
}
int main(){
	n=read();
	F(i,1,n){
		a[i]=read();
	}
	dp[a[1]-1]=0;
	F(i,2,n){
		while (dp.size()){
			auto O=*dp.rbegin();
			LL x=O.first,val=O.second;
			if (O.first>=a[i]){
				LL nx=x%a[i],nval=val+(x-x%a[i])*(i-1);
				upd(nx,nval);
				nx=a[i]-1; nval=val+(((x-a[i]+1)/a[i])*(a[i]))*(i-1);
				upd(nx,nval);
				dp.erase(x);
			}
			else break;
		}
//		for (auto O:dp){
//			cout<<O.first<<" "<<O.second<<"   ohh\n";
//		}
//		cout<<"--------------\n";
	}
	LL ans=0;
	for (auto O:dp){
		ans=max(ans,O.second+O.first*n);
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
3
4 2 1
*/