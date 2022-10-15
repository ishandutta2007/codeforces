#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string s = "NO ESCAPE";

struct Node {
	int b;
	int c;
	int d;
	int h;
	Node (int b, int c, int d, int h) : b(b), c(c), d(d), h(h) {}
};

void solve(int test_ind){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> x(n);
	for (int i=0;i<n;++i) scanf("%d", &x[i]);

	int a, b, c, d, h;

	vector<vector<Node> > g(n);
	for (int i=0;i<k;++i){
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
		a--;b--;c--;d--;
		g[a].push_back(Node(b, c, d, h));
	}

	vector<unordered_map<int, long long> > dp(n);
	dp[0][0] = 0;
	for (int i=0;i<n;++i){
		long long mxx = -1;
		set<int> bs = {m-1};
		for (Node &p: g[i]){
			bs.insert(p.b);
		}
		for (auto &p: dp[i])
			bs.insert(p.first);
		// x(old - new) + h
		// -xnew + max(xold+h)
		bool first = true;
		for (int j:bs){
			if (dp[i].find(j) != dp[i].end()){
				if (first){
					mxx = dp[i][j] + j * 1ll * x[i];
					first = false;
				}
				mxx = max(dp[i][j] + j * 1ll * x[i], mxx);
			}
			if (!first){
				if (dp[i].find(j) != dp[i].end()) dp[i][j] = max(dp[i][j], mxx - j * 1ll * x[i]);
				else {
					dp[i][j] = mxx - j * 1ll * x[i];
				}
			}
		}
		// x(new - old) + h
		// xnew + max(h-xold)
		first = true;
		for (auto it=bs.rbegin();it!=bs.rend();it++){
			int j = *it;
			if (dp[i].find(j) != dp[i].end()){
				if (first){
					mxx = dp[i][j] - j * 1ll * x[i];
					first = false;
				}
				mxx = max(dp[i][j] - j * 1ll * x[i], mxx);
			}
			if (!first) {
				if (dp[i].find(j) != dp[i].end()) dp[i][j] = max(dp[i][j], mxx + j * 1ll * x[i]);
				else {
					dp[i][j] = mxx + j * 1ll * x[i];
				}
			}
		}

		for (Node &p: g[i]){
			if (dp[i].find(p.b) == dp[i].end()) continue;
			if (dp[p.c].find(p.d) != dp[p.c].end()){
				dp[p.c][p.d] = max(dp[p.c][p.d], dp[i][p.b] + p.h);
			}
			else{
				dp[p.c][p.d] = dp[i][p.b] + p.h;
			}
		}
	}
	if (dp[n-1].find(m-1) != dp[n-1].end()){
		cout << -dp[n-1][m-1] << endl;
	} else {
		cout << s << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}