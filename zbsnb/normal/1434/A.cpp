#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x[100010][10];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int a[6];
	for(int i=0;i<6;i++) cin>>a[i];
	sort(a,a+6,greater<int>());
	int n;cin>>n;
	vector<pair<int,pair<int,int> > > vec;
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		for(int j=0;j<6;j++){
			x[i][j]=tmp-a[j];
			vec.push_back({x[i][j],{i,j}});
		}
	}
	sort(vec.begin(),vec.end());
	multiset<int> s;
	int ans=2e9+10,cnt=0;
	for(auto it:vec){
		int now=it.first,tp=it.second.first,ind=it.second.second;
		if(ind==0){
			cnt++;
			s.insert(now);
		}
		else{
			s.erase(s.find(x[tp][ind-1]));
			s.insert(now);
		}
		if(cnt==n){
			ans=min(ans,now-*s.begin());
		}
		// cout<<now<<" "<<*s.begin()<<endl;
	}
	cout<<ans<<endl;
}