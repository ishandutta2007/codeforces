#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <unordered_set>

using namespace std;

int cnt[40000];

void solve(int test_ind){
	string s;
	cin >> s;
	int ans = 0;
	// RL
	// DL
	// RU

	for (int i=0;i<s.size();++i){
		if (s[i] == 'L' || s[i] == 'U') continue;
		int w;
		if (s[i] == 'D'){
			int fu = -1, ll=i;
			for (int j=i+1;j<s.size();++j){
				if (s[j] == 'L' && j == ll + 1) ll++;
				if (s[j] == 'U') {
					fu = j;
					break;
				}
			}
			if (fu == -1) {
				continue;
			}
			w = fu - ll;
		} else {
			int fu = -1, fl=-1;
			bool rg = true, down = false;
			for (int j=i+1;j<s.size();++j){
				if (down) {
					if (s[j] != 'L' && fl == -1){
						fl = j - 1;
					}
				} else {
					if (s[j] == 'L' && rg) {rg = false;if (fl==-1)ans++;continue;}
					if (s[j] == 'R' && !rg) {rg= true; continue;}
					if (s[j] == 'L') {
						break;
					}
					if (s[j] == 'R' && fl == -1) {
						fl = j - 1;
					}
				}
				if (s[j] == 'U') {
					fu = j;
					break;
				}
				if (s[j] == 'D') {
					if (rg && fl == -1) {
						fl = j - 1;
					}
					down = true;
				}
			}
			if (fu == -1) continue;
			w = fu - fl;
		}
		bool du = false;
		
		auto put = [&](int r, int c) -> bool {
			if (cnt[r * w + c]++) return false;
			return true;
		};

		memset(cnt, 0, 20000 * sizeof(int));

		int mr = 0;
		for (int j=i;j<s.size();++j){
			int r = (j - i) / w;
			mr = max(mr, r);
			int c = (j - i) % w;
			if (s[j] == 'L') {
				if (c == 0) break;
				if (!put(r, c - 1)) break;
			}
			if (s[j] == 'R') {
				if (c == w - 1) break;
				if (!put(r, c+1)) break;
			}
			if (s[j] == 'U') {
				du = true;
				if (r == 0) break;
				if (!put(r-1, c)) break;
			}
			if (s[j] == 'D') {
				du = true;
				mr = r + 1;
				if (!put(r+1, c)) break;
			}
			if (du && mr == r && c == w - 1) {
				// cout << i << " " << j << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}