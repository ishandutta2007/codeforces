#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	map<int, int> m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		m[x] = i;
	}
	vector<int> b;
	set<int> all_nums;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		all_nums.insert(i);
		x = m[x];
		b.push_back(x);
	}
	long long ans=0;
	for(int i=0;i<n;++i){
		ans += *all_nums.begin() != b[i];
		all_nums.erase(b[i]);
	}
	cout<<ans<<endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}