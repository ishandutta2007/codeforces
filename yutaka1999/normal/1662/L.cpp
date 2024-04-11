#include <bits/stdc++.h>
#define INF 100000000000000000LL
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

int main(){
	int n,v;
	scanf("%d%d",&n,&v);
	vector <int> T(n),A(n);
	for(int i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	vector <P> vx;
	for(int i=0;i<n;i++){
		ll x=A[i]+(ll) T[i]*v;
		ll y=-A[i]+(ll) T[i]*v;
		if(x>=0&&y>=0){
			vx.push_back(P(x,y));
		}
	}
	sort(vx.begin(),vx.end());
	vector <ll> dp(n+1);
	for(int i=1;i<=n;i++) dp[i]=INF;
	for(int i=0;i<vx.size();i++){
		int p=upper_bound(dp.begin(),dp.end(),vx[i].second)-dp.begin();
		dp[p]=vx[i].second;
	}
	for(int i=n;i>=0;i--){
		if(dp[i]!=INF){
			printf("%d\n",i);
			break;
		}
	}
}