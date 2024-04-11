#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<long double,int> > pq;

long double dp[1000001],f[101];

int p[101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	dp[n]=1;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		f[i]=p[i]/100.0;
		dp[n]*=f[i];
		pq.push(make_pair(((1-f[i])*p[i]/100+f[i])/f[i],i));
	}
	long double ans=0;
	ans+=n*dp[n];
	for(int i=n+1;i<=1000000;i++){
		auto now=pq.top();pq.pop();
		dp[i]=dp[i-1]*now.first;
		f[now.second]*=now.first;
		ans+=i*(dp[i]-dp[i-1]);
		pq.push(make_pair(((1-f[now.second])*p[now.second]/100+f[now.second])/f[now.second],now.second));
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
}