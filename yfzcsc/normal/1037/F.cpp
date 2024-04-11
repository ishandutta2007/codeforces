#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 1001000
using namespace std;
typedef pair<int,int> pii;
int dp[maxn],n,K,ans,sum0;
pii a[maxn];
set<int>st;
int cal(int len){
	return dp[len];
}
void ins(int x){
	auto it=st.insert(x).first;
	int l=it==st.begin()?0:*prev(it);
	int r=next(it)==st.end()?n+1:*next(it);
	sum0=(sum0-cal(r-l-1)+mod)%mod;
	sum0=(sum0+cal(x-l-1))%mod;
	sum0=(sum0+cal(r-x-1))%mod;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=K;i<=n;++i)
		dp[i]=((i-K+1)+dp[i-K+1])%mod;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n+1);
	for(int i=n,j;i>=1;i=j){
		int sum1=sum0;
		for(j=i;a[j].first==a[i].first&&j>=1;j--)
			ins(a[j].second);
		ans=(ans+1ll*(sum1-sum0+mod)*a[i].first)%mod;
	}
	printf("%d",ans);
}