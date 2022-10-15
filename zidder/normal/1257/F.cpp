#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
 
#define ll long long
using namespace std;
 
inline int cnt1(int x){
	int ans=0;
	while(x){x&=(x-1);++ans;}
	return ans;
}
vector<vector<int> > v1, v2;
map<vector<int>, int> mp;
const int P = 31;
 
void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;++i)cin>>v[i];
	int m1=(1<<15)-1;
	for(int i=0;i<(1<<15);++i){
		v1.emplace_back();
		v2.emplace_back();
		for(auto u:v){
			v1.back().push_back(cnt1(((u>>15)^i)&m1));
			v2.back().push_back(cnt1((u^i)&m1));
		}
		mp[v2.back()] = i;
	}
	for(int i=0;i<=m1;++i){
		for(int cnt=0;cnt<=30;++cnt){
		    vector<int> s;
			for(auto u:v1[i]){
				s.push_back(cnt-u);
			}
			auto it = mp.find(s);
			if (it != mp.end()){
				int ind = it->second;
				cout<<(i<<15)+ind;
				return;
			}
		}
	}
	cout << -1;
}
 
int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}