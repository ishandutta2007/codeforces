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
	string s;
	cin >> s;

	vector<vector<int> > C(5001, vector<int> (5001));
	const int MOD = 998244353;
	C[0][0] = 1;
	for (int i=1;i<=5000;++i){
		for (int j=0;j<=5000;++j){
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
		}
	}
	vector<int> psum(n+1);
	for (int i=1;i<=n;++i){
		psum[i] = psum[i-1] + (s[i-1] == '1');
	}
	int ans = 1;
	if (psum[n] < k){
		cout << 1 << endl;
		return;
	}
	for (int l=0;l<n-1;++l){
		for (int r=l + 2;r<=n;++r){
			if (psum[r] - psum[l] <= k){
				int c1 = psum[r] - psum[l];
				int c0 = r - l - c1;
				for (int li=0;li<=1;++li){
					for (int ri=0;ri<=1;++ri){
						int c10=0, c11=0;
						if (li == 0) c10++;
						else c11++;
						if (ri==0) c10++;
						else c11++;
						if (c11 > c1 || c10 > c0) continue;
						if ((s[l] == '0') == (li==0) || (s[r-1] == '0') == (ri == 0)) continue;
						int C1 = c1 - c11;
						int C0 = c0 - c10;
						// cout << c1 << " " << c0 << " " << C1 << " " << C0 << endl;
						// cout << l << " " << r << " " << li << " " << ri << " " << C[r-l-2][C1] << endl;
						(ans += C[r-l-2][C1]) %= MOD;
					}
				}
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