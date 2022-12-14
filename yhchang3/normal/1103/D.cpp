#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> v[1000000];
int cnt2[1<<11];
long long int dp[12][1<<11],cost[1<<11],tmp[12][1<<11];
long long int gcd(long long int x,long long int y){
	while((x%=y)&&(y%=x));
	return x^y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long int k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>v[i].second;
	for(int i=0;i<n;i++)
		cin>>v[i].first;
	sort(v,v+n);
	long long int g=0;
	for(int i=0;i<n;i++)
		g=gcd(g,v[i].second);
	if(g==1){
		cout<<0<<endl;
		return 0;
	}
	vector<long long int> p;
	map<long long int,int> cnt;
	for(long long int i=2;i*i<=g;i++){
		if(g%i==0){
			p.emplace_back(i);
			while(g%i==0)	g/=i;
		}
	}
	if(g!=1)	p.emplace_back(g);
	int m=p.size();
	for(int j=0;j<=m;j++)
		for(int k=0;k<1<<m;k++)
			dp[j][k]=1e18;
	for(int i=0;i<n;i++){
		cost[0]=1;
		long long int cur=1;
		for(int j=0;j<m;j++){
			cost[1<<j]=1;
			while(v[i].second%p[j]==0){
				cost[1<<j]*=p[j];
				cur*=p[j];
				v[i].second/=p[j];
			}
		}
		if(++cnt[cur]>m)	continue;
		for(int j=0;j<=m;j++)
			for(int k=0;k<1<<m;k++)
				tmp[j][k]=dp[j][k];
		for(int mask=1;mask<1<<m;mask++){
			cost[mask]=cost[mask^(mask&-mask)]*cost[mask&-mask];
			if(cost[mask]>k)	continue;
			if(++cnt2[mask]>m)	continue;
			int comp=(~mask)&((1<<m)-1);
			for(int j=0;j<m;j++){
				dp[j+1][mask]=min(dp[j+1][mask],v[i].first);
				for(int sub=comp;sub;sub=(sub-1)&comp)
					dp[j+1][mask|sub]=min(dp[j+1][mask|sub],tmp[j][sub]+v[i].first);
			}
		}
	}
	long long int ans=1e18;
	for(int i=1;i<=m;i++)
		if(dp[i][(1<<m)-1]!=1e18)
			ans=min(ans,i*dp[i][(1<<m)-1]);
	if(ans==1e18)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}