#include<bits/stdc++.h>
using namespace std;

bitset<2001> dp[1<<16];

int a[16];
int cnt[16];
bool in[16];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0].set(0);
	for(int i=1;i<1<<n;i++){
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				dp[i]|=dp[i^(1<<j)]<<a[j];
		for(int j=2000/k*k;j>0;j-=k)
			if(dp[i][j])
				dp[i].set(j/k);
	}
	if(!dp[(1<<n)-1][1]){
		cout<<"NO"<<endl;
		return 0;
	}
	int now=(1<<n)-1,v=1;
	for(int i=0;i<n;i++)
		in[i]=true;
	while(now){
		while(v*k<=2000&&dp[now][v*k]){
			for(int i=0;i<n;i++)
				if(in[i])
					cnt[i]++;
			v*=k;
		}
		for(int i=0;i<n;i++)
			if(in[i]&&v>=a[i]&&dp[now^(1<<i)][v-a[i]]){
				now^=(1<<i);
				v-=a[i];
				in[i]^=true;
				break;
			}
	}
	vector<pair<int,int> > r;
	for(int i=0;i<n;i++)
		r.emplace_back(cnt[i],a[i]);
	cout<<"YES"<<endl;
	while(r.size()!=1){
		sort(r.begin(),r.end());
		auto p1=r.back();r.pop_back();
		auto p2=r.back();r.pop_back();
		cout<<p1.second<<' '<<p2.second<<endl;
		p1.second+=p2.second;
		while(p1.second%k==0){
			p1.first--;
			p1.second/=k;
		}
		r.emplace_back(p1);
	}
}