#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long dist(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y){
	long long dx = x.first.first - y.first.first;
	long long dy = x.first.second - y.first.second;
	long long dz = x.second.first - y.second.first;
	return dx* dx+dy*dy+dz*dz;
}
void solve(int test_ind){
	int n;
	cin >> n;
	vector<pair<pair<int, int>, pair<int, int>> > v;
	for(int i=0;i<n;++i){
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back(make_pair(make_pair(x, y), make_pair(z, i+1)));
	}
	for(int i=0;i<n/2;i++){
		auto first = v[0];
		long long minval=dist(v[0], v[1]), minind=1;
		for(int j=2;j<v.size();j++){
			if (dist(v[0], v[j]) < minval){
				minind = j;
				minval = dist(v[0], v[j]);
			}
		}
		cout << v[minind].second.second<<" "<<v[0].second.second<<endl;
		v.erase(v.begin()+minind);
		v.erase(v.begin());
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}