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
	vector<int> p(n, -1);
	for (int i=1;i<n;++i) scanf("%d", &p[i]);
	for (int i=1;i<n;++i) p[i]--;
	vector<int> c(n);
	for (int i=1;i<n;++i) c[p[i]]++;
	sort(c.begin(), c.end());
	int inf = 0;
	multiset<int> cs;
	bool root=false;
	for (int i=n-1;i>=0;--i){
		multiset<int> tmp;
		for (int j: cs) {
			if (j-1) {
				tmp.insert(j-1);
			}
			inf++;
		}
		cs = tmp;
		if (c[i]) {
			if (c[i] - 1) cs.insert(c[i] - 1);
			inf++;
			if (inf == n) {
				cout << n - i << endl;
				return;
			}
		} else {
			if (!root){
				root = true;
				inf++;
				if (inf == n) {
					cout << n - i << endl;
					return;
				}
			} else {
				if (cs.empty()) {
					cout << n - i << endl;
					return;
				}
				int cnt = *cs.rbegin();
				cs.erase(cs.find(cnt));
				if (cnt - 1) cs.insert(cnt-1);
				inf++;
				
				if (inf == n) {
					cout << n - i << endl;
					return;
				}
			}
		}
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