#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	vector<int> a(n1), b(n2), c(n3), d(n4);
	for (int &i: a) scanf("%d", &i);
	for (int &i: b) scanf("%d", &i);
	for (int &i: c) scanf("%d", &i);
	for (int &i: d) scanf("%d", &i);

	auto f = [&](int n1, int n2, vector<int> a, vector<int>& b) {
		int m;
		cin >> m;
		vector<set<int> > g(n2);
		vector<pair<int, int> > vp;
		for (int i=0;i<n1;++i) if (a[i] != -1) vp.emplace_back(a[i], i);
		sort(vp.begin(), vp.end());

		for (int i=0;i<m;++i){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;v--;
			g[v].insert(u);
		}

		for (int i=0;i<n2;++i) {
			int d = -1;
			for (int j=0;j<vp.size();++j){
				if (g[i].count(vp[j].second) == 0) {
					if (d == -1 || d > a[vp[j].second]) d = a[vp[j].second];
					break;
				}
			}
			if (d == -1) b[i] = -1;
			else b[i] += d;
		}
	};

	f(n1, n2, a, b);
	f(n2, n3, b, c);
	f(n3, n4, c, d);
	int v = -1;
	for (int i: d) if (i != -1) {if (v==-1)v=i; else v=min(v, i);}
	cout << v << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}