#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	long long int ans = 0;
	for(int i=1;i<=n;i++){
		string s;
		int sc = 0, hc = 0;
		cin>>s;
		for(auto it : s){
			if(it=='h'){
				hc ++, ans += sc;
			}
			else
				sc++;
		}
		v.emplace_back(sc,hc);
	}
	sort(v.begin(),v.end(),[&](pair<int,int> x,pair<int,int> y){
		return 1LL * x.first * y.second > 1LL * x.second * y.first;
	});
	int sc = 0;
	for(auto it:v){
		ans += 1LL * sc * it.second;
		sc+=it.first;
	}
	cout << ans << endl;
}