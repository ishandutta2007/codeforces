#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int a[maxn],b[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		long long int ans=0;
		vector<int> v;
		vector<long long int> sum(m);
		for(int i=1;i<=m;i++){
			cin>>a[i]>>b[i];
			v.emplace_back(-a[i]);
		}
		sort(v.begin(),v.end());
		sum[0]=v[0];
		for(int i=1;i<sum.size();i++)
			sum[i]=sum[i-1]+v[i];
		for(int i=1;i<=m;i++){
			int idx = lower_bound(v.begin(),v.end(),-b[i]) - v.begin();
			if(idx==0)	ans = max(ans,a[i]+1LL*(n-1)*b[i]);
			else if(idx>=n)	ans = max(ans,-sum[n-1]);
			else{
				if(a[i]>b[i])
					ans = max(-sum[idx-1]+1LL*(n-idx)*b[i],ans);
				else
					ans = max(-sum[idx-1]+a[i]+1LL*(n-idx-1)*b[i],ans);
			}
		}
		cout<<ans<<"\n";
	}
}