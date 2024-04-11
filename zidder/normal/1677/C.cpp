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
	vector<int> ca(n), cb(n);
	for (int &i: ca) scanf("%d", &i);
	for (int &i: cb) scanf("%d", &i);
	for (int &i: ca) --i;
	for (int &i: cb) --i;
	vector<int> ib(n);
	for (int i=0;i<n;++i) ib[cb[i]] = i;
	vector<int> cycles;
	vector<bool> visited(n, false);
	for (int i=0;i<n;++i) {
		if (visited[i]) continue;
		int c = 1;
		visited[i] = true;
		for (int j=ib[ca[i]];j!=i;j=ib[ca[j]]){
			c++;
			visited[j] = true;
		}
		cycles.push_back(c);
	}
	sort(cycles.begin(), cycles.end());
	long long ans = 0;
	int h = n, l = 1;
	for (int i: cycles) {
		if (i == 1) continue;
		if (i == 2) {
			ans += (h - l) * 2;
			h--;
			l++;
			continue;
		}
		vector<int> v;
		bool hi = false;
		for (int j=0;j<i;++j){
			if (j == i - 1 && i % 2 == 1) {
				v.push_back(l);
				continue;
			}
			if (hi) v.push_back(h--);
			else v.push_back(l++);
			hi = !hi;
		}
		for (int j=0;j<v.size();++j){
			ans += abs(v[j] - v[(j+1)%v.size()]);
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}