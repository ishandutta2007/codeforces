#include<bits/stdc++.h>
using namespace std;

int a[200001];

int cnt[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long int ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans+=a[i];
	map<pair<int,int>,int> m;
	int q;
	cin>>q;
	while(q--){
		int s,t,u;
		cin>>s>>t>>u;
		auto x=m.find(make_pair(s,t));
		if(x!=m.end()){
			int y=x->second;
			m.erase(x);
			if(cnt[y]<=a[y])
				ans++;
			cnt[y]--;
		}
		if(u!=0){
			m[make_pair(s,t)]=u;
			if(cnt[u]<a[u])
				ans--;
			cnt[u]++;
		}
		cout<<ans<<'\n';
	}

}