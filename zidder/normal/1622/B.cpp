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
	vector<int> p(n);
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	string s;
	cin >> s;
	vector<pair<int, int>> l, h;
	for (int i=0;i<n;++i){
		if (s[i] == '0') l.emplace_back(p[i], i);
		else h.emplace_back(p[i], i);
	}
	sort(l.begin(), l.end());
	sort(h.begin(), h.end());
	vector<int> np(n);
	for (int i=1;i<=l.size();++i){
		np[l[i-1].second] = i;
	}
	for (int i=1;i<=h.size();++i){
		np[h[i-1].second] = i + l.size();
	}
	for (int i: np) printf("%d ", i);
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}