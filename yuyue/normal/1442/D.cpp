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
const int M=3030;
vector<LL> v[M];
int n,num[M],k;
LL dp[M],ans=0,val[M];
void solve(int l,int r){
	if (l==r){
		LL now=dp[k],sum=0;
		F(i,0,SZ(v[l])){
			sum+=v[l][i];
			if (k-i-1>=0) now=max(now,dp[k-i-1]+sum);
		}
		ans=max(now,ans);
		return ;
	}
	int mid=(l+r>>1);
	LL tmp[M];
	F(i,0,k) tmp[i]=dp[i];
	F(i,l,mid){
		DF(j,k,num[i]){
			dp[j]=max(dp[j-num[i]]+val[i],dp[j]);
		}
	}
	solve(mid+1,r); 
	F(i,0,k) dp[i]=tmp[i];
	F(i,mid+1,r){
		DF(j,k,num[i]){
			dp[j]=max(dp[j-num[i]]+val[i],dp[j]);
		}
	}
	solve(l,mid);
}
int main(){
	n=read(); k=read();
	//ms(dp,~1); dp[0]=0;
	F(i,1,n){
		num[i]=read();
		F(j,1,num[i]){
			int x=read(); 
			v[i].pb(x);
			val[i]+=x;
		}
	}
	solve(1,n);
	cout<<ans<<'\n';
	return 0; 
}