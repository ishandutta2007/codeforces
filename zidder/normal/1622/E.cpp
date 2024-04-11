#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	int m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i=0;i<n;++i) scanf("%d", &x[i]);\

	vector<string> s(n);
	for (int i=0;i<n;++i) cin >> s[i];

	long long ans = -1;
	vector<int> ansp(n);

	for (int msk=0;msk<(1<<n);++msk){
		// msk of underestimated
		// ans = overestimated x - underestimated x + underestimated res - overestimated res
		vector<int> cnt(2 * n + 1); // number of unerestimated 1 - number of overestimated 1
		// cnt[n]: number of unerestimated 1 = number of overestimated 1
		for (int j=0;j<m;++j){
			int c = 0;
			for (int i=0;i<n;++i){
				if (msk&(1<<i)){
					// underestimated
					if (s[i][j] == '1') ++c;
				} else {
					if (s[i][j] == '1') --c;
				}
			}
			cnt[c + n]++;
		}
		for (int i=1;i<=2*n;++i) cnt[i] += cnt[i-1];
		// cnt[i]: number of unerestimated 1 - number of overestimated 1 <= i
		vector<int> p(m);
		vector<int> score(n);
		for (int j=0;j<m;++j){
			int c = 0;
			for (int i=0;i<n;++i){
				if (msk&(1<<i)){
					// underestimated
					if (s[i][j] == '1') ++c;
				} else {
					if (s[i][j] == '1') --c;
				}
			}
			p[j] = cnt[c + n]--;
			for (int i=0;i<n;++i){
				if (s[i][j] == '1') score[i]+=p[j];
			}
		}
		long long sm=0;
		for (int i=0;i<n;++i){
			sm += abs(x[i] - score[i]);
		}
		if (sm > ans){
			ans = sm;
			ansp = p;
		}
	}

	for (int i: ansp) cout << i << " ";
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}