#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	vector<pair<int, int> > q(26);
	for (int i=0;i<n;++i) {
		q[a[i]-'a'].first++;
		q[a[i]-'a'].second = 1;
	}
	for (int i=0;i<m;++i) {
		q[b[i]-'a'].first++;
		q[b[i]-'a'].second = 2;
	}
	string c = "";
	int prev = 0, prec = 0;
	for (int i=0; i < n + m; ++i) {
		for (int ind=0; ind<26; ++ind) {
			if (q[ind].first && (prec < k || prev != q[ind].second)) {
				c += 'a' + ind;
				q[ind].first--;
				if (prev == q[ind].second) prec++;
				else {
					prev = q[ind].second;
					prec = 1;
				}
				break;
			}
		}
		bool ok1=false, ok2=false;
		for (int ind=0;ind<26;++ind) {
			if (q[ind].first == 0) continue;
			if (q[ind].second == 1) ok1 = true;
			else ok2 = true;
		}
		if (ok1 && ok2) continue;
		break;
	}
	cout << c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}