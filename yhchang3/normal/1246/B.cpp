#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[100000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,x;
	cin>>n>>k;
	long long int ans=0;
	map<vector<pair<int,int> >,int> m;
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				int cnt=0;
				while(x%j==0){
					cnt++;
					x/=j;
				}
				cnt%=k;
				if(cnt!=0)
					v[i].emplace_back(j,cnt);
			}
		}
		if(x!=1)
			v[i].emplace_back(x,1);
		m[v[i]]++;
	}
	for(int i=0;i<n;i++){
		auto q=v[i];
		for(auto& it:q)
			it.second=k-it.second;
		if(q==v[i])	ans--;
		if(m.count(q))
			ans+=m[q];
	}
	cout<<ans/2<<endl;
}