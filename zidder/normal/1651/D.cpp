#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<pair<int, int> > points(n);
	vector<bool> ans(n);
	vector<pair<int, int> > anss(n);
	map<pair<int, int>, int> points_map;
	for (int i=0;i<n;++i){
		int x, y;
		scanf("%d%d", &x, &y);
		points[i] = make_pair(x, y);
		points_map[points[i]] = i;
	}

	vector<int> q;

	for (int i=0;i<n;++i){
		for (int j=0;j<4;++j){
			int dx = j == 0? 1: j==1?-1:0;
			int dy = j == 2? 1: j==3?-1:0;
			int x = points[i].first + dx;
			int y = points[i].second + dy;
			if ( points_map.find(make_pair(x, y)) == points_map.end() ){
				ans[i] = true;
				anss[i] = make_pair(x, y);
				q.push_back(i);
				break;
			}
		}
	}

	int ind = 0;
	while (ind < q.size()){
		int i = q[ind++];
		for (int j=0;j<4;++j){
			int dx = j == 0? 1: j==1?-1:0;
			int dy = j == 2? 1: j==3?-1:0;
			int x = points[i].first + dx;
			int y = points[i].second + dy;
			if ( points_map.find(make_pair(x, y)) != points_map.end() ){
				int k = points_map[make_pair(x, y)];
				if (!ans[k]){
					ans[k] = true;
					anss[k] = anss[i];
					q.push_back(k);
				}
			}
		}
	}

	for (int i=0;i<n;++i){
		printf("%d %d\n", anss[i].first, anss[i].second);
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