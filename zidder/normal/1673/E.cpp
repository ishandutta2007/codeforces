#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> b(n);
	for (int &i: b) scanf("%d", &i);
	

	auto bp = [&](int x){
		int c = 0;
		while (x%2==0) {x/=2;++c;}
		return c;
	};

	vector<int> fct(n+1);
	for (int i=1;i<=n;++i) fct[i] = fct[i-1] + bp(i);

	vector<vector<int> > C(25, vector<int>(n+1));
	auto bl = [&](int a, int b) -> int {
		if (a < 0 || b > a) return 0;
		return (fct[a] - fct[b] - fct[a-b])==0;
	};
	for (int c=0;c<C.size();++c){
		// [n - 1 - c][i]
		C[c][0] = 0;
		for (int i=1;i<=n;++i){
			C[c][i] = C[c][i-1] ^ (bl(n-c, i-1));
		}
	}

	// cout << C[1][0] << " " << C[1][1] << " " << C[1][2] << " " << C[1][3] << " " << endl;

	vector<int> ans((1<<20));

	for (int i=0;i<n;++i){
		long long p = 1;
		for (int j=i+1;j<=min(n, i+20);++j){
			if (j > i + 1) {
				if (b[j-1] > 20) break;
				p *= (1<<b[j-1]);
			} else {
				p = b[j-1];
			}
			if (p > (1<<20)) break;
			int c = 0;
			if (i) c++;
			if (j < n) c++;

			// sum i = k-c to n - j - i - c  C[n-j-i-c][i]
			if (n-1-c<0) continue;
			if (k > n - (j - i)) continue;
			// cout << c << " " << n - (j-i) - c << " " << k << endl;
			// cout << i << " " << j << endl;
			int cc = C[c + (j - i)][n-c-(j-i)+1] + C[c + (j - i)][max(k-c, 0)];
			// cout << cc << endl;
			if (cc%2==0) continue;
			// cout << "hey " << p <<  endl;
			ans[p] = (ans[p] + 1) % 2;
		}
	}

	bool bb = false;
	for (int i=(1<<20)-1;i>=0;--i){
		if (ans[i]){
			bb = true;
		}
		if (bb) {
			cout << ans[i];
		}
	}
	if (!bb) cout << 0;
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}